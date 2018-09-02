#include "RTClib.h"
#include <FlexiTimer2.h>
#include <Wire.h>

#if 1
#define DEBUG
#endif

RTC_DS1307 rtc;

#define MODE_NORMAL 100
#define MODE_TIMESET_HOUR 101
#define MODE_TIMESET_MIN 102

#define PIN_SEG_A 6
#define PIN_SEG_B 7
#define PIN_SEG_C 8
#define PIN_SEG_D 9
#define PIN_SEG_E 10
#define PIN_SEG_F 11
#define PIN_SEG_G 12
#define PIN_SEG_DP A1

#define PIN_DIGIT_0 A2
#define PIN_DIGIT_1 A3
#define PIN_DIGIT_2 5
#define PIN_DIGIT_3 13
#define PIN_DIGIT_4 A0
#define PIN_DIGIT_5 2

#define PIN_BUTTON_MODE 3
#define PIN_BUTTON_COUNT 4
#define BUTTON_COUNT_SHORT 2
#define BUTTON_COUNT_LONG 8
#define BUTTON_DEBOUNCE 70

#define PIN_SCL A5
#define PIN_SDA A4

//define INTERVAL1 2100
#define INTERVAL1 1000  // usec
//#define INTERVAL 13
#define NUM_DIGITS 6

#define STATE_BUTTON_NOT_PRESSED 0
#define STATE_BUTTON_DOWN 1
#define STATE_BUTTON_PRESSING 2
#define STATE_BUTTON_LONGPRESSED 3

uint8_t digit = 0;
uint8_t hour = 12, minute = 34, second = 56;
uint8_t dot = 0, minus = 0;
uint8_t dotCount = 10;
unsigned long dMicros = 0;
uint8_t bTimeSetDone = 0;
uint8_t bCountStart = 0;
uint8_t buttonPressCount = 0;

unsigned long prev_t = 0;

uint8_t mode = MODE_NORMAL;
uint8_t modeButtonState = STATE_BUTTON_NOT_PRESSED;
unsigned long elapsed = 0;


uint8_t digits[] = {
  PIN_DIGIT_0, PIN_DIGIT_1, PIN_DIGIT_2, PIN_DIGIT_3,
  PIN_DIGIT_4, PIN_DIGIT_5
};
uint8_t times[NUM_DIGITS];

/* ================================== */
void setMode() {
  //delay(50);
  if (mode == MODE_NORMAL) {
    mode = MODE_TIMESET_HOUR;
    // NIXHour.startBlink(NIX_BLINK_MSEC);
#ifdef DEBUG
    Serial.println("Mode: SET_HOUR");
#endif
  } else if (mode == MODE_TIMESET_HOUR) {
    mode = MODE_TIMESET_MIN;
    //NIXHour.stopBlink();
#ifdef DEBUG
    Serial.println("Mode: SET_MIN");
#endif
  } else if (mode == MODE_TIMESET_MIN) {
    mode = MODE_NORMAL;
#ifdef DEBUG
    Serial.println("Mode: NORMAL");
#endif
    bTimeSetDone = 1;
  } else {
    mode = MODE_NORMAL;
#ifdef DEBUG
    Serial.println("Mode: NORMAL");
#endif
    bTimeSetDone = 0;
    bCountStart = 0;
  }
}

void updateRTC() {
  DateTime now = rtc.now();
  DateTime newValue = DateTime(now.year(), now.month(), now.day(), hour, minute, 0);

  rtc.adjust(newValue);
}

void setTime() {
  //delay(50);
  if (mode == MODE_TIMESET_HOUR) {
    if (hour < 23) hour++;
    else hour = 0;
    bCountStart = 1;
  }
  if (mode == MODE_TIMESET_MIN) {
    if (minute < 59) minute++;
    else minute = 0;
    bCountStart = 1;
  }
  //Serial.println(String(hour) + ":" + String(minute));
}

// PIN3=PCINT19, PIN4=PCINT20 --> PCINT2_vect
ISR (PCINT2_vect) {
  if (millis() - prev_t < BUTTON_DEBOUNCE) {
    return;
  }

#ifdef DEBUG
  Serial.println("ISR!");
#endif

  if (digitalRead(PIN_BUTTON_MODE) == LOW) setMode();
  if (digitalRead(PIN_BUTTON_COUNT) == LOW) setTime();
  prev_t = millis();
}

void pciSetup(byte pin) {
  *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));  // enable pin
  PCIFR  |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
  PCICR  |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}

uint8_t procLongPress(uint8_t val, uint8_t max) {
  if (bCountStart) {
    if (digitalRead(PIN_BUTTON_COUNT) == LOW) {
      buttonPressCount++;
      if (buttonPressCount > BUTTON_COUNT_LONG) {
        if (val < max) {
          val++;
        } else {
          val = 0;
        }
        updateRTC();
      }
    } else { // HIGH
      buttonPressCount = 0;
      bCountStart = 0;
    }
  }

  return val;
}

void clearSeg() {
  digitalWrite(PIN_SEG_A, LOW);
  digitalWrite(PIN_SEG_B, LOW);
  digitalWrite(PIN_SEG_C, LOW);
  digitalWrite(PIN_SEG_D, LOW);
  digitalWrite(PIN_SEG_E, LOW);
  digitalWrite(PIN_SEG_F, LOW);
  digitalWrite(PIN_SEG_G, LOW);
  digitalWrite(PIN_SEG_DP, LOW);
}

void decodeSeg(int num, uint8_t dp, uint8_t minus) {
  if (dp) digitalWrite(PIN_SEG_DP, HIGH);

  switch (num) {
    case 0:
      digitalWrite(PIN_SEG_A, HIGH);
      digitalWrite(PIN_SEG_B, HIGH);
      digitalWrite(PIN_SEG_C, HIGH);
      digitalWrite(PIN_SEG_D, HIGH);
      digitalWrite(PIN_SEG_E, HIGH);
      digitalWrite(PIN_SEG_F, HIGH);
      break;
    case 1:
      digitalWrite(PIN_SEG_B, HIGH);
      digitalWrite(PIN_SEG_C, HIGH);
      break;
    case 2:
      digitalWrite(PIN_SEG_A, HIGH);
      digitalWrite(PIN_SEG_B, HIGH);
      digitalWrite(PIN_SEG_G, HIGH);
      digitalWrite(PIN_SEG_E, HIGH);
      digitalWrite(PIN_SEG_D, HIGH);
      break;
    case 3:
      digitalWrite(PIN_SEG_A, HIGH);
      digitalWrite(PIN_SEG_B, HIGH);
      digitalWrite(PIN_SEG_G, HIGH);
      digitalWrite(PIN_SEG_C, HIGH);
      digitalWrite(PIN_SEG_D, HIGH);
      break;
    case 4:
      digitalWrite(PIN_SEG_F, HIGH);
      digitalWrite(PIN_SEG_G, HIGH);
      digitalWrite(PIN_SEG_B, HIGH);
      digitalWrite(PIN_SEG_C, HIGH);
      break;
    case 5:
      digitalWrite(PIN_SEG_A, HIGH);
      digitalWrite(PIN_SEG_F, HIGH);
      digitalWrite(PIN_SEG_G, HIGH);
      digitalWrite(PIN_SEG_C, HIGH);
      digitalWrite(PIN_SEG_D, HIGH);
      break;
    case 6:
      digitalWrite(PIN_SEG_A, HIGH);
      digitalWrite(PIN_SEG_F, HIGH);
      digitalWrite(PIN_SEG_E, HIGH);
      digitalWrite(PIN_SEG_D, HIGH);
      digitalWrite(PIN_SEG_C, HIGH);
      digitalWrite(PIN_SEG_G, HIGH);
      break;
    case 7:
      digitalWrite(PIN_SEG_F, HIGH);
      digitalWrite(PIN_SEG_A, HIGH);
      digitalWrite(PIN_SEG_B, HIGH);
      digitalWrite(PIN_SEG_C, HIGH);
      break;
    case 8:
      digitalWrite(PIN_SEG_A, HIGH);
      digitalWrite(PIN_SEG_B, HIGH);
      digitalWrite(PIN_SEG_C, HIGH);
      digitalWrite(PIN_SEG_D, HIGH);
      digitalWrite(PIN_SEG_E, HIGH);
      digitalWrite(PIN_SEG_F, HIGH);
      digitalWrite(PIN_SEG_G, HIGH);
      break;
    case 9:
      digitalWrite(PIN_SEG_A, HIGH);
      digitalWrite(PIN_SEG_F, HIGH);
      digitalWrite(PIN_SEG_G, HIGH);
      digitalWrite(PIN_SEG_B, HIGH);
      digitalWrite(PIN_SEG_C, HIGH);
      digitalWrite(PIN_SEG_D, HIGH);
      break;
    default:
      clearSeg(); // Turn off digit if num > 10
      break;
  }
}

void writeVFD() {
  boolean flag_on;

  if ((second % 10) != digits[0]) {
    dot = 0xff;
    dMicros = micros();
  }

  if (micros() - dMicros > 100000) {
    dot = 0;
  }

  times[5] = hour / 10;
  times[4] = hour % 10;
  times[3] = minute / 10;
  times[2] = minute % 10;
  times[1] = second / 10;
  times[0] = second % 10;

  for (int i = 0; i < NUM_DIGITS; i++) {
    flag_on = true;
    if (mode == MODE_TIMESET_HOUR && (i != 4 && i != 5)) {
      flag_on = false;
    }
    if (mode == MODE_TIMESET_MIN && (i != 2 && i != 3)) {
      flag_on = false;
    }

    digitalWrite(digits[i], HIGH);
    if ( flag_on ) {
      if (i == 2 || i == 4) decodeSeg(times[i], dot, 0);
      else decodeSeg(times[i], 0, 0);
    }
    delayMicroseconds(INTERVAL1);
    clearSeg();
    digitalWrite(digits[i], LOW);
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_SEG_A, OUTPUT);
  pinMode(PIN_SEG_B, OUTPUT);
  pinMode(PIN_SEG_C, OUTPUT);
  pinMode(PIN_SEG_D, OUTPUT);
  pinMode(PIN_SEG_E, OUTPUT);
  pinMode(PIN_SEG_F, OUTPUT);
  pinMode(PIN_SEG_G, OUTPUT);
  pinMode(PIN_SEG_DP, OUTPUT);
  pinMode(PIN_BUTTON_MODE, INPUT_PULLUP);
  pinMode(PIN_BUTTON_COUNT, INPUT_PULLUP);
  pinMode(PIN_BUTTON_MODE, INPUT_PULLUP);
  pinMode(PIN_BUTTON_COUNT, INPUT_PULLUP);
  pinMode(PIN_DIGIT_0, OUTPUT);
  pinMode(PIN_DIGIT_1, OUTPUT);
  pinMode(PIN_DIGIT_2, OUTPUT);
  pinMode(PIN_DIGIT_3, OUTPUT);
  pinMode(PIN_DIGIT_4, OUTPUT);
  pinMode(PIN_DIGIT_5, OUTPUT);

  Serial.begin(115200);
  Wire.begin();
  rtc.begin();

  if (!rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(__DATE__, __TIME__));
  }

  if (bTimeSetDone == 1) {
    DateTime now = rtc.now();
    DateTime newDate = DateTime(now.year(), now.month(), now.day(), hour, minute, 0);
    rtc.adjust(newDate);
    bTimeSetDone = 0;
  }

  FlexiTimer2::set(INTERVAL1 * NUM_DIGITS / 1000 + 1, writeVFD);
  FlexiTimer2::start();

  pciSetup(PIN_BUTTON_MODE);
  pciSetup(PIN_BUTTON_COUNT);
  EICRA |= bit (ISC11);
  sei();
}

void loop() {
  if (mode == MODE_NORMAL) {
    DateTime now = rtc.now();
    hour = now.hour();
    minute = now.minute();
    second = now.second();
    delay(50);
    return;
  } // if (MODE_NORMAL)

  //
  // mode != MODE_NORMAL
  //
  updateRTC();

  if (mode == MODE_TIMESET_HOUR) {
    hour = procLongPress(hour, 24);
  } // if (MODE_TIMESET_HOUR)

  if (mode == MODE_TIMESET_MIN) {
    minute = procLongPress(minute, 60);
  } // if (MODE_TIMESET_HOUR)

  Serial.println(buttonPressCount);
  delay(100);
}

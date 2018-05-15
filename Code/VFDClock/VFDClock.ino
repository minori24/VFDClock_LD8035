
#include <FlexiTimer2.h>
#include "RTClib.h"
#include <Wire.h>

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
#define PIN_SEG_H A0
#define PIN_SEG_MINUS A2
#define PIN_SEG_DP A1

#define PIN_BUTTON_MODE A7
#define PIN_BUTTON_COUNT A6
#define BUTTON_COUNT_SHORT 2
#define BUTTON_COUNT_LONG 8

#define PIN_SCL A5
#define PIN_SDA A4

#define PIN_SER 2
#define PIN_SRCLK 3
#define PIN_SRCLR 4
#define PIN_RCLK 5
#define INTERVAL 13
#define NUM_DIGITS 6

uint8_t digit = 0;
uint8_t digits[NUM_DIGITS];

uint8_t hour = 23, minute = 25, second = 0;
uint8_t dot = 0, minus = 0;
uint8_t dotCount = 10;
unsigned long dMicros = 0;

uint8_t mode = MODE_NORMAL;
uint8_t bTimeSetDone = 0;
uint8_t bCountStart = 0;
uint16_t buttonPressCount = 0;
unsigned long prev_t = 0;

void setTime(){
  //delay(50);
  if(mode == MODE_TIMESET_HOUR){
    if(hour < 23) hour++;
    else hour = 0;
    bCountStart = 1;
   }
  else if(mode == MODE_TIMESET_MIN){
    if(minute < 59) minute++;
    else minute = 0;
    bCountStart = 1;
  }
  else{

  }

  //Serial.println(String(hour) + ":" + String(minute));

}

void setMode(){
  //delay(50);
  if(mode == MODE_NORMAL){
    mode = MODE_TIMESET_HOUR;
    Serial.println("Mode: SET_HOUR");
  }
  else if(mode == MODE_TIMESET_HOUR){
    mode = MODE_TIMESET_MIN;
    Serial.println("Mode: SET_MIN");
  }
  else if(mode == MODE_TIMESET_MIN){
    mode = MODE_NORMAL;
    Serial.println("Mode: NORMAL");
    bTimeSetDone = 1;
  }
  else{
    mode = MODE_NORMAL;
    Serial.println("Mode: NORMAL");
    bTimeSetDone = 0;
    bCountStart = 0;
  }
}


void clearSeg(){
    digitalWrite(PIN_SEG_A, LOW);
    digitalWrite(PIN_SEG_B, LOW);
    digitalWrite(PIN_SEG_C, LOW);
    digitalWrite(PIN_SEG_D, LOW);
    digitalWrite(PIN_SEG_E, LOW);
    digitalWrite(PIN_SEG_F, LOW);
    digitalWrite(PIN_SEG_G, LOW);
    digitalWrite(PIN_SEG_DP, LOW);
    digitalWrite(PIN_SEG_MINUS, LOW);
}

void decodeSeg(int num, uint8_t dp, uint8_t minus){
  if(dp) digitalWrite(PIN_SEG_DP, HIGH);
  if(minus) digitalWrite(PIN_SEG_MINUS, HIGH);
  
  switch(num){
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

void writeVFD(){

  if((second % 10) != digits[0]){
    dot = 0xff;
    dMicros = micros();
  }
  
  if(micros() - dMicros > 100000){
    dot = 0;
  }
  
  digits[0] = second % 10;
  digits[1] = second / 10;
  digits[2] = minute % 10;
  digits[3] = minute / 10;
  digits[4] = hour % 10;
  digits[5] = hour / 10;

  for(int i = 0; i < NUM_DIGITS; i++){
    digitalWrite(PIN_RCLK, LOW);
    shiftOut(PIN_SER, PIN_SRCLK, MSBFIRST, 0x01 << i);
    if(i == 2 || i == 4) decodeSeg(digits[i], dot, 0);
    else decodeSeg(digits[i], 0, 0);
    digitalWrite(PIN_RCLK, HIGH);
    delayMicroseconds(2100);
    clearSeg();
  }
  
  digitalWrite(PIN_RCLK, LOW);
  shiftOut(PIN_SER, PIN_SRCLK, MSBFIRST, 0);
  digitalWrite(PIN_RCLK, HIGH);
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
  pinMode(PIN_SEG_H, OUTPUT);
  pinMode(PIN_SEG_MINUS, OUTPUT);
  pinMode(PIN_SEG_DP, OUTPUT);
  pinMode(PIN_BUTTON_MODE, INPUT_PULLUP);
  pinMode(PIN_BUTTON_COUNT, INPUT_PULLUP);
  pinMode(PIN_SER, OUTPUT);
  pinMode(PIN_SRCLK, OUTPUT);
  pinMode(PIN_SRCLR, OUTPUT);
  pinMode(PIN_RCLK, OUTPUT);

  digitalWrite(PIN_SRCLR, HIGH);

  for(int i = 0; i < NUM_DIGITS; i++) digits[i] = 0;
  Serial.begin(9600);
  Wire.begin();
  rtc.begin();
  
  if (!rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
     rtc.adjust(DateTime(__DATE__, __TIME__));
  }

  Serial.println("Start");
  
  FlexiTimer2::set(INTERVAL, writeVFD);
  FlexiTimer2::start();

}


void loop() {
  if(bTimeSetDone == 1){
    DateTime now = rtc.now();
    DateTime newDate = DateTime(now.year(), now.month(), now.day(), hour, minute, 0);
    rtc.adjust(newDate);
    bTimeSetDone = 0;
  }

  if(mode == MODE_NORMAL){
    DateTime now = rtc.now();
    hour = now.hour();
    minute = now.minute();
    second = now.second();

    //if(digitalRead(PIN_BUTTON_MODE) == LOW) mode = MODE_TIMESET_HOUR;
  }
  
  if(mode == MODE_TIMESET_HOUR){
    Serial.println("mode == HOUR");
    if(bCountStart){
      if(digitalRead(PIN_BUTTON_COUNT) == LOW){
          buttonPressCount++;
          if(buttonPressCount > BUTTON_COUNT_LONG){
            if(hour < 23) hour++;
            else hour = 0;
            buttonPressCount = 0;
          }
      }
      else{
        buttonPressCount = 0;
        bCountStart = 0;
      }
    }
  }
  
  if(mode == MODE_TIMESET_MIN){

    if(bCountStart){
      if(digitalRead(PIN_BUTTON_COUNT) == LOW){
          buttonPressCount++;
          if(buttonPressCount > BUTTON_COUNT_LONG){
            if(minute < 59) minute++;
            else minute = 0;
            buttonPressCount = 0;
          }
      }
      else{
        buttonPressCount = 0;
        bCountStart = 0;
      }
    }
  }
  
  delay(50);
}

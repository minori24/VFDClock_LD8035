
#include <FlexiTimer2.h>
#include <Wire.h>

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
#define PIN_SEG_MINUS A0
#define PIN_SEG_DP A1

#define PIN_DIGIT_0 A2
#define PIN_DIGIT_1 A3
#define PIN_DIGIT_2 5
#define PIN_DIGIT_3 A6
#define PIN_DIGIT_4 A7
#define PIN_DIGIT_5 2

#define PIN_BUTTON_MODE 3
#define PIN_BUTTON_COUNT 4
#define BUTTON_COUNT_SHORT 2
#define BUTTON_COUNT_LONG 8

#define PIN_SCL A5
#define PIN_SDA A4

#define INTERVAL 20
#define NUM_DIGITS 6

uint8_t digit = 0;

uint8_t hour = 23, minute = 25, second = 0;
uint8_t dot = 0, minus = 0;
uint8_t dotCount = 10;
unsigned long dMicros = 0;

uint8_t mode = MODE_NORMAL;
uint8_t bTimeSetDone = 0;
uint8_t bCountStart = 0;
uint16_t buttonPressCount = 0;
unsigned long prev_t = 0;

uint8_t digits[NUM_DIGITS] = {PIN_DIGIT_0, PIN_DIGIT_1, PIN_DIGIT_2, PIN_DIGIT_3, 
                                            PIN_DIGIT_4, PIN_DIGIT_5};
uint8_t times[NUM_DIGITS];

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
  
  times[0] = second % 10;
  times[1] = second / 10;
  times[2] = minute % 10;
  times[3] = minute / 10;
  times[4] = hour % 10;
  times[5] = hour / 10;

  for(int i = 0; i < NUM_DIGITS; i++){
    for(int j = 0; j < NUM_DIGITS; j++){
        digitalWrite(digits[j], LOW);
        if(i == j) digitalWrite(digits[j], HIGH); 
    }
    
    if(i == 2 || i == 4) decodeSeg(times[i], dot, 0);
    else decodeSeg(times[i], 0, 0);
    delayMicroseconds(2000);
    clearSeg();
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
  pinMode(PIN_SEG_MINUS, OUTPUT);
  pinMode(PIN_SEG_DP, OUTPUT);
  pinMode(PIN_BUTTON_MODE, INPUT_PULLUP);
  pinMode(PIN_BUTTON_COUNT, INPUT_PULLUP);
  pinMode(PIN_DIGIT_0, OUTPUT);
  pinMode(PIN_DIGIT_1, OUTPUT);
  pinMode(PIN_DIGIT_2, OUTPUT);
  pinMode(PIN_DIGIT_3, OUTPUT);
  pinMode(PIN_DIGIT_4, OUTPUT);
  pinMode(PIN_DIGIT_5, OUTPUT);
  
  for(int i = 0; i < NUM_DIGITS; i++) digits[i] = 0;
  Serial.begin(115200);
  Wire.begin();

  Serial.println("Start");
  
  FlexiTimer2::set(INTERVAL, writeVFD);
  FlexiTimer2::start();
}


void loop() {
  
  if(mode == MODE_NORMAL){
    
    //Serial.println(second);
    //if(digitalRead(PIN_BUTTON_MODE) == LOW) mode = MODE_TIMESET_HOUR;
  }
  
  delay(50);
}

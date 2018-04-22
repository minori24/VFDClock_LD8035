#include <FlexiTimer2.h>

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

#define PIN_SW_A A7
#define PIN_SW_B A6

#define PIN_SCL A5
#define PIN_SDA A4

#define PIN_SER 2
#define PIN_SRCLK 3
#define PIN_SRCLR 4
#define PIN_RCLK 5

#define INTERVAL 10

#define NUM_DIGITS 6

uint8_t digit = 0;
uint8_t digits[NUM_DIGITS];


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
      digitalWrite(PIN_SEG_A, HIGH);
      digitalWrite(PIN_SEG_B, HIGH);
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
  clearSeg();
  for(int i = 0; i < NUM_DIGITS; i++){
    digitalWrite(PIN_RCLK, LOW);    
    shiftOut(PIN_SER, PIN_SRCLK, MSBFIRST, 0x10 >> i);
    if(i==2 || i==4) decodeSeg(digits[i], 1, 0);
    else decodeSeg(digits[i], 0, 0);
    digitalWrite(PIN_RCLK, HIGH);
    delay(INTERVAL);
  }

  if(digit < NUM_DIGITS){
    digit++;  
  }
  else{
    digit = 0;
    
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
  pinMode(PIN_SEG_H, OUTPUT);
  pinMode(PIN_SEG_MINUS, OUTPUT);
  pinMode(PIN_SEG_DP, OUTPUT);
  pinMode(PIN_SW_A, INPUT_PULLUP);
  pinMode(PIN_SW_B, INPUT_PULLUP);
  pinMode(PIN_SER, OUTPUT);
  pinMode(PIN_SRCLK, OUTPUT);
  pinMode(PIN_SRCLR, OUTPUT);
  pinMode(PIN_RCLK, OUTPUT);

  digitalWrite(PIN_SRCLR, LOW);

  FlexiTimer2::set(50, writeVFD);
  FlexiTimer2::start();
  for(int i = 0; i < NUM_DIGITS; i++) digits[i] = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < NUM_DIGITS; i++) digits[i] = i;
  delay(1000);
}

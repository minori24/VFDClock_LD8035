// VfdClock.ino
// (c) 2018 FaLab Kannai
//
static String	VersionStr	= "06.01.02";

#include <Wire.h>
#include "RTClib.h"
#include "Button.h"
#include "VersionMode.h"
#include "VFD.h"
#include "Clock.h"
#include "StopWatch.h"
#include "Game1.h"

#define 	VERSION_MSEC    3000 // msec

#define		MODE_NULL	0x00
#define		MODE_VERSION	0x01
#define		MODE_CLOCK	0x02
#define		MODE_STOP_WATCH	0x03
#define		MODE_GAME1	0x10

#define 	BUTTON_N 	2

#define 	PIN_BUTTON_MODE	3
#define 	PIN_BUTTON_SET	4
uint8_t    PinSeg[]      = { 6, 7, 8, 9, 10, 11, 12, A1 };
// uint8_t    PinDigit[]    = { 2, A0, 13, 5, A3, A2 };
uint8_t   PinDigit[]    = { 2, 13, A3, A0, 5, A2 };

//=========================================================
void setup()
//=========================================================
{
  for(uint8_t i = 0; i < 8; i++){
    pinMode(PinSeg[i], OUTPUT);
    digitalWrite(PinSeg[i], HIGH);
  }
  for(uint8_t i = 0; i < 6; i++){
    pinMode(PinDigit[i], OUTPUT);
    digitalWrite(PinDigit[i], HIGH);
  }
}

//=========================================================
void loop()
//=========================================================
{
  while(1);
}

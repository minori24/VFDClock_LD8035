// VfdClock.ino
// (c) 2018 FaLab Kannai
//
static String	VersionStr	= "06.02.00";

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
uint8_t		PinSeg[]     	= { 6, 7, 8, 9, 10, 11, 12, A1 };
uint8_t		PinDigit[]   	= { 2, A0, 13, 5, A3, A2 };

uint8_t		Mode 		= MODE_NULL;

RTC_DS1307	Rtc;
VFD		Vfd;
Button		*Btn;

VersionMode	Ver;
Clock		Cl1;
StopWatch	SW1;
Game1		Gm1;

unsigned long	CurMsec		= 0;
unsigned long	PrevMsec	= 0;
unsigned long	VersionStart	= 0;
boolean 	BlinkEnable	= true;

//=========================================================
void startVersion()
{
  VersionStart = CurMsec;
  Mode = MODE_VERSION;
}
//---------------------------------------------------------
void startClock()
{
  Mode = MODE_CLOCK;
}
//---------------------------------------------------------
void startStopWatch()
{
  //SW1.init(&Vfd);
  Mode = MODE_STOP_WATCH;
}
//---------------------------------------------------------
void startGame1()
{
  Gm1.init(&Vfd);
  Mode = MODE_GAME1;
}

//=========================================================
// MODE_VERSION
//=========================================================
void versionBtn0_IntrHandler(unsigned long cur_msec)
{
}
//---------------------------------------------------------
void versionBtn1_IntrHandler(unsigned long cur_msec)
{
}
//---------------------------------------------------------
void versionBtn0_LoopHandler()
{
  if ( Btn[0].click_count() >= 1 ) {
    Mode = MODE_CLOCK;
  }
}
//---------------------------------------------------------
void versionBtn1_LoopHandler()
{
}
//=========================================================
// MODE_CLOCK
//=========================================================
void clockBtn0_IntrHandler(unsigned long cur_msec)
{
  switch ( Cl1.mode() ) {
  case Clock::MODE_SET_DATE_YEAR:	Cl1.set_mode(Clock::MODE_SET_DATE_MONTH);	break;
  case Clock::MODE_SET_DATE_MONTH:	Cl1.set_mode(Clock::MODE_SET_DATE_DAY);		break;
  case Clock::MODE_SET_DATE_DAY:	Cl1.set_mode(Clock::MODE_SET_TIME_HOUR);	break;
  case Clock::MODE_SET_TIME_HOUR:	Cl1.set_mode(Clock::MODE_SET_TIME_MINUTE);	break;
  case Clock::MODE_SET_TIME_MINUTE:	Cl1.set_mode(Clock::MODE_SET_TIME_SECOND);	break;
  case Clock::MODE_SET_TIME_SECOND:
    Cl1.set_adjust_flag(true);
    Cl1.set_mode(Clock::MODE_DISP_TIME);
    break;
  default:
    break;
  } // switch ( Cl1.mode() )
}
//---------------------------------------------------------
void clockBtn1_IntrHandler(unsigned long cur_msec)
{
  switch ( Cl1.mode() ) {
  case Clock::MODE_SET_DATE_YEAR:	Cl1.countUpYear();	break;
  case Clock::MODE_SET_DATE_MONTH:	Cl1.countUpMonth();	break;
  case Clock::MODE_SET_DATE_DAY:	Cl1.countUpDay();	break;
  case Clock::MODE_SET_TIME_HOUR:	Cl1.countUpHour();	break;
  case Clock::MODE_SET_TIME_MINUTE:	Cl1.countUpMinute();	break;
  case Clock::MODE_SET_TIME_SECOND:	Cl1.countUpSecond();	break;
  default:	break;
  } // switch ( Cl1.mode() )
}
//---------------------------------------------------------
void clockBtn0_LoopHandler()
{
  switch ( Cl1.mode() ) {
  case Clock::MODE_DISP_TIME:
    if ( Btn[0].click_count() == 1 ) {
      Cl1.set_mode(Clock::MODE_DISP_DATE);
      return;
    }
    if ( Btn[0].click_count() == 2 ) {
      startStopWatch();
      return;
    }
    if ( Btn[0].click_count() >= 3 ) {
      startGame1();
      return;
    }
    if ( Btn[0].long_pressed() || Btn[0].repeat() ) {
      Cl1.set_mode(Clock::MODE_SET_DATE_YEAR);
      return;
    }
    break;
  case Clock::MODE_DISP_DATE:
    if ( Btn[0].click_count() >= 1 ) {
      Cl1.set_mode(Clock::MODE_DISP_TIME);
      return;
    }
    if ( Btn[0].long_pressed() || Btn[0].repeat() ) {
      Cl1.set_mode(Clock::MODE_SET_DATE_YEAR);
      return;
    }
    break;
  default:
    break;
  } // switch ( Cl1.mode() )
}
//---------------------------------------------------------
void clockBtn1_LoopHandler()
{
  switch ( Cl1.mode() ) {
  case Clock::MODE_DISP_DATE:
  case Clock::MODE_DISP_TIME:
    if ( Btn[1].click_count() >= 1 ) {      
      if ( BlinkEnable ) {
	BlinkEnable = false;
      } else {
	BlinkEnable = true;
      }
      Serial.print("BlinkEnable: ");
      Serial.println(BlinkEnable);
    }
    
    /*
    if ( Btn[1].click_count() == 2 ) {
      startStopWatch();
      return;
    }
    if ( Btn[1].click_count() >= 3 ) {
      startGame1();
      return;
    }
    */
    break;
  default:
    if ( Btn[1].long_pressed() || Btn[1].repeat() ) {
      // single click, long pressed, repeat
      BlinkEnable = false;
      switch ( Cl1.mode() ) {
      case Clock::MODE_SET_DATE_YEAR:	Cl1.countUpYear();	break;
      case Clock::MODE_SET_DATE_MONTH:	Cl1.countUpMonth();	break;
      case Clock::MODE_SET_DATE_DAY:	Cl1.countUpDay();	break;
      case Clock::MODE_SET_TIME_HOUR:	Cl1.countUpHour();	break;
      case Clock::MODE_SET_TIME_MINUTE:	Cl1.countUpMinute();	break;
      case Clock::MODE_SET_TIME_SECOND:	Cl1.countUpSecond();	break;
      deault:	break;
      } // switch
    } else {
      if ( ! BlinkEnable ) {
	BlinkEnable = true;
      }
    }
    break;
  } // switch ( Cl1.mode() )
}
//=========================================================
// MODE_STOP_WATCH
//=========================================================
void stopWatchBtn0_IntrHandler(unsigned long cur_msec)
{
}
//---------------------------------------------------------
void stopWatchBtn1_IntrHandler(unsigned long cur_msec)
{
  if ( SW1.mode() == StopWatch::MODE_TIME ) {
    if ( SW1.stat() == StopWatch::STAT_STOP ) {
      SW1.start();
    } else if ( SW1.stat() == StopWatch::STAT_RUNNING ) {
      SW1.stop();
    }
  } else if ( SW1.mode() == StopWatch::MODE_LAP ) {
    SW1.set_mode(StopWatch::MODE_TIME);
  }
}
//---------------------------------------------------------
void stopWatchBtn0_LoopHandler()
{
  if ( Btn[0].click_count() == 1 ) {
    if ( SW1.mode() == StopWatch::MODE_TIME && SW1.stat() == StopWatch::STAT_STOP ) {
      SW1.reset();
    }
    return;
  }
  
  if ( Btn[0].click_count() >= 2 ) {
    startClock();
    return;
  }
}
//---------------------------------------------------------
void stopWatchBtn1_LoopHandler()
{
}
//=========================================================
// MODE_GAME1
//=========================================================
void game1Btn0_IntrHandler(unsigned long cur_msec)
{
  switch ( Gm1.mode() ) {
  case Game1::MODE_PLAY:
    Gm1.p1()->up();
    break;
  case Game1::MODE_SCORE:
  case Game1::MODE_END:
  default:
    break;
  } // switch 
}
//---------------------------------------------------------
void game1Btn1_IntrHandler(unsigned long cur_msec)
{
  switch ( Gm1.mode() ) {
  case Game1::MODE_PLAY:
    Gm1.p1()->shoot(Game1::BULLET_INTERVAL);
    break;
  case Game1::MODE_SCORE:
  case Game1::MODE_END:
  default:
    break;
  } // switch ( Gm1.mode() )
}
//---------------------------------------------------------
void game1Btn0_LoopHandler()
{
  switch ( Gm1.mode() ) {
  case Game1::MODE_PLAY:
    break;
  case Game1::MODE_SCORE:
    break;
  case Game1::MODE_END:
    if ( Btn[0].long_pressed() ) {
      startGame1();
      return;
    }
    if ( Btn[0].click_count() >= 2 ) {
      Mode = MODE_CLOCK;
      return;
    }
    break;
  default:
    break;
  } // switch ( Gm1.mode() )
}
//---------------------------------------------------------
void game1Btn1_LoopHandler()
{
  switch ( Gm1.mode() ) {
  case Game1::MODE_PLAY:
    break;
  case Game1::MODE_SCORE:
    break;
  case Game1::MODE_END:
    if ( Btn[1].long_pressed() ) {
      startGame1();
      return;
    }
    break;
  default:
    break;
  } // switch ( Gm1.mode() )
}

//=========================================================
// interrupt handlers
//---------------------------------------------------------
void btn_IntrHandler(unsigned long cur_msec)
{
  for (int btn_num = 0; btn_num < BUTTON_N; btn_num++) {
    if ( Btn[btn_num].get() ) {
      Btn[btn_num].print(true);

      if ( Btn[btn_num].value() == HIGH ) {
	continue;
      }

      // LOW
      switch ( btn_num ) {
      case 0:
	switch ( Mode ) {
	case MODE_VERSION:	versionBtn0_IntrHandler(cur_msec);	break;
	case MODE_CLOCK:	clockBtn0_IntrHandler(cur_msec);	break;
	case MODE_STOP_WATCH:	stopWatchBtn0_IntrHandler(cur_msec);	break;
	case MODE_GAME1:	game1Btn0_IntrHandler(cur_msec);	break;
	default:  break;
	} // switch (Mode)
	break;

      case 1:
	switch ( Mode ) {
	case MODE_VERSION:	versionBtn1_IntrHandler(cur_msec);	break;
	case MODE_CLOCK:	clockBtn1_IntrHandler(cur_msec);	break;
	case MODE_STOP_WATCH:	stopWatchBtn1_IntrHandler(cur_msec);	break;
	case MODE_GAME1:	game1Btn1_IntrHandler(cur_msec);	break;
	defaut:	  break;
	} // switch ( Mode )
	break;

      default:
	break;
      } // switch ( btn_num )
    }
  } // for
}
//---------------------------------------------------------
ISR (PCINT2_vect)
{
  static uint8_t       prev_pin;
  static unsigned long prev_msec = 0;
  unsigned long        cur_msec = millis();

  if ( cur_msec - prev_msec < Button::DEBOUNCE ) {
    return;
  }
  prev_msec = cur_msec;

  btn_IntrHandler(cur_msec);
}
//=========================================================
// button event in loop handlers
//---------------------------------------------------------
void btn_LoopHandler()
{
  for (int btn_num = 0; btn_num < BUTTON_N; btn_num++) {
    if ( Btn[btn_num].get() ) {
      Btn[btn_num].print();

      switch ( btn_num ) {
      case 0:
	switch ( Mode ) {
	case MODE_VERSION:	versionBtn0_LoopHandler();	break;
	case MODE_CLOCK:	clockBtn0_LoopHandler();	break;
	case MODE_STOP_WATCH:	stopWatchBtn0_LoopHandler();	break;
	case MODE_GAME1:	game1Btn0_LoopHandler();	break;
	default:    break;
	} // switch ( Mode )
	break;
      case 1:
	switch ( Mode ) {
	case MODE_VERSION:	versionBtn1_LoopHandler();	break;
	case MODE_CLOCK:	clockBtn1_LoopHandler();	break;
	case MODE_STOP_WATCH:	stopWatchBtn1_LoopHandler();	break;
	case MODE_GAME1:	game1Btn1_LoopHandler();	break;
	default:    break;
	} // switch ( Mode )
	break;
      default:
	break;
      } // switch ( btn_num )
    } // if
  } // for
}

//=========================================================
void setup()
//=========================================================
{
  Serial.begin(115200);
  while (!Serial) {} // for Leonardo

  Serial.println("Version: " + VersionStr);

  size_t digit_n = sizeof(PinDigit) / sizeof(PinDigit[0]);

  // init RTC
  Rtc.begin();

  // set random seed
  unsigned long sec = Rtc.now().second();
  randomSeed(sec);

  // init VFD
  Vfd.init(PinSeg, PinDigit, digit_n);

  // init Buttons
  Btn = new Button[BUTTON_N];
  Btn[0].init(PIN_BUTTON_MODE, "[MODE]");
  Btn[1].init(PIN_BUTTON_SET,  "[SET] ");

  Serial.print("Button::Num: ");
  Serial.println(Button::Num);
  for (int i=0; i < Button::Num; i++) {
    Button::Obj[i]->print();
  }

  // init all modes
  Ver.init(&Vfd, VersionStr);
  Cl1.init(&Vfd, &Rtc);
  SW1.init(&Vfd);
  Gm1.init(&Vfd);

  // start Version Mode
  startVersion();

  sei();
}

//=========================================================
void loop()
//=========================================================
{
  // Button Handler
  btn_LoopHandler();

  CurMsec = millis(); // MUST! after btn_LoopHandler()

  // Adjust clock
  if ( Cl1.adjustIfNecessary() ) {
    Serial.println(Cl1.dateStr());
  }

  // 
  switch ( Mode ) {
  case MODE_VERSION:
    if ( CurMsec - VersionStart > VERSION_MSEC ) {
      startClock();
    }
    Ver.display(BlinkEnable);
    break;
  case MODE_CLOCK:	Cl1.loop(CurMsec, BlinkEnable);	break;
  case MODE_STOP_WATCH:	SW1.loop(CurMsec);		break;
  case MODE_GAME1:	Gm1.loop(CurMsec);		break;
  default:    break;
  } // switch ( Mode )
}

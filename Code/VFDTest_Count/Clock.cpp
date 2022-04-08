// Player.cpp
// (c) 2018 FabLab Kannai
//
#include "Clock.h"

//===========================================
//Clock::Clock() {}
//-------------------------------------------
void Clock::init(VFD *vfd, RTC_DS1307 *rtc)
{
  _vfd = vfd;
  _rtc = rtc;
  _cur_dt = _rtc->now();
}
//-------------------------------------------
void Clock::loop(unsigned long cur_msec, boolean blink_sw)
{
  if ( _mode == MODE_DISP_DATE ) {
    if ( cur_msec - _date_start_msec > DISP_DATE_MSEC ) {
      Serial.println("Clock::loop(" + String(cur_msec) + ")" +
		     ": _date_start_msec=" + String(_date_start_msec));
      set_mode(MODE_DISP_TIME);
    }
  }

  display(blink_sw);
}
//-------------------------------------------
mode_t Clock::mode()
{
  return _mode;
}
//-------------------------------------------
void Clock::set_mode(mode_t mode)
{
  Serial.print("Clock::set_mode(0x" + String(mode, 16) + ")");
  if ( mode == MODE_DISP_DATE ) {
    _date_start_msec = millis();
    Serial.print(": _date_start_msec=" + String(_date_start_msec));
  }
  _mode = mode;
  Serial.println();
}

//-------------------------------------------
DateTime Clock::cur_dt()
{
  return _cur_dt;
}
//-------------------------------------------
String Clock::dateStr()
{
  String YYYY = String(_cur_dt.year());
  String MM   = String(_cur_dt.month()+100).substring(1);
  String DD   = String(_cur_dt.day()+100).substring(1);
  String hh   = String(_cur_dt.hour()+100).substring(1);
  String mm   = String(_cur_dt.minute()+100).substring(1);
  String ss   = String(_cur_dt.second()+100).substring(1);
  String ms   = String(_msec_offset + 1000).substring(1);
  return YYYY + "/" + MM + "/" + DD + " " + hh + ":" + mm + ":" + ss + "." + ms;
}

//-------------------------------------------
boolean Clock::adjust_flag()
{
  return _adjust_flag;
}
//-------------------------------------------
void Clock::set_adjust_flag(boolean flag)
{
  _adjust_flag = flag;
}


//-------------------------------------------
boolean Clock::update()
{
  static boolean flag_updated = false;
  boolean flag_changed = false;
  static unsigned long prev_msec_offset = 0;
  unsigned long msec_offset = millis() % 1000;

  if ( msec_offset < prev_msec_offset ) {
    flag_updated = false;
  }
  
  if ( ! flag_updated ) {
    if ( msec_offset >= _msec_offset ) {
      _cur_dt = _rtc->now();
      flag_changed = true;
      flag_updated = true;
    }
  }

  prev_msec_offset = msec_offset;
  return flag_changed;
}

//-------------------------------------------
void Clock::adjust() {
    _msec_offset = millis() % 1000;
    _rtc->adjust(_cur_dt);
}

//-------------------------------------------
boolean Clock::adjustIfNecessary()
{
  if ( _adjust_flag ) {
    adjust();
    _adjust_flag = false;
    return true;
  }
  return false;
}

//-------------------------------------------
void Clock::countUpYear()
{
  uint8_t year = _cur_dt.year() % 100;

  year = ( year + 1 ) % 100;
  _cur_dt = DateTime(2000 + year, _cur_dt.month(), _cur_dt.day(),
		     _cur_dt.hour(), _cur_dt.minute(), _cur_dt.second());
  _adjust_flag = true;
}
//-------------------------------------------
void Clock::countUpMonth()
{
  uint8_t month = _cur_dt.month();

  if ( month == 12 ) {
    month = 1;
  } else {
    month++;
  }
  _cur_dt = DateTime(_cur_dt.year(), month, _cur_dt.day(),
		     _cur_dt.hour(), _cur_dt.minute(), _cur_dt.second());
  _adjust_flag = true;
}
//-------------------------------------------
void Clock::countUpDay()
{
  unsigned long year  = _cur_dt.year();
  uint8_t       month = _cur_dt.month();
  uint8_t       day   = _cur_dt.day();
  uint8_t	days_in_month = 31;

  if ( month == 4 || month == 6 || month == 9 || month == 11 ) {
    days_in_month = 30;
  }
  if ( month == 2 ) {
    if ( ( year % 400 == 0 ) || ( year % 100 != 0 && year % 4 == 0 ) ) {
      days_in_month = 29;
    } else {
      days_in_month = 28;
    }
  }

  if ( day == days_in_month ) {
    day = 1;
  } else {
    day++;
  }
  _cur_dt = DateTime(year, month, day,
		     _cur_dt.hour(), _cur_dt.minute(), _cur_dt.second());
  _adjust_flag = true;
}
//-------------------------------------------
void Clock::countUpHour()
{
  uint8_t hour = _cur_dt.hour();

  hour = ( hour + 1 ) % 24;
  _cur_dt = DateTime(_cur_dt.year(), _cur_dt.month(), _cur_dt.day(),
		     hour, _cur_dt.minute(), _cur_dt.second());
  _adjust_flag = true;
}
//-------------------------------------------
void Clock::countUpMinute()
{
  uint8_t minute = _cur_dt.minute();

  minute = ( minute + 1 ) % 60;
  _cur_dt = DateTime(_cur_dt.year(), _cur_dt.month(), _cur_dt.day(),
		     _cur_dt.hour(), minute, _cur_dt.second());
  _adjust_flag = true;
}
//-------------------------------------------
void Clock::countUpSecond()
{
  uint8_t second = _cur_dt.second();

  second = ( (second / 10) * 10 + 10 ) % 60;
  _cur_dt = DateTime(_cur_dt.year(), _cur_dt.month(), _cur_dt.day(),
		     _cur_dt.hour(), _cur_dt.minute(), second);
  _adjust_flag = true;
}

//-------------------------------------------
void Clock::setVfd(unsigned long num1, unsigned long num2, unsigned long num3)
{
  _vfd->set(0, (num1 % 100) / 10, false, false);
  _vfd->set(1, (num1 % 100) % 10, false, false);
  _vfd->set(2, (num2 % 100) / 10, false, false);
  _vfd->set(3, (num2 % 100) % 10, false, false);
  _vfd->set(4, (num3 % 100) / 10, false, false);
  _vfd->set(5, (num3 % 100) % 10, false, false);
}

//-------------------------------------------
void Clock::setVfdDate() {
  setVfd(_cur_dt.year(), _cur_dt.month(), _cur_dt.day());
}
//-------------------------------------------
void Clock::setVfdTime() {
  setVfd(_cur_dt.hour(), _cur_dt.minute(), _cur_dt.second());
  if ( _cur_dt.hour() < 10 ) {
    _vfd->setValue(0, VFD::VAL_NULL);
  }
  _vfd->setDp(1, true);
  _vfd->setDp(3, true);
}

//-------------------------------------------
void Clock::displayDate()
{
  update();
  setVfdDate();
}
//-------------------------------------------
void Clock::displayTime()
{
  update();
  setVfdTime();

  if ( _cur_dt.second() % 10 == 0 ) {
    _vfd->setBlink(5, true);
    _vfd->setBlink(4, true);
    if ( _cur_dt.second() == 0 ) {
      _vfd->setBlink(3, true);
      if ( _cur_dt.minute() % 10 == 0 ) {
	_vfd->setBlink(2, true);
	if ( _cur_dt.minute() == 0 ) {
	  _vfd->setBlink(1, true);
	  if ( _cur_dt.hour() % 10 == 0 ) {
	    _vfd->setBlink(0, true);
	  }
	}
      }
    }
  }
  if ( _cur_dt.second() >= 57 ) {
    _vfd->setBlink(4, true);
    _vfd->setBlink(5, true);
  }
}
//-------------------------------------------
void Clock::displaySetDate()
{
  boolean blist[] = {false, false, false, false, false, false};

  setVfdDate();

  switch ( _mode ) {
  case MODE_SET_DATE_YEAR:
    blist[0] = blist[1] = true;
    break;
  case MODE_SET_DATE_MONTH:
    blist[2] = blist[3] = true;
    break;
  case MODE_SET_DATE_DAY:
    blist[4] = blist[5] = true;
    break;
  } // switch ( _mode )
  _vfd->setBlink(blist);
}
//-------------------------------------------
void Clock::displaySetTime()
{
  boolean blist[] = {false, false, false, false, false, false};

  setVfdTime();
  
  switch ( _mode ) {
  case MODE_SET_TIME_HOUR:
    blist[0] = blist[1] = true;
    break;
  case MODE_SET_TIME_MINUTE:
    blist[2] = blist[3] = true;
    break;
  case MODE_SET_TIME_SECOND:
    blist[4] = blist[5] = true;
    break;
  } // switch ( _mode )
  _vfd->setBlink(blist);
}
//-------------------------------------------
void Clock::display(boolean blink_sw)
{
  switch ( _mode ) {
  case MODE_DISP_DATE:
    displayDate();
    break;
  case MODE_DISP_TIME:
    displayTime();
    break;
  case MODE_SET_DATE_YEAR:
  case MODE_SET_DATE_MONTH:
  case MODE_SET_DATE_DAY:
    displaySetDate();
    break;
  case MODE_SET_TIME_HOUR:
  case MODE_SET_TIME_MINUTE:
  case MODE_SET_TIME_SECOND:
    displaySetTime();
  default:
    break;
  } // switch ( _mode )

  _vfd->display(blink_sw);
}

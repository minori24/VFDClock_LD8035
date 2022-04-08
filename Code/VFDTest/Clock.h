// Game1.h
// (c) 2018 FabLab Kannai
//
#ifndef CLOCK_H
#define CLOCK_H
#include <Arduino.h>
#include "RTClib.h"
#include <Wire.h>
#include "VFD.h"

typedef uint8_t mode_t;

class Clock {
 public:
  static const unsigned long	DISP_DATE_MSEC	= 3000;	// msec
  
  // bit pattern
  // 00------  .. OK
  // 01------  .. WARN
  // 10------  .. ERR
  // --01----  .... DISP
  // --10----  .... SET
  // ----01--  ...... DATE
  // ----10--  ...... TIME
  // ------00  ........ ALL
  // ------01  ........ YEAR/HOUR
  // ------10  ........ MONTH/MINUTE
  // ------11  ........ DAY/SECOND
  static const mode_t MODEMASK_STAT		= 0xC0;
  static const mode_t MODEMASK_DISP_SET		= 0x30;
  static const mode_t MODEMASK_DATE_TIME	= 0x0C;
  static const mode_t MODEMASK_ITEM		= 0x03;

  static const mode_t MODE_FF000000_OK		= 0x00;
  static const mode_t MODE_FF000000_WARN	= 0x40;
  static const mode_t MODE_FF000000_ERR		= 0x80;
  static const mode_t MODE_00FF0000_DISP	= 0x10;
  static const mode_t MODE_00FF0000_SET		= 0x20;
  static const mode_t MODE_0000FF00_DATE	= 0x04;
  static const mode_t MODE_0000FF00_TIME	= 0x08;
  static const mode_t MODE_0000FF00_YEAR_HOUR	= 0x01;
  static const mode_t MODE_000000FF_MONTH_MINUTE= 0x02;
  static const mode_t MODE_000000FF_DAY_SECOND	= 0x03;
  
  static const mode_t MODE_DISP			= 0x10;
  static const mode_t MODE_DISP_DATE		= 0x14;
  static const mode_t MODE_DISP_TIME		= 0x18;
  static const mode_t MODE_SET			= 0x20;
  static const mode_t MODE_SET_DATE		= 0x24;
  static const mode_t MODE_SET_DATE_YEAR	= 0x25;
  static const mode_t MODE_SET_DATE_MONTH	= 0x26;
  static const mode_t MODE_SET_DATE_DAY		= 0x27;
  static const mode_t MODE_SET_TIME		= 0x28;
  static const mode_t MODE_SET_TIME_HOUR	= 0x29;
  static const mode_t MODE_SET_TIME_MINUTE	= 0x2A;
  static const mode_t MODE_SET_TIME_SECOND	= 0x2B;
  static const mode_t MODE_ERR			= 0x80;


  Clock() {};
  
  void		init(VFD *vfd, RTC_DS1307 *rtc);

  void		loop(unsigned long cur_msec, boolean blink_sw);

  mode_t	mode();
  void		set_mode(mode_t mode);

  DateTime	cur_dt();
  String	dateStr();
  
  boolean	adjust_flag();
  void		set_adjust_flag(boolean flag);

  boolean	update();
  void		adjust();
  boolean	adjustIfNecessary();

  void		countUpYear();
  void		countUpMonth();
  void		countUpDay();
  void		countUpHour();
  void		countUpMinute();
  void		countUpSecond();

  void		setVfd(unsigned long num1, unsigned long num2, unsigned long num3);
  void		setVfdDate();
  void		setVfdTime();

  void		displayDate();
  void		displayTime();
  void		displaySetDate();
  void		displaySetTime();
  void		display(boolean blink_sw);
  
 private:
  RTC_DS1307	*_rtc;
  VFD		*_vfd;
  
  mode_t	_mode		= MODE_DISP_TIME;
  boolean	_adjust_flag	= false;

  DateTime	_cur_dt;
  unsigned long _msec_offset	= 0; // msec

  unsigned long	_date_start_msec;
};

#endif

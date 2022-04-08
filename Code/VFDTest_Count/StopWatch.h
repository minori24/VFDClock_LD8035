// StopWatch.h
// (c) 2018 FabLab Kannai
//
#ifndef STOP_WATCH_H
#define STOP_WATCH_H
#include <Arduino.h>
#include "VFD.h"

typedef	uint8_t	stat_t;
typedef uint8_t	mode_t;

//======================================================
class StopWatch {
 public:
  static const stat_t	STAT_STOP	= 0x01;
  static const stat_t	STAT_RUNNING	= 0x02;

  static const mode_t	MODE_TIME	= 0x01;
  static const mode_t	MODE_LAP	= 0x02;

  StopWatch() {};

  void		init(VFD *vfd);

  void		loop(unsigned long cur_msec);

  mode_t	mode();
  void		set_mode(mode_t mode);

  stat_t	stat();
  void		set_stat(stat_t stat);

  unsigned long	time_val();
  unsigned long	lap_val();
  
  void		start();
  void		stop();
  void		reset();
  void		lap();

  void		setVfd(unsigned long msec, boolean blink);
  void		display();
  
 private:
  VFD		*_vfd;

  stat_t	_stat;
  mode_t	_mode;

  unsigned long _start_msec;
  unsigned long _cur_msec;
  unsigned long	_lap_msec;
};
#endif

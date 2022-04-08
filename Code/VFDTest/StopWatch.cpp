// StopWatch.cpp
// (c) FabLab Kannai
//
#include "StopWatch.h"

//===================================================
//StopWatch::StopWatch() {}
//===================================================
void StopWatch::init(VFD *vfd)
{
  _vfd = vfd;

  reset();
}
//---------------------------------------------------
void StopWatch::reset()
{
  _cur_msec = _start_msec = _lap_msec = millis();
  _mode = MODE_TIME;
  _stat = STAT_STOP;
}
//---------------------------------------------------
void StopWatch::loop(unsigned long cur_msec)
{
  if ( _stat == STAT_RUNNING ) {
    _cur_msec = millis();
  }

  display();
}
//---------------------------------------------------
mode_t StopWatch::mode()
{
  return _mode;
}
void StopWatch::set_mode(mode_t mode)
{
  _mode = mode;
}
//---------------------------------------------------
stat_t StopWatch::stat()
{
  return _stat;
}
void StopWatch::set_stat(stat_t stat)
{
  _stat = stat;
}
//---------------------------------------------------
unsigned long StopWatch::time_val()
{
  if ( _cur_msec < _start_msec ) {
    _cur_msec = _start_msec;
  }
  return _cur_msec - _start_msec;
}
unsigned long StopWatch::lap_val()
{
  if ( _lap_msec < _start_msec ) {
    _lap_msec = _start_msec;
  }
  return _lap_msec - _start_msec;
}
//---------------------------------------------------
void StopWatch::start()
{
  unsigned long offset = time_val();
  
  _cur_msec = millis();
  _start_msec = _cur_msec - offset;
  _stat = STAT_RUNNING;
}
//---------------------------------------------------
void StopWatch::stop()
{
  _cur_msec = millis();
  _stat = STAT_STOP;
}
//---------------------------------------------------
void StopWatch::lap()
{
  _lap_msec = millis();
}
//---------------------------------------------------
void StopWatch::setVfd(unsigned long msec, boolean blink)
{
  unsigned long subsec = msec / 10;
  unsigned long sec = subsec / 100;
  subsec = subsec % 100;
  unsigned long min = ( sec / 60 ) % 100;
  sec = sec % 60;

  _vfd->set(0, min / 10, false, blink);
  _vfd->set(1, min % 10, true , blink);
  _vfd->set(2, sec / 10, false, blink);
  _vfd->set(3, sec % 10, true , blink);
  _vfd->set(4, subsec / 10, false, blink);
  _vfd->set(5, subsec % 10, false, blink);
}
//---------------------------------------------------
void StopWatch::display()
{
  if ( _mode == MODE_TIME ) {
    setVfd(time_val(), false);
  } else if ( _mode == MODE_LAP ) {
    setVfd(lap_val(), true);
  }
  
  _vfd->display();
}

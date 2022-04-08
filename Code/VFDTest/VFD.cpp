// VFD.cpp
// (c) 2018 FabLab Kannai
//
#include "VFD.h"

//-------------------------------------------
//VFD::VFD() {}
//-------------------------------------------
void VFD::init(uint8_t pin_seg[], uint8_t pin_digit[], size_t digitN) {
  _pin_seg = new uint8_t[SEG_N];
  for (int i = 0; i < SEG_N; i++) {
    _pin_seg[i] = pin_seg[i];
    pinMode(_pin_seg[i], OUTPUT);
    digitalWrite(_pin_seg[i], LOW);
  }
  
  _digitN    = digitN;
  _digitI    = 0;
  _pin_digit = new uint8_t[_digitN];
  _val       = new uint8_t[_digitN];
  _dp        = new boolean[_digitN];
  _bl        = new boolean[_digitN];
  for (int i = 0; i < _digitN; i++) {
    _pin_digit[i] = pin_digit[i];
    _val[i]       = VAL_NULL;
    _dp[i]        = false;
    _bl[i]        = false;
    pinMode(_pin_digit[i], OUTPUT);
    digitalWrite(_pin_digit[i], LOW);
  }
}
//-------------------------------------------
size_t VFD::digitN() {
  return _digitN;
}
size_t VFD::digitI() {
  return _digitI;
}
//-------------------------------------------
void VFD::clear()
{
  for (int i = 0; i < _digitN; i++) {
    clear(i);
  }
}
void VFD::clear(uint8_t idx)
{
  _val[idx] = VAL_NULL;
  _dp[idx] = false;
  _bl[idx] = false;
}
//-------------------------------------------
void VFD::set(uint8_t idx, uint8_t val, boolean dp, boolean bl)
{
  _val[idx] = val;
  _dp[idx] = dp;
  _bl[idx] = bl;
}
//-------------------------------------------
void VFD::setValue(uint8_t val0, uint8_t val1, uint8_t val2,
		   uint8_t val3, uint8_t val4, uint8_t val5)
{
  _val[0] = val0;
  _val[1] = val1;
  _val[2] = val2;
  _val[3] = val3;
  _val[4] = val4;
  _val[5] = val5;
}
//-------------------------------------------
void VFD::setValue(uint8_t val[])
{
  for (int i=0; i < _digitN; i++) {
    _val[i] = val[i];
  }
}
//-------------------------------------------
void VFD::setValue(uint8_t idx, uint8_t val)
{
  _val[idx] = val;
}
//-------------------------------------------
void VFD::setNum(unsigned long num)
{
  for (int i=0; i < _digitN; i++) {
    uint8_t v = (uint8_t)((unsigned long)((double)num / pow(10, 5 - i)) % 10);
    _val[i] = v;
  }
}
//-------------------------------------------
void VFD::setDp(uint8_t idx, boolean dp)
{
  _dp[idx] = dp;
}
//-------------------------------------------
void VFD::setDp(boolean *dp)
{
  for (int i=0; i < _digitN; i++) {
    _dp[i] = dp[i];
  }
}
//-------------------------------------------
void VFD::setDp(boolean dp)
{
  for (int i=0; i < _digitN; i++) {
    _dp[i] = dp;
  }
}
//-------------------------------------------
void VFD::setBlink(uint8_t idx, boolean blink)
{
  _bl[idx] = blink;
}
//-------------------------------------------
void VFD::setBlink(boolean *blink)
{
  for (int i=0; i < _digitN; i++) {
    _bl[i] = blink[i];
  }
}
//-------------------------------------------
void VFD::setBlink(boolean blink)
{
  for (int i=0; i < _digitN; i++) {
    _bl[i] = blink;
  }
}
//-------------------------------------------
boolean VFD::blinkOff() {
  if ( _cur_msec % BLINK_INTERVAL > BLINK_ON_MSEC ) {
    return true;
  }
  return false;
}
//-------------------------------------------
void VFD::displayOne() {
  for (int i = 0; i < SEG_N - 1; i++) {
    digitalWrite(_pin_seg[i], VAL[_val[_digitI]][i]);
  }
  digitalWrite(_pin_seg[SEG_N - 1], _dp[_digitI]);
  digitalWrite(_pin_digit[_digitI], HIGH);
}
//-------------------------------------------
void VFD::display(boolean blink_sw)
{
  if ( _digitI == 0 ) {
    _cur_msec = millis();
  }

  digitalWrite(_pin_digit[_digitI], LOW);
  _digitI = ( _digitI + 1 ) % _digitN;
  
  if ( _val[_digitI] != VAL_NULL ) {
    if ( ! (blink_sw && _bl[_digitI] && blinkOff()) ) {
      displayOne();
    }
  }
  delay(DISP_DELAY);
}
//-------------------------------------------
void VFD::display()
{
  display(true);
}

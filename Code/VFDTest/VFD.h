// VFD.h
// (c) 2018 FabLab Kannai

#ifndef VFD_H
#define VFD_H
#include <Arduino.h>

class VFD {
  public:
    static const unsigned long DISP_DELAY     = 2;   // msec
    static const unsigned long BLINK_INTERVAL = 400; // msec
    static const unsigned long BLINK_ON_MSEC  = 300; // msec
    static const uint8_t       SEG_N          = 8;
    
    const boolean VAL[19][SEG_N-1] = {
      {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW }, // 0
      {LOW , HIGH, HIGH, LOW , LOW , LOW , LOW }, // 1
      {HIGH, HIGH, LOW , HIGH, HIGH, LOW , HIGH}, // 2
      {HIGH, HIGH, HIGH, HIGH, LOW , LOW , HIGH}, // 3
      {LOW , HIGH, HIGH, LOW , LOW , HIGH, HIGH}, // 4
      {HIGH, LOW , HIGH, HIGH, LOW , HIGH, HIGH}, // 5
      {HIGH, LOW , HIGH, HIGH, HIGH, HIGH, HIGH}, // 6
      {HIGH, HIGH, HIGH, LOW , LOW , LOW , LOW }, // 7
      {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH}, // 8
      {HIGH, HIGH, HIGH, HIGH, LOW , HIGH, HIGH}, // 9
      {HIGH, HIGH, HIGH, LOW , HIGH, HIGH, HIGH}, // A
      {LOW , LOW , HIGH, HIGH, HIGH, HIGH, HIGH}, // b
      {HIGH, LOW , LOW , HIGH, HIGH, HIGH, LOW }, // C
      {LOW , HIGH, HIGH, HIGH, HIGH, LOW , HIGH}, // d
      {HIGH, LOW , LOW , HIGH, HIGH, HIGH, HIGH}, // E
      {HIGH, LOW , LOW , LOW , HIGH, HIGH, HIGH}, // F
      {HIGH, LOW , LOW , LOW , LOW , LOW , LOW }, // 
      {LOW , LOW , LOW , LOW , LOW , LOW , HIGH}, // -
      {LOW , LOW , LOW , HIGH, LOW , LOW , LOW }  // _
    };
			
    static const uint8_t VAL_BAR_HIGH = 10;
    static const uint8_t VAL_BAR_MID  = 11;
    static const uint8_t VAL_BAR_LOW  = 12;
    static const uint8_t VAL_NULL     = 0xff;

    VFD() {};
    
    void init(uint8_t pin_seg[], uint8_t pin_digit[], size_t digitN);

    size_t digitN();
    size_t digitI();

    void clear();
    void clear(uint8_t idx);
    
    void set(uint8_t idx, uint8_t val, boolean dp, boolean blink);
    
    void setValue(uint8_t val0, uint8_t val1, uint8_t val2,
		  uint8_t val3, uint8_t val4, uint8_t val5);
    void setValue(uint8_t val[]);
    void setValue(uint8_t idx, uint8_t val);
    
    void setNum(unsigned long num);
    
    void setDp(uint8_t idx, boolean dp);
    void setDp(boolean *dp);
    void setDp(boolean dp);
    
    void setBlink(uint8_t idx, boolean blink);
    void setBlink(boolean *blink);
    void setBlink(boolean blink);

    boolean blinkOff();
    void displayOne();
    void display(boolean blink_sw);
    void display();

  private:
    uint8_t *_pin_seg;
    boolean *_dp;
    boolean *_bl;

    uint8_t *_pin_digit;
    size_t  _digitN;
    size_t  _digitI = 0;

    uint8_t *_val;

    unsigned long _cur_msec;
};
#endif

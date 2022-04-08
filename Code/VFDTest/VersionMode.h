// VersionMode.h
// (c) 2018 FabLab Kannai
//
#ifndef VERSION_MODE_H
#define VERSION_MODE_H

#include <Arduino.h>
#include "VFD.h"
#include "Button.h"

//
// Version String Format: "AA.BB.CC"
//
class VersionMode {
 public:
  VersionMode();

  void		init(VFD *vfd, String str);

  void		set_version_str(String str);

  void		print();
  void		display(boolean blink_sw);
  
 private:
  VFD		*_vfd;
  String	_version_str;
};
#endif

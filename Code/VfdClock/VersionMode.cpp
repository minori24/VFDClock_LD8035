// VersionMode.cpp
// (c) 2018 FabLab Kannai
//
#include "VersionMode.h"

//===============================================================
VersionMode::VersionMode()
{
}
//===============================================================
void VersionMode::init(VFD *vfd, String str)
{
  _vfd = vfd;
  set_version_str(str);
}

void VersionMode::set_version_str(String str)
{
  _version_str = str;
}

void VersionMode::print()
{
  Serial.println("Version: " + _version_str);
}

void VersionMode::display(boolean blink_sw)
{
  _vfd->set(0, _version_str[0] - '0', false, true);
  _vfd->set(1, _version_str[1] - '0', true , true);
  
  _vfd->set(2, _version_str[3] - '0', false, true);
  _vfd->set(3, _version_str[4] - '0', true , true);
  
  _vfd->set(4, _version_str[6] - '0', false, true);
  _vfd->set(5, _version_str[7] - '0', false, true);

  _vfd->display();  
}

#ifndef LOGINVALIDATER_H
#define LOGINVALIDATER_H

#include <iostream>
#include <string>

#include "Staff.h"

class LoginValidater
{
  public:
    Staff* doLogin(bool& success);
};
#endif
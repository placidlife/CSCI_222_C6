#ifndef LOGINVALIDATER_H
#define LOGINVALIDATER_H

#include <iostream>
#include <string>

#include "Actor.h"

class LoginValidater
{
  public:
    Actor* doLogin(bool& success);
};
#endif
#ifndef LOGINVALIDATER_H
#define LOGINVALIDATER_H

#include <iostream>
#include <string>

#include "Staff.h"

class LoginValidater
{
  public:
    //LoginValidater();
    Staff* doLogin(bool& success);
  private:
    std::string dataFile;
    void increaseLoginCount(std::string uName, std::string pWord);
};
#endif
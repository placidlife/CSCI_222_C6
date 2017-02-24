#include "LoginValidater.h"

#include "Staff.h"
#include "Manager.h"

Actor* LoginValidater::doLogin(bool& success)
{
  std::string usrName;
  std::cout << "User ID: ";
  std::getline(std::cin, usrName);
  //std::cin.ignore(100, '\n');
  std::cout << std::endl;
  
  std::string pwd;
  std::cout << "Password: ";
  std::getline(std::cin, pwd);
  //std::cin.ignore(100, '\n');
  std::cout << std::endl;
#if 1  
  int userType;
  std::cout << "User Type: ";
  std::cin >> userType;
  std::cout << std::endl;
#endif
  Actor * curStf;
  if(userType)
  {
    curStf = new Manager();
  }
  else
  {
    curStf = new Staff();
  }
  curStf->setStaffID(usrName);
  curStf->setPassword(pwd);
  success = true;
  return curStf;
}
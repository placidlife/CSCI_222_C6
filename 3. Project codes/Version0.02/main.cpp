#include "LoginValidater.h"
#include "WarehouseManager.h"
#include "Staff.h"

int main()
{
  LoginValidater lv;
  //success is -1, 0, 1
  //0 is login fail
  //1 is login success
  bool success = false;
  
  Staff * curStaff;
  
  while(!success)
  {
    curStaff = lv.doLogin(success);  
  }
  
  WarehouseManager wm(curStaff);  
  curStaff->setWM(&wm);
  // std::string fileName;
  // std::getline(std::cin, filename);
  // wm.readFile(fileName);
  wm.running();
}
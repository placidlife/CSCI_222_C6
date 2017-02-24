#include "LoginValidater.h"
#include "WarehouseManager.h"
#include "Actor.h"

int main()
{
  LoginValidater lv;
  //success is -1, 0, 1
  //0 is login fail
  //1 is login success
  bool success = false;
  
  Actor * curStaff;
  
  while(!success)
  {
    curStaff = lv.doLogin(success);  
  }
  
  WarehouseManager wm(curStaff);  
  // std::string fileName;
  // std::cin >> fileName;
  // wm.readFile(fileName);
  wm.running();
}
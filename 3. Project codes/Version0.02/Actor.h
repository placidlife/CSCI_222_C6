#ifndef ACTOR_H
#define ACTOR_H

#include <string>
#include <iostream>

//abstract class for the staff and manager
class Actor
{
  public:
    virtual void displayMenu() = 0;
    
    void setStaffID(std::string stfID);
    void setStaffName(std::string stfName);
    void setPassword(std::string stfPwd);
    
    std::string getStaffID();
    // std::string getStaffName();
    // std::string getPassword();
    void setWM(void * warehouse);
  protected:
    std::string staffID;
    std::string staffName;
    std::string password;
    int loginCount;
    void * WM;
    
};
#endif
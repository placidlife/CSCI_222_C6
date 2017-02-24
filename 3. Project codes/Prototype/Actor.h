#ifndef ACTOR_H
#define ACTOR_H

#include <string>

class Actor
{
  public:
    virtual void displayMenu() = 0;
    
    void setStaffID(std::string stfID);
    void setStaffName(std::string stfName);
    void setPassword(std::string stfPwd);
    
    // std::string getStaffID(std::string stfID);
    // std::string getStaffName(std::string stfName);
    // std::string getPassword(std::string stfPwd);
    
  protected:
    std::string staffID;
    std::string staffName;
    std::string password;
    int loginCount;
    
};
#endif
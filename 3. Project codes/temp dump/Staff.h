#ifndef STAFF_H
#define STAFF_H

#include <iostream>

class Staff
{
  public:
    Staff(){}
    ~Staff(){}
    virtual void displayMenu();
    
  public:
    void setStaffID(std::string stfID);
    void setStaffName(std::string stfName);
    void setPassword(std::string stfPwd);
    
    std::string getStaffID();
    // std::string getStaffName();
    // std::string getPassword();
    void setWM(void * warehouse);
    
  protected:
    virtual void doSearchStock();
    virtual void doProcessTransaction();
    virtual void doDailySummary();
    virtual void doWeeklySummary();
    virtual void doMonthlySummary();
    virtual void doYearlySummary();
  
  protected:
    std::string staffID;
    std::string staffName;
    std::string password;
    int loginCount;
    void * WM;
    Search search;
};

#endif

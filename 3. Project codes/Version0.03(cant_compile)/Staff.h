#ifndef STAFF_H
#define STAFF_H

#include <iostream>
#include "Transaction.h"
#include "TransactionList.h"

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
    virtual void summaryMenu();
  
  private:
    void doDailySummary();
    void doWeeklySummary();
    void doMonthlySummary();
    void doYearlySummary();
    
  private:
    std::vector<Transaction *>  collapseDay(std::string day);
    std::vector<Transaction *>  collapseWeek(std::string weekStart, std::string weekEnd);
    std::vector<Transaction *>  collapseMonth(std::string month);
    std::vector<Transaction *>  collapseYear(std::string year);
    
    tm getDate(std::string input);
    int convertMonthStrToInt(std::string input);
    int converYYtoYYYY(std::string input);
  
  protected:
    std::string staffID;
    std::string staffName;
    std::string password;
    int loginCount;
    void * WM;
};

#endif
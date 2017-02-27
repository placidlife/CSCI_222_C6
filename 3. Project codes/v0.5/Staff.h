#ifndef STAFF_H
#define STAFF_H

#include <string>
#include <iostream>
#include "Search.h"
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
    virtual void doProcessStockIn();
    virtual void doProcessStockOut();
    virtual void summaryMenu();
    virtual void processData(std::string line);
    virtual void readFile();
    
  protected:
    void doDailySummary();
    void doWeeklySummary();
    void doMonthlySummary();
    void doYearlySummary();
    
  private:
    std::vector<Transaction *>  collapseDay(std::string day);
    std::vector<Transaction *>  collapseWeek(std::string weekStart, std::string weekEnd);
    std::vector<Transaction *>  collapseMonth(std::string month);
    std::vector<Transaction *>  collapseYear(std::string year);
  
  protected:
    std::string staffID;
    std::string staffName;
    std::string password;
    int loginCount;
    void * WM;
    Search search;
};

#endif

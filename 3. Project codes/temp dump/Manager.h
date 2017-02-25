#ifndef MANAGER_H
#define MANAGER_H

//#include "Actor.h"
#include "Staff.h"

class Manager : public Staff
{
  public:
    Manager(){}
    ~Manager(){}
    void displayMenu();
    
  private:
    void doAddNewStock();
    void doRemoveStock();
    void doEditStock();
    void doEditTransaction();
#if 0
    void doSearchStock();
    void doProcessTransaction();
    void doDailySummary();
    void doWeeklySummary();
    void doMonthlySummary();
    void doYearlySummary();
#endif
    void readFile();
    void processData(string);
    
};

#endif

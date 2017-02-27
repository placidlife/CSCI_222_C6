#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include "Staff.h"
#include "Common.h"
#include "WarehouseManager.h"

class Manager : public Staff {
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

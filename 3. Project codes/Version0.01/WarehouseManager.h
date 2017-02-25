#ifndef WAREHOUSEMANAGER_H
#define WAREHOUSEMANAGER_H

#include "Staff.h"

class WarehouseManager
{
  private:
    Staff * workingStaff;
    //std::vector<Transactions*> transactionList[];
    
  public:
    WarehouseManager(Staff * stf);
    //~WarehouseManager();
    //void readFile(std::string fileName); //takes in the file name and populates the transactionList
    void running(); // does most of the work
#if 1
    void testFunction();
#endif
  private:
    //void storeTransaction();
    
};
#endif
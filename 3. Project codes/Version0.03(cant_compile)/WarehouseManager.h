#ifndef WAREHOUSEMANAGER_H
#define WAREHOUSEMANAGER_H

#include "Staff.h"
#include "TransactionList.h"

class WarehouseManager
{
  private:
    Staff * workingStaff;
    TransactionList allTransactions;
    
  public:
    WarehouseManager(Staff * stf);
    //~WarehouseManager();
    //void readFile(std::string fileName); //takes in the file name and populates the transactionList
    TransactionList * getTransaction();
    void running(); // does most of the work
#if 1
    void testFunction();
#endif
  private:
    //void storeTransaction();
    
};
#endif
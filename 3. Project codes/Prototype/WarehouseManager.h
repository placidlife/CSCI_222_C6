#ifndef WAREHOUSEMANAGER_H
#define WAREHOUSEMANAGER_H

#include "Actor.h"

class WarehouseManager
{
  private:
    Actor * workingStaff;
    //std::vector<Transactions*> transactionList[];
    
  public:
    WarehouseManager(Actor * stf);
    //~WarehouseManager();
    //void readFile(std::string fileName); //takes in the file name and populates the transactionList
    void running(); // does most of the work
    
  private:
    //void storeTransaction();
    
};
#endif
#ifndef WAREHOUSEMANAGER_H
#define WAREHOUSEMANAGER_H

#include "Staff.h"

class WarehouseManager
{
  private:
    Staff * workingStaff;
    TransactionList transactionList;
    StockItemList stockItemList;
    
  public:
    WarehouseManager(Staff * stf);
    //~WarehouseManager();
    setData(TransactionList tList, StockItemList sIL);
    void running(); // does most of the work
#if 1
    void testFunction();
#endif
  private:
    //void storeTransaction();
    
};
#endif

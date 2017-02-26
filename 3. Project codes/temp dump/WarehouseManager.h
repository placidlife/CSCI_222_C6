#ifndef WAREHOUSEMANAGER_H
#define WAREHOUSEMANAGER_H

#include "Staff.h"
#include "TransactionList.h"
#include "StockItemList.h"

class WarehouseManager
{
  private:
    Staff * workingStaff;
    TransactionList transactionList;
    StockItemList stockItemList;
    
  public:
    WarehouseManager(Staff * stf);
    //~WarehouseManager();
    void setData(TransactionList tList, StockItemList sIL);
    void running(); // does most of the work
#if 1
    void testFunction();
#endif
  private:
    //void storeTransaction();
    
};
#endif

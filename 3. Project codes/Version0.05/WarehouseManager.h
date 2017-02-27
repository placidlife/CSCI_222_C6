#ifndef WAREHOUSEMANAGER_H
#define WAREHOUSEMANAGER_H

#include "TransactionList.h"
#include "StockItemList.h"
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
    void setData(TransactionList tList, StockItemList sIL);
    void running(); // does most of the work
#if 1
    void testFunction();
#endif

	string generateTransactionID();
	void generateRemainingQuantity();
	bool searchItemID(string itemID);
	bool searchItemID(string itemName, string itemCat, string itemSubCat);
	vector<StockItem *> getListOfStockItem();
	void updateItemQuantity(string itemID, int quantRemain);
	void addStockItem(StockItem* item);
	void addTransaction(Transaction* t);

  private:
    //void storeTransaction();
    
};
#endif

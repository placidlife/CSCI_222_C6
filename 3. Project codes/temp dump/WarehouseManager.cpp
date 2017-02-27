#include "WarehouseManager.h"

WarehouseManager::WarehouseManager(Staff * curStf)
{
  workingStaff = curStf;
}

void WarehouseManager::running()
{
  workingStaff->displayMenu();
}

void WarehouseManager::setData(TransactionList tList, StockItemList sIList){
	transactionList = tList;
	stockItemList = sIList;
}

string WarehouseManager::generateTransactionID(){
	// TODO
	return "";
}

void WarehouseManager::generateRemainingQuantity(){
	transactionList.generateRemainingQuantity();
}

bool WarehouseManager::searchItemID(string itemID){
	return stockItemList.searchStockItem (itemID); 
}

bool WarehouseManager::searchItemID(string itemName, string itemCat, string itemSubCat){
	return stockItemList.searchStockItem (itemName, itemCat, itemSubCat); 
}

vector<StockItem *> WarehouseManager::getListOfStockItem(){
	return stockItemList.getListOfStockItems();
}

void WarehouseManager::updateItemQuantity(string itemID, int quantRemain){
	stockItemList.updateItemQuantity(itemID, quantRemain);
}

void WarehouseManager::addStockItem(StockItem* item){
	stockItemList.addStockItem(item);
}

void WarehouseManager::addTransaction(Transaction* t){
	transactionList.addTransaction(t);
}

void WarehouseManager::testFunction()
{
  std::cout << "The current working staff is : " << workingStaff->getStaffID() << std::endl;
}



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

// get last transaction ID and generate a new one 
string WarehouseManager::generateTransactionID(){
	string lastID = transactionList.getLatestTransactionID();
	int lastIDInt = stoi(lastID);
	int newIDInt = ++lastIDInt;
	stringstream ss;
	ss << setw(9) << setfill('0') << newIDInt;
	string newID = ss.str();
	return newID;
}

void WarehouseManager::generateRemainingQuantity(){
	transactionList.generateRemainingQuantity();
}

StockItem* WarehouseManager::getStockItem(string input){
	return stockItemList.getStockItem(input);
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
	// add transaction into TList
	transactionList.addTransaction(t);
	// and go through item list to get out item to store transaction too
	stockItemList.addTransaction(t);
}

void WarehouseManager::testFunction()
{
  std::cout << "The current working staff is : " << workingStaff->getStaffID() << std::endl;
}

TransactionList * WarehouseManager::getTransaction()
{
  return &transactionList;
}

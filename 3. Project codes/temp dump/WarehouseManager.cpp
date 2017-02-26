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

void WarehouseManager::testFunction()
{
  std::cout << "The current working staff is : " << workingStaff->getStaffID() << std::endl;
}



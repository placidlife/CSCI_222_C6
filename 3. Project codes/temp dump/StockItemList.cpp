#include "StockItemList.h"

// constructor
StockItemList::StockItemList(){
	// read stock item file and get in all stock item data
	readStockItemFile();
}

void StockItemList::readStockItemFile(){
	string fileName = "StockItems.txt";
	// TODO
}

void StockItemList::updateStockItemFile(){
	// TODO
}

void StockItemList::addStockItem(StockItem * item){
	// add new item to list
	stockItems.push_back(t);
	// update data file
	updateStockItemFile();
}

bool StockItemList::searchStockItem (string itemID){
	// iterate through list and find matching ID
	for (auto const & item : stockItems){
		if (strcmp(item->getID(), itemID) == 0){
			return true;
		}
	}
	return false;
}

StockItem* StockItemList::getStockItem (string itemID){
	// iterate through list and find matching ID
	for (auto const & item : stockItems){
		if (strcmp(item->getID(), itemID) == 0){
			return t;
		}
	}
}

bool StockItemList::updateStockItem (string itemID, StockItem * item){
	// iterate through list and find matching ID
	// then overwrite that element
	for (size_t i = 0; i != (sizeof(stockItems) / sizeof(StockItem *)); i++){
		if (strcmp(stockItems[i]->getID(), itemID) == 0){
			stockItems[i] = item;
			return true;
		}
	}
	return false;
}

bool StockItemList::removeStockItem (StockItem * item){
	// iterate through list and find item
	// then remove it from list
	for (size_t i = 0; i != (sizeof(stockItems) / sizeof(StockItem *)); i++){
		if (stockItems[i]->getID() == item->getID()){
			stockItems.erase (stockItems.begin()+i);
			return true;
		}
	}
	return false;
}


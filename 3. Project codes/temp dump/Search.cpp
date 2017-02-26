#include "Search.h"

Search::Search(void * WMptr){
	WM = WMptr
}
		
bool Search::checkItemExists(string itemID){
	return static_cast<WarehouseManager*>(WM)->searchItemID(itemID);
}
		
bool Search::checkItemExists(string itemName, itemCat, itemSubCat){
	return static_cast<WarehouseManager*>(WM)->searchItemID(itemName, itemCat, itemSubCat);
}
		

void Search::searchItemName(){
	// TODO
}
	
void Search::searchItemCat(){
	// TODO
}

void Search::searchItemPrice(){
	// TODO
}

void Search::searchItemQuantity(){
	// TODO
}


vector<StockItem *> Search::findItemID(string itemID){
	// TODO
}

vector<StockItem *> Search::findItemName(string itemName){
	// TODO
}

vector<StockItem *> Search::findItemCat(string itemCat, string itemSubCat){
	// TODO
}

vector<StockItem *> Search::findItemPrice(int min, int max){
	// TODO
}

vector<StockItem *> Search::fidnItemQuantity(int min, int max){
	// TODO
}

void Search::printSearchResults (vector<StockItem *>){
	// TODO
}


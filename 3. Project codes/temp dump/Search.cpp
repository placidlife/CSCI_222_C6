#include "Search.h"

Search::setWM(void * wm){
	WM = wm
}
		
bool Search::checkItemExists(string itemID){
	return static_cast<WarehouseManager*>(WM)->searchItemID(itemID);
}
		
bool Search::checkItemExists(string itemName, itemCat, itemSubCat){
	return static_cast<WarehouseManager*>(WM)->searchItemID(itemName, itemCat, itemSubCat);
}
		

void Search::searchItemName(){
	string itemName;
	cout << "Please enter item name: " ;
	getline(cin, itemName);
	
	vector<StockItem *> stockItems = static_cast<WarehouseManager*>(WM)->getListOfStockItem();
	cout << StockItemList::getHeader();

	for (auto const & item : stockItems) {

		if ( strcmp(itemName, item->getName()) == 0 ){
			cout << item->toString();
		}
	}
	pressEnter();
}
	
void Search::searchItemCat(){
	string itemCat, itemSubCat;
	cout << "Please enter iteam category: ";
	getline(cin, itemCat);
	cout << "Please enter item sub-category: "
	getline(cin,itemSubCat);

	Vector<StockItem *) stockItems = static_cast<WarehouseManager*>(WM)->getListOfStockItem();
	cout << StcokItemList::getHeader();

	for (auto const & item : stockItems) {
	
		if ( ( strcmp(itemCat, item->getCat()) == 0 ) && ( strcmp(itemSubCat, item->getSubCat()) == 0 ) ) {
			cout << item->toString();
		}
	}
	pressEnter();
}

void Search::searchItemPrice(){
	int itemPrice;
	cout << "Please enter item name: " ;
	getline(cin, itemPrice);
	
	vector<StockItem *> stockItems = static_cast<WarehouseManager*>(WM)->getListOfStockItem();
	cout << StockItemList::getHeader();

	for (auto const & item : stockItems) {

		if ( strcmp(itemPrice, item->getPrice()) == 0 ){
			cout << item->toString();
		}
	}
	pressEnter();
}

void Search::searchItemQuantity(){
	int itemQuantity;
	cout << "Please enter item name: " ;
	getline(cin, itemQuantity);
	
	vector<StockItem *> stockItems = static_cast<WarehouseManager*>(WM)->getListOfStockItem();
	cout << StockItemList::getHeader();

	for (auto const & item : stockItems) {

		if ( strcmp(itemQuantity, item->getQuantity()) == 0 ){
			cout << item->toString();
		}
	}
	pressEnter();
}

/*
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
*/

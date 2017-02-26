#include "Search.h"
#include "WarehouseManager.h"

void Search::setWM(void * wm){
	WM = wm;
}
		
bool Search::checkItemExists(string itemID){
	return static_cast<WarehouseManager*>(WM)->searchItemID(itemID);
}
		
bool Search::checkItemExists(string itemName, string itemCat, string itemSubCat){
	return static_cast<WarehouseManager*>(WM)->searchItemID(itemName, itemCat, itemSubCat);
}
		

void Search::searchItemName(){
	string itemName;
	cout << "Please enter item name: " ;
	getline(cin, itemName);
	
	vector<StockItem *> stockItems = static_cast<WarehouseManager*>(WM)->getListOfStockItem();
	cout << StockItemList::getHeader();

	for (const auto & item : stockItems) {

		if (itemName == item->getName()){
			cout << item->toString();
		}
	}
	Common::pressEnter();
}
	
void Search::searchItemCat(){
	cout << "Search Item by Category" << endl << endl;
	string itemCat, itemSubCat;
	cout << "Please enter iteam category: ";
	getline(cin, itemCat);
	cout << "Please enter item sub-category: ";
	getline(cin,itemSubCat);

	vector<StockItem *> stockItems = static_cast<WarehouseManager*>(WM)->getListOfStockItem();
	cout << StockItemList::getHeader();

	for (auto const & item : stockItems) {
	
		if (itemCat == item->getCat() && itemSubCat == item->getSubCat()) {
			cout << item->toString();
		}
	}
	Common::pressEnter();
}

void Search::searchItemPrice(){
	cout << "Search Item by Price" << endl << endl;
	string minStr;
	string maxStr;
	double minPrice;
	double maxPrice;
	cout << "Please enter minimum price: " ;
	getline(cin, minStr);
	// check if input is valid while converting string to double
	// while not valid, keep asking user to input again.
	while(!(minPrice = Common::checkPositiveCurrency(minStr))){
		cout << "Please enter only positive integer: ";
		getline(cin, minStr);
	}

	cout << "Please enter maximum price: " ;
	getline(cin, maxStr);
	// check if input is valid while converting string to double
	// while not valid, keep asking user to input again.
	while(!(maxPrice = Common::checkPositiveCurrency(maxStr))){
		cout << "Please enter only positive integer: ";
		getline(cin, maxStr);
	}
	
	vector<StockItem *> stockItems = static_cast<WarehouseManager*>(WM)->getListOfStockItem();
	cout << StockItemList::getHeader();

	for (auto const & item : stockItems) {
		if (item->getPrice() >= minPrice && 
			item->getPrice() <= maxPrice){
			cout << item->toString();
		}
	}
	Common::pressEnter();
}

void Search::searchItemQuantity(){
	cout << "Search Item by Quantity" << endl << endl;
	string minStr;
	string maxStr;
	int minQuant;
	int maxQuant;
	cout << "Please enter minimum quantity: " ;
	getline(cin, minStr);
	// check if input is valid while converting string to int
	// while not valid, keep asking user to input again.
	while(!(minQuant = Common::checkPositiveInt(minStr))){
		cout << "Please enter only positive integer: ";
		getline(cin, minStr);
	}

	cout << "Please enter maximum quantity: " ;
	getline(cin, maxStr);
	// check if input is valid while converting string to int
	// while not valid, keep asking user to input again.
	while(!(maxQuant = Common::checkPositiveInt(maxStr))){
		cout << "Please enter only positive integer: ";
		getline(cin, maxStr);
	}
	
	vector<StockItem *> stockItems = static_cast<WarehouseManager*>(WM)->getListOfStockItem();
	cout << StockItemList::getHeader();

	for (auto const & item : stockItems) {
		if (item->getQuantity() >= minQuant && 
			item->getQuantity() <= maxQuant){
			cout << item->toString();
		}
	}
	Common::pressEnter();
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

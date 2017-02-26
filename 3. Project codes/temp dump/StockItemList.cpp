#include <fstream>

#include "StockItemList.h"

// constructor
StockItemList::StockItemList(){
	// read stock item file and get in all stock item data
	readStockItemFile();
}

void StockItemList::readStockItemFile(){
	string fileName = "WMTStockItemsData.txt";
	ifstream infile;
	
	infile.open(fileName);
	
	
}

void StockItemList::updateStockItemFile(){
	string fileName = "WMTStockItemsData.txt";
	ofstream outfile;

	outfile.open(fileName, ios_base::app);
	if (!outfile){
		cout << "could not open file " << fileName << " to append." << endl << endl;
		exit (-1);
		infile.close();
	}
	// append latest item to file
	outfile << stockItems.pop_back().toString();
	outfile.close();
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

bool StockItemList::searchStockItem (string itemName, string itemCat, string itemSubCat){
	// iterate through list and find matching details
	for (auto const & item : stockItems){
		if (strcmp(item->getName(), itemName) == 0 &&
			strcmp(item->getCat(), itemCat) == 0 &&
			strcmp(item->getSubCat(), itemSubCat) == 0 ){
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


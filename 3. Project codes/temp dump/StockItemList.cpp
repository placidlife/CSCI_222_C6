#include <fstream>

#include "StockItemList.h"

// constructor
StockItemList::StockItemList(){
	// read stock item file and get in all stock item data
	readStockItemFile();
}

void StockItemList::readStockItemFile(){
	cout << "Loading Stock Items..." << endl << endl;
	string fileName = "WMTStockItemsData.txt";
	ifstream infile;
	
	infile.open(fileName);
	
	if (!infile){
		cout << "could not open file " << fileName << " to read." << endl << endl;
		exit (-1);
		infile.close();
	}

	while (getline (infile, line)){
		processData(line);
	}

	infile.close();
	cout << "Stock Items successfully loaded!" << endl << endl;
}

void StockItemList::processData(string line){
	// if line is empty (in case of any writing error) don't do anything
	if (line.length() > 0){
		// use stringstream to break line into tokens
		istringstream iss(line);
		string token;
		vector<string> fields;
		while (getline(iss, token, ":")){
			// store tokens into vector to access later
			fields.push_back(token);
		}
		// now extract the data and store them accordingly
		string itemID = fields[0];
		string itemName = fields[1];
		string itemCat = fields[2];
		string itemSubCat = fields[3];
		double itemPrice = stod(fields[4]);
		int itemQuantity = stoi(fields[5]);
		int itemThreshold = stoi(fields[6]);
		// now create item
		StockItem *newItem = new StockItem(itemID, itemName, itemCat, itemSubCat);
		newItem->updatePrice(itemPrice);
		newItem->updateQuantity(itemQuantity);
		newItem->updateThreshold(itemThreshold);

		// store item to list 
		stockItems.push_back(newItem);
	}
}


void StockItemList::updateStockItemFile(){
	string fileName = "WMTStockItemsData.txt";
	ofstream outfile;

	outfile.open(fileName, ios_base::app);
	if (!outfile){
		cout << "could not open file " << fileName << " to append." << endl << endl;
		exit (-1);
		outfile.close();
	}
	// append latest item to file
	StockItem * stockItem = stockItems.pop_back();
	outfile << stockItem->getID() << ":"
		<< stockItem->getName() << ":"
		<< stockItem->getCat() << ":"
		<< stockItem->getSubCat() << ":"
		<< stockItem->getPrice() << ":"
		<< stockItem->getQuantity() << ":"
		<< stockItem->getThreshold() << endl;
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

vector<StockItem *> StockItemList::getListOfStockItems(){
	return stockItems;
}

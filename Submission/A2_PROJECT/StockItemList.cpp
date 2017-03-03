#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>

#include "StockItemList.h"

// constructor
StockItemList::StockItemList(){
	// read stock item file and get in all stock item data
	readStockItemFile();
}

void StockItemList::setWM(void *wm){
	WM = wm;
}	

void StockItemList::readStockItemFile(){
	cout << "Loading Stock Items..." << endl << endl;
	string fileName = "WMTStockItemsData.txt";
	// trying to .open file first to create file if it doesn't already exist
	ofstream outfile;
	outfile.open(fileName);
	outfile.close();
	// now trying to read in file
	ifstream infile;
	string line;
	
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
		string delimiter = ":";
		vector<string> fields;
		size_t pos = 0;
		while ((pos = line.find(delimiter)) != string::npos){
			token = line.substr(0, pos);
			// store tokens into vector to access later
			fields.push_back(token);
			line.erase(0, pos + delimiter.length());
		}
		// last field not pushed back, so do that manually outside
		fields.push_back(line);
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
	StockItem * stockItem = stockItems.back();
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
	stockItems.push_back(item);
	// update data file
	updateStockItemFile();
}

void StockItemList::addTransaction(Transaction * t){
	// find stock item with ID and add transaction to it
	for (auto const & item : stockItems){
		if (item->getID() == t->getStockItemID()){
			item->addTransaction(t);
			break;
		}
	}
}

bool StockItemList::searchStockItem (string itemID){
	// iterate through list and find matching ID
	for (auto const & item : stockItems){
		if (item->getID() == itemID){
			return true;
		}
	}
	return false;
}

bool StockItemList::searchStockItem (string itemName, string itemCat, string itemSubCat){
	// iterate through list and find matching details
	for (auto const & item : stockItems){
		if (item->getName() == itemName &&
			item->getCat() == itemCat &&
			item->getSubCat() == itemSubCat){
			return true;
		}
	}
	return false;
}

StockItem* StockItemList::getStockItem (string itemID){
	// iterate through list and find matching ID
	for (auto const & item : stockItems){
		if (item->getID() == itemID){
			return item;
		}
	}
	return NULL; // shouldn't reach here, but need this to compile
}

bool StockItemList::updateStockItem (string itemID, StockItem * item){
	// iterate through list and find matching ID
	// then overwrite that element
	for (size_t i = 0; i != (sizeof(stockItems) / sizeof(StockItem *)); i++){
		if (stockItems[i]->getID() == itemID){
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

string StockItemList::getHeader(){
	ostringstream ss;
	ss << setw(10) << left << "ID";
	ss << setw(25) << left << "Name";
	ss << setw(15) << left << "Category";
	ss << setw(20) << left << "Sub-Category";
	ss << setw(10) << left << "Price";
	ss << setw(10) << left << "Quantity" << "\n";
	return ss.str();
}

// for when generation remaining quantity
void StockItemList::updateItemQuantity(string itemID, int quantRemain){
	// find item and update it's quantity
	for (auto const & item : stockItems){
		if (itemID == item->getID()){
			item->updateQuantity(quantRemain);
			break;
		}
	}
}

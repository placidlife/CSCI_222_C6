#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm> // to use find() in vector
#include "StockItem.h"
#include "Transaction.h"

using namespace std;

// constructor
StockItem::StockItem(string id, string name, string cat, string subCat){
	itemID = id;
	itemName = name;
	itemCat = cat;
	itemSubCat = subCat;
	itemPrice = 0;
	unitQuantity = 0;
	itemThreshold = 0;
}

// mutators
void StockItem::updateName(string name){
	itemName = name;
}
bool StockItem::updatePrice(double price){
	if (price < 0){
		return false;
	}
	else {
		itemPrice = price;
		return true;
	}
}
bool StockItem::updateQuantity(int quant){
	if (quant < 0){
		return false;
	}
	else {
		unitQuantity = quant;
		return true;
	}
}
void StockItem::updateCat(string cat){
	itemCat = cat;
}
void StockItem::updateSubCat(string subCat){
	itemSubCat = subCat;
}
bool StockItem::updateThreshold(int threshold){
	if (threshold < 0){
		return false;
	}
	else {
		itemThreshold = threshold;
		return true;
	}
}

// assessors
string StockItem::getName(){
	return itemName;
}
string StockItem::getID(){
	return itemID;
}
double StockItem::getPrice(){
	return itemPrice;
}
int StockItem::getQuantity(){
	return unitQuantity;
}
string StockItem::getCat(){
	return itemCat;
}
string StockItem::getSubCat(){
	return itemSubCat;
}
int StockItem::getThreshold(){
	return itemThreshold;
}
string StockItem::toString(){
	// using http://stackoverflow.com/questions/2342162/stdstring-formatting-like-sprintf
	// returns the following format
	// ID	Name		Category	Sub-Category	Price	Quantity
	ostringstream ss;
	ss << setw(10) << left << itemID;
	ss << setw(25) << left << itemName;
	ss << setw(15) << left << itemCat;
	ss << setw(20) << left << itemSubCat;
	ss << "$" << setw(10) << left << setprecision(2) << itemPrice;
	ss << setw(10) << left << unitQuantity << "\n";
	return ss.str();
}

void StockItem::addTransaction (Transaction *t){
	itemTransactions.push_back(t);
}
void StockItem::removeTransaction (Transaction *t){
	// using https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom
	itemTransactions.erase (std::remove (itemTransactions.begin(),
		itemTransactions.end(), t), itemTransactions.end());
}

// print transaction history to console
void StockItem::printItemSumm(){
	// print header
	cout << setw(15) << left << "TransactionID";
	cout << setw(10) << left << "itemID";
	cout << setw(25) << left << "Date and Time";
	cout << setw(5) << left << "In";
	cout << setw(5) << left << "Out";
	cout << setw(8) << left << "Amount";
	cout << setw(10) << left << "Total Amount";
	cout << "Quantity Remaining\n";
	// iterate through all transactions, and print out latest 20
	int count = 0;
	for (auto const &t : itemTransactions){
		cout << t->toString();
		i++;
		if (i == 20)
			break;
	}
}

// export transaction history to file
void StockItem::exportItemFile(string fileName){
	// TODO
}




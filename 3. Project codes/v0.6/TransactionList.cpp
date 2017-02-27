#include <algorithm> // for searching a vector
#include "TransactionList.h"
#include "Common.h"
#include "Transaction.h"
#include "WarehouseManager.h"

using namespace std;


// constructor
TransactionList::TransactionList(){
	// read stock item file and get in all stock item data
	readTransactionFile();
}

void TransactionList::setWM(void *wm){
	WM = wm;
}

void TransactionList::readTransactionFile(){
	cout << "Loading Transactions..." << endl << endl;
	string fileName = "WMTTransactionsData.txt";

	// trying to .open file first to create file if it doesn't already exist
	ofstream outfile;
	outfile.open(fileName);
	outfile.close();
	// now trying to read in file
	ifstream infile;
	
	infile.open(fileName);
	
	if (!infile){
		cout << "could not open file " << fileName << " to read." << endl << endl;
		exit (-1);
		infile.close();
	}

	string line;
	while (getline (infile, line)){
		processData(line);
	}

	infile.close();
	cout << "Transactions successfully loaded!" << endl << endl;
}

void TransactionList::processData(string line){
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
		/*
		string transID = fields[0];
		string itemID = fields[1];
		int itemPrice = stoi(fields[2]);
		int stockChanged = stoi(fields[3]);
		tm date = Common::getDateAndTime2(fields[4]);
		int quantityRemaining = stoi(fields[5]);
		*/
		string transID = fields[0];
		string itemName = fields[1];
		string itemCat = fields[2];
		string itemSubCat = fields[3];
		int itemPrice = stoi(fields[4]);
		int stockChanged = stoi(fields[5]);
		tm date = Common::getDateAndTime2(fields[6]);
		//int quantityRemaining = stoi(fields[5]);

		// now create transaction
		Transaction *newTrans = new Transaction(itemName, transID, itemName, date,
		itemPrice, stockChanged);
		// update the quantity remaining
		//newTrans->updateQuantityRemaining(quantityRemaining);

		// store item to list 
		transactions.push_back(newTrans);
	}
}

void TransactionList::updateTransactionFile(){
	string fileName = "WMTTransactionsData.txt";
	ofstream outfile;

	outfile.open(fileName, ios_base::app);
	if (!outfile){
		cout << "could not open file " << fileName << " to append." << endl << endl;
		exit (-1);
		outfile.close();
	}
	// append latest item to file
	Transaction * trans = transactions.back();
	outfile << trans->getTransactionID() << ":";
	outfile << trans->getStockItemID() << ":";
	outfile << trans->getTransactionPrice() << ":";
	outfile << trans->getQuantityProcessed() << ":";
	outfile << Common::getDateStringForFile(trans->getDateAndTime()) << ":";
	outfile << trans->getQuantityRemaining() << endl;
	outfile.close();
}

void TransactionList::addTransaction(Transaction * t){
	// add new transaction to list
	transactions.push_back(t);
	// update data file
	updateTransactionFile();
}

bool TransactionList::searchTransaction (string tID){
	// iterate through list and find matching ID
	for (auto const & t : transactions){
		if (t->getTransactionID() == tID){
			return true;
		}
	}
	return false;
}

Transaction* TransactionList::getTransaction (string tID){
	// iterate through list and find matching ID
	for (auto const & t : transactions){
		if (t->getTransactionID() == tID){
			return t;
		}
	}
	return NULL; // shouldn't need this, but just to compile
}

bool TransactionList::updateTransaction (string tID, Transaction * t){
	// iterate through list and find matching ID
	// then overwrite that element
	for (size_t i = 0; i != (sizeof(transactions) / sizeof(Transaction *)); i++){
		if (transactions[i]->getTransactionID() == tID){
			transactions[i] = t;
			return true;
		}
	}
	return false;
}

bool TransactionList::removeTransaction (Transaction * t){
	// iterate through list and find transaction
	// then remove it from list
	for (size_t i = 0; i != (sizeof(transactions) / sizeof(Transaction *)); i++){
		if (transactions[i]->getTransactionID() ==
				t->getTransactionID()){
			transactions.erase (transactions.begin()+i);
			return true;
		}
	}
	return false;
}

string TransactionList::getLatestTransactionID (){
	// if there are no tranasctions
	// create first ID to be 000000000
	if (transactions.empty()){
		return "000000000";
	}
	else{
		return transactions.back()->getTransactionID();
	}

}

string TransactionList::getHeader(){
	ostringstream ss;
	ss << setw(15) << left << "Transaction ID";
	ss << setw(8) << left << "Item ID";
	ss << setw(20) << left << "Date and Time";
	ss << setw(5) << left << "IN";
	ss << setw(5) << left << "OUT";
	ss << setw(10) << left << "Amount";
	ss << setw(13) << left << "Total Amount";
	ss << "Quantity Remaining" << "\n";
	return ss.str();
}

void TransactionList::generateRemainingQuantity(){
	// keep a list of items that have been given an initial quantity
	vector<string> doneItems;
	// go through every transaction in list 
	for (auto const & t : transactions){
		// for transaction whose item is not in list of initialized items
		if (!checkIfItemInVector(t->getStockItemID(), doneItems)){
			// give them an initial quantity
			t->updateQuantity(1000);
			// update the item too
			static_cast<WarehouseManager*>(WM)->updateItemQuantity(t->getStockItemID(), 1000);
			// and put their id into list
			doneItems.push_back(t->getStockItemID());
		}
	}

	// now go through every initialized item
	// and go through every transaction of each item 
	// to update the remaining quantity of the following transactions
	for (auto const & itemID : doneItems){
		int prevQuant = 1000;
		for (auto const & t : transactions) {
			if (itemID == t->getStockItemID()){
				// udpate the current remaining quantity
				// by + or - the quantity processed
				t->updateQuantityRemaining(prevQuant + t->getQuantityProcessed());
				// update the item too
				static_cast<WarehouseManager*>(WM)->updateItemQuantity(itemID, t->getQuantityRemaining());	
				// set current remaining quantity to prev for later use
				prevQuant = t->getQuantityRemaining();
			}
		}
	}
}

// to check if item is in list
bool TransactionList::checkIfItemInVector(string item, vector<string> vec){
	if (find(vec.begin(), vec.end(), item) != vec.end()){
		return true;
	}else{
		return false;
	}
}

vector<Transaction *> TransactionList::getFullList()
{
  return transactions;
}

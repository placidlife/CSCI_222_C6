#include <algorithm> // for searching a vector
#include "Transaction.h"

using namespace std;


// constructor
TransactionList::TransactionList(void *wm){
	// set WM
	WM = wm;
	// read stock item file and get in all stock item data
	readTransactionFile();
}

void TransactionList::readTransactionFile(){
	cout << "Loading Transactions..." << endl << endl;
	string fileName = "WMTTransactionsData.txt";
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
	cout << "Transactions successfully loaded!" << endl << endl;
}

void TransactionList::processData(){
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
		string transID = fields[0];
		string itemID = fields[1];
		int itemPrice = stoi(fields[2]);
		int stockChanged = stoi(fields[3]);
		tm date = //stod(fields[4]);
		int quantityRemaining = stoi(fields[5]);

		// now create transaction
		Transaction *newTrans = new Transaction(itemID, transactionID, date,
		itemPrice, stockChanged, quantityRemaining);

		// store item to list 
		stockItems.push_back(newItem);
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
	Transaction * trans = transactions.pop_back();
	outfile << transactions->getTransactionID() << ":"
		<< transactions->getStockItemID() << ":"
		<< transactions->getTransactionPrice() << ":"
		<< transactions->getQuantityProcessed() << ":"
		<< transactions->getDateAndTime() << ":"
		<< transactions->getQuantityRemaining() << endl;
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
		if (strcmp(t->getTransactionID(), tID) == 0){
			return true;
		}
	}
	return false
}

Transaction* TransactionList::getTransaction (string tID){
	// iterate through list and find matching ID
	for (auto const & t : transactions){
		if (strcmp(t->getTransactionID(), tID) == 0){
			return t;
		}
	}
}

bool TransactionList::updateTransaction (string tID, Transaction * t){
	// iterate through list and find matching ID
	// then overwrite that element
	for (size_t i = 0; i != (sizeof(transactions) / sizeof(Transaction *)); i++){
		if (strcmp(transactions[i]->getTransactionID(), tID) == 0){
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

static string TransactionList::getHeader(){
	ostringstream ss;
	ss << setw(15) << left << "Transaction ID";
	ss << setw(8) << left << "Item ID";
	ss << setw(20) << left << "Date and Time";
	ss << setw(5) << left << "IN";
	ss << setw(5) << left << "OUT";
	ss << setw(10) << left << "Amount";
	ss << setw(13) << left << "Total Amount" <<
	ss << "Quantity Remaining" << "\n";
	return ss.str();
}

void TransactionList::generateRemainingQuantity(){
	// keep a list of items that have been given an initial quantity
	vector<string> doneItems;
	// go through every transaction in list 
	for (auto const & t : transactions){
		// for transaction whose item is not in list of initialized items
		if (!checkIn(t->getStockItemID(), doneItems){
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
			if (strcmp(itemID, t->getStockItemID() == 0){
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

//added by daryl
vector<Transaction *> getFullList()
{
  return transactions;
}

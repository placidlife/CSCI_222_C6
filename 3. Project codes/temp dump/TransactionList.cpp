#include <algorithm> // for searching a vector
#include "Transaction.h"

using namespace std;


// constructor
TransactionList::TransactionList(){
	// read stock item file and get in all stock item data
	readTransactionFile();
}

void TransactionList::readTransactionFile(){
	string generalName = "Transactions";
	// TODO
}

void TransactionList::updateTransactionFile(){
	// TODO
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


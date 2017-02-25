#ifndef TRANSACTIONLIST_H
#define TRANSACTIONLIST_H

using namespace std;

class TransactionList {

	private:
		vector<Transaction *> transactions;
		void readTransactionFile();
		void updateTransactionFile();

	public: 
		// constructor
		TransactionList();
		
		void addTransaction(Transaction * t);
		bool searchTransaction (string tID); // use this to check if exists first
		Transaction* getTransaction (string tID); // then use this to get it
		bool updateTransaction (string tID, Transaction * t);
		bool removeTransaction (Transaction * t);

};

#endif

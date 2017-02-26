#ifndef TRANSACTIONLIST_H
#define TRANSACTIONLIST_H

using namespace std;

class TransactionList {

	private:
		vector<Transaction *> transactions;
		void * WM;
		void readTransactionFile();
		void updateTransactionFile();

	public: 
		// constructor
		TransactionList(void * wm);
		
		void addTransaction(Transaction * t);
		// use this to check if exists first
		bool searchTransaction (string tID); 
		// then use this to get it
		Transaction* getTransaction (string tID); 
		bool updateTransaction (string tID, Transaction * t);
		bool removeTransaction (Transaction * t);

		// used to print header for item
		static string getHeader(); 

		// for initialization, give all transactions a remaining quantity
		void generateRemainingQuantity();

};

#endif

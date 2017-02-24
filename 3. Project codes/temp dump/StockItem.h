#ifndef STOCKITEM_H
#define STOCKITEM_H

#include <string>
#include <vector>

using namespace std;

class StockItem {
	private: 
		string itemID;
		string itemName;
		double itemPrice;
		int unitQuantity;
		string itemCat;
		string itemSubCat;
		int itemThreshold;
		vector<Transaction *> itemTransactions;

		//string generateID();
		// it seems that this generateID() function should be 
		// better placed in the calling function that is creating 
		// this stockItem object, because they will have the 
		// access to all the item's ID.
	public: 
		// constructor
		StockItem(string itemID, string itemName, string itemCat, string itemSubCat);
		
		// mutators
		void updateName(string);
		bool updatePrice(double);
		bool updateQuantity(int);
		void updateCat(string);
		void updateSubCat(string);
		bool updateThreshold(int);
		
		// assessors
		string getName();
		string getID();
		double getPrice();
		int getQuantity();
		string getCat();
		string getSubCat();
		int getThreshold();
		string toString();

		// others
		void printItemSumm(); // print transactions to console
		void exportItemFile(string fileName); // save transactions to file
		void addTransaction (Transaction *t);
		void removeTransaction (Transaction *t);
};

#endif

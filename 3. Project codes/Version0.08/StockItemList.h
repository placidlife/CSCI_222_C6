#ifndef STOCKITEMLIST_H
#define STOCKITEMLIST_H

#include "StockItem.h"

using namespace std;

class StockItemList {

	private:
		vector<StockItem *> stockItems;
		void * WM;
		void readStockItemFile();
		void updateStockItemFile();
		void processData(string line);

	public: 
		// constructor
		StockItemList();
		void setWM(void *wm);
		
		void addStockItem(StockItem * item);
		void addTransaction(Transaction * t);
		// use this to check if exists first
		bool searchStockItem (string itemID); 
		bool searchStockItem (string itemName, string itemCat, string itemSubCat); 
		// then use this to get it
		StockItem* getStockItem (string itemID);
		bool updateStockItem (string itemID, StockItem * item);
		bool removeStockItem (StockItem * item);

		// give list of stock items to search
		vector<StockItem *> getListOfStockItems();

		// used to print header for item
		static string getHeader(); 

		// for when generation remaining quantity
		void updateItemQuantity(string itemID, int quantRemain);

};

#endif

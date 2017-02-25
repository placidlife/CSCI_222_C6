#ifndef STOCKITEMLIST_H
#define STOCKITEMLIST_H

using namespace std;

class StockItemList {

	private:
		vector<StockItem *> stockItems;
		void readStockItemFile();
		void updateStockItemFile();

	public: 
		// constructor
		StockItemList();
		
		void addStockItem(StockItem * item);
		bool searchStockItem (string itemID); // use this to check if exists first
		StockItem* getStockItem (string itemID); // then use this to get it
		bool updateStockItem (string itemID, StockItem * item);
		bool removeStockItem (StockItem * item);

};

#endif

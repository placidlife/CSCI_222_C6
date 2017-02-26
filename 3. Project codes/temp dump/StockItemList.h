#ifndef STOCKITEMLIST_H
#define STOCKITEMLIST_H

using namespace std;

class StockItemList {

	private:
		vector<StockItem *> stockItems;
		void readStockItemFile();
		void updateStockItemFile();
		void processData(string line);

	public: 
		// constructor
		StockItemList();
		
		void addStockItem(StockItem * item);
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

};

#endif

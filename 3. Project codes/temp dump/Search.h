#ifndef SEARCH_H
#define SEARCH_H

class Search {
	public: 
		Search(void * WM);
		
		bool checkItemExists(string itemID);
		bool checkItemExists(string itemName, string itemCat, string itemSubCat);
		
		void searchItemName();	
		void searchItemCat();
		void searchItemPrice();
		void searchItemQuantity();
	private: 
		void * WM; 

		vector<StockItem *> findItemID(string itemID);
		vector<StockItem *> findItemName(string itemName);
		vector<StockItem *> findItemCat(string itemCat, string itemSubCat);
		vector<StockItem *> findItemPrice(int min, int max);
		vector<StockItem *> fidnItemQuantity(int min, int max);
		void printSearchResults (vector<StockItem *>);
};

#endif

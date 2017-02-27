#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <vector>
#include <ctime>
#include "Common.h"

using namespace std;

class Transaction
{
	private:
		string	itemID;
		string	transactionID;
		string  itemName;
		tm	date;
		double	transactionPrice;
		double	transactionTotal;
		int	quantityProcessed;
		int 	quantityRemaining;
	public:
		Transaction(string itemID, string transactionID, string itemName, tm date, double transactionPrice, int quantityProcessed);
		//string generateID();
		string	getStockItemID();
		string	getTransactionID();
		string  getItemName();
		tm	getDateAndTime();
		double	getTransactionPrice();
		double	getTransactionTotal();
		int	getQuantityProcessed();
		int 	getQuantityRemaining();
		
		bool	updateQuantity(int);
		bool	updateDateAndTime(tm);
		bool	updatePrice(double);
		void	updateQuantityRemaining(int);

		string	toString(); // get string for item itself
		void	voidTransaction();
};

#endif

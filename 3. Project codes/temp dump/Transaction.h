#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <vector>
#include <ctime>

#include "StockItem.cpp"

using namespace std;

class Transaction
{
	private:
		string	itemID;
		string	transactionID;
		tm	date;
		double	transactionPrice;
		double	transactionTotal;
		int	quantityProcessed;
	public:
		Transaction(string itemID, string transactionID, tm date, 
			double transactionPrice, int quantityProcessed);
		//string generateID();
		string	getStockItemID();
		string	getTransactionID();
		tm	getDateAndTime();
		double	getTransactionPrice();
		double	getTransactionTotal();
		int	getQuantityProcessed();
		
		void	updateQuantity(int);
		void	updateDateAndTime(tm);
		void	updatePrice(double);

		string	toString();
		void	voidTransaction();
}

#endif

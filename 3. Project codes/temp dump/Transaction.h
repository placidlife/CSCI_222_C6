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
		tm	time;
		double	transactionPrice;
		double	transactionTotal;
		int	quantityProcessed;
	public:
		Transaction(string itemID, string transactionID, tm date, tm time, 
			double transactionPrice, int quantityProcessed);
		//string generateID();
		string	getStockItemID();
		string	getTransactionID();
		tm	getDate();
		tm	getTime();
		double	getTransactionPrice();
		double	getTransactionTotal();
		int	getQuantityProcessed();
		
		void	updateQuantity(int);
		void	updateDate(tm);
		void	updateTime(tm);
		void	updatePrice(double);

		string	toString();
		void	voidTransaction();
}

#endif

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
		time_t	date;
		time_t	time;
		double	transactionPrice;
		double	transactionTotal;
		int		quantityProcessed;
	public:
		Transaction(string itemID, string transactionID, time_t date, time_t time, 
			double transactionPrice, double transactionTotal);
		//string generateID();
		string	getStockItemID();
		string	getTransactionID();
		time_t	getDate();
		time_t	getTime();
		double	getTransactionPrice();
		double	getTransactionTotal();
		int		getQuantityProcessed();
		
		void	updateQuantity(int);
		void	updateDate(time_t);
		void	updateTime(time_t);
		void	updatePrice(double);

		string	toString();
		void	voidTransaction();
}

#endif

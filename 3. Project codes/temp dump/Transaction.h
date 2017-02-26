#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <vector>
#include <ctime>

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
		int 	quantityRemaining;
	public:
		Transaction(string itemID, string transactionID, tm date, double transactionPrice, int quantityProcessed);
		//string generateID();
		string	getStockItemID();
		string	getTransactionID();
		tm	getDateAndTime();
		double	getTransactionPrice();
		double	getTransactionTotal();
		int	getQuantityProcessed();
		int 	getQuantityRemaining();
		
		void	updateQuantity(int);
		void	updateDateAndTime(tm);
		void	updatePrice(double);
		void	updateQuantityRemaining(int);

		string	toString(); // get string for item itself
		void	voidTransaction();
};

#endif

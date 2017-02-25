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
		time_t	transactionDate;
		time_t	transactionTime;
		double	transactionPrice;
		double	transactionTotal;
		int		quantityProcessed;
	public:
		Transaction(string itemID, string transactionID, time_t transactionDate, time_t transactionTime, 
			double transactionPrice, double transactionTotal, int quantityProcessed);
		//string generateID();
		string	getStockItemID();
		string	getTransactionID();
		time_t	getDate();
		time_t	getTime();
		double	getTransactionPrice();
		double	getTransactionTotal();
		int		getQuantityProcessed();
		
		bool	updateQuantity(int);
		bool	updateDate(time_t);
		bool	updateTime(time_t);
		bool	updatePrice(double);

		string	toString();
};

#endif

#include <string>
#include <sstream>

#include "Transaction.h"

using namespace std;

//Transaction(string itemID, string transactionID, time_t date, time_t time, double transactionPrice, double transactionTotal);
Transaction::Transaction(string iID, string transac_ID, time_t transac_date, time_t transac_time, 
	double price, double totalPrice, int quantity)
{
	itemID 				= iID;
	transactionID		= transac_ID;
	date				= transac_date;
	time				= transac_time;
	transactionPrice	= price;
	transactionTotal	= totalPrice;
	quantityProcessed	= quantity;
}

string Transaction::getStockItemID()
{ return itemID; }

string Transaction::getTransactionID()
{ return transactionID; }

time_t Transaction::getDate()
{ return date;  }

time_t Transaction::getTime()
{ return time; }

double Transaction::getTransactionPrice()
{ return transactionPrice; }

double Transaction::getTransactionTotal()
{ return transactionTotal; }

int Transaction::getQuantityProcessed()
{ return quantityProcessed; }


bool Transaction::updateQuantity(int quantity)
{ 
	if (quantity < 0)
		return false;
	else
	{
		quantityProcessed = quantity;
		return true;
	}
}
// with reference from https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
bool Transaction::updateDate(time_t transac_date)
{
	time_t now 	= time(0);
	tm *ltm 	= localtime(&now);
	//tm *check	= inputtime(&transac_date);
	if ( (ltm->tm_year < transac_date.tm_year) && (ltm->tm_mon < transac_date->tm_mon) && (ltm->tm_mday < transac_date->tm_mday) )
		return false;
	else
	{
		date = transac_date;
		return true;
	}
}

void Transaction::updateTime(time_t transac_time)
{
	time = transac_time;
}

bool Transaction::updatePrice(double price)
{ 
	if (price < 0)
		return false;
	else
	{
		transactionPrice = price;
		return true;
	}
}

string Transaction::toString(){
	// using http://stackoverflow.com/questions/2342162/stdstring-formatting-like-sprintf
	// returns the following format
	// itemID	transactionID	date	time	price	totalPrice	Quantity
	ostringstream ss;
	ss << setw(10) << left << itemID;
	ss << setw(10) << left << transactionID;
	ss << setw(10) << left << date;
	ss << setw(10) << left << time;
	ss << "$" << setw(10) << left << setprecision(2) << transactionPrice;
	ss << "$" << setw(10) << left << setprecision(2) << transactionTotal;
	ss << setw(10) << left << quantityProcessed << "\n";
	return ss.str();
}



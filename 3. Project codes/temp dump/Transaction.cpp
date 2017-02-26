#include <string>
#include <sstream>
#include <ctime>
#include <time.h>
#include <iomanip>

#include "Transaction.h"

using namespace std;

Transaction::Transaction(string iID, string transac_ID, tm transac_date,
	double price, int quantity)
{
	itemID 			= iID;
	transactionID		= transac_ID;
	date			= transac_date;
	transactionPrice	= price;
	quantityProcessed	= quantity;
	transactionTotal	= quantity * price;
	
}

string Transaction::getStockItemID()
{ return itemID; }

string Transaction::getTransactionID()
{ return transactionID; }

time_t Transaction::getDateAndTime()
{ return date;  }

double Transaction::getTransactionPrice()
{ return transactionPrice; }

double Transaction::getTransactionTotal()
{ return transactionTotal; }

int Transaction::getQuantityProcessed()
{ return quantityProcessed; }


bool Transaction::updateQuantity(int quantity)
{ 
	quantityProcessed = quantity;
	return true;
}

void Transaction::updateQuantityRemaining(int quantity){
	quantityRemaining = quantity;
}
// with reference from https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
bool Transaction::updateDateAndTime(time_t transac_date)
{
/*
time_t my_time;
struct tm * timeinfo; 
time (&my_time);
timeinfo = localtime (&my_time);
*/

	time_t now;
	time (&now);
	tm *check	= localtime(&transac_date);
	tm *ltm 	= localtime(&now);
	if ( ltm->tm_year < check->tm_year)
	{ 
		if( ltm->tm_mon < check->tm_mon)
		{
			if (ltm->tm_mday < check->tm_mday)
				return false;
		}
	}
	else
	{
		date = transac_date;
		return true;
	}
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



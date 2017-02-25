#include <string>
#include <sstream>
#include <ctime>
#include <time.h>
#include <iomanip>

#include "Transaction.h"

using namespace std;

Transaction::Transaction(string iID, string transac_ID, time_t transac_date, time_t transac_time, 
	double price, double totalPrice, int quantity)
{
	itemID 				= iID;
	transactionID		= transac_ID;
	transactionDate		= transac_date;
	transactionTime		= transac_time;
	transactionPrice	= price;
	transactionTotal	= totalPrice;
	quantityProcessed	= quantity;
}

string Transaction::getStockItemID()
{ return itemID; }

string Transaction::getTransactionID()
{ return transactionID; }

time_t Transaction::getDate()
{ return transactionDate;  }

time_t Transaction::getTime()
{ return transactionTime; }

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

	time_t t = time(0);   // get time now
    tm *now = localtime( & t );
	tm *check	= localtime( & transac_date );
	if ( now->tm_year >= check->tm_year)
	{ 
		if( now->tm_mon >= check->tm_mon)
		{
			if (now->tm_mday >= check->tm_mday)
			{
				transactionDate = transac_date;
				return true;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

bool Transaction::updateTime(time_t transac_time)
{
	time_t t = time(0);   // get time now
    tm *now = localtime( & t );
	tm *check	= localtime( & transac_time );
	if ( now->tm_year >= check->tm_year)
	{ 
		if( now->tm_mon >= check->tm_mon)
		{
			if (now->tm_mday >= check->tm_mday)
			{
				if (now->tm_hour >= check->tm_hour)
				{
					if(now->tm_min >= check->tm_min)
					{
						transactionTime	= transac_time;
						return true;
					}
				}
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
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
	ss << setw(10) << left << transactionDate;
	ss << setw(10) << left << transactionTime;
	ss << "$" << setw(10) << left << setprecision(2) << transactionPrice;
	ss << "$" << setw(10) << left << setprecision(2) << transactionTotal;
	ss << setw(10) << left << quantityProcessed << "\n";
	return ss.str();
}



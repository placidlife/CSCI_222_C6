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

tm Transaction::getDateAndTime()
{ return date;  }

double Transaction::getTransactionPrice()
{ return transactionPrice; }

double Transaction::getTransactionTotal()
{ return transactionTotal; }

int Transaction::getQuantityProcessed()
{ return quantityProcessed; }

int Transaction::getQuantityRemaining()
{ return quantityRemaining; }

bool Transaction::updateQuantity(int quantity)
{ 
	quantityProcessed = quantity;
	return true;
}

void Transaction::updateQuantityRemaining(int quantity){
	quantityRemaining = quantity;
}
// with reference from https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
bool Transaction::updateDateAndTime(tm transac_date)
{
	time_t now;
	time (&now);
	// if difference between taken date is future from now
	// return false
	if (difftime(now, mktime(&transac_date) < 0)){
		return false;
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
	ss << setw(15) << left << transactionID;
	ss << setw(8) << left << itemID;
	ss << setw(20) << left << Common::getDateString(date);
	if (quantityProcessed > 0){
		ss << setw(5) << left << quantityProcessed; // IN
		ss << setw(5) << left << 0;		// OUT
	}else{
		ss << setw(5) << left << 0;	//IN
		ss << setw(5) << left << 0-quantityProcessed;	//OUT
	}
	ss << "$" << setw(10) << left << setprecision(2) << transactionPrice;
	ss << "$" << setw(13) << left << setprecision(2) << transactionTotal;
	ss << quantityRemaining << "\n";
	return ss.str();
}



#include "Staff.h"
#include "WarehouseManager.h"

void Staff::displayMenu()
{
  while(1)
  {
    std::cout << "Welcome to Warehouse Management Tool" << std::endl << std::endl;
    std::cout << "1)	Search stock item" << std::endl;
    std::cout << "2)	Process transaction" << std::endl;
    std::cout << "3)	View stock summary report" << std::endl;
    std::cout << "7)	Quit" << std::endl;

    int choice;
    std::cout << "Enter option: ";
    std::cin >> choice;
    std::cout << std::endl;
    
    switch(choice)
    {
      case 1:
        doSearchStock();
        break;
      case 2:
        doProcessTransaction();
        break;
      case 3:
        summaryMenu();
        break;
      case 4:
        return;
        break;
      
    }
  }
}

void Staff::doSearchStock()
{
  std::cout << "Staff::doEditStock()" << std::endl << std::endl;
}

void Staff::doProcessTransaction()
{
  std::cout << "Staff::doProcessTransaction()" << std::endl << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
void summaryMenu()
{
  while(1)
  {
    std::cout << "Choose the range of the summary" << std::endl << std::endl;
    std::cout << "a)	View daily stock summary report" << std::endl;
    std::cout << "b)	View weekly stock summary report" << std::endl;
    std::cout << "c)	View monthly stock summary report" << std::endl;
    std::cout << "d)	View yearly stock summary report" << std::endl;
    std::cout << "e)	Quit" << std::endl;

    char choice;
    std::cout << "Enter option: ";
    std::cin >> choice;
    std::cout << std::endl;
    
    switch(choice)
    {
      case 'a':
        doDailySummary();
        break;
      case 'b':
        doWeeklySummary();
        break;
      case 'c':
        doMonthlySummary();
        break;
      case 'd':
        doYearlySummary();
        break;
      case 'e':
        return;
        break;
      
    }
  }
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
void Staff::doDailySummary()
{
  std::cout << "Staff::doDailySummary()" << std::endl << std::endl;
}

void Staff::doWeeklySummary()
{
  std::cout << "Staff::doWeeklySummary()" << std::endl << std::endl;
}

void Staff::doMonthlySummary()
{
  std::cout << "Staff::doMonthlySummary()" << std::endl << std::endl;
}

void Staff::doYearlySummary()
{
  std::cout << "Staff::doYearlySummary()" << std::endl << std::endl;
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
std::vector<Transaction *>  Staff::collapseDay(std::string day)
{
  TransactionList * tList = static_cast<WarehouseManager*>(WM)->getTransaction();
  std::vector<Transaction *> thisDay;
  std::vector<Transaction *> retVal;
  std::stringstream ss;
  ss << setw(10) << left << "ItemID";
	ss << setw(30) << left << "Item Name";
	ss << setw(10) << left << "IN";
	ss << setw(10) << left << "OUT";
  ss << setw(15) << left << "Amount";
	ss << setw(15) << left << "Total Amount";
  ss << setw(15) << left << "Quantity Remaining";
  ss << std::endl;
	
  
  struct tm inDate = getDate(day);
  
  for (auto it : (tList->getFullList()).begin())
  {
    if(it->getDate().tm_mday == inDate.tm_mday && 
       it->getDate().tm_mon == inDate.tm_mon &&
       it->getDate().tm_year == inDate.tm_year)
       {
         thisDay.push_back(it);
         retVal.push_back(it);
       }
  }
  
  
  
  while(!thisDay.empty())
  {
    if(!thisDay.back())
    {
      thisDay.pop_back();
      continue;
    }
    Transaction * prime = nullptr;
    if(!prime)
    {
      prime = thisDay.back();
      thisDay.back() = nullptr;
      thisDay.pop_back();
    }
    
    std::string itmID(prime->getStockItemID());
    std::string transacID(prime->getTransactionID());
    double price = prime->getTransactionPrice();
    int incoming = 0;
    int outgoing = 0;
    
    if(prime->getQuantityProcessed() > 0)
      incoming += prime->getQuantityProcessed();
    else
      outgoing -= prime->getQuantityProcessed();
    
    for(auto it : thisDay)
    {
      if(it && it != prime)
      {
        if(!prime.compare(it->getStockItemID()))
        {
          if(it->getQuantityProcessed() > 0)
            incoming += it->getQuantityProcessed();
          else
            outgoing -= it->getQuantityProcessed();
        }
        it = nullptr;
      }
    }
    ss << setw(10) << left << itmID;
    ss << setw(30) << left << "Item Name";
    ss << setw(10) << left << incoming;
    ss << setw(10) << left << outgoing;
    ss << setw(15) << left << price;
    ss << setw(15) << left << (incoming - outgoing) * price;
    ss << setw(15) << left << incoming - outgoing;
    ss << std::endl;
  }
  
}

vector<Transaction *>  Staff::collapseWeek(std::string weekStart, std::string weekEnd)
{
  TransactionList * tList = static_cast<WarehouseManager*>(WM)->getTransaction();
  std::vector<Transaction *> thisDay;
  std::vector<Transaction *> retVal;
  std::stringstream ss;
  ss << setw(10) << left << "ItemID";
	ss << setw(30) << left << "Item Name";
	ss << setw(10) << left << "IN";
	ss << setw(10) << left << "OUT";
  ss << setw(15) << left << "Amount";
	ss << setw(15) << left << "Total Amount";
  ss << setw(15) << left << "Quantity Remaining";
  ss << std::endl;
	
  
  struct tm startDate = getDate(weekStart);
  struct tm endDate = getDate(weekEnd);
  
  for (auto it : (tList->getFullList()).begin())
  {
    if(it->getDate().tm_mday >= startDate.tm_mday && 
       it->getDate().tm_mday <= endDate.tm_mday && 
       it->getDate().tm_mon == startDate.tm_mon &&
       it->getDate().tm_year == startDate.tm_year)
       {
         thisDay.push_back(it);
         retVal.push_back(it);
       }
  }
  
  
  
  while(!thisDay.empty())
  {
    if(!thisDay.back())
    {
      thisDay.pop_back();
      continue;
    }
    Transaction * prime = nullptr;
    if(!prime)
    {
      prime = thisDay.back();
      thisDay.back() = nullptr;
      thisDay.pop_back();
    }
    
    std::string itmID(prime->getStockItemID());
    std::string transacID(prime->getTransactionID());
    double price = prime->getTransactionPrice();
    int incoming = 0;
    int outgoing = 0;
    
    if(prime->getQuantityProcessed() > 0)
      incoming += prime->getQuantityProcessed();
    else
      outgoing -= prime->getQuantityProcessed();
    
    for(auto it : thisDay)
    {
      if(it && it != prime)
      {
        if(!prime.compare(it->getStockItemID()))
        {
          if(it->getQuantityProcessed() > 0)
            incoming += it->getQuantityProcessed();
          else
            outgoing -= it->getQuantityProcessed();
        }
        it = nullptr;
      }
    }
    ss << setw(10) << left << itmID;
    ss << setw(30) << left << "Item Name";
    ss << setw(10) << left << incoming;
    ss << setw(10) << left << outgoing;
    ss << setw(15) << left << price;
    ss << setw(15) << left << (incoming - outgoing) * price;
    ss << setw(15) << left << incoming - outgoing;
    ss << std::endl;
  }
  
}


vector<Transaction *>  Staff::collapseMonth(std::string month)
{
  TransactionList * tList = static_cast<WarehouseManager*>(WM)->getTransaction();
  std::vector<Transaction *> thisDay;
  std::vector<Transaction *> retVal;
  std::stringstream ss;
  ss << setw(10) << left << "ItemID";
	ss << setw(30) << left << "Item Name";
	ss << setw(10) << left << "IN";
	ss << setw(10) << left << "OUT";
  ss << setw(15) << left << "Amount";
	ss << setw(15) << left << "Total Amount";
  ss << setw(15) << left << "Quantity Remaining";
  ss << std::endl;
	
  
  struct tm inMonth = getDate(month);
  
  for (auto it : (tList->getFullList()).begin())
  {
    if(it->getDate().tm_mon == startDate.tm_mon &&
       it->getDate().tm_year == startDate.tm_year)
       {
         thisDay.push_back(it);
         retVal.push_back(it);
       }
  }
  
  
  
  while(!thisDay.empty())
  {
    if(!thisDay.back())
    {
      thisDay.pop_back();
      continue;
    }
    Transaction * prime = nullptr;
    if(!prime)
    {
      prime = thisDay.back();
      thisDay.back() = nullptr;
      thisDay.pop_back();
    }
    
    std::string itmID(prime->getStockItemID());
    std::string transacID(prime->getTransactionID());
    double price = prime->getTransactionPrice();
    int incoming = 0;
    int outgoing = 0;
    
    if(prime->getQuantityProcessed() > 0)
      incoming += prime->getQuantityProcessed();
    else
      outgoing -= prime->getQuantityProcessed();
    
    for(auto it : thisDay)
    {
      if(it && it != prime)
      {
        if(!prime.compare(it->getStockItemID()))
        {
          if(it->getQuantityProcessed() > 0)
            incoming += it->getQuantityProcessed();
          else
            outgoing -= it->getQuantityProcessed();
        }
        it = nullptr;
      }
    }
    ss << setw(10) << left << itmID;
    ss << setw(30) << left << "Item Name";
    ss << setw(10) << left << incoming;
    ss << setw(10) << left << outgoing;
    ss << setw(15) << left << price;
    ss << setw(15) << left << (incoming - outgoing) * price;
    ss << setw(15) << left << incoming - outgoing;
    ss << std::endl;
  }
  
}

vector<Transaction *>  Staff::collapseYear(std::string year)
{
  TransactionList * tList = static_cast<WarehouseManager*>(WM)->getTransaction();
  std::vector<Transaction *> thisDay;
  std::vector<Transaction *> retVal;
  std::stringstream ss;
  ss << setw(10) << left << "ItemID";
	ss << setw(30) << left << "Item Name";
	ss << setw(10) << left << "IN";
	ss << setw(10) << left << "OUT";
  ss << setw(15) << left << "Amount";
	ss << setw(15) << left << "Total Amount";
  ss << setw(15) << left << "Quantity Remaining";
  ss << std::endl;
	
  
  struct tm inMonth = getDate(month);
  
  for (auto it : (tList->getFullList()).begin())
  {
    if(it->getDate().tm_year == startDate.tm_year)
       {
         thisDay.push_back(it);
         retVal.push_back(it);
       }
  }
  
  
  
  while(!thisDay.empty())
  {
    if(!thisDay.back())
    {
      thisDay.pop_back();
      continue;
    }
    Transaction * prime = nullptr;
    if(!prime)
    {
      prime = thisDay.back();
      thisDay.back() = nullptr;
      thisDay.pop_back();
    }
    
    std::string itmID(prime->getStockItemID());
    std::string transacID(prime->getTransactionID());
    double price = prime->getTransactionPrice();
    int incoming = 0;
    int outgoing = 0;
    
    if(prime->getQuantityProcessed() > 0)
      incoming += prime->getQuantityProcessed();
    else
      outgoing -= prime->getQuantityProcessed();
    
    for(auto it : thisDay)
    {
      if(it && it != prime)
      {
        if(!prime.compare(it->getStockItemID()))
        {
          if(it->getQuantityProcessed() > 0)
            incoming += it->getQuantityProcessed();
          else
            outgoing -= it->getQuantityProcessed();
        }
        it = nullptr;
      }
    }
    ss << setw(10) << left << itmID;
    ss << setw(30) << left << "Item Name";
    ss << setw(10) << left << incoming;
    ss << setw(10) << left << outgoing;
    ss << setw(15) << left << price;
    ss << setw(15) << left << (incoming - outgoing) * price;
    ss << setw(15) << left << incoming - outgoing;
    ss << std::endl;
  }
  
}

///////////////////////////////////////////////////////////////////////////////

void Staff::setStaffID(std::string stfID)
{
  staffID = stfID;
}

void Staff::setStaffName(std::string stfName)
{
  staffName = stfName;
}

void Staff::setPassword(std::string stfPwd)
{
  password = stfPwd;
}

std::string Staff::getStaffID()
{
  return staffID;
}

void Staff::setWM(void * warehouse)
{
  WM = warehouse;
}

using namespace std;

tm Staff::getDate(string input)
{
	// use stringstream to break line into tokens
	istringstream iss (input);
	string token;
	vector<string> fields;
	while (getline(iss, token, "-")){
		// store tokens into vector to access later
		fields.push_back(token);
	}
	// extract data to store into dates
	int day = stoi(fields[0]);
	int month = convertMonthStrToInt(fields[1]);
	int year = convertYYtoYYYY(fields[2]);
	// convert extracted data into time datatype
	struct tm date = {};
	date.tm_year = year - 1900;
	date.tm_mon = month -1;
	date.tm_mday = day;
	return date;
}

int Staff::convertMonthStrToInt(string input)
{
	if (strcmp(input, "Jan") == 0 || strcmp(input, "JAN") == 0){
		return 0;
	}
	if (strcmp(input, "Feb") == 0 || strcmp(input, "FEB") == 0){
		return 1;
	}
	if (strcmp(input, "Mar") == 0 || strcmp(input, "MAR") == 0){
		return 2;
	}
	if (strcmp(input, "Apr") == 0 || strcmp(input, "APR") == 0){
		return 3;
	}
	if (strcmp(input, "May") == 0 || strcmp(input, "MAY") == 0){
		return 4;
	}
	if (strcmp(input, "Jun") == 0 || strcmp(input, "JUN") == 0){
		return 5;
	}
	if (strcmp(input, "Jul") == 0 || strcmp(input, "JUL") == 0){
		return 6;
	}
	if (strcmp(input, "Aug") == 0 || strcmp(input, "AUG") == 0){
		return 7;
	}
	if (strcmp(input, "Sep") == 0 || strcmp(input, "SEP") == 0){
		return 8;
	}
	if (strcmp(input, "Oct") == 0 || strcmp(input, "OCT") == 0){
		return 9;
	}
	if (strcmp(input, "Nov") == 0 || strcmp(input, "NOV") == 0){
		return 10;
	}
	if (strcmp(input, "Dec") == 0 || strcmp(input, "DEC") == 0){
		return 11;
	}
	return -1;
}

int Staff::converYYtoYYYY(string input)
{
	int year = stoi(input);
	// if year is already in YYYY format, just return it as it is
	if (year > 1000){
		return year;
	}
	// a little lecheck, but I'm going to get date now to find current year
	// to use as the line to draw between 1900s and 2000s
	time_t now;
	time(&now);
	struct tm *timeNow = localtime(&now);
	int yearNow = 1900 + timeNow->tm_year;
	// get last two digit of current year
	yearNow %= 100;
	// use that as the cut off for 1900s 
	if (year > yearNow){
		return year + 1900;
	}
	else{
		return year + 2000;
	}
}	

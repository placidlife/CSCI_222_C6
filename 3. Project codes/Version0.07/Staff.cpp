#include "Staff.h"
#include "Common.h"
#include "WarehouseManager.h"
#include <string>

using namespace std;

void Staff::displayMenu()
{
  while(1)
  {
    std::cout << "Welcome to Warehouse Management Tool" << std::endl << std::endl;
    std::cout << "1)	Search stock item" << std::endl;
    std::cout << "2)	Process transaction" << std::endl;
    std::cout << "3)	View stock summary report" << std::endl;
    std::cout << "4)	Quit" << std::endl;

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
void Staff::summaryMenu()
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

void Staff::doDailySummary()
{
  std::cout << "Staff::doDailySummary()" << std::endl << std::endl;
  std::cout << "Staff::doDailySummary()" << std::endl << std::endl;
  std::string inDay;
  std::cout << "Enter date to view (DD-MMM-YYYY): ";
  std::cin.ignore();
  std::getline(std::cin, inDay);
  std::cout << std::endl;
  std::vector<Transaction *> toOut = collapseDay(inDay);
  for(auto it : toOut)
  {
    it->toString();
  }
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
std::vector<Transaction *>  Staff::collapseDay(std::string day)
{
  TransactionList * tList = static_cast<WarehouseManager*>(WM)->getTransaction();
  std::vector<Transaction *> retVal;
  if(tList->getFullList().empty())
  {
    std::cout << "Transaction List is empty!" << std::endl;
    return retVal;
  }
  std::vector<Transaction *> thisDay;
  std::stringstream ss;
  ss << setw(10) << left << "ItemID";
	ss << setw(30) << left << "Item Name";
	ss << setw(10) << left << "IN";
	ss << setw(10) << left << "OUT";
  ss << setw(15) << left << "Amount";
	ss << setw(15) << left << "Total Amount";
  ss << setw(15) << left << "Quantity Remaining";
  ss << std::endl;
	
  
  struct tm inDate = Common::getDate(day);
  
  for (auto it : tList->getFullList())
  {
    if(it->getDateAndTime().tm_mday == inDate.tm_mday && 
       it->getDateAndTime().tm_mon == inDate.tm_mon &&
       it->getDateAndTime().tm_year == inDate.tm_year)
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
        if(!prime->getStockItemID().compare(it->getStockItemID()))
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
  return retVal;
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

void Staff::setWM(void * wm)
{
  WM = wm;
  search.setWM(wm);
}

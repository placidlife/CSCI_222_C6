#include "Staff.h"
#include "Common.h"
#include "WarehouseManager.h"
#include "Search.h"
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
    std::cout << "4)	Import and process data from file" << std::endl;
    std::cout << "5)	Quit" << std::endl;

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
        readFile();
        break;
      case 5:
        return;
        break;
      
    }
  }
}

void Staff::doSearchStock()
{
  Search srch;
  srch.setWM(WM);
  while(1)
  {
    std::cout << "Choose the search type" << std::endl << std::endl;
    std::cout << "a)	Search by item name" << std::endl;
    std::cout << "b)	Search by item category" << std::endl;
    std::cout << "c)	Search by item price" << std::endl;
    std::cout << "d)	Search by item quantity" << std::endl;
    std::cout << "e)	Quit" << std::endl;

    char choice;
    std::cout << "Enter option: ";
    std::cin >> choice;
    std::cout << std::endl;
    
    switch(choice)
    {
      case 'a':
        srch.searchItemName();
        break;
      case 'b':
        srch.searchItemCat();
        break;
      case 'c':
        srch.searchItemPrice();
        break;
      case 'd':
        srch.searchItemQuantity();
        break;
      case 'e':
        return;
        break;
      
    }
  }
}

void Staff::doProcessTransaction()
{
   while(1)
  {
    std::cout << "Process Transaction" << std::endl << std::endl;
	std::cout << "1)	Process stock in" << std::endl;
	std::cout << "2)	Process stock out" << std::endl;
	std::cout << "3)	Return to main menu" << std::endl;

    int choice;
    string input;
    std::cout << "\nEnter option: ";
    getline(cin, input);

    while (!Common::checkInRange(1, 3, input)){
	std::cout << "Invalid input. Please enter only 1 ~ 3: ";
	    getline(cin, input);
    }
    choice = stoi(input);
    std::cout << std::endl;
    
    switch(choice)
    {
      case 1:
        doProcessStockIn();
        break;
      case 2:
        doProcessStockOut();
        break;
      case 3:
        return;
        break;
    }
  }
}

void Staff::doProcessStockIn(){
	cout << "Processing stock in" << endl << endl;
	std::cout << "Enter item ID: ";
	string input;
	std::getline (std::cin,input);
	// if item exists
	if ( static_cast<WarehouseManager*>(WM)->searchItemID(input)){
		std::cout << "Item Found:" << std::endl << std::endl;
        StockItem *stockItem = static_cast<WarehouseManager*>(WM)->getStockItem(input);
        std::cout << StockItemList::getHeader() << std::endl << std::endl;
        std::cout << stockItem->toString() << std::endl << std::endl;
        string message = "Proceed to process? (Y/N): ";
		// if user selects yes
		if (Common::getInputYN(message)){
			// ask for quantity 
			std::cout << "Enter stock quantity ";
			string inputStockQuantity;
            std::getline (std::cin,inputStockQuantity);
            // while input is not valid, keep prompting for input
            while (!Common::checkPositiveInt(inputStockQuantity)){
            	cout << "Please enter a positive number: ";
            	std::getline (std::cin,inputStockQuantity);
			}
			// ask for time and date
			cout << "Enter date and time in the following format: " << endl;
			cout << "YYYY-MM-DD HH:MM (leave blank for current date and time) : ";
			string dateStr;
			tm date;
			std::getline (std::cin,dateStr);
			// if input is empty, get current date and time
			if (dateStr.empty()){
				date = Common::getCurrentTime();
			}
			// if there is input, check if input format is right
			else{
				// the checkValidDateTime() will do error checking and print error messages
				while(!Common::checkValidDateTime(dateStr)){
					std::getline (std::cin,dateStr);
				}
				// convert string to tm
				date = Common::getDate2(dateStr);
			}
			// now create transaction item
			string itemID = stockItem->getID();
			string tranID = static_cast<WarehouseManager*>(WM)->generateTransactionID();
			string itemName = stockItem->getName();
			double price = stockItem->getPrice();
			int quant = stoi(inputStockQuantity);
			Transaction *newT = new Transaction(itemID, tranID, itemName, date, price, quant);
			// store transaction object
			static_cast<WarehouseManager*>(WM)->addTransaction(newT);
			// update current item's quantity
			stockItem->processQuantity(quant);
			std::cout << "Transaction successfully processed" << std::endl << std::endl;
			cout << "Item details : " << endl;
            std::cout << StockItemList::getHeader() << std::endl;
         	std::cout << stockItem->toString() << std::endl << std::endl << endl;
         	cout << "Transaction details : " << endl;
         	cout << TransactionList::getHeader() << endl;
         	cout << newT->toString() << endl << endl;
		}
		// if user selects no, do nothing
	}
	// if item does not exist
	else{
		cout << "Error! " << input << " does not exist! " << endl << endl;
	}
	
	Common::pressEnter();
}

void Staff::doProcessStockOut(){
	
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
  std::string inDay;
  std::cout << "Enter date to view (DD-MMM-YYYY): ";
  std::cin.ignore();
  std::getline(std::cin, inDay);
  std::cout << std::endl;
  std::vector<Transaction *> toOut = collapseDay(inDay);
  
  std::string filename(inDay);
  filename += "_Day_Report.txt";
  std::fstream myFile;
  myFile.open(filename, std::fstream::out | std::fstream::trunc);
  if(myFile.is_open())
  {
    for(auto it : toOut)
    {
      myFile << it->toString() << std::endl;
    }
  }
  myFile.close();
}

void Staff::doWeeklySummary()
{
  std::string wkStart;
  std::string wkEnd;
  std::cout << "Enter date of week start (DD-MMM-YYYY): ";
  std::cin.ignore();
  std::getline(std::cin, wkStart);
  std::cout << std::endl;
  std::cout << "Enter date of week end (DD-MMM-YYYY): ";
  std::cin.ignore();
  std::getline(std::cin, wkEnd);
  std::cout << std::endl;
  std::vector<Transaction *> toOut = collapseWeek(wkStart, wkEnd);
  
  std::string filename(wkStart);
  filename += "_Week_Report.txt";
  std::fstream myFile;
  myFile.open(filename, std::fstream::out | std::fstream::trunc);
  if(myFile.is_open())
  {
    for(auto it : toOut)
    {
      myFile << it->toString() << std::endl;
    }
  }
  myFile.close();
}

void Staff::doMonthlySummary()
{
  std::string inDay;
  std::cout << "Enter date within month to view (DD-MMM-YYYY): ";
  std::cin.ignore();
  std::getline(std::cin, inDay);
  std::cout << std::endl;
  std::vector<Transaction *> toOut = collapseMonth(inDay);
  
  std::string filename(inDay);
  filename += "_Month_Report.txt";
  std::fstream myFile;
  myFile.open(filename, std::fstream::out | std::fstream::trunc);
  if(myFile.is_open())
  {
    for(auto it : toOut)
    {
      myFile << it->toString() << std::endl;
    }
  }
  myFile.close();
}

void Staff::doYearlySummary()
{
  std::string inDay;
  std::cout << "Enter date within year to view (DD-MMM-YYYY): ";
  std::cin.ignore();
  std::getline(std::cin, inDay);
  std::cout << std::endl;
  std::vector<Transaction *> toOut = collapseYear(inDay);
  
  std::string filename(inDay);
  filename += "_Year_Report.txt";
  std::fstream myFile;
  myFile.open(filename, std::fstream::out | std::fstream::trunc);
  if(myFile.is_open())
  {
    for(auto it : toOut)
    {
      myFile << it->toString() << std::endl;
    }
  }
  myFile.close();
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
  
  if(!thisDay.empty())
  {
    ss << setw(10) << left << "ItemID";
    ss << setw(20) << left << "Item Name";
    ss << setw(10) << left << "IN";
    ss << setw(10) << left << "OUT";
    ss << setw(15) << left << "Amount";
    ss << setw(15) << left << "Total Amount";
    ss << setw(15) << left << "Quantity Remaining";
    ss << std::endl;
  }
  
  while(1)
  {
    if(thisDay.empty())
      break;
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
    std::string itmName(prime->getItemName());
    double price = prime->getTransactionPrice();
    int incoming = 0;
    int outgoing = 0;
    
    if(prime->getQuantityProcessed() > 0)
      incoming += prime->getQuantityProcessed();
    else
      outgoing -= prime->getQuantityProcessed();
    
    for(unsigned i = 0; i < thisDay.size(); ++i)
    {
      if(!prime->getStockItemID().compare(thisDay[i]->getStockItemID()))
      {
        if(thisDay[i]->getQuantityProcessed() > 0)
          incoming += thisDay[i]->getQuantityProcessed();
        else
          outgoing -= thisDay[i]->getQuantityProcessed();
        thisDay[i] = nullptr;
      }
    }
    
    bool popped;
    do
    {
      
      popped = false;
      unsigned i;
      for(i = 0; i < thisDay.size(); ++i)
      {
        if(!thisDay[i])
        {
          popped = true;
          break;
        }
      }
      if(popped)
      {
        thisDay.erase(thisDay.begin() + i);
      }
    }while(popped);
    
    ss << setw(10) << left << itmID;
    ss << setw(20) << left << itmName;
    ss << setw(10) << left << incoming;
    ss << setw(10) << left << outgoing;
    ss << fixed;
    ss << setw(15) << left << setprecision(2) << price;
    ss << setw(15) << left << setprecision(2) << (incoming - outgoing) * price;
    ss << setw(15) << left << incoming - outgoing;
    ss << std::endl;
  }
  std::cout << ss.str();
  return retVal;
}

std::vector<Transaction *>  Staff::collapseWeek(std::string weekStart, std::string weekEnd)
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
  
  struct tm wkStart = Common::getDate(weekStart);
  struct tm wkEnd = Common::getDate(weekEnd);
  
  for (auto it : tList->getFullList())
  {
    if(it->getDateAndTime().tm_mday >= wkStart.tm_mday &&
       it->getDateAndTime().tm_mday <= wkEnd.tm_mday && 
       it->getDateAndTime().tm_mon == wkStart.tm_mon &&
       it->getDateAndTime().tm_year == wkStart.tm_year)
       {
         thisDay.push_back(it);
         retVal.push_back(it);
       }
  }
  
  if(!thisDay.empty())
  {
    ss << setw(10) << left << "ItemID";
    ss << setw(20) << left << "Item Name";
    ss << setw(10) << left << "IN";
    ss << setw(10) << left << "OUT";
    ss << setw(15) << left << "Amount";
    ss << setw(15) << left << "Total Amount";
    ss << setw(15) << left << "Quantity Remaining";
    ss << std::endl;
  }
  
  while(1)
  {
    if(thisDay.empty())
      break;
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
    std::string itmName(prime->getItemName());
    double price = prime->getTransactionPrice();
    int incoming = 0;
    int outgoing = 0;
    
    if(prime->getQuantityProcessed() > 0)
      incoming += prime->getQuantityProcessed();
    else
      outgoing -= prime->getQuantityProcessed();
    
    for(unsigned i = 0; i < thisDay.size(); ++i)
    {
      if(!prime->getStockItemID().compare(thisDay[i]->getStockItemID()))
      {
        if(thisDay[i]->getQuantityProcessed() > 0)
          incoming += thisDay[i]->getQuantityProcessed();
        else
          outgoing -= thisDay[i]->getQuantityProcessed();
        thisDay[i] = nullptr;
      }
    }
    
    bool popped;
    do
    {
      
      popped = false;
      unsigned i;
      for(i = 0; i < thisDay.size(); ++i)
      {
        if(!thisDay[i])
        {
          popped = true;
          break;
        }
      }
      if(popped)
      {
        thisDay.erase(thisDay.begin() + i);
      }
    }while(popped);
    
    ss << setw(10) << left << itmID;
    ss << setw(20) << left << itmName;
    ss << setw(10) << left << incoming;
    ss << setw(10) << left << outgoing;
    ss << fixed;
    ss << setw(15) << left << setprecision(2) << price;
    ss << setw(15) << left << setprecision(2) << (incoming - outgoing) * price;
    ss << setw(15) << left << incoming - outgoing;
    ss << std::endl;
  }
  std::cout << ss.str();
  return retVal;
}

std::vector<Transaction *>  Staff::collapseMonth(std::string month)
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
  
  struct tm inMonth = Common::getDate(month);
  
  for (auto it : tList->getFullList())
  {
    if(it->getDateAndTime().tm_mon == inMonth.tm_mon &&
       it->getDateAndTime().tm_year == inMonth.tm_year)
       {
         thisDay.push_back(it);
         retVal.push_back(it);
       }
  }
  
  if(!thisDay.empty())
  {
    ss << setw(10) << left << "ItemID";
    ss << setw(20) << left << "Item Name";
    ss << setw(10) << left << "IN";
    ss << setw(10) << left << "OUT";
    ss << setw(15) << left << "Amount";
    ss << setw(15) << left << "Total Amount";
    ss << setw(15) << left << "Quantity Remaining";
    ss << std::endl;
  }
  
  while(1)
  {
    if(thisDay.empty())
      break;
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
    std::string itmName(prime->getItemName());
    double price = prime->getTransactionPrice();
    int incoming = 0;
    int outgoing = 0;
    
    if(prime->getQuantityProcessed() > 0)
      incoming += prime->getQuantityProcessed();
    else
      outgoing -= prime->getQuantityProcessed();
    
    for(unsigned i = 0; i < thisDay.size(); ++i)
    {
      if(!prime->getStockItemID().compare(thisDay[i]->getStockItemID()))
      {
        if(thisDay[i]->getQuantityProcessed() > 0)
          incoming += thisDay[i]->getQuantityProcessed();
        else
          outgoing -= thisDay[i]->getQuantityProcessed();
        thisDay[i] = nullptr;
      }
    }
    
    bool popped;
    do
    {
      
      popped = false;
      unsigned i;
      for(i = 0; i < thisDay.size(); ++i)
      {
        if(!thisDay[i])
        {
          popped = true;
          break;
        }
      }
      if(popped)
      {
        thisDay.erase(thisDay.begin() + i);
      }
    }while(popped);
    
    ss << setw(10) << left << itmID;
    ss << setw(20) << left << itmName;
    ss << setw(10) << left << incoming;
    ss << setw(10) << left << outgoing;
    ss << fixed;
    ss << setw(15) << left << setprecision(2) << price;
    ss << setw(15) << left << setprecision(2) << (incoming - outgoing) * price;
    ss << setw(15) << left << incoming - outgoing;
    ss << std::endl;
  }
  std::cout << ss.str();
  return retVal;
}
std::vector<Transaction *>  Staff::collapseYear(std::string year)
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
  
  struct tm inYear = Common::getDate(year);
  
  for (auto it : tList->getFullList())
  {
    if(it->getDateAndTime().tm_mon == inYear.tm_mon &&
       it->getDateAndTime().tm_year == inYear.tm_year)
       {
         thisDay.push_back(it);
         retVal.push_back(it);
       }
  }
  
  if(!thisDay.empty())
  {
    ss << setw(10) << left << "ItemID";
    ss << setw(20) << left << "Item Name";
    ss << setw(10) << left << "IN";
    ss << setw(10) << left << "OUT";
    ss << setw(15) << left << "Amount";
    ss << setw(15) << left << "Total Amount";
    ss << setw(15) << left << "Quantity Remaining";
    ss << std::endl;
  }
  
  while(1)
  {
    if(thisDay.empty())
      break;
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
    std::string itmName(prime->getItemName());
    double price = prime->getTransactionPrice();
    int incoming = 0;
    int outgoing = 0;
    
    if(prime->getQuantityProcessed() > 0)
      incoming += prime->getQuantityProcessed();
    else
      outgoing -= prime->getQuantityProcessed();
    
    for(unsigned i = 0; i < thisDay.size(); ++i)
    {
      if(!prime->getStockItemID().compare(thisDay[i]->getStockItemID()))
      {
        if(thisDay[i]->getQuantityProcessed() > 0)
          incoming += thisDay[i]->getQuantityProcessed();
        else
          outgoing -= thisDay[i]->getQuantityProcessed();
        thisDay[i] = nullptr;
      }
    }
    
    bool popped;
    do
    {
      
      popped = false;
      unsigned i;
      for(i = 0; i < thisDay.size(); ++i)
      {
        if(!thisDay[i])
        {
          popped = true;
          break;
        }
      }
      if(popped)
      {
        thisDay.erase(thisDay.begin() + i);
      }
    }while(popped);
    
    ss << setw(10) << left << itmID;
    ss << setw(20) << left << itmName;
    ss << setw(10) << left << incoming;
    ss << setw(10) << left << outgoing;
    ss << fixed;
    ss << setw(15) << left << setprecision(2) << price;
    ss << setw(15) << left << setprecision(2) << (incoming - outgoing) * price;
    ss << setw(15) << left << incoming - outgoing;
    ss << std::endl;
  }
  std::cout << ss.str();
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

void Staff::readFile()
{
	cout << "Importing and processing data from file" << endl << endl;

	cout << "Please enter name of file you would like to import: ";

	string fileName;
	cin.ignore();
	getline (cin, fileName);

	ifstream infile;
	
	infile.open(fileName);

	if (!infile){
		cout << fileName << " does not exist." << endl << endl;
		infile.close();
	}
	else{
		cout << "Reading in file... " << endl << endl;

		string line;
		while (getline (infile, line)){
			processData(line);
		}
	
		// call function to generate remaining quantity for all transactions
		static_cast<WarehouseManager*>(WM)->generateRemainingQuantity();

		infile.close();

		cout << "Data imported and processed successfully!" << endl; 
	}

	Common::pressEnter();
}

void Staff::processData(string line){
	// if line is empty (in case of any writing error) don't do anything
	if (line.length() > 0){
		// use stringstream to break line into tokens
		istringstream iss(line);
		string token;	
		string delimiter = ":";
		vector<string> fields;
		size_t pos = 0;
		while ((pos = line.find(delimiter)) != string::npos){
			token = line.substr(0, pos);
			// store tokens into vector to access later
			fields.push_back(token);
			line.erase(0, pos + delimiter.length());
		}
		// last field not pushed back, so do that manually outside
		fields.push_back(line);
		// now extract the data and store them accordingly
		string itemID = fields[0];
		string itemName = fields[1];
		string itemCat = fields[2];
		string itemSubCat = fields[3];
		double itemPrice = stod(fields[4]);
		int stockMoved = stoi(fields[5]);
		tm date = Common::getDate(fields[6]);
		tm time = Common::getRandomTime();
		date = Common::setTimeToDate(date, time);
		string transID = static_cast<WarehouseManager*>(WM)->generateTransactionID();
		// now create item
		StockItem *newItem = new StockItem(itemID, itemName, itemCat, itemSubCat);
		newItem->updatePrice(itemPrice);
		// NOTE: REMEMBER THAT UNIT QUANTITY NOT UPDATED YET	
		// NOTE: for his data, we'll just leave the threshold to 0
		
		// store item to list 
		static_cast<WarehouseManager*>(WM)->addStockItem(newItem);
		// now create transaction 
		Transaction *newTransaction = new Transaction(itemID, transID, itemName, date, itemPrice, stockMoved);
		// store transaction to list
		static_cast<WarehouseManager*>(WM)->addTransaction(newTransaction);
	}
}

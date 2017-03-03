#include "Staff.h"
#include "WarehouseManager.h"

using namespace std;

void Staff::displayMenu()
{
  while(1)
  {
    std::cout << "Welcome to Warehouse Management Tool" << std::endl << std::endl;
    std::cout << "1)	Search stock item" << std::endl;
    std::cout << "2)	Process transaction" << std::endl;
    std::cout << "3)	View daily stock summary report" << std::endl;
    std::cout << "4)	View weekly stock summary report" << std::endl;
    std::cout << "5)	View monthly stock summary report" << std::endl;
    std::cout << "6)	View yearly stock summary report" << std::endl;
    std::cout << "7)	Quit" << std::endl;

    int choice;
    string input;
    std::cout << "Enter option: ";
    getline(cin, input);

    while (!Common::checkInRange(1, 7, input)){
	std::cout << "Invalid input. Please enter only 1 ~ 7: ";
	    getline(cin, input);
    }
    choice = stoi(input);
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
        doDailySummary();
        break;
      case 4:
        doWeeklySummary();
        break;
      case 5:
        doMonthlySummary();
        break;
      case 6:
        doYearlySummary();
        break;
      case 7:
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
			string itemID = stockItem->getName();
			string tranID = static_cast<WarehouseManager*>(WM)->generateTransactionID();
			double price = stockItem->getPrice();
			int quant = stoi(inputStockQuantity);
			Transaction *newT = new Transaction(itemID, tranID, date, price, quant);
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

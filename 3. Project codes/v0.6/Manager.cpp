#include "Manager.h"
#include <string>

using namespace std; 

void Manager::displayMenu()
{
  while(1)
  {
    std::cout << "Welcome to Warehouse Management Tool" << std::endl << std::endl;
    std::cout << "1)	Add a new stock item" << std::endl;
    std::cout << "2)	Remove existing stock item" << std::endl;
    std::cout << "3)	Edit existing stock item" << std::endl;
    std::cout << "4)	Search stock item" << std::endl;
    std::cout << "5)	Process transaction" << std::endl;
    std::cout << "6)	Edit transaction" << std::endl;
    std::cout << "7)	View stock summary report" << std::endl;
    std::cout << "8)	Import and process data from file" << std::endl;
    std::cout << "9)	Quit" << std::endl;

    int choice;
    //string input;
    std::cout << "Enter option: ";
    //getline(cin, input);
    std::cin >> choice;
    //choice = stoi(input);
    std::cout << std::endl;
    
    switch(choice)
    {
      case 1:
        doAddNewStock();
        break;
      case 2:
        doRemoveStock();
        break;
      case 3:
        doEditStock();
        break;
      case 4:
        doSearchStock();
        break;
      case 5:
        doProcessTransaction();
        break;
      case 6:
        doEditTransaction();
        break;
      case 7:
        summaryMenu();
        break;
      case 8:
        readFile();
        break;
      case 9:
        return;
        break;
      default:
        {
          std::cout << "Invalid input. Please enter only 1 ~ 9: ";
          break;
        }
    }
  }
}

void Manager::doAddNewStock()
{
  std::cout << "Manager::doAddNewStock()" << std::endl << std::endl;
  //this line to an example of how to connect to the warehouse manager
  static_cast<WarehouseManager*>(WM)->testFunction();
}

void Manager::doRemoveStock()
{
  std::cout << "Manager::doRemoveStock()" << std::endl << std::endl;
}

void Manager::doEditStock()
{
  std::cout << "Manager::doEditStock()" << std::endl << std::endl;
}

void Manager::doEditTransaction()
{
  std::cout << "Manager::doEditTransaction()" << std::endl << std::endl;
}

#if 0
void Manager::doSearchStock()
{
  std::cout << "Manager::doEditStock()" << std::endl << std::endl;
}

void Manager::doProcessTransaction()
{
  std::cout << "Manager::doProcessTransaction()" << std::endl << std::endl;
}

void Manager::doDailySummary()
{
  std::cout << "Manager::doDailySummary()" << std::endl << std::endl;
}

void Manager::doWeeklySummary()
{
  std::cout << "Manager::doWeeklySummary()" << std::endl << std::endl;
}

void Manager::doMonthlySummary()
{
  std::cout << "Manager::doMonthlySummary()" << std::endl << std::endl;
}

void Manager::doYearlySummary()
{
  std::cout << "Manager::doYearlySummary()" << std::endl << std::endl;
}
#endif



#include <iostream>

#include "Manager.h"

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
    std::cout << "7)	View daily stock summary report" << std::endl;
    std::cout << "8)	View weekly stock summary report" << std::endl;
    std::cout << "9)	View monthly stock summary report" << std::endl;
    std::cout << "10)	View yearly stock summary report" << std::endl;
    std::cout << "11)	Import and process data from file" << std::endl;
    std::cout << "12)	Quit" << std::endl;

    int choice;
    std::cout << "Enter option: ";
    std::cin >> choice;
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
        doDailySummary();
        break;
      case 8:
        doWeeklySummary();
        break;
      case 9:
        doMonthlySummary();
        break;
      case 10:
        doYearlySummary();
        break;
      case 11:
        readFile();
        break;
      case 12:
        return;
        break;
      
    }
  }
}

void Manager::doAddNewStock()
{
  std::cout << "Manager::doAddNewStock()" << std::endl << std::endl;
}

void Manager::doRemoveStock()
{
  std::cout << "Manager::doRemoveStock()" << std::endl << std::endl;
}

void Manager::doEditStock()
{
  std::cout << "Manager::doRemoveStock()" << std::endl << std::endl;
}

void Manager::doSearchStock()
{
  std::cout << "Manager::doEditStock()" << std::endl << std::endl;
}

void Manager::doProcessTransaction()
{
  std::cout << "Manager::doProcessTransaction()" << std::endl << std::endl;
}

void Manager::doEditTransaction()
{
  std::cout << "Manager::doEditTransaction()" << std::endl << std::endl;
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

void Manager::readFile()
{
  std::cout << "Manager::readFile()" << std::endl << std::endl;
}

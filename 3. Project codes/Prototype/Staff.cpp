#include <iostream>

#include "Staff.h"

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
  std::cout << "Staff::doProcessTransaction()" << std::endl << std::endl;
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


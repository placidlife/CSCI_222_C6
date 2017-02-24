#ifndef MANAGER_H
#define MANAGER_H

#include "Actor.h"

class Manager : public Actor
{
  public:
    Manager(){}
    ~Manager(){}
    void displayMenu();
    
  private:
    void doAddNewStock();
    void doRemoveStock();
    void doEditStock();
    void doSearchStock();
    void doProcessTransaction();
    void doEditTransaction();
    void doDailySummary();
    void doWeeklySummary();
    void doMonthlySummary();
    void doYearlySummary();
    //isnt this to be at the start?
    void readFile();
};

#endif
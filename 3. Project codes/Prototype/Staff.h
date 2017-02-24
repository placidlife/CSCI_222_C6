#ifndef STAFF_H
#define STAFF_H

#include "Actor.h"

class Staff : public Actor
{
  public:
    Staff(){}
    ~Staff(){}
    void displayMenu();
    
  private:
    void doSearchStock();
    void doProcessTransaction();
    void doEditTransaction();
    void doDailySummary();
    void doWeeklySummary();
    void doMonthlySummary();
    void doYearlySummary();
    
};

#endif
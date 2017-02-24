#include "WarehouseManager.h"

WarehouseManager::WarehouseManager(Actor * curStf)
{
  workingStaff = curStf;
}

void WarehouseManager::running()
{
  workingStaff->displayMenu();
}

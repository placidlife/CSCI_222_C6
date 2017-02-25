#include "Actor.h"
#include "WarehouseManager.h"

void Actor::setStaffID(std::string stfID)
{
  staffID = stfID;
}

void Actor::setStaffName(std::string stfName)
{
  staffName = stfName;
}

void Actor::setPassword(std::string stfPwd)
{
  password = stfPwd;
}

std::string Actor::getStaffID()
{
  return staffID;
}

void Actor::setWM(void * warehouse)
{
  WM = warehouse;
}

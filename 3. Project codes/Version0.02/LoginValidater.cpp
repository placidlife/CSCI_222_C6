#include "LoginValidater.h"

#include "Staff.h"
#include "Manager.h"

#include <fstream>
#include <functional>
#include <sstream>

Staff* LoginValidater::doLogin(bool& success)
{
  int usertype = 2;
  std::hash<std::string> str_hash;
  std::fstream myFile;
  std::string usrName;
  std::string pwd;
  while(usertype == 2)
  {
    bool upLoginCount = false;
    std::string acctToUpUser;
    std::string acctToUpPass;
    
    std::cout << "User ID: ";
    std::getline(std::cin, usrName);
    std::cout << std::endl;
    
    std::cout << "Password: ";
    std::getline(std::cin, pwd);
    std::cout << std::endl;
    
    myFile.open("userData.txt", std::fstream::in);
    if(myFile.is_open())
    {
      while(!myFile.eof())
      {
        std::stringstream tempss;
        std::string tempStr;
        
        std::string username;
        std::getline(myFile, username, ':');
        
        size_t password;
        std::getline(myFile, tempStr, ':');
        tempss << tempStr;
        tempss >> password;
        tempss.clear();
        
        int userType;
        std::getline(myFile, tempStr, ':');
        tempss << tempStr;
        tempss >> userType;
        tempss.clear();
        
        int loginCount;
        std::getline(myFile, tempStr, '\n');
        tempss << tempStr;
        tempss >> loginCount;
        tempss.clear();
        
        if(loginCount >= 3)
        {
          std::cout << "Account is currently locked" << std::endl;
          break;
        }
        
        if(!usrName.compare(username))
        {
          if(str_hash(pwd) == password)
          {
            usertype = userType;
            break;            
          }
          std::cout << "Invalid username or password" << std::endl;
          acctToUpUser = username;
          tempss << password;
          tempss >> tempStr;
          tempss.clear();
          acctToUpPass = tempStr;
          upLoginCount = true;
          break;
        }
        else if(usrName.compare(username))
        {
          std::cout << "Invalid username or password" << std::endl;
          continue;
        }
      }
    }
    myFile.close();
    if(upLoginCount)
      increaseLoginCount(acctToUpUser, acctToUpPass);
  }
#if 0
  std::cout << "User Type: ";
  std::cin >> userType;
  std::cout << std::endl;
#endif
  Staff * curStf;
  if(usertype == 1)
  {
    curStf = new Manager();
  }
  else if(usertype == 0)
  {
    curStf = new Staff();
  }
  curStf->setStaffID(usrName);
  curStf->setPassword(pwd);
  success = true;
  return curStf;
}

void LoginValidater::increaseLoginCount(std::string uName, std::string pWord)
{
  std::fstream myFile;
  std::stringstream ss;
  
  myFile.open("userData.txt", std::fstream::in);
  if(myFile.is_open())
  {
    while(!myFile.eof())
    {
      
      std::string username;
      std::string password;
      std::string userType;
      std::string loginCount;
      std::getline(myFile, username, ':');
      std::getline(myFile, password, ':');
      std::getline(myFile, userType, ':');
      std::getline(myFile, loginCount, '\n');
      
      if(username.empty())
        break;
      
      std::stringstream tempss;
      if(!username.compare(uName) && !password.compare(pWord))
      {
        int i;
        tempss << loginCount;
        tempss >> i;
        tempss.clear();
        ++i;
        tempss << i;
        tempss >> loginCount;
      }
      
      ss << username << ":";
      ss << password << ":";
      ss << userType << ":";
      ss << loginCount << "\n";
    }
  }

  myFile.close();
  
  myFile.open("userData.txt", std::fstream::out | std::fstream::trunc);
  
  if(myFile.is_open())
    myFile << ss.str();
  
  myFile.close();
}
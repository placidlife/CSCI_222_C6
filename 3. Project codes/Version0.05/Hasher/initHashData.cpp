// this program is to take in a file formated as
// [username]:[password]:[user type]:[login attempts]
// and replaces the passwords with a hased version


#include <string>
#include <iostream>
#include <fstream>
#include <functional>
#include <sstream>

int main()
{
  std::hash<std::string> str_hash;
  std::string filename;
  std::getline(std::cin, filename);
  //std::ifstream myFile(filename);
  
  std::fstream myFile;
  std::stringstream ss;
  
  myFile.open(filename, std::fstream::in);
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
      ss << username << ":";
      ss << str_hash(password) << ":";
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
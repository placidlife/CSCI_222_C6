#ifndef COMMON_H
#define COMMON_H

#include <ctime>
#include <sstream> // for stringstream
#include <vector>
#include <stdlib.h> // rand
#include <iostream>
#include <string>

using namespace std;

class Common{
	public:
		static void pressEnter();
		// get string input and check if input is positive int
		static int checkPositiveInt(string input);
		// get string input and check if input is positive double
		static double checkPositiveCurrency(string input);
		
		// get string date and time, and check if it's a past date
		static bool checkValidDateTime1(string date, string time);
		static bool checkValidDateTime2(string dateAndTime);

		// get a random time of tm datatype
		static tm getRandomTime();
		// get current time of tm datatype
		static tm getCurrentTime();
		// a function to get user to input only "Y/N" with error checking
		static bool getInputYN(string message);

		// convert date string to tm datatype
		static tm getDate(string input);
		// convert time string to tm datatype
		static tm getTime(string input);
		// combine time tm to date tm
		static tm setTimeToDate(tm date, tm time);

		// convert string input of date and time into tm datatype
		// for user input
		static tm getDateAndTime(string input);
		// for reading in data file's format
		static tm getDateAndTime2(string input);
		 
		// convert tm datatype to string
		// nice version (not for data file)
		static string getDateString(tm date);
		// another version (for data file)
		static string getDateStringForFile(tm date);

	private: 
		// convert month string name to int
		static int convertMonthStrToInt(string input);
		// convert month int to string name
		static string convertMonthIntToString(int i);
		// convert year string (YY) to int (YYYY)
		static int convertYYtoYYYY (string input);
		

};

#endif

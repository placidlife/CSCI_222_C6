#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class Common{
	public:
		void pressEnter();
		// get string input and check if input is positive int
		int checkPositiveInt(string input);
		// get string input and check if input is positive double
		double checkPositiveCurrency(string input);
		// get string date and time, and check if it's a past date
		bool checkValidDateTime(string date, string time);
		// convert date string to tm datatype
		tm getDate(string input);
		// convert time string to tm datatype
		tm getTime(string input);
		// get a random time of tm datatype
		tm getRandomTime();
		// combine time tm to date tm
		tm setTimeToDate(tm date, tm time); 

	private: 
		// convert month string name to int
		int convertMonthStrToInt(string input);
		// convert year string (YY) to int (YYYY)
		int convertYYtoYYYY (string input);

};

#endif

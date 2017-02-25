#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class Common{
	public:
		void pressEnter();
		int checkPositiveInt(string input);
		double checkPositiveCurrency(string input);
		bool checkValidDateTime(string input);
		time_t getDate(string input);
		time_t getRandomTime();
};

#endif

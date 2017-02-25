#include "common.h"

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

void Common::pressEnter(){
	cin.ignore();
	cout << "Press Enter to continue...";
	cin.getline();
}

int Common::checkPositiveInt(string input){
	// TODO
}

double Common::checkPositiveCurrency(string input){
	// TODO
}

bool Common::checkValidDateTime(string input){
	// TODO
}

tm Common::getDate(string input){
	// use stringstream to break line into tokens
	istringstream iss (inpue);
	string token;
	vector<string> fields;
	while (getline(iss, token, "-")){
		// store tokens into vector to access later
		fields.push_back(token);
	}
	// extract data to store into dates
	int day = fields[0];
	int month = convertMonthStrToInt(fields[1]);
	int year = convertYYtoYYYY(fields[2]);
	// convert extracted data into time datatype
	struct tm date = {};
	date.tm_year = year - 1900;
	date.tm_mon = month -1;
	date.tm_mday = day;
	return date;
}

time_t Common::getRandomTime(){
	// TODO
}


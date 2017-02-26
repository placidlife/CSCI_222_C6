#include "common.h"

#include <iostream>
#include <ctime>
#include <string>
#include <stdlib.h> // rand

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

bool Common::checkValidDateTime1(string dateStr, string timeStr){
	// convert string input into tm struct data type
	struct tm date = getDate(dateStr);
	struct tm time = getTime(timeStr);
	date = setTimeToDate(date, time);
	time_t now;
	time(&now);
	// if the current date is future from now
	// return false
	if (difftime(now, mktime(&date) < 0){
		return false;
	}else{
		return true;
	}
}

bool Common::checkValidDateTime2(string dateAndTimeStr){
	// convert string input into tm struct data type
	struct tm dateAndTime = getDateAndTime(dateAndTimeStr);
	time_t now;
	time(&now);
	// if the current date is future from now
	// return false
	if (difftime(now, mktime(&dateAndTime) < 0){
		return false;
	}else{
		return true;
	}
}

tm Common::getRandomTime(){
	struct tm time;
	srand(time(NULL));
	time.tm_hour = rand()%24;
	time.tm_min = rand()%60;
	time.tm_sec = rand()%60;
	return time;
}

tm Common::getCurrentTime(){
	time_t now;
	time(&now);
	struct tm *timeNow = localtime(&now);
	return *timeNow;
}

// combine the time tm to the date tm 
tm Common::setTimeToDate(tm date, tm time){
	date.tm_hour = time.tm_hour;
	date.tm_min = time.tm_min;
	date.tm_sec = time.tm_sec;
}

tm Common::getDate(string input){
	// use stringstream to break line into tokens
	istringstream iss (input);
	string token;
	vector<string> fields;
	while (getline(iss, token, "-")){
		// store tokens into vector to access later
		fields.push_back(token);
	}
	// extract data to store into dates
	int day = stoi(fields[0]);
	int month = convertMonthStrToInt(fields[1]);
	int year = convertYYtoYYYY(fields[2]);
	// convert extracted data into time datatype
	struct tm date = {};
	date.tm_year = year - 1900;
	date.tm_mon = month -1;
	date.tm_mday = day;
	return date;
}

tm Common::getTime(string input){
	// use stringstream to break line into tokens
	istringstream iss (input);
	string token;
	vector<string> fields;
	while (getline(iss, token, ".")){
		// store tokens into vector to access later
		fields.push_back(token);
	}
	// extract data to store into dates
	int hour = stoi(fields[0]);
	int min = stoi(fields[1]);
	int sec = stoi(fields[2]);
	// convert extracted data into time datatype
	struct tm time = {};
	time.tm_hour = hour;
	time.tm_min = min;
	time.tm_sec = sec;
	return time;
}

tm Common::getDateAndTime(string input){
	// use stringstream to break line into tokens
	istringstream iss (input);
	string token;
	vector<string> fields;
	// break string into tokens using multiple delimeters
	while (getline(iss, input)){
		size_t prev = 0, pos;
		while ((pos = input.find_first_of("- :", prev)) != string::npos){
			if (pos > prev)
				fields.push_back(input.substr(prev, pos-prev));
			prev = pos+1;
		}
		if (prev < input.length())
			fields.push_back(input.substr(prev, string::npos));
	}

	// extract data to store into dates
	int year = stoi(fields[0]);
	int month = stoi(fields[1]);
	int day = stoi(fields[2]);
	int hour = stoi(fields[3]);
	int min = stoi(fields[4]);

	// convert extracted data into time datatype
	struct tm time = {};
	time.tm_year = year;
	time.tm_month = month;
	time.tm_day = day;
	time.tm_hour = hour;
	time.tm_min = min;
	return time;
}

int Common::convertMonthStrToInt(string input){
	if (strcmp(input, "Jan") == 0 || strcmp(input, "JAN") == 0){
		return 0;
	}
	if (strcmp(input, "Feb") == 0 || strcmp(input, "FEB") == 0){
		return 1;
	}
	if (strcmp(input, "Mar") == 0 || strcmp(input, "MAR") == 0){
		return 2;
	}
	if (strcmp(input, "Apr") == 0 || strcmp(input, "APR") == 0){
		return 3;
	}
	if (strcmp(input, "May") == 0 || strcmp(input, "MAY") == 0){
		return 4;
	}
	if (strcmp(input, "Jun") == 0 || strcmp(input, "JUN") == 0){
		return 5;
	}
	if (strcmp(input, "Jul") == 0 || strcmp(input, "JUL") == 0){
		return 6;
	}
	if (strcmp(input, "Aug") == 0 || strcmp(input, "AUG") == 0){
		return 7;
	}
	if (strcmp(input, "Sep") == 0 || strcmp(input, "SEP") == 0){
		return 8;
	}
	if (strcmp(input, "Oct") == 0 || strcmp(input, "OCT") == 0){
		return 9;
	}
	if (strcmp(input, "Nov") == 0 || strcmp(input, "NOV") == 0){
		return 10;
	}
	if (strcmp(input, "Dec") == 0 || strcmp(input, "DEC") == 0){
		return 11;
	}
	return -1;
}

int Common::converYYtoYYYY(string input){
	int year = stoi(input);
	// if year is already in YYYY format, just return it as it is
	if (year > 1000){
		return year;
	}
	// a little lecheck, but I'm going to get date now to find current year
	// to use as the line to draw between 1900s and 2000s
	time_t now;
	time(&now);
	struct tm *timeNow = localtime(&now);
	int yearNow = 1900 + timeNow->tm_year;
	// get last two digit of current year
	yearNow %= 100;
	// use that as the cut off for 1900s 
	if (year > yearNow){
		return year + 1900;
	}
	else{
		return year + 2000;
	}
}	


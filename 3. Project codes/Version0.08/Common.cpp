#include "Common.h"

using namespace std;

void Common::pressEnter(){
	cout << "Press Enter to continue...";
	string throwAway;
	getline(cin, throwAway);
}

bool Common::checkInRange(int a, int b, string input){
	if (!checkPositiveInt(input))
		return false;
	int c = stoi(input);
	if (c >= a && c <= b)
		return true;
	else
		return false;
}

int Common::checkPositiveInt(string input){
	// check if int
	if (!input.empty() && input.find_first_not_of("0123456789") == string::npos){
		int i = stoi(input);
		return i;
	}
	return 0;
}

double Common::checkPositiveCurrency(string input){
	// check if number
	if (!input.empty() && input.find_first_not_of("0123456789.") == string::npos){
		double i = stod(input);
		return i;
	}
	return 0;
}

// function that gets user to input only "Y/N" with error checking
bool Common::getInputYN(string message){
	string input;
	cout << message;
	while (1){
		getline(cin, input);
		if (input.size() > 1){
			cout << "Please enter only 'Y' or 'N': ";
		}	
		else if (input == "Y" || input == "y"){
			return 1;
		}else if (input == "N" || input == "n"){
			return 0;
		}else{
			cout << "Please enter only 'Y' or 'N': ";
		}
	}
	return 0; // won't come here, just need for compilation
}

// get input and check if valid date and time format
bool Common::checkValidDateTime(string dateStr){
	// check if input format is valid
	if (!checkValidDateTimeFormat(dateStr)){
		cout << "Please enter a valid format: (YYYY-MM-DD HH:MM) : ";
		return false;
	}
	// convert string input into tm struct data type
	struct tm date = getDate2(dateStr);
	time_t timeNow;
	time(&timeNow);
	// if the current date is future from now
	// return false
	if (difftime(timeNow, mktime(&date) < 0)){
		cout << "Please enter a past date: ";
		return false;
	}else{
		return true;
	}
}

// check if string is of correct format
bool Common::checkValidDateTimeFormat(string input){
	// TODO 
	return true;
}

bool Common::checkValidDateTime1(string dateStr, string timeStr){
	// convert string input into tm struct data type
	struct tm date = getDate(dateStr);
	struct tm timee = getTime(timeStr);
	date = setTimeToDate(date, timee);
	time_t timeNow;
	time(&timeNow);
	// if the current date is future from now
	// return false
	if (difftime(timeNow, mktime(&date) < 0)){
		return false;
	}else{
		return true;
	}
}

bool Common::checkValidDateTime2(string dateAndTimeStr){
	// convert string input into tm struct data type
	struct tm dateAndTime = getDateAndTime(dateAndTimeStr);
	time_t timeNow;
	time(&timeNow);
	// if the current date is future from now
	// return false
	if (difftime(timeNow, mktime(&dateAndTime)) < 0){
		return false;
	}else{
		return true;
	}
}

tm Common::getRandomTime(){
	struct tm myTime;
	srand(time(NULL));
	myTime.tm_hour = rand()%24;
	myTime.tm_min = rand()%60;
	myTime.tm_sec = rand()%60;
	return myTime;
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
	return date;
}

// convert date string to tm datatype
// for format of DD-MON-YY 
tm Common::getDate(string input){
	// use stringstream to break line into tokens
	istringstream iss (input);
	string token;
	string delimiter = "-";
	vector<string> fields;
	size_t pos = 0;
	while ((pos = input.find(delimiter)) != string::npos){
		token = input.substr(0, pos);
		// store tokens into vector to access later
		fields.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	fields.push_back(input);
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

// convert date string to tm datatype
// for format of YYYY-MM-DD HH:MM
tm Common::getDate2(string input){
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
	int mins = stoi(fields[4]);
	// convert extracted data into time datatype
	struct tm date = {};
	date.tm_year = year - 1900;
	date.tm_mon = month -1;
	date.tm_mday = day;
	date.tm_hour = hour;
	date.tm_min = mins;
	return date;
}

tm Common::getTime(string input){
	// use stringstream to break line into tokens
	istringstream iss (input);
	string token;
	string delimiter = ".";
	vector<string> fields;
	size_t pos = 0;
	while ((pos = input.find(delimiter)) != string::npos){
		token = input.substr(0, pos);
		// store tokens into vector to access later
		fields.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	fields.push_back(input);
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

// convert string input of date and time into tm datatype
// for user input
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
	time.tm_mon = month;
	time.tm_mday = day;
	time.tm_hour = hour;
	time.tm_min = min;
	return time;
}

// convert string input of date and time into tm datatype
// for data file 
tm Common::getDateAndTime2(string input){
	// use stringstream to break line into tokens
	istringstream iss (input);
	string token;
	string delimiter = "-";
	vector<string> fields;
	size_t pos = 0;
	while ((pos = input.find(delimiter)) != string::npos){
		token = input.substr(0, pos);
		// store tokens into vector to access later
		fields.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	fields.push_back(input);
	// extract data to store into dates
	int day = stoi(fields[0]);
	// convert month string to int and store
	int month = convertMonthStrToInt(fields[1]);
	// convert year string to int and get full year to store
	int year = convertYYtoYYYY(fields[2]);
	// convert time (conjoined string) into int and break into hour and min
	int time = stoi(fields[3]); 
	int min = time % 100; // get last two digit
	int hour = time / 100; // get first two digit

	// convert extracted data into time datatype
	struct tm timet = {};
	timet.tm_year = year;
	timet.tm_mon = month;
	timet.tm_mday = day;
	timet.tm_hour = hour;
	timet.tm_min = min;
	return timet;
}


string Common::getDateString(tm date){
	stringstream ss;
	ss << date.tm_year << "-" 
		<< date.tm_mon << "-"
		<< date.tm_mday << " "
		<< date.tm_hour << ":"
		<< date.tm_min;
	return ss.str();
}

string Common::getDateStringForFile(tm date){
	stringstream ss;
	// ss day
	ss << date.tm_mday << "-";
	// convert month to string and ss
	string month = convertMonthIntToString(date.tm_mon);
	ss << month << "-";
	// convert year to int, and get last two digits and ss
	int year = date.tm_year;
	year %= 100; 
	ss << year << "-";
	// get hour and mins into one int and ss
	int time = date.tm_hour * 100 + date.tm_min;
	ss << time;
	return ss.str();
}

string Common::convertMonthIntToString(int i){
	if (i == 0)
		return "Jan";
	if (i == 1)
		return "Feb";
	if (i == 2)
		return "Mar";
	if (i == 3)
		return "Apr";
	if (i == 4)
		return "May";
	if (i == 5)
		return "Jun";
	if (i == 6)
		return "Jul";
	if (i == 7)
		return "Aug";
	if (i == 8)
		return "Sep";
	if (i == 9)
		return "Oct";
	if (i == 10)
		return "Nov";
	if (i == 11)
		return "Dec";
	else
		return "error";
}

int Common::convertMonthStrToInt(string input){
	if (input == "Jan" || input == "JAN"){
		return 0;
	}
	if (input == "Feb" || input == "FEB"){
		return 1;
	}
	if (input == "Mar" || input == "MAR"){
		return 2;
	}
	if (input == "Apr" || input == "APR"){
		return 3;
	}
	if (input == "May" || input == "MAY"){
		return 4;
	}
	if (input == "Jun" || input == "JUN"){
		return 5;
	}
	if (input == "Jul" || input == "JUL"){
		return 6;
	}
	if (input == "Aug" || input == "AUG"){
		return 7;
	}
	if (input == "Sep" || input == "SEP"){
		return 8;
	}
	if (input == "Oct" || input == "OCT"){
		return 9;
	}
	if (input == "Nov" || input == "NOV"){
		return 10;
	}
	if (input == "Dec" || input == "DEC"){
		return 11;
	}
	return -1;
}

int Common::convertYYtoYYYY(string input){
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


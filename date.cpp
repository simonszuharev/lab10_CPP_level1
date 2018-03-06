#include "date.hpp"

// Default constructor
Date::Date() {
	setDefaultDate();
}

// Alternate constructor
Date::Date(int m, int d, int y) {
	if(setDate(m, d, y) == false)
		setDefaultDate();
}

//Date constructor
Date::Date(int doy, int y){
    if(setDate(doy, y) == false){
		setDefaultDate();}
}

// Get functions
int Date::getMonth() {return month;}
int Date::getDay() {return day;}
int Date::getYear() {return year;}
int Date::getDayOfYear () {return dayOfYear;}

// Set functions
bool Date::setDate(int m, int d, int y) {
	bool isValid = isValidDate(m, d, y);
	if(isValid == true) {
		month = m; day = d; year = y;
	}
	return isValid;
}

bool Date::setDate (int doy, int y){
    int m = 0;
    dayOfYear = doy;
    const int daysForLeap[] = {31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};
    const int daysForYear[] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

    bool isValid = isValidDateOfYear(doy, y);
	if(isValid == true) {
		year = y;
		if(isLeapYear(y)==true){
		while(daysForLeap[m] < doy){m++;}
        month = m+1;
        day = (doy-daysForLeap[month-2]);
        }
        if(isLeapYear(y) == false){
            while(daysForYear[m] < doy){m++;}
        month = m+1;
        day = (doy-daysForYear[month-2]);
        }
        }
	return isValid;
}

// Date to mm/dd/yyyy string
string Date::toString() {
	return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
}

string Date::toLongString(){
    return DEFAULT_MONTHS[month-1]+ " " + to_string(day) + ", " + to_string(year);
}

// Set default date
void Date::setDefaultDate() {
	month = DEFAULT_MONTH;
	day = DEFAULT_DAY;
	year = DEFAULT_YEAR;
}

// Date validation
bool Date::isValidDate(int m, int d, int y) {
	const int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	bool result = false;
	if(m > 0 && m < 13) {
		if(d > 0 && y > 0) {
			int maxDays = daysInMonth[m - 1];
			if(m == 2 && isLeapYear(y) == true) maxDays++;
			if(d <= maxDays)
				result = true;
		}
	}
	return result;
}

bool Date::isValidDateOfYear(int doy, int y){
    bool result = false;
    if(isLeapYear(y) == true && doy>0 && doy <=366){result = true;}
    if(isLeapYear(y) == false && doy>0 && doy <=365){result = true;}
    return result;
}

// Leap year check for date validation
bool Date::isLeapYear(int y) {
	if(y % 400 == 0)		// if mod 400 then is leap
		return true;
	else if (y % 100 == 0)	// if mod 100 then not leap
		return false;
	else if (y % 4 == 0)	// if mod 4 then is leap
		return true;
	else
		return false;		// otherwise, not leap
}


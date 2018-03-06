#ifndef DATE_H
#define DATE_H

#include <string>
#include <ctime>

using namespace std;

class Date {
	private:
		// Constants used by class
		const int DEFAULT_MONTH = 1;
		const int DEFAULT_DAY = 1;
		const int DEFAULT_YEAR = 1970;
		const string DEFAULT_MONTHS[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
		// Member variables
		int month, day, year, dayOfYear;
		// Member functions
		void setDefaultDate();				// Set default date
		bool isValidDate(int m, int d, int y);	// Date validation
		bool isValidDateOfYear(int doy, int y);
		bool isLeapYear(int y);				// Leap year check
	public:
		// Constructors
		Date();								// Default constructor
		Date(int m, int d, int y);			// Alternate constructor
		Date(int doy, int y);				// Alternate constructor (***)
		// Member functions
		int getMonth();						// Get month
		int getDay();						// Get day
		int getYear();						// Get year
		int getDayOfYear ();
		bool setDate(int m, int d, int y);	// Set date
		bool setDate (int doy, int y);
		string toString();					// Date to mm/dd/yyyy
		string toLongString();
};
#endif

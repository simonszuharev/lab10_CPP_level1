#include <iostream>
#include "date.hpp"

using namespace std;

/*This laboratory exercise extends the functionality of the Date class developed in
Exam 2 by allowing a Date object to be created using day-of-year and by providing an additional date formatting option.
 The existing functionality in the Date class is to be retained and not modified in any way.
 Add the following public member functions to the Date class:

• An alternate constructor taking two parameters, day-of-year and year, that allows the date to be set when the object is created.
 If the date passed is invalid, set the date to January 1, 1970.  The constructor prototype is:

Date (int doy, int y)

• A function taking two parameters, day-of-year and year, that allows a date to be set after a Date object is created.
 If the date passed is invalid, do not modify the date and return false. Otherwise, set the date and return true. The function prototype is:

bool setDate (int doy, int y)

• A function that returns the day-of-year.  The function prototype is:

int getDayOfYear ()

• A function that returns a formatted date string in the form: month dd, yyyy (for example May 3, 2017). The function prototype is:

string toLongString ()

Start with the zipped Date class definition (date.hpp) and implementation (date.cpp) files found in the Review folder.
  Submit your solution as a zip file containing your revised date.hpp and date.cpp files.
  Name the file lab10_annnnnnn.zip where annnnnnn is your ACC student identification number.8?*/

int main()
{

    Date Date1(61, 2000);
    Date Date2(60, 2001);
    Date DateDefault;
    cout << Date1.toLongString() << endl;
    cout << Date2.toLongString() << endl;
    cout << Date1.getDayOfYear() << endl;
    cout << Date1.toString() << endl;
    cout << DateDefault.toLongString() << endl;
    cout << "Hello world!" << endl;
    return 0;
}

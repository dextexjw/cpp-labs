#include <iostream>
using namespace std;

int minutesSinceStartOfMonth(int days, int hours, int minutes)
{
    return days * 24 * 60 + hours * 60 + minutes;
}

int main()
{
    int days1, hours1, minutes1;
    int days2, hours2, minutes2;

    cout << "Enter first time (days hours minutes): ";
    cin >> days1 >> hours1 >> minutes1;

    cout << "Enter second time (days hours minutes): ";
    cin >> days2 >> hours2 >> minutes2;

    int firstTime{minutesSinceStartOfMonth(days1, hours1, minutes1)};
    int secondTime{minutesSinceStartOfMonth(days2, hours2, minutes2)};

    int difference{secondTime - firstTime};

    if (difference < 0)
    {
        difference = -difference;
    }

    cout << "The amount of time between the two times is "
         << difference << " minutes." << endl;

    return 0;
}

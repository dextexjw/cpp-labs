#include <iostream>
using namespace std;

int minutesSinceStartOfMonth(int days, int hours, int minutes)
{
    // Each full day has 24 hours, and each hour has 60 minutes.
    return days * 24 * 60 + hours * 60 + minutes;
}

int main()
{
    int firstDays;
    int firstHours;
    int firstMinutes;

    int secondDays;
    int secondHours;
    int secondMinutes;

    cout << "Enter the first time." << endl;
    cout << "Days: ";
    cin >> firstDays;
    cout << "Hours: ";
    cin >> firstHours;
    cout << "Minutes: ";
    cin >> firstMinutes;

    cout << "\nEnter the second time." << endl;
    cout << "Days: ";
    cin >> secondDays;
    cout << "Hours: ";
    cin >> secondHours;
    cout << "Minutes: ";
    cin >> secondMinutes;

    int firstTotalMinutes{
        minutesSinceStartOfMonth(firstDays, firstHours, firstMinutes)};

    int secondTotalMinutes{
        minutesSinceStartOfMonth(secondDays, secondHours, secondMinutes)};

    int difference{secondTotalMinutes - firstTotalMinutes};

    if (difference < 0)
    {
        difference = -difference;
    }

    cout << "The amount of time between the two times is "
         << difference << " minutes." << endl;

    return 0;
}

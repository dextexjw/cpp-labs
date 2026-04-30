#include <iostream>
#include <string>
using namespace std;

bool validDate(int month, int day) {
    int daysInMonth[12] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (month < 1 || month > 12) {
        return false;
    }

    if (day < 1 || day > daysInMonth[month - 1]) {
        return false;
    }

    return true;
}

string getSign(int month, int day) {
    string signs[12] = {
        "Capricorn", "Aquarius", "Pisces", "Aries",
        "Taurus", "Gemini", "Cancer", "Leo",
        "Virgo", "Libra", "Scorpio", "Sagittarius"
    };

    int startDay[12] = {
        20, 19, 21, 20,
        21, 22, 23, 23,
        23, 23, 22, 22
    };

    /*
       If the day is before the start day of this month's new sign,
       then the sign is the previous month's sign.
    */
    if (day < startDay[month - 1]) {
        month--;

        if (month == 0) {
            month = 12;
        }
    }

    return signs[month - 1];
}

void printCompatibleSigns(string sign) {
    string groups[4][3] = {
        {"Aries",  "Leo",     "Sagittarius"},  // Fire
        {"Taurus", "Virgo",   "Capricorn"},    // Earth
        {"Gemini", "Libra",   "Aquarius"},     // Air
        {"Cancer", "Scorpio", "Pisces"}        // Water
    };

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 3; col++) {
            if (groups[row][col] == sign) {

                // cout << "Most compatible with: ";

                for (const string& s : groups[row]) {
                    if (s != sign) {
                        cout << s << ", ";
                    }
                }

                cout << endl;
                return;
            }
        }
    }
}

int main() {
    int month, day;

    cout << "Enter birthdate: ";
    cin >> month >> day;

    if (!validDate(month, day)) {
        cout << "Invalid birthdate" << endl;
        return 0;
    }

    string sign = getSign(month, day);

    cout << "Sign is: " << sign << endl;

    cout << "Most compatible with: ";
    printCompatibleSigns(sign);
    cout << endl;

    return 0;
}
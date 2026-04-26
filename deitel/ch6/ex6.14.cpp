#include <cmath>
#include <iostream>

using namespace std;

double roundToInteger(double number) {
    return floor(number + 0.5);
}

double roundToTenths(double number) {
    return floor(number * 10 + 0.5) / 10;
}

double roundToHundredths(double number) {
    return floor(number * 100 + 0.5) / 100;
}

double roundToThousandths(double number) {
    return floor(number * 1000 + 0.5) / 1000;
}

int main() {
    double number;

    cout << "Enter numbers to round, or enter EOF to end input:\n";

    while (cin >> number) {
        cout << "\nOriginal number: " << number << '\n';
        cout << "Rounded to integer: " << roundToInteger(number) << '\n';
        cout << "Rounded to tenths: " << roundToTenths(number) << '\n';
        cout << "Rounded to hundredths: " << roundToHundredths(number) << '\n';
        cout << "Rounded to thousandths: " << roundToThousandths(number) << "\n\n";

        cout << "Enter another number, or enter EOF to end input:\n";
    }

    return 0;
}

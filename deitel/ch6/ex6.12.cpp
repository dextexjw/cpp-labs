#include <iostream>

using namespace std;

float calculateCharges(float hrs) {
    float amount;
    if (hrs <= 3.0f) {
        amount = 20.0f;
    } else if (hrs >= 9.0f) {
        amount = 50.0f;
    } else {
        amount = ceil(hrs - 3.0f) * 5.0f + 20.0f;
    }
    return amount;
}

int main() {

    float a{1.0f}, b{3.0f}, c{7.5f}, d{9.5f};

    cout << "Hours: " << a << "\tCharge: $" << calculateCharges(a) << endl;
    cout << "Hours: " << b << "\tCharge: $" << calculateCharges(b) << endl;
    cout << "Hours: " << c << "\tCharge: $" << calculateCharges(c) << endl;
    cout << "Hours: " << d << "\tCharge: $" << calculateCharges(d) << endl;

    return 0;
}
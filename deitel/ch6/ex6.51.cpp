#include <iostream>
using namespace std;

template <typename T>
T minimum(T value1, T value2) {
    return value1 < value2 ? value1 : value2;
}

int main() {
    int integer1{25};
    int integer2{12};
    char character1{'G'};
    char character2{'B'};
    double double1{3.14};
    double double2{2.71};

    cout << "Minimum integer: " << minimum(integer1, integer2) << endl;
    cout << "Minimum character: " << minimum(character1, character2) << endl;
    cout << "Minimum floating-point number: " << minimum(double1, double2)
         << endl;

    return 0;
}

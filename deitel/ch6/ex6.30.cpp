#include <iostream>
using namespace std;

int reverseDigits(int number) {
    int reversed{0};

    while (number > 0) {
        reversed = reversed * 10 + number % 10;
        number /= 10;
    }

    return reversed;
}

int main() {
    cout << "7631 reversed is " << reverseDigits(7631) << endl;
    cout << "12345 reversed is " << reverseDigits(12345) << endl;
    cout << "1000 reversed is " << reverseDigits(1000) << endl;
    cout << "7 reversed is " << reverseDigits(7) << endl;

    return 0;
}

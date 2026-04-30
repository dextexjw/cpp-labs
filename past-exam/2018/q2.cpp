#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string number;

    cout << "Enter a positive integer: ";
    cin >> number;

    int n = number.length();
    vector<int> digits(n);

    // Convert characters to integer digits
    for (int i = 0; i < n; i++) {
        digits[i] = number[i] - '0';
    }

    bool selfDescribing = true;

    for (int i = 0; i < n; i++) {
        int count = 0;

        // Count how many times digit i appears
        for (int j = 0; j < n; j++) {
            if (digits[j] == i) {
                count++;
            }
        }

        if (digits[i] != count) {
            selfDescribing = false;
            break;
        }
    }

    if (selfDescribing) {
        cout << number << " is self-describing." << endl;
    } else {
        cout << number << " is not self-describing." << endl;
    }

    return 0;
}
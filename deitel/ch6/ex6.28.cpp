#include <iostream>
using namespace std;

int isDudeney(int number) {
    int addition{0}, cube{1};
    int x{number};

    while (x > 0) {
      // cout << number % 10 << " ";
      addition += x % 10;
      x = x / 10;
    }

    // cout << "Sum of the digits is: " << addition;
    cube = addition * addition * addition;

    if (cube == number)
      return 1;
    else
      return 0;
}

int main() {

    cout << "Check 512: " << isDudeney(512) << endl;
    cout << "Check 1729: " << isDudeney(189) << endl;
    cout << "Check 4913: " << isDudeney(4913) << endl;
    cout << "Check 5832: " << isDudeney(5555) << endl;

    return 0;
}

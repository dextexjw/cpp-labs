#include <iostream>
#include "Complex.h"
using namespace std;

int main() {
    Complex c1(3, 4);
    Complex c2(1, -2);

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex product = c1 * c2;

    cout << "c1 + c2 = " << sum << endl;
    cout << "c1 - c2 = " << diff << endl;
    cout << "c1 * c2 = " << product << endl;

    c1.setReal(5);
    c1.setImag(6);
    cout << "Updated c1 = " << c1 << endl;
    cout << "c1 real part: " << c1.getReal() << endl;
    cout << "c1 imaginary part: " << c1.getImag() << endl;

    return 0;
}

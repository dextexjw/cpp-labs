#include <iostream>
using namespace std;

int pow(unsigned int base, unsigned int exponent) {
    if (exponent == 0) return 1;
    return base * pow(base, exponent - 1);
}

int main()
{
    cout << pow(2, 3) << endl;
    return 0;
}
#include <iostream>
using namespace std;

void breakdown(int x)
{
    int divisor{1};

    while (x / divisor >= 10)
    {
        divisor *= 10;
    }

    while (divisor > 0)
    {
        cout << x / divisor << " ";
        x = x % divisor;
        divisor /= 10;
    }
}

void trash()
{
    int a{11}, b{2}, c{3};

    int result{a % b};
    cout << a << " % " << b << ": " << result << endl;

    cout << "interger part of the quotient" << endl;
    cout << a << " / " << b << ": " << a / b << endl;

    cout << a << " % " << c << ": " << int(a % c) << endl;
    cout << a << " % " << c << ": " << a % c << " without int casting" << endl;
}

int main()
{
    breakdown(12345678);
    return 0;
}

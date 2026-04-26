#include <iostream>
using namespace std;

int isFactor (int a, int b) {
    if ( a% b == 0) return true;
    else return false;
}

int main()
{
    cout << isFactor(10,5) << endl;
    cout << isFactor(10,3) << endl;
    return 0;
}
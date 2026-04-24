#include <iostream>
using namespace std;

int main() {
    int x{0}, y{1};
    cout << x << endl;
    cout << y << endl;

    int round{20};

    while (round > 0)
    {
        int z = x + y;
        cout << z << endl;
        x = y;
        y = z;

        --round;
    } 

    return 0;
}

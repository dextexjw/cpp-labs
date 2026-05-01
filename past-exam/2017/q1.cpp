#include <iostream>
using namespace std;

bool possible(int bars)
{
    for (int thief = 1; thief <= 3; thief++)
    {
        if (bars % 3 != 1)
            return false;

        // thief takes one third plus the extra bar
        bars = 2 * (bars / 3);
    }

    // final morning division must also leave 1 bar
    return (bars % 3 == 1);
}

int main()
{
    cout << "Possible original numbers of gold bars:\n";

    for (int bars = 1; bars <= 500; bars++)
    {
        if (possible(bars))
            cout << bars << endl;
    }

    return 0;
}
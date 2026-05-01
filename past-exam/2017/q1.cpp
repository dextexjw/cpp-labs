#include <iostream>
using namespace std;

bool possible(int bars)
{
    for (int thief = 1; thief <= 3; thief++)
    {
        if (bars % 3 != 1)
            return false;

        // bars is 3*k + 1 for some k (because bars % 3 == 1)
        int k = bars / 3;
        int taken_by_thief = k + 1;   // one equal third (k bars) plus the extra bar
        bars = bars - taken_by_thief; // same as 2 * k; pile left for the next night
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
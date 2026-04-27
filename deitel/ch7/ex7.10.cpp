#include <iostream>
#include <array>
#include <cstdlib>
using namespace std;

int main()
{
    const size_t noOfServers = 30;

    array<int, noOfServers> servers{};

    for (int& i : servers)
    {
        i = rand() % 90 + 20;
        cout << i << " ";
    }

    cout << endl
         << endl
         << "Salary distribution:" << endl;

    array<int, 9> salaryRange{};

    for (int i : servers)
    {
        if (i < 30)
        {
            salaryRange[0]++;
        }
        else if (i < 40)
        {
            salaryRange[1]++;
        }
        else if (i < 50)
        {
            salaryRange[2]++;
        }
        else if (i < 60)
        {
            salaryRange[3]++;
        }
        else if (i < 70)
        {
            salaryRange[4]++;
        }
        else if (i < 80)
        {
            salaryRange[5]++;
        }
        else if (i < 90)
        {
            salaryRange[6]++;
        }
        else if (i < 100)
        {
            salaryRange[7]++;
        }
        else
        {
            salaryRange[8]++;
        }
    }

    // range start from 20 to 29, 30 to 39, ..., 90 to 99
    for (size_t i = 0; i < salaryRange.size(); ++i){
        cout << (i * 10 + 20) << " - " << (i * 10 + 29) << ": " << salaryRange[i] << endl;
    }

    return 0;
}

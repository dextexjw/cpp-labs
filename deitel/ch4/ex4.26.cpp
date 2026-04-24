#include <iostream>
using namespace std;
int main()
{
    int size{1};
    cout << "Give a square size to print: ";
    cin >> size;

    for (int j{0}; j < size; ++j)
    {
        for (int i{0}; i < size; ++i)
        {
            if (j == 0 || j == size - 1 || i == 0 || i == size - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}

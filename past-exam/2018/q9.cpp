#include <iostream>
using namespace std;

int main()
{
    const int n = 15;
    int arr[n] = {0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0};

    cout << "Original Array:  ";
    for (int i : arr) cout << i << " ";
    cout << endl;

    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        while (arr[left] == 0) left++;

        while (arr[right] == 1) right--;

        if (left < right)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;

            left++;
            right--;
        }
    }

    cout << "Array at output: ";

    for (int i : arr) cout << i << " ";

    return 0;
}
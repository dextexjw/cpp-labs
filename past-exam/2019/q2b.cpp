#include <iostream>
using namespace std;

int main() {
    const int MAX = 50;
    int a[MAX][MAX];
    int n;

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter array values:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter row " << i << ": ";
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int row = 0; row < n; row++) {
        int minCol = 0;

        // find smallest element in this row
        for (int col = 1; col < n; col++) {
            if (a[row][col] < a[row][minCol]) {
                minCol = col;
            }
        }

        // check if it is largest in its column
        bool largestInColumn = true;
        for (int r = 0; r < n; r++) {
            if (a[r][minCol] > a[row][minCol]) {
                largestInColumn = false;
            }
        }

        if (largestInColumn) {
            cout << "Saddle element is " << a[row][minCol] << endl;
            cout << "Location is row " << row
                 << ", column " << minCol << endl;
            return 0;
        } else {
    }

    cout << "No saddle element found" << endl;

    return 0;
}
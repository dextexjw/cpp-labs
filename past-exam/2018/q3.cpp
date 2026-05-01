#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int** square = new int*[n];

    for (int i = 0; i < n; i++) {
        square[i] = new int[n];
    }

    cout << "Enter " << n * n << " numbers:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> square[i][j];
        }
    }

    int target = 0;

    for (int j = 0; j < n; j++) {
        target += square[0][j];
    }

    bool magic = true;

    // Check all rows
    for (int i = 0; i < n; i++) {
        int rowSum = 0;

        for (int j = 0; j < n; j++) {
            rowSum += square[i][j];
        }

        if (rowSum != target) {
            magic = false;
        }
    }

    // Check all columns
    for (int j = 0; j < n; j++) {
        int colSum = 0;

        for (int i = 0; i < n; i++) {
            colSum += square[i][j];
        }

        if (colSum != target) {
            magic = false;
        }
    }

    // Check main diagonal
    int diag1 = 0;

    for (int i = 0; i < n; i++) {
        diag1 += square[i][i];
    }

    if (diag1 != target) {
        magic = false;
    }

    // Check other diagonal
    int diag2 = 0;

    for (int i = 0; i < n; i++) {
        diag2 += square[i][n - 1 - i];
    }

    if (diag2 != target) {
        magic = false;
    }

    if (magic) {
        cout << "The square is a magic square." << endl;
    } else {
        cout << "The square is not a magic square." << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] square[i];
    }

    delete[] square;

    return 0;
}
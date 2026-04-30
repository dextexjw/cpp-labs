#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

// Function to print points
void printPoints(Point arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "(" << arr[i].x << ", " << arr[i].y << ") ";
    }
    cout << endl;
}

// Bubble sort by increasing x
void sortByX(Point arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].x > arr[j + 1].x) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Bubble sort by decreasing y
void sortByYDesc(Point arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].y < arr[j + 1].y) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Bubble sort by distance from (0,0)
void sortByDistance(Point arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {

            int d1 = arr[j].x * arr[j].x + arr[j].y * arr[j].y;
            int d2 = arr[j + 1].x * arr[j + 1].x + arr[j + 1].y * arr[j + 1].y;

            if (d1 > d2) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    const int SIZE = 20;
    Point points[SIZE];

    // Input
    cout << "Enter 20 (x, y) pairs:\n";
    for (int i = 0; i < SIZE; i++) {
        cin >> points[i].x >> points[i].y;
    }

    // Copy original array (so each sort is independent)
    Point temp[SIZE];

    // (i) Sort by increasing x
    for (int i = 0; i < SIZE; i++) temp[i] = points[i];
    sortByX(temp, SIZE);
    cout << "\nSorted by increasing x:\n";
    printPoints(temp, SIZE);

    // (ii) Sort by decreasing y
    for (int i = 0; i < SIZE; i++) temp[i] = points[i];
    sortByYDesc(temp, SIZE);
    cout << "\nSorted by decreasing y:\n";
    printPoints(temp, SIZE);

    // (iii) Sort by distance from (0,0)
    for (int i = 0; i < SIZE; i++) temp[i] = points[i];
    sortByDistance(temp, SIZE);
    cout << "\nSorted by increasing distance from (0,0):\n";
    printPoints(temp, SIZE);

    return 0;
}
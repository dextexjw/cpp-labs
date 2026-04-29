#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // This program compares two text files line by line.
    // If every line is the same in both files, they are considered similar.

    string firstFileName, secondFileName;

    cout << "Enter the name of the first file: ";
    cin >> firstFileName;
    cout << "Enter the name of the second file: ";
    cin >> secondFileName;

    ifstream firstFile(firstFileName);
    ifstream secondFile(secondFileName);

    // Stop if either file cannot be opened.
    if (!firstFile || !secondFile) {
        cout << "Error: Could not open one or both files." << endl;
        return 1;
    }

    string firstLine, secondLine;

    while (getline(firstFile, firstLine) && getline(secondFile, secondLine)) {
        if (firstLine != secondLine) {
            cout << "The files are not similar." << endl;
            return 0;
        }
    }

    // If one file still has extra lines, the files are different.
    if (getline(firstFile, firstLine) || getline(secondFile, secondLine)) {
        cout << "The files are not similar." << endl;
        return 0;
    }

    cout << "The files are similar." << endl;
    return 0;
}
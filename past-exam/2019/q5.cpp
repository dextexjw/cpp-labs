#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string inputName1, inputName2, outputName;

    // Get the three file names from the user
    // cout << "Enter first input file name: ";
    // cin >> inputName1;

    // cout << "Enter second input file name: ";
    // cin >> inputName2;

    // cout << "Enter output file name: ";
    // cin >> outputName;

    inputName1 = "q5_file1.txt";
    inputName2 = "q5_file2.txt";
    outputName = "q5_output.txt";

    ifstream file1(inputName1.c_str());
    ifstream file2(inputName2.c_str());
    ofstream outputFile(outputName.c_str());

    // Check that all files opened correctly
    if (!file1 || !file2 || !outputFile) {
        cout << "Error opening one of the files." << endl;
        return 1;
    }

    string record1, record2;

    // Read the first record from each input file
    bool hasRecord1 = static_cast<bool>(getline(file1, record1));
    bool hasRecord2 = static_cast<bool>(getline(file2, record2));

    // Merge while both files still have records
    while (hasRecord1 && hasRecord2) {
        if (record1 <= record2) {
            outputFile << record1 << '\n';
            hasRecord1 = static_cast<bool>(getline(file1, record1));
        }
        else {
            outputFile << record2 << '\n';
            hasRecord2 = static_cast<bool>(getline(file2, record2));
        }
    }

    // Copy remaining records from first file, if any
    while (hasRecord1) {
        outputFile << record1 << '\n';
        hasRecord1 = static_cast<bool>(getline(file1, record1));
    }

    // Copy remaining records from second file, if any
    while (hasRecord2) {
        outputFile << record2 << '\n';
        hasRecord2 = static_cast<bool>(getline(file2, record2));
    }

    file1.close();
    file2.close();
    outputFile.close();

    cout << "Files merged successfully." << endl;

    return 0;
}
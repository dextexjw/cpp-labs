#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isSeparator(char ch) {
    return ch == ' ' || ch == ',' || ch == '.';
}

int countWords(string line) {
    int words = 0;
    bool inWord = false;

    for (char c : line) {
        if (isSeparator(c)) {
            if (inWord) {
                words++;
                inWord = false;
            }
        }
        else {
            inWord = true;
        }
    }

    // If the line ended while inside a word, count that last word
    if (inWord) {
        words++;
    }

    return words;
}

int main() {
    ifstream inputFile("q4_input.txt");

    if (!inputFile) {
        cout << "Error opening file." << endl;
        return 1;
    }

    string line;
    int lineCount = 0;

    while (getline(inputFile, line)) {
        lineCount++;

        int wordCount = countWords(line);

        cout << "Line " << lineCount << ": "
             << wordCount << " words" << endl;
    }

    cout << "Total lines: " << lineCount << endl;

    inputFile.close();

    return 0;
}
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

// Convert a word (example: SEND) to a number using letter -> digit mapping.
int toNumber(const string& word, int letterToDigit[]) {
    int value = 0;
    for (char c : word) {
        value = value * 10 + letterToDigit[c - 'A'];
    }
    return value;
}

// Convert user input to uppercase so send/SEND/SeNd all work.
void makeUpperCase(string& text) {
    for (char& c : text) {
        c = static_cast<char>(toupper(static_cast<unsigned char>(c)));
    }
}

// Safety check: only A-Z letters are allowed.
bool containsOnlyLetters(const string& text) {
    for (char c : text) {
        if (c < 'A' || c > 'Z') {
            return false;
        }
    }
    return true;
}

// Backtracking function:
// Try assigning digits to unique letters one by one.
bool solvePuzzle(int index, const string& uniqueLetters, int letterToDigit[],
                 bool usedDigits[], const string& x, const string& y,
                 const string& z) {
    int totalLetters = uniqueLetters.size();

    // Base case: all letters assigned. Now test equation.
    if (index == totalLetters) {
        // Leading letter of a word cannot be 0.
        if (letterToDigit[x[0] - 'A'] == 0 ||
            letterToDigit[y[0] - 'A'] == 0 ||
            letterToDigit[z[0] - 'A'] == 0) {
            return false;
        }

        int numX = toNumber(x, letterToDigit);
        int numY = toNumber(y, letterToDigit);
        int numZ = toNumber(z, letterToDigit);
        return (numX + numY == numZ);
    }

    int letterIndex = uniqueLetters[index] - 'A';

    // Try every unused digit (0 to 9).
    for (int digit = 0; digit <= 9; digit++) {
        if (usedDigits[digit]) {
            continue;
        }

        letterToDigit[letterIndex] = digit;
        usedDigits[digit] = true;

        if (solvePuzzle(index + 1, uniqueLetters, letterToDigit, usedDigits, x,
                        y, z)) {
            return true;
        }

        // Undo assignment (backtrack).
        usedDigits[digit] = false;
    }

    return false;
}

int main() {
    string x, y, z;
    cout << "Enter x, y, z: ";
    cin >> x >> y >> z;

    makeUpperCase(x);
    makeUpperCase(y);
    makeUpperCase(z);

    if (!containsOnlyLetters(x) || !containsOnlyLetters(y) || !containsOnlyLetters(z)) {
        cout << "Invalid input. Please use letters only (A-Z).\n";
        return 0;
    }

    // Build list of unique letters.
    string uniqueLetters = "";
    for (char c : x + y + z) {
        if (uniqueLetters.find(c) == string::npos) {
            uniqueLetters += c;
        }
    }

    cout << "Unique letters: " << uniqueLetters << endl;

    int totalLetters = uniqueLetters.size();
    if (totalLetters > 10) {
        cout << "No solution found\n";
        return 0;
    }

    int letterToDigit[26] = {0};
    bool usedDigits[10] = {false};

    if (solvePuzzle(0, uniqueLetters, letterToDigit, usedDigits, x, y, z)) {
        cout << "Solution:\n";
        for (int i = 0; i < totalLetters; i++) {
            cout << uniqueLetters[i] << " = "
                 << letterToDigit[uniqueLetters[i] - 'A'] << endl;
        }
        return 0;
    }

    cout << "No solution found\n";
    return 0;
}
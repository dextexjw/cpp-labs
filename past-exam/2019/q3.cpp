#include <cctype>
#include <iostream>
#include <string>
using namespace std;

// Convert a word (example: SEND) into a number using the current letter->digit map.
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

bool hasLeadingZero(const string& x, const string& y, const string& z,
                    int letterToDigit[]) {
    return letterToDigit[x[0] - 'A'] == 0 ||
           letterToDigit[y[0] - 'A'] == 0 ||
           letterToDigit[z[0] - 'A'] == 0;
}

bool equationHolds(const string& x, const string& y, const string& z,
                   int letterToDigit[]) {
    int xValue = toNumber(x, letterToDigit);
    int yValue = toNumber(y, letterToDigit);
    int zValue = toNumber(z, letterToDigit);
    return (xValue + yValue == zValue);
}

// Iterative backtracking:
// - "depth" = which unique letter we are assigning now.
// - Try a free digit, go deeper.
// - If stuck, undo and go back (backtrack).
bool solvePuzzle(const string& uniqueLetters, int letterToDigit[],
                 bool usedDigits[], const string& x, const string& y,
                 const string& z) {
    int totalUniqueLetters = uniqueLetters.size();

    // For each depth, remember:
    // - which digit to start trying from next time
    // - which digit we chose (so we can undo it on backtrack)
    int nextDigitToTryAtDepth[26] = {0};
    int chosenDigitAtDepth[26];
    for (int i = 0; i < 26; i++) {
        chosenDigitAtDepth[i] = -1;
    }

    int depth = 0;

    while (depth >= 0) {
        // If all letters got digits, test full assignment.
        if (depth == totalUniqueLetters) {
            if (!hasLeadingZero(x, y, z, letterToDigit) &&
                equationHolds(x, y, z, letterToDigit)) {
                return true; // Found a valid mapping.
            }

            // Full assignment failed -> go back one step.
            depth--;
            if (depth >= 0) {
                int previousDigit = chosenDigitAtDepth[depth];
                if (previousDigit != -1) {
                    usedDigits[previousDigit] = false;
                    chosenDigitAtDepth[depth] = -1;
                }
            }
            continue;
        }

        int currentLetterIndex = uniqueLetters[depth] - 'A';
        bool placedDigit = false;

        // Try digits for the current letter.
        for (int digit = nextDigitToTryAtDepth[depth]; digit <= 9; digit++) {
            if (usedDigits[digit]) {
                continue;
            }

            letterToDigit[currentLetterIndex] = digit;
            usedDigits[digit] = true;
            chosenDigitAtDepth[depth] = digit;
            nextDigitToTryAtDepth[depth] = digit + 1;

            // Go one step deeper to assign the next letter.
            depth++;
            if (depth < 26) {
                nextDigitToTryAtDepth[depth] = 0;
            }
            placedDigit = true;
            break;
        }

        if (placedDigit) {
            continue;
        }

        // No digit worked here. Reset this depth and backtrack.
        nextDigitToTryAtDepth[depth] = 0;
        depth--;
        if (depth >= 0) {
            int previousDigit = chosenDigitAtDepth[depth];
            if (previousDigit != -1) {
                usedDigits[previousDigit] = false;
                chosenDigitAtDepth[depth] = -1;
            }
        }
    }

    return false;
}

int main() {
    string x, y, z;
    cout << "Enter x y z: ";
    cin >> x >> y >> z;

    // Make input uppercase so users can type in any case.
    makeUpperCase(x);
    makeUpperCase(y);
    makeUpperCase(z);

    // Validate input.
    if (!containsOnlyLetters(x) || !containsOnlyLetters(y) || !containsOnlyLetters(z)) {
        cout << "Invalid input. Please use letters only (A-Z).\n";
        return 0;
    }

    // Step 1: collect unique letters used in x, y, z.
    string uniqueLetters = "";
    for (char c : x + y + z) {
        if (uniqueLetters.find(c) == string::npos) {
            uniqueLetters += c;
        }
    }

    cout << "Unique letters: " << uniqueLetters << endl;

    // More than 10 unique letters means impossible (only digits 0-9 exist).
    int totalLetters = uniqueLetters.size();
    if (totalLetters > 10) {
        cout << "No solution found\n";
        return 0;
    }

    // letterToDigit[L - 'A'] gives the digit assigned to letter L.
    int letterToDigit[26] = {0};
    // usedDigits[d] says whether digit d is already taken by another letter.
    bool usedDigits[10] = {false};

    // Step 2: search for a valid assignment.
    if (solvePuzzle(uniqueLetters, letterToDigit, usedDigits, x, y, z)) {
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
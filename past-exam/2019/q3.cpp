#include <cctype>
#include <iostream>
#include <string>
using namespace std;

// Convert a word (example: SEND) into a number using the current mapping.
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

// Try assigning digits to letters one by one (backtracking).
bool solvePuzzle(int index, const string& uniqueLetters, int letterToDigit[],
                 bool usedDigits[], const string& word1, const string& word2,
                 const string& resultWord) {
    int totalLetters = uniqueLetters.size();

    // Base case: all letters assigned. Now test equation.
    if (index == totalLetters) {
        // Leading letter of a word cannot be 0.
        if (letterToDigit[word1[0] - 'A'] == 0 ||
            letterToDigit[word2[0] - 'A'] == 0 ||
            letterToDigit[resultWord[0] - 'A'] == 0) {
            return false;
        }

        int value1 = toNumber(word1, letterToDigit);
        int value2 = toNumber(word2, letterToDigit);
        int resultValue = toNumber(resultWord, letterToDigit);
        return (value1 + value2 == resultValue);
    }

    int letterIndex = uniqueLetters[index] - 'A';

    // Try every unused digit (0 to 9).
    for (int digit = 0; digit <= 9; digit++) {
        if (usedDigits[digit]) {
            continue;
        }

        letterToDigit[letterIndex] = digit;
        usedDigits[digit] = true;

        if (solvePuzzle(index + 1, uniqueLetters, letterToDigit, usedDigits, word1, word2, resultWord)) {
            return true;
        }

        // Undo assignment (backtrack).
        usedDigits[digit] = false;
    }

    return false;
}

int main() {
    string word1, word2, resultWord;
    cout << "Enter word1 word2 resultWord: ";
    cin >> word1 >> word2 >> resultWord;

    // Make input uppercase so users can type in any case.
    makeUpperCase(word1);
    makeUpperCase(word2);
    makeUpperCase(resultWord);

    // Validate input.
    if (!containsOnlyLetters(word1) || !containsOnlyLetters(word2) || !containsOnlyLetters(resultWord)) {
        cout << "Invalid input. Please use letters only (A-Z).\n";
        return 0;
    }

    // Collect unique letters from all three words.
    string uniqueLetters = "";
    for (char c : word1 + word2 + resultWord) {
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

    if (solvePuzzle(0, uniqueLetters, letterToDigit, usedDigits, word1, word2, resultWord)) {
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
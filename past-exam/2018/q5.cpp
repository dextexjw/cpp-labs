#include <iostream>
#include <fstream>
#include <stack>
#include <string>
using namespace std;

bool isOpening(char ch) {
    return ch == '(' || ch == '[' || ch == '{';
}

bool isClosing(char ch) {
    return ch == ')' || ch == ']' || ch == '}';
}

bool matches(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int main() {
    string fileName;
    ifstream inputFile;
    stack<char> brackets;
    char ch;
    bool balanced = true;

    inputFile.open("textq5.txt");

    if (!inputFile) {
        cout << "Could not open file." << endl;
        return 1;
    }

    while (inputFile.get(ch) && balanced) {
        if (isOpening(ch)) {
            brackets.push(ch);
        }
        else if (isClosing(ch)) {
            if (brackets.empty()) {
                balanced = false;
            }
            else if (matches(brackets.top(), ch)) {
                brackets.pop();
            }
            else {
                balanced = false;
            }
        }
    }

    inputFile.close();

    if (balanced && brackets.empty()) {
        cout << "All parentheses are balanced." << endl;
    }
    else {
        cout << "Parentheses are not balanced." << endl;
    }

    return 0;
}
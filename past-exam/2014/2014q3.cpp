#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;

    while (true) {
        cout << "enter a line of text: ";
        getline(cin, line);  // read full line (including spaces)

        // Stop if user enters empty line
        if (line.empty()) {
            break;
        }

        // Reverse the string manually
        string reversed = "";
        
        for (int i = line.length() - 1; i >= 0; i--) {
            reversed += line[i];
        }

        cout << "the reversed line is: " << reversed << endl;

        // cout << swap("3","4") << endl;
    }

    return 0;
}
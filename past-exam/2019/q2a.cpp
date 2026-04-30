#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;

    cout << "enter a line of text: ";
    getline(cin, line);

    while (line != "") {
        cout << "the reversed line is: ";

        for (int i = line.length() - 1; i >= 0; i--) {
            cout << line[i];
        }

        cout << endl;

        cout << "enter a line of text: ";
        getline(cin, line);
    }

    return 0;
}
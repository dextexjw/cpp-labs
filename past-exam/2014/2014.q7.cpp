#include <iostream>
#include <cctype>
#include <fstream>

using namespace std;

int getNextCharacter(ifstream &file){
    char ch;
    while (file.get(ch)) {
        if (!isspace(static_cast<unsigned char>(ch))) {
            return ch;
        }
    }
	return EOF;
}

int main() {
    ifstream file01("file01.txt");
    ifstream file02("file02.txt");

    while (true) {
        int c1 = getNextCharacter(file01);
        int c2 = getNextCharacter(file02);

        // If both reached end → similar
        if (c1 == EOF && c2 == EOF) {
            cout << "true" << endl;
            return 0;
        }

        // If mismatch or one ends early → not similar
        if (c1 != c2) {
            cout << "false" << endl;
            return 0;
        }
    }

}
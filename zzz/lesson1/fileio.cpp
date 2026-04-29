#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> filenames = {
        "data.txt",
        "../data.txt",
        "cpp-labs/zzz/data.txt"
    };

    ifstream file;

    for (string filename : filenames) {
        file.open(filename);

        if (file) {
            break;
        }

        file.close();
        file.clear();
    }

    if (!file) {
        cout << "Could not open data.txt" << endl;
        return 1;
    }

    string line;

    while (getline(file, line)) {
        cout << line << endl;
    }

    return 0;
}

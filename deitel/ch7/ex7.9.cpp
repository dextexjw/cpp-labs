#include <iostream>
#include <array>
using namespace std;

int main() {
    array<array<int, 2>, 3> t;

    for (size_t i{0}; i < t.size(); ++i) {
        for (size_t j{0}; j < t[i].size(); ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            t[i][j] = 0;
        }
    }

    
}

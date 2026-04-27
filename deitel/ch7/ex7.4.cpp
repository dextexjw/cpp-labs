// with the row or column number. Assume that the array was initialized with an initialize list containing the values from 1 through 16 in order. Show the output. 
// Write a nested for statement that displays the values of each element of array table in tabular format with 4 rows and 4 columns. Each row and column should be labelled

#include <iostream>
#include <array>

using namespace std;


int main() {

    const size_t arraySize{4};
    array<array<int, arraySize>, arraySize> table;

    cout << "   [0] [1] [2] [3]" << endl;

    for (int row{0}; row < table.size(); ++row) {
      
      cout << "[" << row << "] ";
      
      for (int column{0}; column < table[row].size(); ++column) {
        
        table[row][column] = row*column;
        cout << table[row][column] << " - ";
      
      }
      cout << endl;
    }

    return 0;
}

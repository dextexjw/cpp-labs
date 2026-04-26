#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

unsigned long factorial(unsigned long number, unsigned int depth = 0);
void printIndent(unsigned int depth);

int main() {
   unsigned long number{5};

   cout << "Visualizing " << number << "!\n\n";
   unsigned long answer{factorial(number)};

   cout << "\nFinal answer: " << number << "! = " << answer << endl;

   return 0;
}

unsigned long factorial(unsigned long number, unsigned int depth) {
   printIndent(depth);
   cout << "factorial(" << number << ") begins; local number = " << number << endl;

   if (number <= 1) {
      printIndent(depth);
      cout << "Base case reached: factorial(" << number << ") returns 1"
           << endl;
      return 1;
   }

   printIndent(depth);
   cout << "Need " << number << " * factorial(" << number - 1
        << "), so call factorial(" << number - 1 << ")" << endl;

   unsigned long recursiveResult{factorial(number - 1, depth + 1)};
   unsigned long result{number * recursiveResult};

   printIndent(depth);
   cout << "Back in factorial(" << number << "): " << number << " * "
        << recursiveResult << " = " << result << endl;

   return result;
}

void printIndent(unsigned int depth) {
   cout << string(depth * 3, ' ');
}

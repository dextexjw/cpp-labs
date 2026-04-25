#include <iostream>

using namespace std;

void printStarsThenSpaces(int stars, int spaces) {
  for (int i = 0; i < stars; i++) { cout << "*"; }
  for (int j = 0; j < spaces; j++) { cout << " "; }
  cout << "\t";
}

void printSpacesThenStars(int spaces, int stars) {
  for (int i = 0; i < spaces; i++) { cout << " "; }
  for (int j = 0; j < stars; j++) { cout << "*"; }
  cout << "\t";
}

int main() {
  for (int i = 1; i <= 10; i++) {
    printStarsThenSpaces(i, 10 - i);
    printStarsThenSpaces(11 - i, i - 1);
    printSpacesThenStars(i - 1, 11 - i);
    printSpacesThenStars(10 - i, i);
    cout << endl;
  }

  return 0;
}

#include <iostream>
#include "Time.h"

using namespace std;

int main() {
  Time now;

  cout << "Current time (universal): ";
  now.printUniversal();
  cout << "\nCurrent time (standard): ";
  now.printStandard();
  cout << endl;

  return 0;
}

#include <iostream>
#include "Time.h"
#include "Math.h"

using namespace std;

void timefn() {
  Time t;

  cout << "The universal time is: ";
  t.printUniversal();
  cout << "\nThe standard time is: ";
  t.printStandard();
  cout << endl;
}

void mathfn() {
  Math m;

  cout << "2 + 3 = " << m.add(2, 3) << endl;
  cout << "4 * 5 = " << m.multiply(4, 5) << endl;
}

int main() {
  // timefn();

  mathfn();

  return 0;
}

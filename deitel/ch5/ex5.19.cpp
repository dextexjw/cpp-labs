#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  long double pi = 0.0L;
  int firstTermBeginningWith314159 = 0;

  cout << fixed << setprecision(10);
  cout << "Term\tApproximation of pi" << endl;

  for (int term = 1; term <= 200000; term++) {
    long double denominator = 2.0L * term - 1.0L;

    if (term % 2 == 1) {
      pi += 4.0L / denominator;
    } else {
      pi -= 4.0L / denominator;
    }

    cout << term << '\t' << pi << endl;

    if (firstTermBeginningWith314159 == 0 &&
        floor(pi * 100000.0L) == 314159.0L) {
      firstTermBeginningWith314159 = term;
    }
  }

  cout << "\nThe approximation first begins with 3.14159 after "
       << firstTermBeginningWith314159 << " terms." << endl;

  return 0;
}

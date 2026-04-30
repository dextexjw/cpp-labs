#include <iostream>
#include "Set.h"
using namespace std;

int main() {
    Set<int> a;
    a.add(10);
    a.add(20);
    a.add(10);

    Set<double> b{1.5, 2.5, 1.5};

    cout << a.contains(20) << endl;
    a.remove(20);
    cout << a.contains(20) << endl;

    cout << b.size() << endl;

    return 0;
}
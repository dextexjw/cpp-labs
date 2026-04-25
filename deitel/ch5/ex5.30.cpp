#include <iostream>
#include "DollarAmount.h"

using namespace std;

int main() {
    DollarAmount amount1{1, 25}; // $1.25
    DollarAmount amount2{2, 50}; // $2.50
    DollarAmount amount3{amount1 + amount2};

    cout << "$1.25 contains " << amount1.getAmount() << " pennies\n";
    cout << "$2.50 contains " << amount2.getAmount() << " pennies\n";
    cout << "$1.25 + $2.50 contains " << amount3.getAmount()
         << " pennies\n";

    cout << "$1.25 + $2.50 = $" << (amount1 + amount2).getAmount() / 100.0 << "\n";


    return 0;
}

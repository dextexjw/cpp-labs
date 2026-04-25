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

    cout << "$1.25 + $2.50 = $" << amount3.toString() << "\n";
    amount3.divide(2);
    cout << "$3.75 divided by 2 = $" << amount3.toString() << "\n";

    DollarAmount halfDown{1};
    DollarAmount halfUp{3};
    DollarAmount halfToEven{2};
    DollarAmount twoAndHalfToEven{5};

    halfDown.addInterest(1, 2);
    halfUp.addInterest(1, 2);
    halfToEven.addInterest(1, 4);
    twoAndHalfToEven.addInterest(1, 2);

    cout << "\nBanker's rounding tests:\n";
    cout << "1 penny plus 0.5 pennies interest = "
         << halfDown.getAmount() << " pennies\n";
    cout << "3 pennies plus 1.5 pennies interest = "
         << halfUp.getAmount() << " pennies\n";
    cout << "2 pennies plus 0.5 pennies interest = "
         << halfToEven.getAmount() << " pennies\n";
    cout << "5 pennies plus 2.5 pennies interest = "
         << twoAndHalfToEven.getAmount() << " pennies\n";

    DollarAmount principal{1000, 0};
    int rate{5};
    int divisor{100};

    cout << "\nYear" << "\tAmount on deposit\n";

    for (int year{1}; year <= 10; ++year) {
      principal.addInterest(rate, divisor);
      cout << year << "\t$" << principal.toString() << "\n";
    }

    return 0;
}

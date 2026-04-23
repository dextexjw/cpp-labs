#include <iostream>
#include "ElectricBill.h"

using namespace std;

int main() {
    ElectricBill bill;
    bill.setUnitsUsed(100);
    bill.setAmountPaid(1000);

    cout << "Units Used: " << bill.getUnitsUsed() << " kWh" << endl;
    cout << "Amount Paid: $" << bill.getAmountPaid() << endl;
    
    cout << "Price after deductions: $" << bill.priceAfterDeductions() << endl;
    cout << "Actual rate per kWh: $" << bill.priceAfterDeductions() / bill.getUnitsUsed() << endl;
    
    return 0;
}
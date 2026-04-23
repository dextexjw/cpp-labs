#include <iostream>
#include "Invoice.h"

using namespace std;

void invoicefn() {
    Invoice inv("1234", "Widget", 10, 5);
    
    cout << "Part Number: " << inv.getPartNumber() << endl;
    cout << "Description: " << inv.getDescription() << endl;
    cout << "Quantity: " << inv.getQuantity() << endl;
    cout << "Price per Item: $" << inv.getPricePerItem() << endl;
    cout << "VAT Rate: " << inv.getVatRate() * 100 << "%" << endl;

    cout << "The total amount for the invoice is: $ " << inv.getInvoiceAmount() << endl;
}

int main() {
    invoicefn();
    
    return 0;
}
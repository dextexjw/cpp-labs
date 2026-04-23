#include <iostream>
#include <string>

using namespace std;

class Invoice
{

public:
    Invoice(string part, string desc, int quant, int price)
    {
        part_number = part;
        description = desc;
        quantity = quant;
        price_per_item = price;
        vat_rate = 0.20;
        discount_rate = 0;
    }

    // Part number getter and setter
    string getPartNumber() const {
        return part_number;
    }
    void setPartNumber(string part) {
        part_number = part;
    }

    // Description getter and setter
    string getDescription() const {
        return description;
    }
    void setDescription(string desc) {
        description = desc;
    }

    // Quantity getter and setter
    int getQuantity() const {
        return quantity;
    }
    void setQuantity(int quant) {
        quantity = quant;
    }

    // Price per item getter and setter
    int getPricePerItem() const {
        return price_per_item;
    }
    void setPricePerItem(int price) {
        price_per_item = price;
    }

    // VAT rate getter and setter
    double getVatRate() const {
        return vat_rate;
    }
    void setVatRate(double vat) {
        vat_rate = vat;
    }

    // Discount rate getter and setter
    double getDiscountRate() const {
        return discount_rate;
    }
    void setDiscountRate(double discount) {
        discount_rate = discount;
    }

    

private:
    string part_number;
    string description;
    int quantity;
    int price_per_item;
    double vat_rate;
    double discount_rate;
};
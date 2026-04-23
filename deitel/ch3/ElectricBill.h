#ifndef ELECTRICBILL_H
#define ELECTRICBILL_H

#include <iostream>

class ElectricBill {
private:
    double amountPaid = 0;
    double vatRate = 0.15; // Example VAT rate
    double ewuraCharge = 5.00; // Example EWURA charge
    double reaCharge = 2.50; // Example REA charge
    double unitsUsed = 0;
    double ratePerKWh = 295; // Example rate per kWh

public:
    double calculateBill(double kWhUsed) {
        const double ratePerKWh = 0.12; // Example rate
        return kWhUsed * ratePerKWh;
    }

    double getAmountPaid() const {
        return amountPaid;
    }

    void setAmountPaid(double amount) {
        if (amount < 0) {
            amount = 0;
        }
        amountPaid = amount;
    }

    void setUnitsUsed(double units) {
        if (units < 0) {
            units = 0;
        }
        unitsUsed = units;
    }

    double getVAT() {
        return calculateBill(unitsUsed) * vatRate;
    }

    double getEWURA() const {
        return ewuraCharge;
    }

    double getREA() const {
        return reaCharge;
    }

    double getUnitsUsed() const {
        return unitsUsed;
    }

    double getTotalAmount() {
        return calculateBill(unitsUsed) + getVAT() + getEWURA() + getREA();
    }

    double priceAfterDeductions() {
        double x = amountPaid - getVAT() - getEWURA() - getREA();
        return x;
    }

};

#endif
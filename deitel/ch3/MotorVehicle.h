#ifndef MOTORVEHICLE_H
#define MOTORVEHICLE_H

#include <string>
using std::string;

class MotorVehicle {
private:
    string make;
    string fuelType;
    int yearOfManufacture;
    string color;
    int engineCapacity;

public:
    // Constructor
    MotorVehicle(string m, string fuel, int year, string c, int engine)
        : make(m), fuelType(fuel), yearOfManufacture(year), color(c), engineCapacity(engine) {}

    // Getters
    string getMake() const { return make; }
    string getFuelType() const { return fuelType; }
    int getYearOfManufacture() const { return yearOfManufacture; }
    string getColor() const { return color; }
    int getEngineCapacity() const { return engineCapacity; }

    // Setters
    void setMake(string m) { make = m; }
    void setFuelType(string fuel) { fuelType = fuel; }
    void setYearOfManufacture(int year) { yearOfManufacture = year; }
    void setColor(string c) { color = c; }
    void setEngineCapacity(int engine) { engineCapacity = engine; }
};

#endif

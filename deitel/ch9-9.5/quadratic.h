#ifndef QUADRATIC_H
#define QUADRATIC_H
#include <string>

class Quadratic
{
    public:
        Quadratic();
        Quadratic(double a, double b, double c);

        Quadratic add(const Quadratic& other);
        Quadratic subtract(const Quadratic& other);
        std::string toString() const;
        std::string solve() const;

    private:
        double a;
        double b;
        double c;
        char variable;
};

#endif
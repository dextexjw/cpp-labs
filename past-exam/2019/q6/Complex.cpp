#include "Complex.h"

Complex::Complex(double r, double i) {
    real = r;
    imag = i;
}

double Complex::getReal() const {
    return real;
}

double Complex::getImag() const {
    return imag;
}

void Complex::setReal(double r) {
    real = r;
}

void Complex::setImag(double i) {
    imag = i;
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

Complex Complex::operator*(const Complex& other) const {
    double r = real * other.real - imag * other.imag;
    double i = real * other.imag + imag * other.real;
    return Complex(r, i);
}

ostream& operator<<(ostream& out, const Complex& c) {
    out << c.real;

    if (c.imag >= 0) {
        out << " + " << c.imag << "i";
    } else {
        out << " - " << -c.imag << "i";
    }

    return out;
}
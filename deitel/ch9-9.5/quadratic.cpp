#include "quadratic.h"
#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

// Default constructor: a=1, b=0, c=0, variable='x'
Quadratic::Quadratic() : a(1), b(0), c(0), variable('x') {}

// Parameterized constructor: ensure a is never 0 (default to 1 if given 0)
Quadratic::Quadratic(double a, double b, double c) {
  this->a = (a == 0) ? 1 : a;
  this->b = b;
  this->c = c;
  this->variable = 'x';
}

// add: adds two Quadratic equations by adding corresponding a, b, c values
Quadratic Quadratic::add(const Quadratic& other) {
  return Quadratic(this->a + other.a, this->b + other.b, this->c + other.c);
}

// subtract: subtracts two Quadratic equations by subtracting corresponding a, b, c values
Quadratic Quadratic::subtract(const Quadratic& other) {
  return Quadratic(this->a - other.a, this->b - other.b, this->c - other.c);
}

// toString: returns string representation in form ax^2 + bx + c = 0
std::string Quadratic::toString() const {
  ostringstream oss;
  oss << fixed << setprecision(2);
  
  // Build the equation string
  oss << a << variable << "^2";
  
  if (b >= 0) {
    oss << " + " << b << variable;
  } else {
    oss << " - " << abs(b) << variable;
  }
  
  if (c >= 0) {
    oss << " + " << c;
  } else {
    oss << " - " << abs(c);
  }
  
  oss << " = 0";
  return oss.str();
}

// solve: solves quadratic equation using quadratic formula
// Returns solutions if discriminant > 0, otherwise returns "No Real Roots"
std::string Quadratic::solve() const {
  ostringstream oss;
  oss << fixed << setprecision(2);
  
  // Calculate discriminant (b^2 - 4ac)
  double discriminant = b * b - 4 * a * c;
  
  if (discriminant > 0) {
    // Two distinct real roots
    double x1 = (-b + sqrt(discriminant)) / (2 * a);
    double x2 = (-b - sqrt(discriminant)) / (2 * a);
    oss << "Solutions: x1 = " << x1 << ", x2 = " << x2;
  } else if (discriminant == 0) {
    // One repeated real root
    double x = -b / (2 * a);
    oss << "One solution (repeated root): x = " << x;
  } else {
    // No real roots
    oss << "No Real Roots";
  }
  
  return oss.str();
}

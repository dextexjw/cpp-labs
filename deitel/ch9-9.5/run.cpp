#include "quadratic.h"
#include <iostream>

using namespace std;

int main() {
  cout << "=== Quadratic Equation Solver ===" << endl << endl;

  // Test 1: Default constructor
  cout << "Test 1: Default Constructor" << endl;
  Quadratic q;
  cout << "Default equation: " << q.toString() << endl;
  cout << "Solving: " << q.solve() << endl << endl;

  // Test 2: Parameterized constructor with normal values
  cout << "Test 2: Quadratic x^2 + 2x + 1 = 0 (one root)" << endl;
  Quadratic q1(1, 2, 1);
  cout << "Equation: " << q1.toString() << endl;
  cout << "Solving: " << q1.solve() << endl << endl;

  // Test 3: Quadratic with two distinct roots
  cout << "Test 3: Quadratic x^2 - 5x + 6 = 0 (two roots)" << endl;
  Quadratic q2(1, -5, 6);
  cout << "Equation: " << q2.toString() << endl;
  cout << "Solving: " << q2.solve() << endl << endl;

  // Test 4: Quadratic with no real roots
  cout << "Test 4: Quadratic x^2 + 1 = 0 (no real roots)" << endl;
  Quadratic q3(1, 0, 1);
  cout << "Equation: " << q3.toString() << endl;
  cout << "Solving: " << q3.solve() << endl << endl;

  // Test 5: Add two quadratics
  cout << "Test 5: Addition of Quadratics" << endl;
  cout << "Q1: " << q1.toString() << endl;
  cout << "Q2: " << q2.toString() << endl;
  Quadratic q_sum = q1.add(q2);
  cout << "Sum: " << q_sum.toString() << endl;
  cout << "Solving sum: " << q_sum.solve() << endl << endl;

  // Test 6: Subtract two quadratics
  cout << "Test 6: Subtraction of Quadratics" << endl;
  cout << "Q2: " << q2.toString() << endl;
  cout << "Q1: " << q1.toString() << endl;
  Quadratic q_diff = q2.subtract(q1);
  cout << "Difference (Q2 - Q1): " << q_diff.toString() << endl;
  cout << "Solving difference: " << q_diff.solve() << endl << endl;

  // Test 7: Constructor validation (a cannot be 0)
  cout << "Test 7: Constructor with a = 0 (should default to 1)" << endl;
  Quadratic q4(0, 3, 2);  // a=0, should become 1
  cout << "Equation: " << q4.toString() << endl;
  cout << "Solving: " << q4.solve() << endl << endl;

  // Test 8: Negative coefficients
  cout << "Test 8: Negative Coefficients (2x^2 - 3x - 5 = 0)" << endl;
  Quadratic q5(2, -3, -5);
  cout << "Equation: " << q5.toString() << endl;
  cout << "Solving: " << q5.solve() << endl << endl;

  // Test 9: Chained operations
  cout << "Test 9: Chained Operations" << endl;
  Quadratic q6(1, 1, 1);
  Quadratic q7(2, 2, 2);
  Quadratic q8 = q6.add(q7).add(q7);
  cout << "Result after multiple adds: " << q8.toString() << endl;
  cout << "Solving: " << q8.solve() << endl;

  return 0;
}
#include <iostream>
#include "Account.h"

using namespace std;

void ex3_9(){
  Account acc1(50, "Jamal Khan");
  
  cout << "Account: " << acc1.getName() << ", Balance: $" << acc1.getBalance() << endl;
  
  // Test successful withdrawal
  cout << "\nAttempting to withdraw $20..." << endl;
  acc1.withdraw(20);
  
  // Test withdrawal that exceeds balance
  cout << "\nAttempting to withdraw $50..." << endl;
  acc1.withdraw(50);
  
  cout << "\nFinal balance: $" << acc1.getBalance() << endl;
}

int main(){
  ex3_9();
  return 0;
}

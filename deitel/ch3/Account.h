#include <iostream>
#include <string>

class Account {
public:
  Account(int bal, std::string nam){
    balance = bal;
    name = nam;
  }

  int getBalance(){
    return balance;
  }
  void setBalance(int bal){
    balance = bal;
  }

  std::string getName(){
    return name;
  }
  void setName(std::string account_name){
    name = account_name;
  }

  void withdraw(int withdrawal_amount) {
    if (balance >= withdrawal_amount) {
      balance -= withdrawal_amount;
      std::cout << "Withdrawal of $" << withdrawal_amount << " successful. "
                << "New balance: $" << balance << std::endl;
    } else {
      std::cout << "Withdrawal amount exceeded account balance." << std::endl;
    }
  }

private:
  int balance{0};
  std::string name;
};
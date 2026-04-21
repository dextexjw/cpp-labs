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

  int withdraw(int withdraw_ammount){
    if ( balance >= withdraw_ammount)
      balance -= withdraw_ammount;
    else
     return 0;
    return balance;
  }

private:
  int balance{0};
  std::string name;
};
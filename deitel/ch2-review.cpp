#include "iostream"

void review2_3(){
  // 2.3a
  int c{0}, thisIsAVariable{0}, q76354{0};
  
  //2.3b
  std::cout << "Enter an Integer: ";
  std::cin >> c;
  
  //2.3c
  std::cout << "Plus 10 equals -> " << c+10 << std::endl;
  
  //2.3d
  if (c > 15) {
    c -= 5;
    std::cout << "If the value is greater then 15, minus 10 equals -> " << c << std::endl;
  }
  
  //2.3f
  std::cout << " This is a C++ \n program" << std::endl;
  
  //2.3g
  std::cout << " This \n is \n a \n C++ \n program" << std::endl;
  
  //2.3h
  std::cout << " This \t is \t a \t C++ \t program" << std::endl;
}

int review2_4(){
  // calculate the product of three int
  int a = 0, b = 0, c = 0, result = 0;

  std::cout << "Enter the three integers: ";
  std::cin >> a >> b >> c;

  result = a * b * c;
  std::cout << "Product of the three integer is: " << result << std::endl;

  return result;
}

int main () {

  int returned_value = 0;
  returned_value = review2_4();  

  std::cout << "retuned_value is " << returned_value;

  //std::cout << "Hello World!";
  return 0;
}

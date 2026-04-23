#ifndef MATH_H
#define MATH_H

class Math {
 public:
  Math();
  ~Math();

  int add(int x, int y);
  int multiply(int x, int y); 

  private:
    signed int x;
    signed int y;

};

#endif

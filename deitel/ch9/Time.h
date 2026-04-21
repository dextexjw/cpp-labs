#ifndef TIME_H
#define TIME_H

class Time {
 public:
  Time();
  Time(int hour, int minute, int second);

  void setTime(int hour, int minute, int second);
  void printUniversal() const;
  void printStandard() const;

 private:
  unsigned int hour{0};
  unsigned int minute{0};
  unsigned int second{0};
};

#endif

#include "Time.h"

#include <ctime>
#include <iomanip>
#include <iostream>
#include <stdexcept>

using namespace std;

Time::Time() {
  const time_t now = time(nullptr);
  const tm* local = localtime(&now);

  if (local == nullptr) {
    throw runtime_error("localtime failed");
  }

  setTime(local->tm_hour, local->tm_min, local->tm_sec);
}

Time::Time(int hour, int minute, int second) {
  setTime(hour, minute, second);
}

void Time::setTime(int h, int m, int s) {
  if ((h >= 0 && h < 24) && (m >= 0 && m < 60) && (s >= 0 && s < 60)) {
    hour = static_cast<unsigned int>(h);
    minute = static_cast<unsigned int>(m);
    second = static_cast<unsigned int>(s);
  } else {
    throw invalid_argument("hour, minute and/or second was out of range");
  }
}

void Time::printUniversal() const {
  cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2)
       << second;
}

void Time::printStandard() const {
  cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":" << setfill('0') << setw(2)
       << minute << ":" << setw(2) << second << (hour < 12 ? " AM" : " PM");
}

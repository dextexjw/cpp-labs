#include <cstdint>
#include <string>

class DollarAmount {
 public:
  explicit DollarAmount(int64_t value = 0) : amount{value} {}

  DollarAmount(int64_t dollars, int64_t cents)
      : amount{dollars * 100 + cents} {}

  int64_t getAmount() const { return amount; }

  DollarAmount operator+(const DollarAmount& other) const {
    return DollarAmount{amount + other.amount};
  }

  DollarAmount operator-(const DollarAmount& other) const {
    return DollarAmount{amount - other.amount};
  }

  void add(DollarAmount right) {
    amount += right.amount;
  }

  void subtract(DollarAmount right) {
    amount -= right.amount;
  }

  // Adds interest using banker's rounding (round-half-to-even)
  // This minimizes rounding bias by rounding to the nearest even number
  // when the remainder is exactly half the divisor
  void addInterest(int rate, int divisor) {
    int64_t numerator{amount * rate};
    int64_t quotient{numerator / divisor};
    int64_t remainder{numerator % divisor};
    
    // Get absolute values for rounding calculation
    int64_t absRemainder{remainder < 0 ? -remainder : remainder};
    int64_t absDivisor{divisor < 0 ? -divisor : divisor};
    int64_t doubledRemainder{absRemainder * 2};

    bool remainderIsMoreThanHalf{doubledRemainder > absDivisor};
    bool remainderIsExactlyHalf{doubledRemainder == absDivisor};
    bool quotientIsOdd{quotient % 2 != 0};

    bool shouldRound{
        remainderIsMoreThanHalf || (remainderIsExactlyHalf && quotientIsOdd)};

    if (shouldRound) {
      if (numerator < 0) {
        quotient -= 1;
      } else {
        quotient += 1;
      }
    }

    DollarAmount interest{quotient};
    add(interest);
  }

  void divide(int divisor) {
    amount = (amount + divisor / 2) / divisor;
  }

  std::string toString() const {
    // Extract dollars (integer division by 100)
    std::string dollars{std::to_string(amount / 100)};
    
    // Extract cents with proper absolute value handling for negatives
    int64_t centsAmount{amount % 100};
    centsAmount = centsAmount < 0 ? -centsAmount : centsAmount;
    
    // Format cents with leading zero if single digit
    std::string cents{std::to_string(centsAmount)};
    std::string centsPadded{cents.size() == 1 ? "0" + cents : cents};
    
    return dollars + "." + centsPadded;
  }

 private:
  int64_t amount{0};
};

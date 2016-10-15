#include <string>

class Account {
public:
  void calculate() { amount += amount * interestRate; }
  static double rate() { return interestRate; }
  static void rate(double newRate) { interestRate = newRate; }

private:
  std::string owner;
  double amount;
  static double interestRate;
  static constexpr double todayRate = 5.75;
  static double initRate() { return todayRate; }
};

double Account::interestRate = initRate();

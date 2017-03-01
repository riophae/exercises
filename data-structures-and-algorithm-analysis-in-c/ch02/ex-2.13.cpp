#include <cmath>
#include <iostream>

bool isPrime(int n) {
  int r = sqrt(n);

  for (int i = 2; i <= r; ++i) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}

int main() {
  std::cout << isPrime(2) << std::endl;
  std::cout << isPrime(7) << std::endl;
  std::cout << isPrime(16) << std::endl;

  return 0;
}

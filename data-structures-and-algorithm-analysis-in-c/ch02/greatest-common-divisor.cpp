#include <iostream>

unsigned int gcd(unsigned int m, unsigned int n) {
  unsigned int rem;

  while (n > 0) {
    rem = m % n;
    m = n;
    n = rem;
  }

  return m;
}

int main() {
  std::cout << gcd(1989, 1590) << std::endl;

  return 0;
}

#include <iostream>

long int pow(long int x, unsigned int n) {
  if (n <= 1) return n == 1 ? x : 1;
  if (n % 2 == 0) return pow(x * x, n / 2);
  return pow(x * x, n / 2) * x;
}

int main() {
  std::cout << pow(2, 20) << std::endl;

  return 0;
}

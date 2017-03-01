#include <iostream>

int pow(int x, unsigned int power) {
  int result = 1;
  int n = x;

  while (power > 0) {
    if ((power & 1) == 1) {
      result *= n;
    }
    n *= n;
    power >>= 1;
  }

  return result;
}

int main() {
  std::cout << pow(2, 10) << std::endl;

  return 0;
}

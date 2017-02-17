#include <iostream>

int calcMod(int radix, int power, int mod) {
  if (power == 0) {
    return 1 % mod;
  } else if (power == 1) {
    return 2 % mod;
  } else if (power % 2 == 0) {
    int temp = calcMod(radix, power / 2, mod);
    return temp * temp % mod;
  } else {
    int f1 = calcMod(radix, power / 2, mod);
    int f2 = calcMod(radix, power - (power / 2), mod);
    return (f1 * f2) % mod;
  }
}

int main() {
  std::cout << calcMod(2, 100, 5) << std::endl;

  return 0;
}

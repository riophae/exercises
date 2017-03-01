#include <cmath>
#include <iostream>

void findPrimesLessThan(const int n) {
  int *primes = new int[n + 1];

  for (int i = 2; i <= n; ++i) {
    primes[i] = i;
  }

  for (int i = 2; i < sqrt(n); ++i) {
    if (primes[i] == -1) {
      continue;
    }

    int j = i;
    while ((j += i) <= n) {
      primes[j] = -1;
    }
  }

  for (int i = 2; i <= n; ++i) {
    if (primes[i] != -1) std::cout << i << " ";
  }
  std::cout << std::endl;
}

int main() {
  findPrimesLessThan(128);

  return 0;
}

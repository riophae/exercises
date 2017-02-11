#include <cstring>
#include <iostream>
#include <cmath>

void calcAllPermutations(char *str, const int len) {
  int n = 0;
  const int max = pow(len, len);

  while (n < max) {
    int i = n;
    int j = 0;

    while (i > 0) {
      const int r = i % len;
      std::cout << str[r];
      i = (i - r) / len;
      ++j;
    }

    while (j++ < len) {
      std::cout << str[0];
    }

    std::cout << std::endl;
    ++n;
  }
}

int main() {
  char str[] = "abc";
  calcAllPermutations(str, strlen(str));

  return 0;
}

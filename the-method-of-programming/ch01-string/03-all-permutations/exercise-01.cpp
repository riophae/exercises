#include <cstring>
#include <iostream>
#include <cmath>

void calcAllPermutations(const char *str, const int len) {
  int n = 0;
  const int max = pow(len, len);
  char *digits = new char[len];

  while (n < max) {
    int i = n;
    int j = 0;

    while (i > 0) {
      const int r = i % len;
      digits[len - j - 1] = str[r];
      i = (i - r) / len;
      ++j;
    }

    while (j < len) {
      digits[len - j - 1] = str[0];
      ++j;
    }

    std::cout << digits << " ";
    ++n;
  }

  std::cout << std::endl;
}

int main() {
  char str[] = "abc";
  calcAllPermutations(str, strlen(str));

  return 0;
}

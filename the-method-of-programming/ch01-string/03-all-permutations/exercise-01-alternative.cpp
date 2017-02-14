#include <cstring>
#include <iostream>
#include <cmath>

void calcAllPermutations(const char *str, const int len, const int level) {
  static char *p = new char[len];

  for (int i = 0; i < len; ++i) {
    p[level] = str[i];
    if (level == len - 1) {
      std::cout << p << " ";
    } else {
      calcAllPermutations(str, len, level + 1);
    }
  }

  if (level == 0) {
    std::cout << std::endl;
  }
}

int main() {
  const char str[] = "abc";
  calcAllPermutations(str, strlen(str), 0);

  return 0;
}

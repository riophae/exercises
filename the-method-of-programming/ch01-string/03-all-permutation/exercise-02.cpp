#include <cstring>
#include <iostream>

void calcAllCombinations(char *str) {
  const int base = strlen(str);
  const int max = base * 2 + 1;
  int n = 1;

  while (n <= max) {
    int i = 0;

    while (i < base) {
      if ((1 << i) & n) std::cout << str[i];
      ++i;
    }

    std::cout << std::endl;
    ++n;
  }
}

int main() {
  char str[] = "abc";
  calcAllCombination(str);

  return 0;
}

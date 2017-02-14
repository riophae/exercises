#include <cstring>
#include <algorithm>
#include <iostream>

void countOccurrences(const char *str) {
  const int len = strlen(str);
  int count[256];
  std::fill(count, count + 256, 0);

  for (int i = 0; i < len; ++i) {
    ++count[(int)str[i]];
  }

  for (int i = 0; i < 256; ++i) {
    if (count[i] > 0) {
      std::cout << "[" << (char)i << "]" << count[i] << " ";
    }
  }
  std::cout << std::endl;
}

int main() {
  countOccurrences("*Riophae*Lee*");

  return 0;
}

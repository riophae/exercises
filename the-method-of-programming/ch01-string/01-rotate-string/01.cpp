#include <cstring>
#include <iostream>

void leftShiftOne(char *str, int len) {
  char initial = str[0];
  for (int i = 1; i < len; ++i) {
    str[i - 1] = str[i];
  }
  str[len - 1] = initial;
}

void rotateString(char *str, int len, int n) {
  while (n--) {
    leftShiftOne(str, len);
  }
}

int main() {
  char str[] = "abcdef";
  rotateString(str, strlen(str), 3);
  std::cout << str << std::endl;

  return 0;
}

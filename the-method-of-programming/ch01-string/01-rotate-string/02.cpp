#include <cstring>
#include <iostream>

void reverseString(char *str, int from, int to) {
  while (from < to) {
    char t = str[from];
    str[from++] = str[to];
    str[to--] = t;
  }
}

void rotateString(char *str, int len, int n) {
  reverseString(str, 0, n - 1);
  reverseString(str, n, len - 1);
  reverseString(str, 0, len - 1);
}

int main() {
  char str[] = "abcdef";
  rotateString(str, strlen(str), 3);
  std::cout << str << std::endl;

  return 0;
}

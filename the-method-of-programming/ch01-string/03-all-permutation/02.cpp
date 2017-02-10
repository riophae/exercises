#include <string.h>
#include <iostream>

void swap(char &i, char &j) {
  const int temp = i;
  i = j;
  j = temp;
}

void reverse(char *i, char *j) {
  while (i < j) {
    const char temp = *i;
    *i = *j;
    *j = temp;
    i++;
    j--;
  }
}

bool calcNextPermutation(char *str, int len) {
  int i = len - 2;
  while (i >= 0 && str[i] >= str[i + 1]) i--;
  if (i < 0) return false;

  int j = len - 1;
  while (str[i] > str[j]) j--;
  swap(str[i], str[j]);

  reverse(str + i + 1, str + len - 1);

  return true;
}

int main() {
  char str[] = "12345";
  while (calcNextPermutation(str, strlen(str))) {
    std::cout << str << std::endl;
  }

  return 0;
}

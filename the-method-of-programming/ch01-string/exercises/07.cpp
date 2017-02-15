#include <cstring>
#include <iostream>

void swap(char *str, int i, int j) {
  const char temp = str[i];
  str[i] = str[j];
  str[j] = temp;
}

void findFirstLetterThatOccursOnce(char *str) {
  const int len = strlen(str);

  for (int i = 0; i < len; ) {
    int count = 1;
    int j = i + 1;

    while (j < len) {
      if (str[j] == str[i]) {
        swap(str, i + count, j);
        ++count;
      }
      ++j;
    }

    if (count == 1) {
      std::cout << str[i] << std::endl;
      return;
    }

    i += count;
  }
}

int main() {
  char str[] = "abaccdeff";
  findFirstLetterThatOccursOnce(str);

  return 0;
}

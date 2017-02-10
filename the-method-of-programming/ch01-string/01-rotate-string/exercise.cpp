#include <iostream>

void reverseString(char *str, int from, int to) {
  while (from < to) {
    char t = str[from];
    str[from++] = str[to];
    str[to--] = t;
  }
}

void reverseWords(char *str) {
  int i = 0, j = 0;

  while (true) {
    if (str[i + 1] == '\0' || str[i + 1] == ' ') {
      reverseString(str, j, i);

      if (str[i + 1] == '\0') {
        break;
      }

      j = i + 2;
    }

    ++i;
  }

  reverseString(str, 0, i);
}

int main() {
  char str[] = "I am a student.";
  reverseWords(str);
  std::cout << str << std::endl;

  return 0;
}

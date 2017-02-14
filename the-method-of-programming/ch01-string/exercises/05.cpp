#include <cstring>
#include <cctype>
#include <iostream>

void reverseString(char *str, int head, int tail) {
  while (head < tail) {
    const char temp = str[head];
    str[head] = str[tail];
    str[tail] = temp;
    ++head;
    --tail;
  }
}

void squashWhitespacesAndReverseWords(char *str) {
  int len = strlen(str);
  int from, to;

  for (from = 0, to = 0; from < len; ++from, ++to) {
    if (isspace(str[from])) {
      str[to] = ' ';
      while (from + 1 < len && isspace(str[from + 1])) {
        ++from;
      }
    } else {
      str[to] = str[from];

      const int start = to;
      while (from + 1 < len && !isspace(str[from + 1])) {
        ++from;
        ++to;
        str[to] = str[from];
      }
      reverseString(str, start, to);
    }
  }

  str[to] = 0;
}

int main() {
  char str[] = "abc  efg hij";
  squashWhitespacesAndReverseWords(str);
  std::cout << str << std::endl;

  return 0;
}

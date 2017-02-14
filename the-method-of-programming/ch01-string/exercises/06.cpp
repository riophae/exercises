#include <cstring>
#include <iostream>

void zipString(char *str) {
  const int len = strlen(str);
  int from, to;

  for (from = 0, to = 0; from < len; ++from, ++to) {
    int count = 1;

    while (from + 1 < len && str[from] == str[from + 1]) {
      ++count;
      ++from;
    }

    if (count > 1) {
      str[to++] = '0' + count;
    }
    str[to] = str[from];
  }

  str[to] = 0;
}

int main() {
  char str[] = "cccddecc";
  zipString(str);
  std::cout << str << std::endl;

  return 0;
}

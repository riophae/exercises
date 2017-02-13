#include <cstring>
#include <iostream>

void moveAsterisks(char *str) {
  int count = 0;
  int len = strlen(str);

  for (int to = len - 1, from; to >= 0; --to) {
    while (from = to - count, from >= 0 && str[from] == '*') {
      ++count;
    }

    str[to] = from < 0 ? '*' : str[from];
  }
}

int main() {
  char str[] = "*Riophae*Lee*";
  moveAsterisks(str);
  std::cout << str << std::endl;

  return 0;
}

#include <cstring>
#include <iostream>

void reverseString(char *str) {
  char *head = str;
  char *tail = head + strlen(str) - 1;

  while (head < tail) {
    char temp = *head;
    *head = *tail;
    *tail = temp;
    ++head;
    --tail;
  }
}

int main() {
  char string[] = "July";
  reverseString(string);
  std::cout << string << std::endl;

  return 0;
}

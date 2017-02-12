#include <iostream>

bool isPalindrome(const char *str, int n) {
  if (str == NULL || n < 1) {
    return false;
  }

  const char *head = str;
  const char *tail = str + n - 1;

  while (head < tail) {
    if (*head != *tail) return false;
    ++head;
    --tail;
  }

  return true;
}

int main() {
  std::cout << isPalindrome("abc", 3) << std::endl;
  std::cout << isPalindrome("abba", 4) << std::endl;

  return 0;
}

#include <iostream>

bool isPalindrome(const char *str, int n) {
  if (str == NULL || n < 1) {
    return false;
  }

  const char *left = str + ((n - 1) / 2);
  const char *right = str + (n / 2);

  while (left >= str) {
    if (*left != *right) return false;
    --left;
    ++right;
  }

  return true;
}

int main() {
  std::cout << isPalindrome("abc", 3) << std::endl;
  std::cout << isPalindrome("abba", 4) << std::endl;

  return 0;
}

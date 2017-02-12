#include <climits>
#include <cctype>
#include <iostream>

int strToInt(const char *str) {
  unsigned int n = 0;
  int sign = 1;

  while (isspace(*str)) {
    ++str;
  }

  if (*str == '+' || *str == '-') {
    if (*str == '-') sign = -1;
    ++str;
  }

  while (isdigit(*str)) {
    unsigned int c = *str - '0';
    if (sign > 0) {
      if (n > (INT_MAX - c) / 10) {
        return INT_MAX;
      }
    } else if (n > ((unsigned)INT_MIN - c) / 10) {
      return INT_MIN;
    }
    n = n * 10 + c;
    ++str;
  }

  return sign > 0 ? n : -n;
}

int main() {
  std::cout << strToInt("2147483646") << std::endl;
  std::cout << strToInt("2147483647") << std::endl;
  std::cout << strToInt("2147483648") << std::endl;
  std::cout << strToInt("21474836470") << std::endl;

  std::cout << strToInt("-2147483647") << std::endl;
  std::cout << strToInt("-2147483648") << std::endl;
  std::cout << strToInt("-2147483649") << std::endl;
  std::cout << strToInt("-21474836480") << std::endl;

  std::cout << strToInt("  233") << std::endl;
  std::cout << strToInt("42abc") << std::endl;
  std::cout << strToInt("") << std::endl;

  return 0;
}

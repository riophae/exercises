#include <cstring>
#include <algorithm>
#include <iostream>

void findLongestPalindrome(const char *original_str) {
  const int original_len = strlen(original_str);
  const int len = original_len * 2 + 3;
  char *str = new char[len];
  int *p = new int[len];
  int pos = 0;
  int max_right = 0;

  str[0] = '^';
  str[len - 1] = '$';
  for (int i = 0; i < original_len; ++i) {
    str[2 * i + 1] = '#';
    str[2 * i + 2] = original_str[i];
  }
  str[len - 2] = '#';

  for (int i = 1; i < len - 2; ++i) {
    if (max_right > i) {
      p[i] = std::min(max_right - i, p[2 * pos - i]);
    } else {
      p[i] = 1;
    }

    while (str[i - p[i]] == str[i + p[i]]) {
      ++p[i];
    }

    if (p[i] > p[pos]) {
      pos = i;
      max_right = i + p[i] - 1;
    }
  }

  const int result = pos > 0 ? p[pos] - 1 : 0;
  std::cout << result << " ";
  for (int i = pos - result + 1; i < pos + result; i += 2) {
    std::cout << str[i];
  }
  std::cout << std::endl;
}

int main() {
  findLongestPalindrome("baxae");
  findLongestPalindrome("axxae");
  findLongestPalindrome("gbbcxcbbe");
  findLongestPalindrome("aaaa");
  findLongestPalindrome("aaa");
  findLongestPalindrome("a^aa");
  findLongestPalindrome("aa^a");
  findLongestPalindrome("");
  findLongestPalindrome("sator arepo tenet opera rotas");

  return 0;
}

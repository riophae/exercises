#include <cstring>
#include <iostream>

void findLongestPalindrome(const char *str) {
  int max = 0;
  int max_start = -1;
  int max_end = -1;
  int len = strlen(str);
  int n;
  int start;
  int end;

  for (int i = 0; i < len; ++i) {
    for (int j = 0; i - j >= 0 && i + j < len; ++j) {
      if (str[i - j] != str[i + j]) break;
      n = j * 2 + 1;
      start = i - j;
      end = i + j;
    }
    if (n > max) {
      max = n;
      max_start = start;
      max_end = end;
    }

    for (int j = 0; i - j >= 0 && i + j + 1 < len; ++j) {
      if (str[i - j] != str[i + j + 1]) break;
      n = j * 2 + 2;
      start = i - j;
      end = i + j + 1;
    }
    if (n > max) {
      max = n;
      max_start = start;
      max_end = end;
    }
  }

  std::cout << max << " ";
  if (max_start > -1) {
    for (int i = max_start; i <= max_end; ++i) {
      std::cout << str[i];
    }
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

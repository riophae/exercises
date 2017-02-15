#include <cstring>
#include <iostream>

int sign(const char letter) {
  return 1 << (letter - 'a');
}

void deleteSpecificLetters(char *text, const char *pattern) {
  int textLen = strlen(text);
  int patternLen = strlen(pattern);
  int s = 0;
  int i, from, to;

  for (i = 0; i < patternLen; ++i) {
    s |= sign(pattern[i]);
  }

  for (from = 0, to = 0; from < textLen; ++from) {
    if ((sign(text[from]) & s) == 0) {
      text[to] = text[from];
      ++to;
    }
  }
  text[to] = 0;
}

int main() {
  char text[] = "They are students.";
  const char pattern[] = "aeiou";
  deleteSpecificLetters(text, pattern);
  std::cout << text << std::endl;

  return 0;
}

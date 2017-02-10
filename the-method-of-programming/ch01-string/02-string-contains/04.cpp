#include <string>
#include <assert.h>
#include <iostream>

bool stringContains(const std::string &a, const std::string &b) {
  int hash = 0;
  for (const char c: a) {
    hash |= 1 << (c - 'a');
  }

  for (const char c: b) {
    if ((hash & (1 << (c - 'a'))) == 0) {
      return false;
    }
  }

  return true;
}

int main() {
  assert(stringContains("abcd", "bad"));
  assert(!stringContains("abcd", "bce"));
  assert(stringContains("abcd", "aa"));
  assert(!stringContains("", "a"));
  assert(stringContains("a", ""));

  return 0;
}

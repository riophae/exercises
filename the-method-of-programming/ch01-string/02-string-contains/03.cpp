#include <string>
#include <assert.h>

bool stringContains(const std::string &a, const std::string &b) {
  static const int primes[26] = {
      2,   3,   5,   7,  11,
     13,  17,  19,  23,  29,
     31,  37,  41,  43,  47,
     53,  59,  61,  67,  71,
     73,  79,  83,  89,  97,
    101
  };

  int product = 1;
  for (const char c: a) {
    int x = primes[c - 'a'];
    if (product % x) product *= x;
  }

  for (const char c: b) {
    if (product % primes[c - 'a']) return false;
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

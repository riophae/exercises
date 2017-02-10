#include <string>
#include <assert.h>

bool stringContains(const std::string &a, const std::string &b) {
  unsigned int i, j = 0;
  while (j < b.length()) {
    i = 0;
    while (i < a.length() && a[i] != b[j]) ++i;
    if (i >= a.length()) return false;
    ++j;
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

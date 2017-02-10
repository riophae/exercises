#include <string>
#include <algorithm>
#include <assert.h>

bool stringContains(const std::string &_a, const std::string &_b) {
  std::string a = _a, b = _b;
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  unsigned int i = 0, j = 0;
  while (j < b.length()) {
    while (i < a.length() && a[i] < b[j]) i += 1;
    if (i >= a.length() || a[i] > b[j]) return false;
    j += 1;
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

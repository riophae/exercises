#include <cstring>
#include <iostream>

int sign(const char* word) {
  static const int primes[26] = {
      2,   3,   5,   7,  11,
     13,  17,  19,  23,  29,
     31,  37,  41,  43,  47,
     53,  59,  61,  67,  71,
     73,  79,  83,  89,  97,
    101
  };
  int product = 1;
  int len = strlen(word);

  for (int i = 0; i < len; ++i) {
    product *= primes[word[i] - 'a'];
  }

  return product;
}

void findAnagrams(const char* word, const char* *dict, const int count) {
  const int wordSignature = sign(word);

  for (int i = 0; i < count; ++i) {
    const int signature = sign(dict[i]);
    if (wordSignature == signature) {
      std::cout << dict[i] << std::endl;
    }
  }
}

int main() {
  const int count = 6;
  const char* dict[count] = {
    "pans",
    "pots",
    "opt",
    "snap",
    "stop",
    "tops",
  };
  const char* word = "naps";
  findAnagrams(word, dict, count);

  return 0;
}

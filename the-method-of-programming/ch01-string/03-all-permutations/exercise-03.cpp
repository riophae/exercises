#include <string>
#include <iostream>

void _calcAllPermutations(std::string prefix, const int level, const int from) {
  for (int i = from; i <= 26 - level; ++i) {
    std::string str = prefix;
    str += 'a' + i;
    if (level > 1) _calcAllPermutations(str, level - 1, i + 1);
    else std::cout << str << std::endl;
  }
}

void calcAllPermutations(const int n) {
  _calcAllPermutations("", n, 0);
}

int main() {
  calcAllPermutations(3);

  return 0;
}

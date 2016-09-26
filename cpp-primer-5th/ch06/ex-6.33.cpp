#include <iostream>
#include <vector>

void print(const std::vector<int>& iv, const decltype(iv.size())& index) {
  if (iv.empty() || index == iv.size()) return;
  std::cout << iv[index] << std::endl;
  print(iv, index + 1);
}

int main() {
  print({}, 0);
  print({ 1, 2, 3 }, 0);
  return 0;
}

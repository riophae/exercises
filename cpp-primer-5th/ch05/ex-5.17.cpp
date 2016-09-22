#include <iostream>
#include <vector>

bool is_prefix(const std::vector<int> &v1, const std::vector<int> &v2) {
  auto size1 = v1.size(), size2 = v2.size();
  auto min = size1 > size2 ? size2 : size1;
  for (decltype(min) i = 0; i < min; ++i) {
    if (v1[i] != v2[i]) return false;
  }
  return true;
}

int main() {
  std::vector<int> v1 = { 0, 1, 2 },
                   v2 = { 0, 1, 2, 3 },
                   v3 = { 2, 3, 5 };
  std::cout << "1 <> 2 : " << is_prefix(v1, v2) << std::endl;
  std::cout << "1 <> 3 : " << is_prefix(v1, v3) << std::endl;
  return 0;
}

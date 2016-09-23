#include <iostream>
#include <string>

int main() {
  bool flag = false;
  std::string prev, curr;
  while (std::cin >> curr) {
    if (!prev.empty()) {
      if (curr == prev) {
        flag = true;
        break;
      }
    }
    prev = curr;
  }
  if (flag) {
    std::cout << "Repeating word: " << curr << std::endl;
  } else {
    std::cout << "No repeating word." << std::endl;
  }
  return 0;
}

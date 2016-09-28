#include <iostream>
#include <vector>

using BINARY_OP_FN = int(const int&, const int&);

int plus(const int& i1, const int& i2) {
  return i1 + i2;
}

int minus(const int& i1, const int& i2) {
  return i1 - i2;
}

int multiply(const int& i1, const int& i2) {
  return i1 * i2;
}

int divide(const int& i1, const int& i2) {
  return i1 / i2;
}

std::vector<BINARY_OP_FN*>math_fns = { plus, minus, multiply, divide };

int main() {
  const int a = 8, b = 4;
  for (BINARY_OP_FN* fn: math_fns) {
    std::cout << fn(a, b) << std::endl;
  }
  return 0;
}

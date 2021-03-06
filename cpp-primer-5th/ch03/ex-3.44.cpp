#include <iostream>
#include <iterator>

// using int_array = int[4];
typedef int int_array[4];

int_array ia[3] = {
  0,  1,  2,  3,
  4,  5,  6,  7,
  8,  9, 10, 11,
};

void fn1() {
  for (const int_array &row: ia) {
    for (const int &i: row) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
}

void fn2() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      std::cout << ia[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void fn3() {
  for (const int_array *i = std::begin(ia); i != std::end(ia); i++) {
    for (const int *j = std::begin(*i); j != std::end(*i); j++) {
      std::cout << *j << " ";
    }
    std::cout << std::endl;
  }
}

void fn4() {
  for (const int_array *i = ia; i != ia + 3; i++) {
    for (const int *j = *i; j != *i + 4; j++) {
      std::cout << *j << " ";
    }
    std::cout << std::endl;
  }
}

int main() {
  fn1();
  std::cout << "------" << std::endl;
  fn2();
  std::cout << "------" << std::endl;
  fn3();
  std::cout << "------" << std::endl;
  fn4();
  std::cout << "------" << std::endl;
  return 0;
}

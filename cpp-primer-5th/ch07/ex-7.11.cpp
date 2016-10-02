#include <iostream>
#include "ex-7.11.hpp"

int main() {
  Sales_data a;
  Sales_data b("978-1-118-29052-1");
  Sales_data c("978-7-5019-9469-4", 5, 10.0);
  Sales_data d(std::cin);
  print(std::cout << "a: ", a);
  print(std::cout << "b: ", b);
  print(std::cout << "c: ", c);
  print(std::cout << "d: ", d);
  return 0;
}

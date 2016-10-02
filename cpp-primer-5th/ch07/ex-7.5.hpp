#include <string>

struct Person {
  std::string name;
  std::string address;

  std::string& getName() { return name; }
  std::string& getAddress() { return address; }
};

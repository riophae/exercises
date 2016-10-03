#include <iostream>
#include <string>

struct Person;
std::istream read(std::istream& is, const Person&);

struct Person {
  std::string name;
  std::string address;

  Person() = default;
  Person(const std::string name_, const std::string address_):
                      name(name_),          address(address_) { }
  Person(std::istream& is) { read(is, *this); }

  std::string getName() const { return name; }
  std::string getAddress() const { return address; }
};

std::istream& read(std::istream& is, Person& item) {
  is >> item.name >> item.address;
  return is;
}

std::ostream& print(std::ostream& os, const Person& item) {
  os << item.name << " " << item.address;
  return os;
}

#include <iostream>
#include <string>

struct Sales_data;
std::istream& read(std::istream&, Sales_data&);

struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;

  Sales_data() = default;
  Sales_data(const std::string& str): bookNo(str) { }
  Sales_data(const std::string& str, unsigned num, double price):
             bookNo(str), units_sold(num), revenue(price * num) { }
  Sales_data(std::istream& is) { read(is, *this); }

  std::string isbn() { return bookNo; }
  Sales_data& combine(const Sales_data&);
};

Sales_data& Sales_data::combine(const Sales_data& rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

std::istream& read(std::istream& is, Sales_data& item) {
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}

std::ostream& print(std::ostream& os, const Sales_data& item) {
  os << item.bookNo << " " << item.units_sold << " " << item.revenue;
  return os;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
  Sales_data sum = lhs;
  sum.combine(rhs);
  return sum;
}

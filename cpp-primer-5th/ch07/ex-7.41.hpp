#include <iostream>
#include <string>

class Sales_data {
private:
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;

public:
  Sales_data() = default;
  Sales_data(const std::string& str, unsigned num, double price):
             bookNo(str), units_sold(num), revenue(price * num) { std::cout << "3" << std::endl; }
  Sales_data(const std::string& str): Sales_data(str, 0, 0) { std::cout << "1" << std::endl; }
  Sales_data(std::istream& is) { read(is, *this); }

  std::string isbn() { return bookNo; }
  Sales_data& combine(const Sales_data&);

private:
  double avg_price() const { return units_sold ? revenue / units_sold : 0; }

friend Sales_data add(const Sales_data&, const Sales_data&); // this is not necessary, since it won't access private class members
friend std::istream& read(std::istream&, Sales_data&);
friend std::ostream& print(std::ostream&, const Sales_data&);
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

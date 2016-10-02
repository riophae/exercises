#include <iostream>
#include <string>

struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;

  std::string isbn() { return bookNo; }
  Sales_data& combine(const Sales_data& rhs);
};

Sales_data& Sales_data::combine(const Sales_data& rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

std::istream &read(Sales_data &item) {
  std::cout << "> ";
  double price = 0;
  std::cin >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return std::cin;
}

std::ostream &print(const Sales_data &item) {
  std::cout << "< " << item.bookNo << " " << item.units_sold << " " << item.revenue << std::endl;
  return std::cout;
}

int main() {
  Sales_data total;
  if (read(total)) {
    Sales_data trans;
    while (read(trans)) {
      if (total.bookNo == trans.bookNo) {
        total.combine(trans);
      } else {
        print(total);
        total = trans;
      }
    }
    print(total);
  }
  return 0;
}

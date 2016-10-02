#include <iostream>
#include <string>

struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

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

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;
  sum.units_sold += rhs.units_sold;
  sum.revenue += rhs.revenue;
  return sum;
}

int main() {
  Sales_data total;
  if (read(total)) {
    Sales_data trans;
    while (read(trans)) {
      if (total.bookNo == trans.bookNo) {
        total = add(total, trans);
      } else {
        print(total);
        total = trans;
      }
    }
    print(total);
  }
  return 0;
}

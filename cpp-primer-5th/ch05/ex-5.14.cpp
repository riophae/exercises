#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> vword;
std::vector<int> vcount;

int find_index(const std::string &word) {
  auto size = vword.size();
  decltype(size) i = 0;
  while (i < size) {
    if (vword[i] == word) return i;
    ++i;
  }
  return -1;
}

bool is_already_exists(const std::string &word) {
  return find_index(word) > -1;
}

void get_input() {
  std::string word;
  while (std::cin >> word) {
    int index = find_index(word);
    if (index > -1) {
      ++vcount[index];
    } else {
      vword.push_back(word);
      vcount.push_back(1);
    }
  }
}

decltype(vcount.size()) find_max_index() {
  auto size = vcount.size();
  decltype(size) i, max_index = 0;
  int max_count = 0;
  for (i = 0; i < size; ++i) {
    if (vcount[i] > max_count) {
      max_count = vcount[i];
      max_index = i;
    }
  }
  return max_index;
}

int main() {
  get_input();
  auto max_index = find_max_index();
  int max_count = vcount[max_index];
  std::string most_repeating_word = vword[max_index];
  std::cout << '"' << most_repeating_word << '"'
            << " has appeared " << max_count
            << " times." << std::endl;
  return 0;
}

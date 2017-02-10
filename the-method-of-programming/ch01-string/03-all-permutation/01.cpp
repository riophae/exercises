#include <iostream>

void swap(char &a, char &b) {
  const int temp = a;
  a = b;
  b = temp;
}

void calcAllPermutation(char *perm, int from, int to) {
  if (to <= 1) return;

  if (from == to) {
    for (int i = 0; i <= to; i++) {
      std::cout << perm[i];
    }
    std::cout << std::endl;
  } else {
    for (int j = from; j <= to; j++) {
      swap(perm[j], perm[from]);
      calcAllPermutation(perm, from + 1, to);
      swap(perm[j], perm[from]);
    }
  }
}

int main() {
  char str[] = "abc";
  calcAllPermutation(str, 0, 2);

  return 0;
}

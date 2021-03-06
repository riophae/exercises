#include <stdio.h>
#include <stdlib.h>

int numbers[1000];
int n = 0;

void print_numbers() {
  for (int i = 0; i < n; i++) {
    printf("%d ", numbers[i]);
  }

  printf("\n");
}

void swap(int x, int y) {
  if (x == y) return;
  int temp;
  temp = numbers[x];
  numbers[x] = numbers[y];
  numbers[y] = temp;
  print_numbers();
}

void quick_sort(int left, int right) {
  if (left >= right) return;
  int base = numbers[left];
  int l = left;
  int r = right;

  while (l < r) {
    while (r > l && numbers[r] >= base) r--;
    while (l < r && numbers[l] <= base) l++;
    swap(l, r);
  }

  swap(left, l);

  quick_sort(left, l - 1);
  quick_sort(l + 1, right);
}

void validate() {
  for (int i = 0; i < n - 1; i++) {
    if (numbers[i] > numbers[i + 1]) {
      printf("The order is wrong! \n");
      exit(1);
    }
  }
}

int main() {
  int t;

  while ((t = scanf("%d", &numbers[n])) != 0) {
    n++;
  }

  quick_sort(0, n - 1);
  validate();

  return 0;
}

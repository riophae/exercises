#include <stdio.h>

int main() {
  int i;

  int max = 10;
  int book[max + 1];
  for (i = 0; i <= max; i++) {
    book[i] = 0;
  }

  int n;
  printf("How much number do you want to input? ");
  scanf("%d", &n);

  int x;
  for (i = 0; i < n; i++) {
    printf("%d: ", i + 1);
    scanf("%d", &x);
    if (x < 0 || x > max) {
      printf("`%d` is not in 0~%d, try again\n", x, max);
      i--;
    } else {
      book[x]++;
    }
  }

  printf("\n");
  printf("Result: \n");

  for (i = 0; i <= max; i++) {
    printf("%d: %d\n", i, book[i]);
  }

  return 0;
}

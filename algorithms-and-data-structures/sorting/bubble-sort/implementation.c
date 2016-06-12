#include <stdio.h>

int main() {
  int i, j;

  int n;
  printf("How much number do you want to input? \n");
  scanf("%d", &n);

  int numbers[n];
  for (i = 0; i < n; i++) {
    printf("%d: ", i + 1);
    scanf("%d", &numbers[i]);
  }

  int temp;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - 1 - i; j++) {
      if (numbers[j] > numbers[j + 1]) {
        temp = numbers[j + 1];
        numbers[j + 1] = numbers[j];
        numbers[j] = temp;
      }
    }
  }

  printf("\n");
  printf("Sorted: \n");

  for (i = 0; i < n; i++) {
    printf("%d\n", numbers[i]);
  }

  return 0;
}

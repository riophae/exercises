#include <stdio.h>

#define LEN 9

int password[LEN] = { 6, 3, 1, 7, 5, 8, 9, 2, 4 };

int main() {
  int i, j, temp;

  i = 0;
  while (++i < LEN) {
    j = i;
    temp = password[j];
    while (j < LEN - 1) {
      password[j] = password[j + 1];
      j++;
    }
    password[j] = temp;
  }

  for (i = 0; i < LEN; i++) {
    printf("%d", password[i]);
  }

  printf("\n");

  return 0;
}

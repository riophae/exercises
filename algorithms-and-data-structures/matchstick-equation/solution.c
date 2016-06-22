#include <stdio.h>

int numberStickMap[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

int get_stick_number(int number) {
  int i = 0;
  while (number / 10) {
    i += numberStickMap[number % 10];
    number /= 10;
  }
  i += numberStickMap[number];
  return i;
}

int main() {
  int i, j, k, n = 0;
  int stickLimit = 24;

  for (i = 0; i <= 1111; i++) {
    for (j = 0; j <= 1111; j++) {
      k = i + j;
      if (get_stick_number(i) + get_stick_number(j) + get_stick_number(k) + 4 == stickLimit) {
        printf("%d + %d = %d\n", i, j, k);
        n++;
      }
    }
  }

  printf("Total: %d\n", n);
  return 0;
}

#include <stdio.h>

#define LEN 9

int password[LEN] = { 6, 3, 1, 7, 5, 8, 9, 2, 4 };
int mapped_idx[LEN] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
int result_idx[LEN];

int main() {
  int i = 0;
  int j;

  while (i < LEN) {
    j = 0;
    while (j < LEN) {
      if (mapped_idx[j] == i + 1) {
        mapped_idx[j] = LEN - 1;
      } else if (mapped_idx[j] > i + 1) {
        mapped_idx[j]--;
      }
      j++;
    }
    i++;
  }

  i = 0;
  while (i < LEN) {
    result_idx[mapped_idx[i]] = i;
    i++;
  }

  i = 0;
  while (i < LEN) {
    printf("%d", password[result_idx[i]]);
    i++;
  }

  printf("\n");

  return 0;
}

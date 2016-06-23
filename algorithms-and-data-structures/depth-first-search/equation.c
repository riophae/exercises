#include <stdio.h>

int numbers[9];
int book[10];

int
convert_number(int x, int y, int z) {
  return (
    x * 100 +
    y * 10 +
    z
  );
}

void
dfs(int step) {
  if (step == 9) {
    int a = convert_number(numbers[0], numbers[1], numbers[2]);
    int b = convert_number(numbers[3], numbers[4], numbers[5]);
    int c = convert_number(numbers[6], numbers[7], numbers[8]);
    if (a + b == c) {
      printf("%d + %d = %d\n", a, b, c);
    }
    return;
  }

  for (int i = 1; i <= 9; i++) {
    if (book[i] == 0) {
      book[i] = 1;
      numbers[step] = i;
      dfs(step + 1);
      book[i] = 0;
    }
  }
}

int
main() {
  dfs(0);
  return 0;
}

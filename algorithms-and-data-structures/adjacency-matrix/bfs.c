#include <stdio.h>

#define N 5

int matrix[N][N] = {
  { 0, 1, 1, -1, 1 },
  { 1, 0, -1, 1, -1 },
  { 1, -1, 0, -1, 1 },
  { -1, 1, -1, 0, -1 },
  { 1, -1, 1, -1, 0 },
};
int book[N];

int
main() {
  int queue[N * N];
  int head = 0, tail = 0;

  queue[tail] = 0;
  book[0] = 1;
  tail++;

  int i, curr;
  while (head < tail) {
    curr = queue[head];
    for (i = 0; i < N; i++) {
      if (matrix[curr][i] == 1 && book[i] == 0) {
        queue[tail] = i;
        book[i] = 1;
        tail++;
      }
    }
    head++;
  }

  for (i = 0; i < tail; i++) {
    printf("%d\n", queue[i]);
  }

  return 0;
}

#include <stdio.h>

#define H 5
#define W 5

#define N 5

int matrix[H][W] = {
  { 0, 1, 1, -1, 1 },
  { 1, 0, -1, 1, -1 },
  { 1, -1, 0, -1, 1 },
  { -1, 1, -1, 0, -1 },
  { 1, -1, 1, -1, 0 },
};
int book[N];

void
dfs(int curr) {
  printf("%d\n", curr);
  book[curr] = 1;
  for (int i = 0; i < N; i++) {
    if (matrix[curr][i] == 1 && book[i] == 0) {
      dfs(i);
    }
  }
}

int
main() {
  dfs(0);
  return 0;
}

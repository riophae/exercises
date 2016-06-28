#include <stdio.h>

int map[50][50];
int book[50];
int stack[2500];
int top = 0;
int n, m;
int shortest = -1;

void
dfs(int curr) {
  int i;

  stack[top++] = curr;
  book[curr] = 1;

  if (curr == n - 1) {
    printf("Path: ");
    int distance = 0;
    for (i = 0; i < top; i++) {
      if (i > 0) distance += map[stack[i - 1]][stack[i]];
      printf("%d ", stack[i]);
    }
    printf("Distance: %d\n", distance);
    if (shortest == -1 || distance < shortest) {
      shortest = distance;
    }
    return;
  }

  for (i = 0; i < n; i++) {
    if (map[curr][i] > 0 && book[i] == 0) {
      dfs(i);
      top--;
      book[i] = 0;
    }
  }
}

int
main() {
  int i, j;
  int a, b, c;

  for (i = 0; i < 50; i++) {
    for (j = 0; j < 50; j++) {
      map[i][j] = i == j ? 0 : -1;
    }
  }

  printf("How many cities & paths? ");
  scanf("%d %d", &n, &m);
  printf("\n");

  for (i = 0; i < m; i++) {
    printf("#%d: ", i);
    scanf("%d %d %d", &a, &b, &c);
    map[a][b] = c;
    printf("\n");
  }

  dfs(0);
  printf("The shortest distance is %d.\n", shortest);

  return 0;
}

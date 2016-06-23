#include <stdio.h>

int box[10], book[10], n = 4;

void dfs(int step) {
  int i;

  if (step == n + 1) {
    for (i = 1; i <= n; i++) {
      printf("%d", box[i]);
    }
    printf("\n");
    return;
  }

  for (i = 1; i <= n; i++) {
    if (book[i] == 0) {
      book[i] = 1;
      box[step] = i;
      dfs(step + 1);
      book[i] = 0;
    }
  }
}

int main() {
  dfs(1);
  return 0;
}

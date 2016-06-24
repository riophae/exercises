#include <stdio.h>

#define W 4
#define H 5

int map[H][W] = {
  { 0, 0, 1, 0 },
  { 0, 0, 0, 0 },
  { 0, 0, 1, 0 },
  { 0, 1, 0, 0 },
  { 0, 0, 0, 1 },
};
int book[H][W];
int entry_x = 0, entry_y = 0;
int goal_x = 3, goal_y = 2;
int moves[4][2] = {
  { 0, 1 },
  { 1, 0 },
  { 0, -1 },
  { -1, 0 },
};
int min = -1;

void
dfs(int curr_pos_x, int curr_pos_y, int step) {
  if (curr_pos_x == goal_x && curr_pos_y == goal_y) {
    if (min == -1 || min > step) {
      min = step;
    }
    return;
  }

  int i;
  int next_pos_x, next_pos_y;

  for (i = 0; i < 4; i++) {
    next_pos_x = curr_pos_x + moves[i][0];
    next_pos_y = curr_pos_y + moves[i][1];

    if (
      next_pos_x < 0 ||
      next_pos_x >= H ||
      next_pos_y < 0 ||
      next_pos_y >= W ||
      map[next_pos_x][next_pos_y] != 0 ||
      book[next_pos_x][next_pos_y] != 0
    ) {
      continue;
    }

    book[next_pos_x][next_pos_y] = 1;
    dfs(next_pos_x, next_pos_y, step + 1);
    book[next_pos_x][next_pos_y] = 0;
  }
}

int
main() {
  dfs(entry_x, entry_y, 0);
  printf("%d\n", min);
  return 0;
}

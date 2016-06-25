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

typedef struct {
  int x;
  int y;
  int step;
} Note;
Note queue[H * W];
int head = 0, tail = 0;

int entry_x = 0, entry_y = 0;
int goal_x = 3, goal_y = 2;

int moves[4][2] = {
  { 0, 1 },
  { 1, 0 },
  { 0, -1 },
  { -1, 0 },
};

int
enqueue(int x, int y, int step) {
  queue[tail].x = x;
  queue[tail].y = y;
  queue[tail].step = step;
  return tail++;
}

int
dequeue() {
  return ++head;
}

int
main() {
  int i;

  enqueue(entry_x, entry_y, 0);

  int next_x, next_y, next_step;
  int flag = 0;
  while (head < tail) {
    for (i = 0; i < 4; i++) {
      next_x = queue[head].x + moves[i][0];
      next_y = queue[head].y + moves[i][1];

      if (
        next_x < 0 ||
        next_x >= H ||
        next_y < 0 ||
        next_y >= W ||
        map[next_x][next_y] != 0 ||
        book[next_x][next_y] != 0
      ) {
        continue;
      }

      next_step = queue[head].step + 1;
      enqueue(next_x, next_y, next_step);
      book[next_x][next_y] = 1;

      if (next_x == goal_x && next_y == goal_y) {
        flag = 1;
        break;
      }
    }

    if (flag == 1) {
      break;
    }

    dequeue();
  }

  printf("%d\n", queue[tail - 1].step);

  return 0;
}

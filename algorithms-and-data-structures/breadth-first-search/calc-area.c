#include <stdio.h>

#define W 10
#define H 10

int map[H][W] = {
  { 1, 2, 1, 0, 0, 0, 0, 0, 2, 3 },
  { 3, 0, 2, 0, 1, 2, 1, 0, 1, 2 },
  { 4, 0, 1, 0, 1, 2, 3, 2, 0, 1 },
  { 3, 2, 0, 0, 0, 1, 2, 4, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 1, 5, 3, 0 },
  { 0, 1, 2, 1, 0, 1, 5, 4, 3, 0 },
  { 0, 1, 2, 3, 1, 3, 6, 2, 1, 0 },
  { 0, 0, 3, 4, 8, 9, 7, 5, 0, 0 },
  { 0, 0, 0, 3, 7, 8, 6, 0, 1, 2 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
};
int book[H][W];
int moves[4][2] = {
  { 1, 0 },
  { 0, 1 },
  { -1, 0 },
  { 0, -1 },
};

typedef struct {
  int x;
  int y;
} pos;

pos queue[H * W];
int head = 0, tail = 0;

int area = 0;

void
enqueue(pos p) {
  queue[tail].x = p.x;
  queue[tail].y = p.y;
  tail++;
}

void
dequeue() {
  head++;
}

void do_book(pos p) {
  book[p.x][p.y] = 1;
}

int
main() {
  int i;

  pos entry;
  entry.x = 5;
  entry.y = 7;
  enqueue(entry);
  do_book(entry);
  area++;

  pos curr, next;
  while (head < tail) {
    curr = queue[head];

    for (i = 0; i < 4; i++) {
      next.x = curr.x + moves[i][0];
      next.y = curr.y + moves[i][1];

      if (
        map[next.x][next.y] == 0 ||
        book[next.x][next.y] == 1
      ) {
        continue;
      }

      enqueue(next);
      do_book(next);
      area++;
    }

    dequeue();
  }

  printf("Area of land: %d\n", area);

  return 0;
}

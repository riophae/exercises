#include <stdio.h>

#define SIZE 6
#define INFINITY 999999

int map[6][6] = {
  { 0       , 1       , 12,       INFINITY, INFINITY, INFINITY },
  { INFINITY, 0       , 9,        3,        INFINITY, INFINITY },
  { INFINITY, INFINITY, 0,        INFINITY, 5,        INFINITY },
  { INFINITY, INFINITY, 4,        0,        13,       15       },
  { INFINITY, INFINITY, INFINITY, INFINITY, 0,        4        },
  { INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, 0        },
};
int book[SIZE];
int dist[SIZE];
int entry = 0;

int
main() {
  int i, j;

  for (i = 0; i < SIZE; i++) {
    dist[i] = map[entry][i];
  }

  for (i = 0; i < SIZE; i++) {
    int curr = -1;
    for (j = 0; j < SIZE; j++) {
      if (j == entry || book[j]) continue;
      if (curr == -1 || dist[j] < dist[curr]) {
        curr = j;
      }
    }
    if (curr == -1) continue;
    book[curr] = 1;
    printf("Shortest: #%d\n", curr);

    for (j = 0; j < SIZE; j++) {
      if (j == curr || map[curr][j] == INFINITY) continue;
      if (dist[curr] + map[curr][j] < dist[j]) {
        printf("Found shorter path between %d and %d: %d -> %d -> %d\n",
          entry, j, entry, curr, j);
        dist[j] = dist[curr] + map[curr][j];
      }
    }
  }
  printf("\n");

  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
      printf("%d\t", map[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  printf("Result: \n");
  for (i = 0; i < SIZE; i++) {
    printf("%d\t", dist[i]);
  }
  printf("\n");

  return 0;
}

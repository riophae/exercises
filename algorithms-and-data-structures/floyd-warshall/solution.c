#include <stdio.h>

#define SIZE 4
#define INFINITE 999999

int map[SIZE][SIZE] = {
  { 0,        2,        6,        4        },
  { INFINITE, 0,        3,        INFINITE },
  { 7,        INFINITE, 0,        1        },
  { 5,        INFINITE, 12,       0        },
};

void
printMap() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf("%d\t", map[i][j]);
    }
    printf("\n");
  }
}

int
main() {
  printf("Original:\n");
  printMap();

  int needOptimization = 1;
  int i = 0;
  while (needOptimization) {
    needOptimization = 0;
    printf("\n");
    printf("Optimization#%d:\n", i++);
    for (int j = 0; j < SIZE; j++) {
      for (int k = 0; k < SIZE; k++) {
        for (int l = 0; l < SIZE; l++) {
          int newDist = map[j][l] + map[l][k];
          if (newDist < map[j][k]) {
            map[j][k] = newDist;
            printf("Found shorter path between P%d and P%d: P%d -> P%d -> P%d\n", j, k, j, l, k);
            needOptimization = 1;
          }
        }
      }
    }
    printMap();
  }

  return 0;
}

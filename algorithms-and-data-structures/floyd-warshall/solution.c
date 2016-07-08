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

  int needOptimizationInNextCycle = 1;
  int cycle = 0;
  while (needOptimizationInNextCycle) {
    needOptimizationInNextCycle = 0;
    printf("\n");
    printf("Optimization#%d:\n", cycle++);
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        for (int k = 0; k < SIZE; k++) {
          int oldDist = map[i][j];
          int newDist = map[i][k] + map[k][j];
          if (newDist < map[i][j]) {
            map[i][j] = newDist;
            printf("Found shorter path between P%d and P%d: P%d -> P%d -> P%d, distance shortened from %d to %d\n",
              i, j, i, k, j, oldDist, newDist);
            needOptimizationInNextCycle = 1;
          }
        }
      }
    }
    if (needOptimizationInNextCycle) {
      printMap();
    } else {
      printf("No optimization made in this cycle.\n");
    }
  }

  return 0;
}

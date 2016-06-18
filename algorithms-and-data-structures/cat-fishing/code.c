#include <stdio.h>

struct stack {
  int data[100];
  int top;
};

struct queue {
  int data[100];
  int head;
  int tail;
};

int main() {
  int i, j;

  struct stack pool;
  pool.top = 0;

  struct queue players[2];

  for (i = 0; i < 2; i++) {
    players[i].head = players[i].tail = 0;
    for (j = 0; j < 6; j++) {
      printf("Player%d#%d: ", i, j);
      scanf("%d", &(players[i].data[players[i].tail++]));
      printf("\n");
    }
  }

  int curr_card;
  int n = 0;
  int is_in_pool;
  while (players[0].head < players[0].tail && players[1].head < players[1].tail) {
    for (i = 0; i < 2; i++) {
      curr_card = players[i].data[players[i].head++];
      printf("#%d Current Player: %d\tCurrent card: %d\n", ++n, i, curr_card);
      is_in_pool = 0;
      for (j = 0; j < pool.top; j++) {
        if (pool.data[j] == curr_card) {
          is_in_pool = 1;
          break;
        }
      }
      pool.data[pool.top++] = curr_card;
      if (!is_in_pool) {
        printf("Card %d is not in pool\n", curr_card);
      } else {
        printf("Card %d is in pool\n", curr_card);
        players[i].data[players[i].tail++] = pool.data[--pool.top];
        if (pool.top > 0) {
          while (pool.top > 0 && pool.data[pool.top - 1] != curr_card) {
            players[i].data[players[i].tail++] = pool.data[--pool.top];
          }
          if (pool.top > 0 && pool.data[pool.top - 1] == curr_card) {
            players[i].data[players[i].tail++] = pool.data[--pool.top];
          }
        }
      }

      printf("Total in Pool: %d \tPool: ", pool.top);
      for (j = 0; j < pool.top; j++) {
        printf("%d ", pool.data[j]);
      }
      printf("\n");

      printf("Cards of Player#%d: ", i);
      for(j = players[i].head; j < players[i].tail; j++) {
        printf("%d ", players[i].data[j]);
      }
      printf("\n");

      printf("\n");
      if (players[i].head == players[i].tail) break;
    }
  }

  for (i = 0; i < 2; i++) {
    if (players[i].head < players[i].tail) {
      printf("Player%d wins!\n", i);
      break;
    }
  }
}

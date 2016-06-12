#include <stdio.h>

#define LEN 9

struct queue {
  int data[100];
  int head;
  int tail;
};

int password[LEN] = { 6, 3, 1, 7, 5, 8, 9, 2, 4 };

int main() {
  struct queue q;

  q.head = 0;
  q.tail = 0;
  for (q.tail = 0; q.tail < LEN; q.tail++) {
    q.data[q.tail] = password[q.tail];
  }

  while (q.head < q.tail) {
    printf("%d", q.data[q.head++]);
    q.data[q.tail++] = q.data[q.head++];
  }

  return 0;
}

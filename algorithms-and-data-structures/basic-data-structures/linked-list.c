#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

int main() {
  int count;
  printf("How many numbers would you like to enter? ");
  scanf("%d", &count);

  struct node *head, *p, *q;
  head = NULL;

  int num;
  for (int i = 0; i < count; i++) {
    p = (struct node *)malloc(sizeof(struct node));
    printf("#%d: ", i);
    scanf("%d", &num);
    p->data = num;
    p->next = NULL;
    if (head == NULL) {
      head = p;
    } else {
      if (num < head->data) {
        p->next = head;
        head = p;
      } else {
        q = head;
        while (q->next != NULL && q->next->data < num) {
          q = q->next;
        }
        p->next = q->next;
        q->next = p;
      }
    }
  }

  p = head;
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");

  return 0;
}

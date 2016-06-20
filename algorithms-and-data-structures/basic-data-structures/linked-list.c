#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

int main() {
  int n;
  printf("How many numbers would you like to enter? ");
  scanf("%d", &n);

  struct node *head, *prev, *curr;
  head = NULL;

  for (int i = 0; i < n; i++) {
    curr = (struct node *)malloc(sizeof(struct node));
    printf("#%d: ", i);
    scanf("%d", &(curr->data));
    curr->next = NULL;
    if (head == NULL) {
      head = curr;
    } else {
      prev->next = curr;
    }
    prev = curr;
  }

  curr = head;
  while (1) {
    if (curr != NULL) {
      printf("%d ", curr->data);
      curr = curr->next;
    } else {
      break;
    }
  }
  printf("\n");

  return 0;
}

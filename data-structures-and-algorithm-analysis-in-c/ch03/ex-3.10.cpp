#include <stdlib.h>
#include <iostream>

#define _DEBUG false

typedef struct node {
  int id;
  struct node *prev;
  struct node *next;
} *Node;

Node
makeNode() {
  Node p = (Node)malloc(sizeof(Node));
  p->next = NULL;
  p->prev = NULL;
  return p;
}

int
JosephusProblem (const int N, const int M) {
  std::cout << "Josephus Problem: N = " << N << ", M = " << M << std::endl;

  Node head = makeNode(), prev = head, curr, p;
  int i = head->id = 1;

  while (i++ < N) {
    prev->next = curr = makeNode();
    curr->id = i;
    curr->prev = prev;
    prev = curr;
  }
  curr->next = head;
  head->prev = curr;

#if _DEBUG
  int _i;
  Node _p;

  _i = N;
  _p = head;
  while (_i-- > 0) {
    _p = _p->prev;
    std::cout << _p->id << std::endl;
  }

  _i = N;
  _p = head;
  while (_i-- > 0) {
    std::cout << _p->id << std::endl;
    _p = _p->next;
  }
#endif

  p = head;
  while (p->next != p) {
    i = M;
    while (i-- > 0) {
      p = p->next;
    }
    std::cout << "Cleared: " << p->id << std::endl;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    Node tmp = p;
    p = p->next;
    free(tmp);
  }

  std::cout << "Winner is: " << p->id << std::endl;
  return p->id;
}

int
main() {
  JosephusProblem(5, 0);
  JosephusProblem(5, 1);

  return 0;
}

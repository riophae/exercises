#include "linked-list.h"
#include <stdlib.h>
#include <iostream>

List
reverseLinkedList(List L) {
  Position head, from = L, to = NULL, tmp;

  while (from != NULL) {
    tmp = MakeListNode();
    tmp->Element = from->Element;
    tmp->Next = to;
    to = tmp;
    from = from->Next;
  }
  head = to;

  return head;
}

List
makeList(int n) {
  Position head = MakeListNode(), prev = head, curr;
  int i = head->Element = 1;

  while (i++ < n) {
    prev->Next = curr = MakeListNode();
    curr->Element = i;
    prev = curr;
  }

  return head;
}

int
main() {
  List l = makeList(10);
  List rl = reverseLinkedList(l);

  PrintList(l);
  std::cout << "------" << std::endl;
  PrintList(rl);

  return 0;
}

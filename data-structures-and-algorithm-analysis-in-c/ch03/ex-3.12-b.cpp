#include "linked-list.h"
#include <stdlib.h>
#include <iostream>

List
reverseLinkedList(List L) {
  Position head, curr = L, prev = NULL, next;

  while (curr != NULL) {
    next = curr->Next;
    curr->Next = prev;
    prev = curr;
    curr = next;
  }
  head = prev;

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
  PrintList(l);

  std::cout << "------" << std::endl;

  l = reverseLinkedList(l);
  PrintList(l);

  return 0;
}

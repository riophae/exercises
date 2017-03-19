#include "linked-list.h"
#include <stdlib.h>
#include <iostream>

List
reverseLinkedList(Position p) {
  if (p->Next == NULL) {
    return p;
  }
  Position head = reverseLinkedList(p->Next);
  p->Next->Next = p;
  p->Next = NULL;
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

  List rl = reverseLinkedList(l);
  PrintList(rl);

  return 0;
}

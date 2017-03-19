#include "linked-list.h"
#include <stdlib.h>
#include <iostream>
#include <cmath>

Position
find(Position p, int x) {
  while (p != NULL) {
    if (p->Element == x) break;
    p = p->Next;
  }
  return p;
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
  int len = 10240000; // It's fine!
  List l = makeList(len);
  std::cout << (find(l, len) != NULL) << std::endl;

  return 0;
}

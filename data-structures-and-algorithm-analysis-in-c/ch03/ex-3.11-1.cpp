#include "linked-list.h"
#include <stdlib.h>
#include <iostream>
#include <cmath>

Position
find(Position p, int x) {
  if (p->Element == x) {
    return p;
  }
  return p->Next == NULL ? NULL : find(p->Next, x);
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
  int len = 43000; // It will crash if len is greater than ~43000
  List l = makeList(len);
  std::cout << (find(l, len) != NULL) << std::endl;

  return 0;
}

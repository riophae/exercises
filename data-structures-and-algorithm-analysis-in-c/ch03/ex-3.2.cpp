#include "linked-list.h"
#include <iostream>

void
PrintLots(List L, List P) {
  Position Node = P;

  while (Node != NULL) {
    Position Q = L;
    int i = 0;

    while (i != Node->Element) {
      Q = Q->Next;
      ++i;
    }
    std::cout << Q->Element << std::endl;

    Node = Node->Next;
  }
}

int main() {
  const int arrA[] =  { 0, 1, 4, 9, 16 };
  const int arrB[] =  { 3, 0, 2 };

  List L = ArrayToList(arrA, sizeof(arrA) / sizeof(arrA[0]));
  List P = ArrayToList(arrB, sizeof(arrB) / sizeof(arrB[0]));

  PrintLots(L, P);

  return 0;
}

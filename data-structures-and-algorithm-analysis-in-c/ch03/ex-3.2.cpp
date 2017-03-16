#include "linked-list.h"
#include <iostream>

int main() {
  const int arrA[] =  { 0, 1, 4, 9, 16 };
  const int arrB[] =  { 3, 0, 2 };

  List A = ArrayToList(arrA, sizeof(arrA) / sizeof(arrA[0]));
  List B = ArrayToList(arrB, sizeof(arrB) / sizeof(arrB[0]));

  Position P = B;
  while (P != NULL) {
    Position Q = A;
    int i = 0;

    while (i != P->Element) {
      Q = Q->Next;
      ++i;
    }
    std::cout << Q->Element << std::endl;

    P = P->Next;
  }

  return 0;
}

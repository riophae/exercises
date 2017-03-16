#include "linked-list.h"
#include <stdlib.h>
#include <iostream>

int main() {
  const int arrA[] = { 2, 3, 5, 7, 11, 13, 17 };
  const int arrB[] = { 3, 6, 9, 11, 13, 19 };

  List A = ArrayToList(arrA, sizeof(arrA) / sizeof(arrA[0]));
  List B = ArrayToList(arrB, sizeof(arrB) / sizeof(arrB[0]));

  Position P = A, Q = B;
  while (P != NULL && Q != NULL) {
    while (P != NULL && P->Element < Q->Element) P = P->Next;
    if (P == NULL) break;

    while (Q != NULL && P->Element > Q->Element) Q = Q->Next;
    if (Q == NULL) break;

    if (P->Element == Q->Element) {
      std::cout << P->Element << std::endl;
      P = P->Next;
      Q = Q->Next;
    }
  }

  return 0;
}

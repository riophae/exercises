#include "doubly-linked-list.h"
#include <stdlib.h>
#include <iostream>

void Swap(Position A, Position B) {
  Position PrevA, PrevB, AftA, AftB;

  PrevA = A->Prev;
  PrevB = B->Prev;
  AftA = A->Next;
  AftB = B->Next;

  if (PrevA != NULL) PrevA->Next = B;
  if (PrevB != NULL) PrevB->Next = A;

  if (AftA != NULL) AftA->Prev = B;
  if (AftB != NULL) AftB->Prev = A;

  A->Prev = PrevB;
  B->Prev = PrevA;

  A->Next = AftB;
  B->Next = AftA;
}

int main() {
  const int arr[] =  { 0, 1, 4, 9, 16 };
  List L = ArrayToList(arr, sizeof(arr) / sizeof(arr[0]));

  Position P4 = Find(4, L);
  Position P16 = Find(16, L);

  Swap(P4, P16);

  PrintList(L);

  std::cout << "------" << std::endl;

  Position PLast = FindLast(L);
  PrintListReversely(PLast);

  return 0;
}

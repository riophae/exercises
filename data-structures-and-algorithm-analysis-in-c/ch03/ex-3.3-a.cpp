#include "linked-list.h"
#include <iostream>

int main() {
  const int arr[] =  { 0, 1, 4, 9, 16 };
  List L = ArrayToList(arr, sizeof(arr) / sizeof(arr[0]));

  Position PP4 = FindPrevious(4, L);
  Position P4 = PP4->Next;
  Position PP16 = FindPrevious(16, L);
  Position P16 = PP16->Next;
  Position Tmp;

  Tmp = P4->Next;
  P4->Next = P16->Next;
  P16->Next = Tmp;
  PP4->Next = P16;
  PP16->Next = P4;

  PrintList(L);

  return 0;
}

#include <stdlib.h>
#include <iostream>

#ifndef _Linked_List_H
#define _Linked_List_H

#define ElementType int

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

// List MakeEmpty(List L);
// int IsEmpty(List L);
// int IsLast(Position P, List L);
// Position Find(ElementType X, List L);
// void Delete(ElementType X, List L);
// Position FindPrevious(ElementType X, List L);
// void Insert(ElementType X, List L, Position P);
// void DeleteList(List L);
// Position Header(List L);
// Position First(List L);
// Position Advance(Position P);
// ElementType Retrieve(Position P);

struct Node {
  ElementType Element;
  Position Next;
};

List MakeListNode()
{
  List L = (struct Node *)malloc(sizeof(struct Node));
  return L;
}

int
IsEmpty(List L)
{
  return L->Next == NULL;
}

int
IsLast(Position P, List L)
{
  return P->Next == NULL;
}

Position
Find(ElementType X, List L)
{
  Position P;

  P = L->Next;
  while (P != NULL && P->Element != X)
    P = P->Next;

  return P;
}

Position
FindPrevious(ElementType X, List L)
{
  Position P;

  P = L;
  while (P->Next != NULL && P->Next->Element != X)
    P = P->Next;

  return P;
}

void
Delete(ElementType X, List L)
{
  Position P, TmpCell;

  P = FindPrevious(X, L);

  if (!IsLast(P, L))
  {
    TmpCell = P->Next;
    P->Next = TmpCell->Next;
    free(TmpCell);
  }
}

void
Insert(ElementType X, List L, Position P)
{
  Position TmpCell;

  TmpCell = MakeListNode();

  TmpCell->Element = X;
  TmpCell->Next = P->Next;
  P->Next = TmpCell;
}

void
DeleteList(List L)
{
  Position P, Tmp;

  P = L->Next;
  L->Next = NULL;
  while (P != NULL)
  {
    Tmp = P->Next;
    free(P);
    P = Tmp;
  }
}

List
ArrayToList(const int *Arr, const int N)
{
  List L;
  Position Curr;

  Curr = L = MakeListNode();
  Curr->Element = Arr[0];

  for (int i = 1; i < N; ++i)
  {
    Insert(Arr[i], L, Curr);
    Curr = Curr->Next;
  }

  return L;
}

void
PrintList(List L)
{
  Position P = L;

  while (P != NULL)
  {
    std::cout << P->Element << std::endl;
    P = P->Next;
  }
}

#endif

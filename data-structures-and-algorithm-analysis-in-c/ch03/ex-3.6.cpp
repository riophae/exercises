#include <stdlib.h>
#include <vector>
#include <iostream>

struct Node {
  int Exponent;
  int Coefficient;
  struct Node *Next;
};

typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

Position
MakeNode() {
  Position P = (Position)malloc(sizeof(struct Node));
  P->Next = NULL;
  return P;
}

List
MakePolynomialList(std::vector<std::vector<int> > args) {
  List L = MakeNode();
  Position P = L;

  for (const auto arg: args) {
    P = P->Next = MakeNode();
    P->Exponent = arg[0];
    P->Coefficient = arg[1];
  }

  return L;
}

Position
First(List L) {
  return L->Next;
}

void
PrintList(List L) {
  Position P = L->Next;

  while (P != NULL) {
    if (P->Coefficient > 1) {
      std::cout << P->Coefficient;
    }

    if (P->Exponent > 0) {
      if (P->Exponent > 1) {
        std::cout << "x^" << P->Exponent;
      } else {
        std::cout << "x";
      }
    }

    if (P->Next != NULL) {
      std::cout << " + ";
    } else {
      std::cout << std::endl;
    }

    P = P->Next;
  }
}

int
main() {
  std::vector<std::vector<int>> ArgsA = { { 0, 1 }, { 14, 5 }, { 1000, 10 } };
  std::vector<std::vector<int>> ArgsB = { { 0, 5 }, { 1, 11 }, { 1492, -2 }, { 1990, 3 } };

  List PA = MakePolynomialList(ArgsA);
  List PB = MakePolynomialList(ArgsB);
  List PResult = MakeNode();

  Position P = First(PA), Q = First(PB), R = PResult;
  while (P != NULL || Q != NULL) {
    int Exponent, Coefficient;

    if (Q == NULL || (P != NULL && P->Exponent < Q->Exponent)) {
      Exponent = P->Exponent;
      Coefficient = P->Coefficient;
      P = P->Next;
    }

    else if (P == NULL || (Q != NULL && P->Exponent > Q->Exponent)) {
      Exponent = Q->Exponent;
      Coefficient = Q->Coefficient;
      Q = Q->Next;
    }

    else {
      Exponent = P->Exponent;
      Coefficient = P->Coefficient + Q->Coefficient;
      P = P->Next;
      Q = Q->Next;
    }

    R = R->Next = MakeNode();
    R->Exponent = Exponent;
    R->Coefficient = Coefficient;
  }

  PrintList(PResult);

  return 0;
}

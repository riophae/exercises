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
  P->Coefficient = 0;
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

bool
IsLast(Position P) {
  return P->Next == NULL;
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
  std::vector<std::vector<int>> ArgsA = { { 0, 1 }, { 2, 3 }, { 10, 2 } };
  std::vector<std::vector<int>> ArgsB = { { 0, 2 }, { 1, 4 }, { 2, 3 }, { 4, 3 } };

  List PA = MakePolynomialList(ArgsA);
  List PB = MakePolynomialList(ArgsB);
  List PResult = MakeNode();

  Position P = First(PA), Q;
  while (P != NULL) {
    Q = First(PB);

    while (Q != NULL) {
      int Exponent = P->Exponent + Q->Exponent;
      int Coefficient = P->Coefficient * Q->Coefficient;

      Position R, Prev;

      if (IsLast(PResult)) {
        R = PResult->Next = MakeNode();
      } else {
        Prev = PResult;
        R = First(PResult);

        while (!IsLast(R) && R->Next->Exponent <= Exponent) {
          Prev = R;
          R = R->Next;
        }

        if (R->Exponent != Exponent) {
          Position TmpCell = MakeNode();

          if (R->Exponent < Exponent) {
            TmpCell->Next = R->Next;
            R->Next = TmpCell;
          } else {
            Prev->Next = TmpCell;
            TmpCell->Next = R;
          }

          R = TmpCell;
        }
      }

      R->Exponent = Exponent;
      R->Coefficient += Coefficient;

      Q = Q->Next;
    }

    P = P->Next;
  }

  PrintList(PResult);

  return 0;
}

#include <stdlib.h>
#include <vector>
#include <iostream>

#define _DEBUG false

#if _DEBUG
int MoveCount = 0;
#endif

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
  P->Exponent = 0;
  P->Coefficient = 0;
  return P;
}

List
MakePolynomialList(const std::vector<std::vector<int> > ArgList) {
  List L = MakeNode();
  Position P = L;

  for (const auto ExponentAndCoefficient: ArgList) {
    P = P->Next = MakeNode();
    P->Exponent = ExponentAndCoefficient[0];
    P->Coefficient = ExponentAndCoefficient[1];
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
  Position P = First(L);

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

    if (!IsLast(P)) {
      std::cout << " + ";
    } else {
      std::cout << std::endl;
    }

    P = P->Next;
  }
}

List
MultiplyPolynomial(List PA, List PB) {
  // Both lists of PA & PB are assumed to be in ascending order.

  List PResult = MakeNode();

  Position P = First(PA), Q;
  while (P != NULL) {
    Q = First(PB);
    Position R = First(PResult);

    while (Q != NULL) {
      int Exponent = P->Exponent + Q->Exponent;
      int Coefficient = P->Coefficient * Q->Coefficient;

      if (IsLast(PResult)) {
        R = PResult->Next = MakeNode();
      } else {
        while (!IsLast(R) && R->Next->Exponent <= Exponent) {
#if _DEBUG
          // If PA has less elements than PB, then we can move less here
          ++MoveCount;
#endif
          R = R->Next;
        }

        if (R->Exponent < Exponent) {
          Position TmpCell = MakeNode();
          TmpCell->Next = R->Next;
          R = R->Next = TmpCell;
#if _DEBUG
        } else if (R->Exponent > Exponent) {
          std::cout << "The input polynomials may be not in ascending order!" << std::endl;
#endif
        }
      }

      R->Exponent = Exponent;
      R->Coefficient += Coefficient;

      Q = Q->Next;
    }

    P = P->Next;
  }

  return PResult;
}

List
PolynomialPow(const List P, const int Exponent) {
  if (Exponent < 1) {
    std::cout << "ERROR" << std::endl;
    return MakeNode();
  }

  if (Exponent == 1) {
    return P;
  }

  List Q = PolynomialPow(P, Exponent / 2);
  List SqaureQ = MultiplyPolynomial(Q, Q);

  return Exponent % 2 == 0
    ? SqaureQ
    : MultiplyPolynomial(P, SqaureQ); // P has less or same elements than SqaureQ
}

int
main() {
  std::vector<std::vector<int>> Args = { { 1, 2 }, { 3, 9 }, { 4, 10 } };

  List P = MakePolynomialList(Args);

  List PResult = PolynomialPow(P, 3);
  PrintList(PResult);

  // Expected result:
  // 8x^3 + 108x^5 + 120x^6 + 486x^7 + 1080x^8 + 1329x^9 + 2430x^10 + 2700x^11 + 1000x^12

#if _DEBUG
  std::cout << "MoveCount: " << MoveCount << std::endl;
#endif

  return 0;
}

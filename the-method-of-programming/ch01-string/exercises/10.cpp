#include <iostream>

struct LinkedList {
  int value;
  LinkedList *next;
};

void printLinkedList(const LinkedList *ll) {
  while (ll != 0) {
    std::cout << ll->value << " ";
    ll = ll->next;
  }
  std::cout << std::endl;
}

LinkedList *createLinkedListFromArray(const int *arr, const int n) {
  LinkedList *head = new LinkedList;
  LinkedList *node = head;

  for (int i = 0; i < n; ++i) {
    node->value = arr[i];
    node->next = new LinkedList;
    node = node->next;
  }

  return head;
}

void calcComplementSet(LinkedList* &setA, const LinkedList *setB) {
  LinkedList *head = new LinkedList;
  head->next = setA;
  const LinkedList *b = setB;

  while (b != 0) {
    LinkedList *prev = head;
    LinkedList *a = setA;

    while (a != 0) {
      if (a->value == b->value) {
        prev->next = a->next;
        break;
      } else {
        prev = a;
      }
      a = a->next;
    }

    b = b->next;
  }

  setA = head->next;
}

int main() {
  const int listA[] = { 5, 10, 20, 15, 25, 30 };
  LinkedList *setA = createLinkedListFromArray(listA, 6);
  const int listB[] = { 5, 15, 35, 25 };
  LinkedList *setB = createLinkedListFromArray(listB, 6);
  calcComplementSet(setA, setB);
  printLinkedList(setA);

  return 0;
}

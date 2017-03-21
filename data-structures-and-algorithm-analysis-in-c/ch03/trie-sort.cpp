#include <cstdlib>
#include <iostream>

#define __DEBUG__ false
#define TrieSize 10

typedef struct TrieNode {
  int value;
  int count;
  struct TrieNode *children[TrieSize];
} TrieNode, *PtrToTrieNode, *Trie;

typedef struct LinkedListNode {
  PtrToTrieNode value;
  struct LinkedListNode *next;
} LinkedListNode, *PtrToLinkedListNode, *LinkedList;

PtrToTrieNode
makeTrieNode() {
  PtrToTrieNode p = (PtrToTrieNode) malloc(sizeof(TrieNode));
  p->count = 0;
  for (int i = 0; i < TrieSize; i++)
    p->children[i] = NULL;
  return p;
}

PtrToLinkedListNode
makeLinkedListNode(PtrToTrieNode t) {
  PtrToLinkedListNode p = (PtrToLinkedListNode) malloc(sizeof(LinkedListNode));
  p->value = t;
  return p;
}

int
getMax(const int *arr, const int n) {
  int max = arr[0];
  for (int i = 0; i < n; i++)
    if (max < arr[i]) max = arr[i];
  return max;
}

void
insertIntoTrie(const Trie root, const int value, int exp) {
  PtrToTrieNode t = root;
  int which;
  int r = value;

  while (exp > 0) {
    which = r / exp;
#if __DEBUG__
    std::cout << which << " ";
#endif
    r -= which * exp;

    if (t->children[which] == NULL)
      t->children[which] = makeTrieNode();

    t = t->children[which];
    exp /= TrieSize;
  }

#if __DEBUG__
  std::cout << std::endl;
#endif
  t->value = value;
  t->count++;
}

int *
trieSort(int *arr, const int n) {
  Trie root = makeTrieNode();
  const int max = getMax(arr, n);

  int exp = 1;
  while (exp < max)
    exp *= TrieSize;

  for (int i = 0; i < n; i++)
    insertIntoTrie(root, arr[i], exp);

  LinkedList head = makeLinkedListNode(root), curr = head, last = curr;
  while (curr != NULL) {
    for (int i = 0; i < TrieSize; i++) {
      PtrToTrieNode t = curr->value;

      if (t->children[i] != NULL)
        last = last->next = makeLinkedListNode(t->children[i]);
    }

    curr = curr->next;
  }

  LinkedList l = head;
  int j = 0;
  while (l != NULL) {
    PtrToTrieNode t = l->value;
    int i = 0;

    while (i++ < t->count)
      arr[j++] = t->value;

    l = l->next;
  }

  return arr;
}

void
output(const int *arr, const int n) {
  for (int i = 0; i < n; i++) {
    std::cout << arr[i];

    if (i < n)
      std::cout << " ";
    else
      std::cout << std::endl;
  }
}

int
main() {
  int arr[] = { 5, 100, 3, 30, 33, 5, 20, 333, 8, 300, 1000, 0, 459, 23 };
  const int n = sizeof(arr) / sizeof(arr[0]);
  trieSort(arr, n);
  output(arr, n);

  return 0;
}

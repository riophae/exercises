#include <stdio.h>
#include <string.h>

struct stack {
  int data[100];
  int top;
};

int main() {
  int i;

  char str[100];
  gets(str);
  int len = strlen(str);
  int mid = len / 2 - 1;

  struct stack s;
  s.top = 0;

  i = 0;
  for (i = 0; i <= mid; i++) {
    s.data[++s.top] = str[i];
  }

  i = len % 2 == 0 ? mid + 1 : mid + 2;
  while (i < len) {
    if (s.data[s.top] != str[i]) break;
    s.top--;
    i++;
  }

  if (s.top == 0) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}

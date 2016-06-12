#include <stdio.h>

struct student {
  char name[21];
  int score;
};

int main() {
  int i, j;

  int n;
  printf("How much number of student do you want to input? \n");
  scanf("%d", &n);

  struct student students[n];
  for (i = 0; i < n; i++) {
    printf("%d: ", i + 1);
    scanf("%s %d", students[i].name, &students[i].score);
  }

  struct student temp;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - 1 - i; j++) {
      if (students[j].score > students[j + 1].score) {
        temp = students[j + 1];
        students[j + 1] = students[j];
        students[j] = temp;
      }
    }
  }

  printf("\n");
  printf("Sorted: \n");

  for (i = 0; i < n; i++) {
    printf("%s: %d\n", students[i].name, students[i].score);
  }

  return 0;
}

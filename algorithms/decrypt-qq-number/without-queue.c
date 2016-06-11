#include <stdio.h>

#define NUL 99999
#define LEN 9

#if 0
 密码为 631758924
 删除开头的一位数字，然后把下一位数字移动到密码末尾，如此不断重复
 最终把删除的数字依次拼接起来，即为加密前的原始值
 期望的结果为 615947283
#endif

int password[] = { 6, 3, 1, 7, 5, 8, 9, 2, 4 };
int qq[LEN];

int main() {
  int i = 0, j;
  int temp;

  while (password[0] != NUL) {
    qq[i++] = password[0];
    temp = password[1];
    j = 0;
    while (j < LEN - 2 && password[j + 2] != NUL) {
      password[j] = password[j + 2];
      j++;
    }
    password[j++] = temp;
    password[j] = NUL;
  }

  for (i = 0; i < LEN; i++) {
    printf("%d", qq[i]);
  }

  printf("\n");

  return 0;
}

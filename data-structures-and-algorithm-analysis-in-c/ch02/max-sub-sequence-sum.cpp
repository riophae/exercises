#include <iostream>

int maxSubSequenceSum(const int *arr, const int n) {
  int thisSum, maxSum, i, j, k;

  maxSum = 0;
  for (i = 0; i < n; ++i) {
    for (j = i; j < n; ++j) {
      thisSum = 0;

      for (k = i; k <= j; ++k) {
        thisSum += arr[k];
      }

      if (thisSum > maxSum) {
        maxSum = thisSum;
      }
    }
  }

  return maxSum;
}

int main() {
  const int arr[8] = { 4, -3, 5, -2, -1, 2, 6, -2 };
  std::cout << maxSubSequenceSum(arr, 8) << std::endl;

  return 0;
}

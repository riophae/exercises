#include <iostream>

int maxSubSequenceSum(const int *arr, const int n) {
  int maxSum, thisSum, i;

  maxSum = thisSum = 0;
  for (i = 0; i < n; ++i) {
    thisSum += arr[i];
    if (thisSum < 0) {
      thisSum = 0;
    } else if (thisSum > maxSum) {
      maxSum = thisSum;
    }
  }

  return maxSum;
}

int main() {
  const int arr[8] = { 4, -3, 5, -2, -1, 2, 6, -2 };
  std::cout << maxSubSequenceSum(arr, 8) << std::endl;

  return 0;
}

#include <iostream>

int minSubSequenceSum(const int *arr, const int n) {
  int i = 0, sum = 0, min = 999999;

  while (i < n) {
    sum += arr[i];
    if (sum > 0) sum = 0;
    if (sum < min) min = sum;
    ++i;
  }

  return min;
}

int main() {
  const int arr[8] = { 4, -3, 5, -2, -1, 2, 6, -2 };
  std::cout << minSubSequenceSum(arr, 8) << std::endl;

  return 0;
}

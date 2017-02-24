#include <iostream>

int minPositiveSubSequenceSum(const int *arr, const int n) {
  int min = 999999;

  for (int i = 0; i < n; ++i) {
    int sum = 0;
    for (int j = i; j < n; ++j) {
      sum += arr[j];
      if (sum > 0 && sum < min) {
        min = sum;
      }
    }
  }

  return min;
}

int main() {
  const int arr[8] = { 6, -100, 30, -2, -1, 0, 6, -2 };
  std::cout << minPositiveSubSequenceSum(arr, 8) << std::endl;

  return 0;
}

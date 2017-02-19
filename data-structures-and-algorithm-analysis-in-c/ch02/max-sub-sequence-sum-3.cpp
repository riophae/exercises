#include <iostream>

inline
int max3(const int &a, const int &b, const int &c) {
  return a > b
    ? a > c ? a : c
    : b > c ? b : c;
}

static
int maxSubSum(const int *arr, const int left, const int right) {
  int maxLeftSum, maxRightSum;
  int maxLeftBorderSum, maxRightBorderSum;
  int leftBorderSum, rightBorderSum;
  int center, i;

  if (left == right) {
    return arr[left] > 0 ? arr[left] : 0;
  }

  center = (left + right) / 2;
  maxLeftSum = maxSubSum(arr, left, center);
  maxRightSum = maxSubSum(arr, center + 1, right);

  maxLeftBorderSum = 0; leftBorderSum = 0;
  for (i = center; i >= left; --i) {
    leftBorderSum += arr[i];
    if (leftBorderSum > maxLeftBorderSum) {
      maxLeftBorderSum = leftBorderSum;
    }
  }

  maxRightBorderSum = 0; rightBorderSum = 0;
  for (i = center + 1; i <= right; ++i) {
    rightBorderSum += arr[i];
    if (leftBorderSum > maxRightBorderSum) {
      maxRightBorderSum = rightBorderSum;
    }
  }

  return max3(
    maxLeftSum,
    maxRightSum,
    maxLeftBorderSum + maxRightBorderSum
  );
}

int maxSubSequenceSum(const int *arr, const int n) {
  return maxSubSum(arr, 0, n - 1);
}

int main() {
  const int arr[8] = { 4, -3, 5, -2, -1, 2, 6, -2 };
  std::cout << maxSubSum(arr, 0, 8) << std::endl;

  return 0;
}

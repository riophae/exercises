#include <iostream>

int binarySearch(const int *arr, const int x, const int n) {
  int low, mid, high;

  low = 0; high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (arr[mid] < x) {
      low = mid + 1;
    } else if (arr[mid] > x) {
      high = mid - 1;
    } else {
      return mid;
    }
  }

  return -1;
}

int main() {
  const int arr[] = { 1, 10, 24, 44, 70, 99, 128, 300 };
  std::cout << binarySearch(arr, 300, sizeof(arr) / sizeof(arr[0])) << std::endl;

  return 0;
}

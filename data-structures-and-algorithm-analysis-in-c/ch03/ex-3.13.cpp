// http://www.sanfoundry.com/cpp-program-implement-radix-sort/

#include <iostream>

int
getMax(const int *arr, const int n) {
  int max = 0;
  for (int i = 0; i < n; ++i)
    if (arr[i] > max) max = arr[i];
  return max;
}

void
countSort(int *arr, const int n, const int exp, const int radix) {
  int output[n], count[radix] = { 0 }, i;

  for (i = 0; i < n; ++i)
    ++count[arr[i] / exp % radix];

  for (i = 1; i < radix; ++i)
    count[i] += count[i - 1];

  for (i = n - 1; i >= 0; --i)
    output[count[arr[i] / exp % radix]-- - 1] = arr[i];

  for (i = 0; i < n; ++i)
    arr[i] = output[i];
}

void
radixSort(int *arr, const int n, const int radix) {
  const int max = getMax(arr, n);
  for (int exp = 1; exp < max; exp *= radix)
    countSort(arr, n, exp, radix);
}

int
main() {
  int ssnList[] = {
    320149836,
    732431211,
    556280027,
    983420936,
    198211045,
    250091218,
    991003780,
  };
  const int n = sizeof(ssnList) / sizeof(ssnList[0]);

  radixSort(ssnList, n, 1000);

  for (int i = 0; i < n; ++i)
    std::cout << ssnList[i] << std::endl;

  return 0;
}

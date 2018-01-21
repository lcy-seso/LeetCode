#include <iostream>
#include <vector>

int maxChunksToSorted(std::vector<int>& arr) {
  size_t n = arr.size();
  if (n == 1) return n;

  int count = 0;
  int max_item = 0;
  for (size_t i = 0; i < n; ++i) {
    if (arr[i] > max_item) max_item = arr[i];

    if (max_item == i) count++;
  }
  return count;
}

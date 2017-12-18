#include <iostream>
#include <vector>

#include "../../utils/utils.h"

template class std::vector<int>;

void merge(std::vector<int>& nums, size_t start, size_t mid, size_t end) {
  // [start, mid] and [mid + 1, end] are all sorted.
  // merge the two array into one.

  std::vector<int> cache(end - start + 1);

  size_t i = start;
  size_t j = mid + 1;

  for (size_t k = 0; k < cache.size(); ++k) {
    if (i > mid)
      cache[k] = nums[j++];
    else if (j > end)
      cache[k] = nums[i++];
    else if (nums[i] <= nums[j])
      cache[k] = nums[i++];
    else
      cache[k] = nums[j++];
  }

  for (size_t i = 0; i < cache.size(); ++i) nums[start + i] = cache[i];
}

void merge_sort(std::vector<int>& nums, size_t start, size_t end) {
  // srot element in [start, end]

  if (start < end) {
    size_t mid = (start + end) / 2;
    merge_sort(nums, start, mid);
    merge_sort(nums, mid + 1, end);
    merge(nums, start, mid, end);
  }
}

int main() {
  const int kMinValue = -35;
  const int kMaxValue = 35;
  const int kMaxArrayLen = 25;

  std::vector<int> nums;
  genRandIntList(nums, randint(0, kMaxArrayLen), kMinValue, kMaxValue);
  std::cout << "Inputs : " << std::endl;
  printList<int>(nums);

  merge_sort(nums, 0, nums.size() - 1);
  std::cout << "Sorted : " << std::endl;
  printList<int>(nums);
  return 0;
}

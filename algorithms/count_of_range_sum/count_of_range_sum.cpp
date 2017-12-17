#include <iostream>
#include <vector>

#include "../utils/utils.h"

int countRangeSumNaive(const std::vector<int>& nums, int lower, int upper) {
  // This exceeds the time limit.
  if (nums.empty()) return 0;

  std::vector<std::vector<long>> range_sum(nums.size());

  range_sum[0].push_back(nums[0]);
  int count = (nums[0] <= upper && nums[0] >= lower ? 1 : 0);

  for (size_t i = 1; i < nums.size(); ++i) {
    range_sum[i].resize(i + 1, 0);
    for (size_t j = 0; j < range_sum[i].size(); ++j) {
      range_sum[i][j] = (j < i ? range_sum[i - 1][j] : 0) + nums[i];
      if (range_sum[i][j] >= lower && range_sum[i][j] <= upper) {
        count++;
      }
    }
  }
  return count;
}

int countWithMergeSort(
    std::vector<long> sums, size_t start, size_t end, int lower, int upper) {
  if (end - start <= 1) return 0;
  int mid = (start + end) / 2;
  int count = countWithMergeSort(sums, start, mid, lower, upper) +
              countWithMergeSort(sums, mid, end, lower, upper);

  std::vector<long> cache(end - start, 0);
  int j = mid;
  int k = mid;
  int t = mid;
  int len = 0;
  for (int i = start, r = 0; i < mid; ++i, ++r) {
    while (j < end && sums[j] - sums[i] < lower) j++;
    while (k < end && sums[k] - sums[i] <= upper) k++;
    count += (k - j);
    while (t < end && sums[t] < sums[i]) cache[r++] = sums[t++];
    cache[r] = sums[i];
    len = r;
  }
  for (int i = 0; i <= len; i++) sums[start + i] = cache[i];
  return count;
}

int countRangeSum(const std::vector<int>& nums, int lower, int upper) {
  if (nums.empty()) return 0;

  std::vector<long> sums(nums.size(), 0);
  sums[0] = nums[0];
  for (size_t i = 1; i < nums.size(); ++i) sums[i] = nums[i] + sums[i - 1];

  return countWithMergeSort(sums, 0, nums.size() + 1, lower, upper);
}

int main() {
  // std::vector<int> nums = {-2, 5, -1};
  std::vector<int> nums = {2147483647, -2147483648, -1, 0};
  int lower = -1;
  int upper = 0;

  std::cout << countRangeSum(nums, lower, upper) << std::endl;
  return 0;
}

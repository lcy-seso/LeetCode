#include <iostream>
#include <utility>

#include "../utils/utils.h"

std::vector<std::pair<int, int>> kSmallestPairsNaive(std::vector<int>& nums1,
                                                     std::vector<int>& nums2,
                                                     const int k) {
  std::vector<std::pair<int, int>> all_pairs(nums1.size() * nums2.size());

  size_t count = 0;
  for (size_t i = 0; i < nums1.size(); ++i) {
    for (size_t j = 0; j < nums2.size(); ++j)
      all_pairs[count++] = std::make_pair(nums1[i], nums2[j]);
  }
  if (k >= all_pairs.size()) return all_pairs;

  std::partial_sort(
      all_pairs.begin(),
      all_pairs.begin() + k,
      all_pairs.end(),
      [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return (a.first + a.second) <= (b.first + b.second);
      });
  all_pairs.resize(k);
  return all_pairs;
}

void printPairs(const std::vector<std::pair<int, int>>& pairs) {
  for (auto pair : pairs)
    std::cout << "[" << pair.first << " " << pair.second << "]" << std::endl;
}

int main() {
  const int kMinValue = -10;
  const int kMaxValue = 10;
  const int kMaxLen = 5;

  std::vector<int> nums1;
  std::vector<int> nums2;

  const size_t len1 = 5;
  const size_t len2 = 3;
  const int k = 3;

  genRandIntList(nums1, len1, kMinValue, kMaxValue);
  std::sort(nums1.begin(), nums1.end());

  genRandIntList(nums2, len2, kMinValue, kMaxValue);
  std::sort(nums2.begin(), nums2.end());

  std::cout << "Inputs : " << std::endl;
  printList<int>(nums1);
  printList<int>(nums2);

  std::cout << std::endl << "Resutls : " << std::endl;
  printPairs(kSmallestPairsNaive(nums1, nums2, k));

  return 0;
}

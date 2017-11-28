#include <iostream>
#include <utility>

#include "../utils/utils.h"

int smallestDistancePairNaive(const std::vector<int>& nums, int k) {
  const int kMaxValue = 1000000;  // The maximum distance is kMaxValue
  std::vector<int> bit_map(kMaxValue, 0);
  for (size_t i = 0; i < nums.size(); ++i) {
    for (size_t j = i + 1; j < nums.size(); ++j) {
      bit_map[std::abs(nums[i] - nums[j])]++;
    }
  }

  size_t i = 0;
  int sum = 0;
  for (; i < kMaxValue; ++i) {
    sum += bit_map[i];
    if (sum >= k) break;
  }
  return i;
}

int main() {
  const int kMinArrayLen = 2;
  const int kMaxArrayLen = 10000;

  const int kMinValue = 0;
  const int kMaxValue = 10;

  int arrayLen = randint(kMinArrayLen, kMaxArrayLen);
  int k = randint(0, arrayLen * (arrayLen - 1) / 2);
  std::cout << "array length = " << arrayLen << std::endl
            << "k = " << k << std::endl;

  std::vector<int> nums;
  genRandIntList(nums, arrayLen, kMinValue, kMaxValue);
  std::cout << "Inputs : " << std::endl;
  printList<int>(nums);
  std::cout << "The " << k << "-th smallest distance is : "
            << smallestDistancePairNaive(nums, k) << std::endl;

  return 0;
}

#include <iostream>

#include "../utils/utils.h"

int reversePairs(const std::vector<int>& nums) { return 0; }

int main() {
  int kMinValue = -10;
  int kMaxValue = 10;
  // size_t kMaxLisLen = 50000;
  size_t kMaxLisLen = 10;

  int len = randint(1, kMaxLisLen);
  std::cout << "Input length : " << len << std::endl;

  std::vector<int> nums;
  genRandIntList(nums, len, kMinValue, kMaxValue);
  std::cout << "Input :" << std::endl;
  printList<int>(nums);

  reversePairs(nums);
  return 0;
}

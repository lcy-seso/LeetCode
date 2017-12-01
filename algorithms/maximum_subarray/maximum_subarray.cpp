#include <iostream>

#include "../utils/utils.h"

int maxSubArray(const std::vector<int>& nums) {
  std::vector<int> max_ending_here(nums.size(), 0);
  max_ending_here[0] = nums[0];

  for (size_t i = 1; i < nums.size(); ++i)
    max_ending_here[i] = std::max(max_ending_here[i - 1] + nums[i], nums[i]);
  return *std::max_element(max_ending_here.begin(), max_ending_here.end());
}

int main() {
  const int kMinValue = -5;
  const int kMaxValue = 5;
  const int kMaxVecLen = 15;

  int len = randint(1, kMaxVecLen);
  std::vector<int> nums;
  genRandIntList(nums, len, kMinValue, kMaxValue);
  std::cout << "Inputs :" << std::endl;
  printList<int>(nums);

  std::cout << "The largest sum is of a contiguous subarray is : "
            << maxSubArray(nums) << std::endl;
  return 0;
}

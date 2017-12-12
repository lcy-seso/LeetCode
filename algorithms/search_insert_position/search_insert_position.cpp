#include <iostream>

#include "../utils/utils.h"

int searchInsert(const std::vector<int>& nums, const int target) {
  int low = 0;
  int high = nums.size() - 1;

  while (low <= high) {
    int mid = (low + high) / 2;
    if (nums[mid] == target)
      return mid;
    else if (nums[mid] < target)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return std::max(low, high);
}

int main() {
  const int kMinValue = -10;
  const int kMaxValue = 10;
  const int kMaxLen = 10;

  int len = randint(1, kMaxLen);
  std::cout << "Input length = " << len << std::endl;
  std::vector<int> nums;
  genRandIntList(nums, len, kMinValue, kMaxValue);
  std::sort(nums.begin(), nums.end());
  printList<int>(nums);

  int target = randint(kMinValue, kMaxValue);
  std::cout << "The target is : " << target << std::endl;
  std::cout << "Output : " << searchInsert(nums, target) << std::endl;
  return 0;
}

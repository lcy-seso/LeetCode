#include <iostream>

#include "../utils/utils.h"

int findUnsortedSubarray(std::vector<int>& nums) {
  if (nums.size() == 1) return 0;

  size_t left_pos = 0;
  int max_to_left = nums[0];
  bool left_found = false;

  size_t right_pos = nums.size() - 1;
  int min_to_right = nums.back();
  bool right_found = false;

  while (true) {
    if (!left_found) {
      if (nums[left_pos + 1] >= max_to_left) {
        left_pos++;
        if (nums[left_pos] <= min_to_right) {
          max_to_left = nums[left_pos];
        } else {
          left_found = true;
        }
      } else {
        left_found = true;
      }
    }

    if (!right_found) {
      if (nums[right_pos - 1] < min_to_right) {
        right_pos--;
        if (max_to_left <= nums[right_pos]) {
          min_to_right = nums[right_pos];
        } else {
          right_found = true;
        }
      } else {
        right_found = true;
      }
    }
    if ((left_found && right_found) || (left_pos >= right_pos)) break;
  }

  std::cout << left_pos << " : " << right_pos << std::endl;
  return left_pos == right_pos ? 0 : right_pos - left_pos + 1;
}

int main() {
  // const size_t kMaxArrayLen = 10000;
  const size_t kMaxArrayLen = 10;
  const int kMinValue = 0;
  const int kMaxValue = 20;

  int array_len = randint(1, kMaxArrayLen);

  // int n[] = {2, 6, 4, 8, 10, 9, 15};
  int n[] = {1, 3, 2, 3, 3};
  // int n[] = {1, 3, 2, 4, 5};
  std::vector<int> nums(n, n + 5);

  // genRandIntList(nums, array_len, kMinValue, kMaxValue);

  std::cout << "Inputs :" << std::endl;
  printList<int>(nums);

  std::cout << "The length of shortest continuous subarray "
            << "that need to sort is " << findUnsortedSubarray(nums) << " ."
            << std::endl;
  return 0;
}

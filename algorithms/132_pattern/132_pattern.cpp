#include <iostream>
#include <limits>
#include <stack>
#include <vector>

bool find132pattern(std::vector<int>& nums) {
  int third =
      std::numeric_limits<int>::min();  // This is the middle element 2 in
                                        // the 132 pattern.
  std::stack<int> second;  // this is the largest element in the 132 pattern.

  for (int i = nums.size() - 1; i >= 0; --i) {
    if (nums[i] < third)
      return true;
    else {
      while (!second.empty() && nums[i] > second.top()) {
        third = second.top();
        second.pop();
      }
    }
    second.push(nums[i]);
  }
  return false;
}

int main() {
  std::vector<int> nums = {3, 1, 4, 2};
  std::cout << find132pattern(nums) << std::endl;
  return 0;
}

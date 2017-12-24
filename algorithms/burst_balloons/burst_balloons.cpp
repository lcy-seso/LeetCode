#include <iostream>

#include "../utils/utils.h"

int maxCoins(std::vector<int>& nums) {
  int n = nums.size();
  nums.insert(nums.begin(), 1);
  nums.push_back(1);
  std::vector<std::vector<int>> dp(nums.size(),
                                   std::vector<int>(nums.size(), 0));
  for (int len = 1; len <= n; ++len) {
    for (int left = 1; left <= n - len + 1; ++left) {
      int right = left + len - 1;
      for (int k = left; k <= right; ++k)
        dp[left][right] = std::max(dp[left][right],
                                   nums[left - 1] * nums[k] * nums[right + 1] +
                                       dp[left][k - 1] + dp[k + 1][right]);
    }
  }
  return dp[1][n];
}

int main() {
  const int kMinValue = 1;
  const int kMaxValue = 15;
  const int kArrarLen = 5;

  std::vector<int> nums;
  genRandIntList(nums, kArrarLen, kMinValue, kMaxValue, 1, true);
  printList<int>(nums);

  std::cout << "Max coins is : " << maxCoins(nums) << std::endl;

  return 0;
}

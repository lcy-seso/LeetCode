#include <iostream>
#include <unordered_map>
#include <vector>

int findMaxLength(const std::vector<int>& nums) {
  std::vector<int> tmp = nums;
  for (auto n : nums) {
    if (!n) n = -1;
  }

  int sum = 0;
  int max_len = 0;
  std::unordered_map<int, int> m;
  m[0] = -1;
  for (int i = 0; i < tmp.size(); ++i) {
    sum += tmp[i];
    if (m.count(sum))
      max_len = std::max(max_len, i - m[sum]);
    else
      m[sum] = i;
  }
  return max_len;
}

int main() {
  std::vector<int> nums = {0, 1, 0, 1};
  std::cout << findMaxLength(nums) << std::endl;
  return 0;
}

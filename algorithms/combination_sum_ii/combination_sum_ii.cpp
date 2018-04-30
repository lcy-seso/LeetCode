#include <iostream>
#include <vector>

void BFS(const std::vector<int>& candidates,
         int target,
         std::vector<std::vector<int>>& results,
         int start,
         std::vector<int>& combination) {
  if (start > candidates.size() || target < 0) {
    return;
  } else if (target == 0) {
    results.emplace_back(combination);
    return;
  } else {
    for (size_t i = start; i < candidates.size(); ++i) {
      if (i != start && candidates[i] == candidates[i - 1]) continue;

      combination.push_back(candidates[i]);

      BFS(candidates, target - candidates[i], results, i + 1, combination);
      combination.pop_back();
    }
  }
}

std::vector<std::vector<int>> combinationSum2(
    const std::vector<int>& candidates, int target) {
  std::vector<std::vector<int>> results;

  std::vector<int> nums = candidates;
  std::sort(nums.begin(), nums.end());

  // record the combination that their sum is equal to target.
  std::vector<int> combination;

  BFS(nums, target, results, 0, combination);

  return results;
}

int main() {
  std::vector<int> candidates = {2, 5, 2, 1, 2};
  const int target = 5;

  std::vector<std::vector<int>> results = combinationSum2(candidates, target);

  std::cout << "results : " << std::endl;
  for (auto result : results) {
    for (auto num : result) std::cout << num << " ";
    std::cout << std::endl;
  }
  return 0;
}

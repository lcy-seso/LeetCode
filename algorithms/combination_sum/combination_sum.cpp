#include <iostream>
#include <vector>

void BFS(const std::vector<int>& candidates,
         const int start,
         const int target,
         std::vector<std::vector<int>>& results,
         std::vector<int>& combination) {
  if (target < 0) {
    return;
  } else if (target == 0) {
    results.emplace_back(combination);
  } else {
    for (size_t i = start; i < candidates.size(); ++i) {
      combination.push_back(candidates[i]);
      BFS(candidates, i, target - candidates[i], results, combination);
      combination.pop_back();
    }
  }
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates,
                                             int target) {
  std::sort(candidates.begin(), candidates.end());

  std::vector<std::vector<int>> results;
  std::vector<int> combination;
  BFS(candidates, 0, target, results, combination);

  return results;
}

int main() {
  std::vector<int> inputs = {2, 3, 6, 7};
  int target = 7;

  std::vector<std::vector<int>> results = combinationSum(inputs, target);

  for (auto combination : results) {
    std::cout << "[ ";
    for (auto n : combination) std::cout << n << " ";
    std::cout << "]" << std::endl;
  }
  return 0;
}

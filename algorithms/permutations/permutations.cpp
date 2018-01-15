#include <iostream>
#include <vector>

void BFS(std::vector<int>& inputs,
         std::vector<int>& permutation,
         std::vector<bool>& visited,
         std::vector<std::vector<int>>& results) {
  if (permutation.size() == inputs.size()) {
    results.emplace_back(permutation);
    return;
  } else {
    for (size_t i = 0; i < inputs.size(); ++i) {
      if (!visited[i]) {
        permutation.push_back(inputs[i]);
        visited[i] = true;
        BFS(inputs, permutation, visited, results);
        visited[i] = false;
        permutation.pop_back();
      }
    }
  }
}

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
  std::vector<std::vector<int>> results;

  std::vector<int> permutation;
  std::vector<bool> visited(nums.size(), false);
  BFS(nums, permutation, visited, results);

  return results;
}

int main() {
  std::vector<int> inputs = {1, 2, 3};
  std::vector<std::vector<int>> results = permute(inputs);

  for (auto permutation : results) {
    std::cout << "[ ";
    for (auto n : permutation) std::cout << n << " ";
    std::cout << "]" << std::endl;
  }
  return 0;
}

#include <iostream>
#include <vector>

void DFS(std::vector<std::vector<int>>& results,
         std::vector<int>& out,
         const int n,
         const int k,
         const int level) {
  if (out.size() == k) {
    results.emplace_back(out);
    return;
  }

  if (out.size() > k) return;

  for (size_t i = level; i <= n; ++i) {
    out.push_back(i);
    DFS(results, out, n, k, i + 1);
    out.pop_back();
  }
}

std::vector<std::vector<int>> combine(int n, int k) {
  std::vector<std::vector<int>> results;
  if (k > n) return results;

  std::vector<int> out;

  DFS(results, out, n, k, 1);

  return results;
}

int main() {
  const int n = 4;
  const int k = 2;

  std::vector<std::vector<int>> results = combine(n, k);
  for (auto item : results) {
    std::cout << "[ ";
    for (auto n : item) std::cout << n << " ";
    std::cout << "]" << std::endl;
  }
  return 0;
}

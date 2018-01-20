#include <iostream>
#include <vector>

int uniquePaths(int m, int n) {
  if (m && n == 0) return 0;

  std::vector<std::vector<int>> paths_number(m, std::vector<int>(n, 0));

  for (size_t i = 0; i < n; ++i) paths_number[0][i] = 1;
  for (size_t i = 0; i < m; ++i) paths_number[i][0] = 1;

  for (size_t i = 1; i < m; ++i) {
    for (size_t j = 1; j < n; ++j) {
      paths_number[i][j] = paths_number[i][j - 1] /* from up */ +
                           paths_number[i - 1][j] /* from left */;
    }
  }
  return paths_number[m - 1][n - 1];
}

int main() {
  const int m = 3;
  const int n = 3;
  std::cout << uniquePaths(m, n) << std::endl;
  return 0;
}

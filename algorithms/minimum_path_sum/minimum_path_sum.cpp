#include <iostream>
#include <vector>

int minPathSum(std::vector<std::vector<int>>& grid) {
  if (grid.empty()) return 0;
  int row_num = grid.size();
  if (grid[0].empty()) return 0;
  int col_num = grid[0].size();

  std::vector<std::vector<int>> square_sum(row_num,
                                           std::vector<int>(col_num, 0));
  square_sum[0][0] = grid[0][0];

  for (size_t i = 1; i < row_num; ++i)
    square_sum[i][0] = square_sum[i - 1][0] + grid[i][0];
  for (size_t i = 1; i < col_num; ++i)
    square_sum[0][i] = square_sum[0][i - 1] + grid[0][i];

  for (size_t i = 1; i < row_num; ++i) {
    for (size_t j = 1; j < col_num; ++j) {
      square_sum[i][j] =
          std::min({square_sum[i - 1][j], square_sum[i][j - 1]}) + grid[i][j];
    }
  }

  return square_sum[row_num - 1][col_num - 1];
}

int main() {
  std::vector<std::vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

  std::cout << minPathSum(grid) << std::endl;
  return 0;
}

#include <iostream>
#include <vector>

bool isToeplitzMatrix(std::vector<std::vector<int>>& matrix) {
  if (matrix.empty()) return false;
  if (matrix[0].empty()) return false;

  size_t row = matrix.size();
  size_t col = matrix[0].size();

  for (size_t i = 1; i < row; ++i) {
    for (size_t j = 1; j < col; ++j) {
      if (matrix[i][j] != matrix[i - 1][j - 1]) return false;
    }
  }
  return true;
}

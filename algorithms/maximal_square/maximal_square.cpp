#include <iostream>
#include "../utils/utils.h"

void genRandomInput(std::vector<std::vector<char>>& matrix) {
  for (size_t i = 0; i < matrix.size(); ++i) {
    for (size_t j = 0; j < matrix[i].size(); ++j) {
      if (randint(0, 1)) matrix[i][j] = '1';
    }
  }
}

int maximalSquare(const std::vector<std::vector<char>>& matrix) {
  if (!matrix.size()) return 0;
  if (matrix.size() == 1) {
    for (auto v : matrix[0])
      if (v == '1') return 1;
    return 0;
  }

  // The memo table used in the dynamic programming.
  std::vector<std::vector<size_t>> maximal_square_size(
      matrix.size(), std::vector<size_t>(matrix[0].size(), 0));

  // Initialize the memo table.
  for (size_t i = 0; i < matrix[0].size(); ++i) {
    if (matrix[0][i] == '1') maximal_square_size[0][i] = 1;
  }
  for (size_t i = 0; i < matrix.size(); ++i) {
    if (matrix[i][0] == '1') maximal_square_size[i][0] = 1;
  }

  for (size_t i = 1; i < maximal_square_size.size(); ++i) {
    for (size_t j = 1; j < maximal_square_size[i].size(); ++j) {
      if (matrix[i][j] == '0') continue;
      size_t min_size = std::min({maximal_square_size[i - 1][j - 1],
                                  maximal_square_size[i][j - 1],
                                  maximal_square_size[i - 1][j]});
      maximal_square_size[i][j] = min_size + 1;
    }
  }

  size_t max = 0;
  for (auto row : maximal_square_size) {
    size_t row_max = *std::max_element(row.begin(), row.end());
    max = row_max > max ? row_max : max;
  }
  return max * max;
}

int main() {
  const int kMaxSquareSize = 10;

  int row_size = randint(1, kMaxSquareSize);
  int col_size = randint(1, kMaxSquareSize);
  std::cout << "row : " << row_size << " ; col : " << col_size << std::endl;

  std::vector<std::vector<char>> matrix(row_size,
                                        std::vector<char>(col_size, '0'));
  genRandomInput(matrix);

  for (auto row : matrix) printList<char>(row);

  std::cout << "the maximal square size is : " << maximalSquare(matrix)
            << std::endl;
  return 0;
}

#include <iostream>
#include <vector>

std::vector<int> getRow(int rowIndex) {
  std::vector<std::vector<int>> triangle(rowIndex + 1, std::vector<int>());
  for (int i = 0; i < rowIndex + 1; ++i) {
    triangle[i].resize(i + 1, 1);
    for (int j = 1; j < i; ++j)
      triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
  }
  return triangle[rowIndex];
}

int main() {
  int n = 3;
  std::vector<int> result = getRow(n);

  for (auto n : result) std::cout << n << " ";
  std::cout << std::endl;

  return 0;
}

#include <iostream>
#include <limits>
#include <random>

void randint(const int min, const int max, std::vector<int>& vec) {
  std::random_device rnd_device;
  std::mt19937 mersenne_engine(rnd_device());
  std::uniform_int_distribution<int> dist(min, max);
  auto gen = std::bind(dist, mersenne_engine);

  std::generate(vec.begin(), vec.end(), gen);
}

void printTriangle(const std::vector<std::vector<int>>& in) {
  size_t row_id = 0;
  for (size_t i = 0; i < in.size(); ++i) {
    std::cout << "row " << i << "\t";
    for (auto const& item : in[i]) std::cout << item << " ";
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void genRandInput(std::vector<std::vector<int>>& out,
                  const size_t depth,
                  const int min,
                  const int max) {
  out.resize(depth);
  for (size_t i = 0; i < depth; ++i) {
    out[i].resize(i + 1);
    randint(min, max, out[i]);
  }
}

int minimumTotal(std::vector<std::vector<int>>& triangle) {
  std::vector<std::vector<int>> minimum_sum;
  minimum_sum.resize(triangle.size(), std::vector<int>());
  const int kMaxSum = std::numeric_limits<int>::max();

  // Initialize the memo table.
  minimum_sum[0].resize(1, triangle[0][0]);

  for (size_t i = 1; i < triangle.size(); ++i) {
    minimum_sum[i].resize(triangle[i].size(), 0);

    for (size_t j = 0; j < triangle[i].size(); ++j) {
      int sum_from_left = j ? minimum_sum[i - 1][j - 1] : kMaxSum;
      int sum_from_up = j < i ? minimum_sum[i - 1][j] : kMaxSum;

      minimum_sum[i][j] = triangle[i][j] + std::min(sum_from_left, sum_from_up);
    }
  }

  return *std::min_element(std::begin(minimum_sum.back()),
                           std::end(minimum_sum.back()));
}

int main() {
  const int kTriangleDepth = 17;
  const int kMinValue = -3;
  const int kMaxValue = 11;

  std::vector<std::vector<int>> triangle;
  genRandInput(triangle, kTriangleDepth, kMinValue, kMaxValue);
  printTriangle(triangle);

  std::cout << "The minimum sum is : " << minimumTotal(triangle) << std::endl;
  return 0;
}

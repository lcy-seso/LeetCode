#include <iostream>
#include <vector>

std::vector<int> countBits(int num) {
  std::vector<int> results(num + 1, 0);

  for (size_t i = 1; i <= num; ++i) results[i] = results[i >> 1] + (i & 1);
  return results;
}

int main() {
  const int num = 5;
  std::vector<int> results = countBits(5);
  for (auto n : results) std::cout << n << " ";
  std::cout << std::endl;
  return 0;
}

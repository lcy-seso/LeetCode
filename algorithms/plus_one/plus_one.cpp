#include <iostream>
#include <vector>

std::vector<int> plusOne(std::vector<int>& digits) {
  std::vector<int> results = digits;
  if (results.empty()) return results;

  auto plus_single_digit = [](int& n) -> bool {
    n += 1;
    if (n >= 10) {
      n %= 10;
      return true;
    }
    return false;
  };

  bool carry_flag = false;
  for (int i = results.size() - 1; i >= 0; --i) {
    carry_flag = plus_single_digit(results[i]);
    if (!carry_flag) break;
  }
  if (carry_flag) results.insert(results.begin(), 1);

  return results;
}

int main() {
  std::vector<int> digits = {2, 4, 9};
  std::vector<int> results = plusOne(digits);
  for (auto n : results) std::cout << n;
  std::cout << std::endl;
  return 0;
}

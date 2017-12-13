#include <iostream>
#include <sstream>
#include <string>

#include "../utils/utils.h"

void string_to_int_arrary(const std::string str, std::vector<int>& ints) {
  ints.reserve(str.size());
  std::transform(
      std::begin(str), std::end(str), std::back_inserter(ints), [](char c) {
        return c - '0';
      });
}

std::string removeKdigits(const std::string num, int k) {
  if (num.size() == k) return "0";

  std::vector<int> digits;
  string_to_int_arrary(num, digits);

  std::ostringstream output;
  size_t cur_start_pos = 0;
  size_t out_digit_count = digits.size() - k;
  bool start_with_zero = true;

  for (size_t i = 0; i < out_digit_count; ++i) {
    cur_start_pos = std::distance(
        digits.begin(),
        std::min_element(digits.begin() + cur_start_pos,
                         digits.end() - (out_digit_count - i - 1)));

    if (start_with_zero) {
      if (digits[cur_start_pos]) {
        start_with_zero = false;
        output << digits[cur_start_pos];
      }
    } else {
      output << digits[cur_start_pos];
    }
    cur_start_pos++;
  }
  if (output.str().empty()) return "0";
  return output.str();
}

int main() {
  const int kMaxLen = 10002;

  int len = randint(1, kMaxLen);
  int k = randint(1, len);

  std::cout << "string len = " << len << std::endl;
  std::cout << "k = " << k << std::endl;

  std::ostringstream str;
  for (int i = 0; i < len; ++i) str << randint(0, 9);
  std::cout << "Input : " << str.str() << std::endl;
  std::cout << removeKdigits(str.str(), k) << std::endl;
  return 0;
}

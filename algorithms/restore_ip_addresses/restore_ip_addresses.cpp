#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

#include "../utils/utils.h"

void string_to_int_arrary(const std::string str, std::vector<int>& ints) {
  ints.reserve(str.size());
  std::transform(str.begin(), str.end(), std::back_inserter(ints), [](char c) {
    return c - '0';
  });
}

int to_one_num(std::vector<int>::iterator& first,
               std::vector<int>::iterator& last) {
  const int kMaxValue = 255;
  if (last - first > 1 && (*first) == 0) return kMaxValue + 1;

  int res = 0;
  int count = 0;
  for (auto i = last - 1; i >= first; --i) res += (*i * std::pow(10, count++));
  return res;
}

std::vector<std::string> restoreIpAddresses(const std::string& s) {
  std::vector<std::string> ips;
  if (s.size() > 12 || s.size() < 4) return ips;

  std::vector<int> nums;
  string_to_int_arrary(s, nums);
  int num_count = nums.size();

  for (size_t i = 1; i < 4; ++i) {
    for (size_t j = 1; j < 4; ++j) {
      for (size_t m = 1; m < 4; ++m) {
        for (size_t n = 1; n < 4; ++n) {
          if (i + j + m + n != num_count) continue;
          auto start = nums.begin();
          auto end = start + i;
          if (to_one_num(start, end) > 255) continue;
          start = end;
          end += j;
          if (to_one_num(start, end) > 255) continue;
          start = end;
          end += m;
          if (to_one_num(start, end) > 255) continue;
          start = end;
          end += n;
          if (to_one_num(start, end) > 255) continue;

          ips.push_back(s.substr(0, i) + "." + s.substr(i, j) + "." +
                        s.substr(i + j, m) + "." + s.substr(i + j + m, n));
        }
      }
    }
  }

  return ips;
}

int main() {
  // std::string input = "25525511135";
  std::string input = "010010";
  std::vector<std::string> ips = restoreIpAddresses(input);
  printList<std::string>(ips);
  return 0;
}

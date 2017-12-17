#include <iostream>

std::string addBinary(std::string& a, std::string& b) {
  // Very straight forward. It is not an elegant solution.
  std::string output = {};

  int carry_flag = 0;
  int first = 0;
  int second = 0;
  for (size_t i = 0; i < std::max(a.length(), b.length()); ++i) {
    if (i >= a.length())
      first = 0;
    else
      first = (a[a.length() - 1 - i] == '0' ? 0 : 1);
    if (i >= b.length())
      second = 0;
    else
      second = (b[b.length() - 1 - i] == '0' ? 0 : 1);

    int res = first + second + carry_flag;
    if (res > 1)
      carry_flag = 1;
    else
      carry_flag = 0;
    output += std::to_string(res % 2);
  }
  if (carry_flag) output += "1";
  std::reverse(output.begin(), output.end());

  return output;
}

int main() {
  std::string a = "101";
  std::string b = "11";
  std::cout << addBinary(a, b) << std::endl;
  return 0;
}

#include <iostream>
#include <map>
#include <vector>

int longestPalindrome(std::string& s) {
  std::map<char, int> char_count;

  for (auto c : s) {
    auto it = char_count.find(c);

    if (it == char_count.end())
      char_count[c] = 1;
    else
      char_count[c] += 1;
  }

  int length = 0;
  bool has_odd_number = false;

  if (char_count.size() == 1) {
    auto it = char_count.begin();
    return it->second;
  }

  for (auto const& c : char_count) {
    std::cout << c.first << " : " << c.second << std::endl;
    if (c.second % 2) {
      if (has_odd_number) {
        length += c.second - 1;
      } else {
        // the character appers odd times in the string.
        length += c.second;
        has_odd_number = true;
      }
    } else {
      length += c.second;
    }
  }

  return length;
}

int main() {
  // std::string input = "abccccdd";
  // std::string input = "ccc";
  // std::string input = "bananas";
  std::string input = "aaaAaaaa";

  std::cout << longestPalindrome(input) << std::endl;
}

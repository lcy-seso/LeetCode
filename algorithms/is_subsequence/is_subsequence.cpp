#include <iostream>
#include <string>

bool isSubsequence(std::string& s, std::string& t) {
  size_t s_len = s.length();
  size_t t_len = t.length();

  size_t i = 0;
  size_t j = 0;

  while (true) {
    if (j == t_len || i == s_len) break;
    if (s[i] == t[j]) {
      i++;
      j++;
    } else {
      j++;
    }
  }

  return i == s_len;
}

int main() {
  std::string s = "abc";
  std::string t = "ahbgdc";
  std::cout << isSubsequence(s, t) << std::endl;
  return 0;
}

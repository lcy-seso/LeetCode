#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

void add_neighbor(const std::vector<char>& gens,
                  std::string& str,
                  std::queue<std::string>& to_be_searched) {
  for (int i = 0; i < str.length(); ++i) {
    for (int j = 0; j < gens.size(); ++j) {
      char c = str[i];
      if (c != gens[j]) {
        str[i] = gens[j];
        to_be_searched.push(str);
        str[i] = c;
      }
    }
  }
}

int minMutation(const std::string start,
                const std::string end,
                const std::vector<std::string>& bank) {
  if (bank.empty()) return -1;

  const std::vector<char> kGens = {'A', 'T', 'C', 'G'};
  std::unordered_set<std::string> bank_set(bank.begin(), bank.end());

  int depth = -1;
  std::queue<std::string> to_be_searched;
  std::unordered_set<std::string> visited;

  std::string s = start;
  add_neighbor(kGens, s, to_be_searched);  // this is the first depth

  while (!to_be_searched.empty()) {
    depth++;

    int count = to_be_searched.size();
    for (int i = 0; i < count; ++i) {
      std::string cur = to_be_searched.front();
      to_be_searched.pop();

      // not a vailid mutation.
      if (bank_set.find(cur) == bank_set.end() ||
          visited.find(cur) != visited.end())
        continue;

      if (cur == end) return depth + 1;

      visited.insert(cur);
      add_neighbor(kGens, cur, to_be_searched);
    }
  }

  return -1;
}

int main() {
  std::string start = "AAAAAAAA";
  std::string end = "CCCCCCCC";
  std::vector<std::string> bank = {"AAAAAAAA",
                                   "AAAAAAAC",
                                   "AAAAAACC",
                                   "AAAAACCC",
                                   "AAAACCCC",
                                   "AACACCCC",
                                   "ACCACCCC",
                                   "ACCCCCCC",
                                   "CCCCCCCA"};

  std::cout << minMutation(start, end, bank) << std::endl;
  return 0;
}

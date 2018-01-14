#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

void add_neighbor(std::string& str, std::queue<std::string>& to_be_searched) {
  for (size_t i = 0; i < 4; ++i) {
    char c = str[i];

    str[i] = (c - '0' + 1) % 10 + '0';
    to_be_searched.push(str);

    str[i] = (c - '0' - 1 + 10) % 10 + '0';
    to_be_searched.push(str);

    str[i] = c;
  }
}

int openLock(std::vector<std::string>& deadends, const std::string& target) {
  const std::string start_state = "0000";

  std::unordered_set<std::string> deadends_set(deadends.begin(),
                                               deadends.end());
  std::unordered_set<std::string> visited;

  std::queue<std::string> to_be_searched;
  to_be_searched.push(start_state);

  int depth = -1;
  while (!to_be_searched.empty()) {
    depth++;

    // Here, during the travering, the depth is needed to be maintained.
    int count = to_be_searched.size();
    for (size_t i = 0; i < count; ++i) {
      // visit nodes have the same depth.
      std::string cur_node = to_be_searched.front();
      to_be_searched.pop();

      if (cur_node == target) return depth;

      if (deadends_set.find(cur_node) != deadends_set.end() ||
          visited.find(cur_node) != visited.end())
        continue;  // A deadend is encountered or the state has already
                   // encountered

      visited.insert(cur_node);
      add_neighbor(cur_node, to_be_searched);
    }
  }
  return -1;
}

int main() {
  // std::vector<std::string> deadends = {
  //     "8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"};
  // std::string target = "8888";

  std::vector<std::string> deadends = {"0201", "0101", "0102", "1212", "2002"};
  std::string target = "0202";

  std::cout << openLock(deadends, target) << std::endl;
  return 0;
}

#include <iostream>
#include <vector>

int findParent(const std::vector<int>& parent_id, int x) {
  while (x != parent_id[x]) x = parent_id[x];
  return x;
}

int findCircleNum(const std::vector<std::vector<int>>& M) {
  int node_count = M.size();

  // initialize
  std::vector<int> parent_id(node_count, 0);
  for (size_t i = 0; i < node_count; ++i) parent_id[i] = i;

  int circle_num = node_count;
  for (size_t i = 0; i < node_count; ++i) {
    for (size_t j = i + 1; j < node_count; ++j) {
      if (M[i][j] == 0) continue;

      int p1 = findParent(parent_id, i);
      int p2 = findParent(parent_id, j);
      if (p1 != p2) {
        parent_id[p1] = p2;
        circle_num--;
      }
    }
  }
  return circle_num;
}

int main() {
  // std::vector<std::vector<int>> M = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  // std::vector<std::vector<int>> M = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
  // std::vector<std::vector<int>> M = {
  //     {1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}};

  std::vector<std::vector<int>> M = {
      {1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
      {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
      {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
      {0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
      {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0},
      {0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1},
      {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
      {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}};

  std::cout << findCircleNum(M) << std::endl;
  return 0;
}

#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

int leastBricks(std::vector<std::vector<int>>& wall) {
  // sum and its frequencies.
  std::unordered_map<int, int> sum_map;

  int layer_width = std::accumulate(wall[0].begin(), wall[0].end(), 0);

  for (auto layer : wall) {
    int cur_sum = 0;
    for (auto width : layer) {
      cur_sum += width;
      sum_map[cur_sum] += 1;
    }
  }

  int max_fre = 0;
  for (auto it = sum_map.begin(); it != sum_map.end(); ++it) {
    if (it->first == layer_width) continue;
    max_fre = it->second > max_fre ? it->second : max_fre;
  }
  return wall.size() - max_fre;
}

int main() {
  std::vector<std::vector<int>> wall = {
      {1, 2, 2, 1}, {3, 1, 2}, {1, 3, 2}, {2, 4}, {3, 1, 2}, {1, 3, 1, 1}};

  std::cout << leastBricks(wall) << std::endl;
  return 0;
}

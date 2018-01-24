#include <iostream>
#include <limits>
#include <unordered_map>
#include <vector>

std::vector<std::string> findRestaurant(std::vector<std::string>& list1,
                                        std::vector<std::string>& list2) {
  std::vector<std::string> results;
  if (list1.empty() || list2.empty()) return results;

  std::unordered_map<std::string, int> map1;
  for (size_t i = 0; i < list1.size(); ++i) map1.insert({list1[i], i});

  int min = std::numeric_limits<int>::max();
  for (size_t i = 0; i < list2.size(); ++i) {
    auto it = map1.find(list2[i]);
    if (it != map1.end()) {
      if (i + map1[list2[i]] < min) {
        min = i + map1[list2[i]];
        results.clear();
        results.emplace_back(list2[i]);
      } else if (i + map1[list2[i]] == min) {
        results.emplace_back(list2[i]);
      }
    }
  }

  return results;
}

int main() {
  std::vector<std::string> list1 = {
      "Shogun", "Tapioca Express", "Burger King", "KFC"};
  std::vector<std::string> list2 = {"KFC", "Shogun", "Burger King"};

  std::vector<std::string> results = findRestaurant(list1, list2);
  for (auto s : results) std::cout << s << std::endl;

  return 0;
}

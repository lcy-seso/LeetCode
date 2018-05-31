#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

typedef std::unordered_map<std::string,
                           std::vector<std::pair<std::string, double>>>
    AdjList;

double BFS(const std::string& start,
           const std::string& end,
           AdjList& adjacent_list) {
  if (adjacent_list.find(start) == adjacent_list.end() ||
      adjacent_list.find(end) == adjacent_list.end())
    return -1.;
  if (start == end) return 1.;

  std::queue<std::pair<std::string, double>> to_be_visited;
  std::set<std::string> visited;

  for (auto child : adjacent_list[start]) to_be_visited.push(child);

  while (!to_be_visited.empty()) {
    int count = to_be_visited.size();
    for (int i = 0; i < count; ++i) {
      auto cur = to_be_visited.front();
      to_be_visited.pop();

      if (visited.find(cur.first) != visited.end()) continue;
      visited.insert(cur.first);

      if (cur.first == end) return cur.second;

      for (auto child : adjacent_list[cur.first])
        to_be_visited.push(
            std::make_pair(child.first, child.second * cur.second));
    }
  }
  return -1.;
}

std::vector<double> calcEquation(
    const std::vector<std::pair<std::string, std::string>> equations,
    const std::vector<double>& values,
    const std::vector<std::pair<std::string, std::string>> queries) {
  // build the adjacent list
  AdjList adjacent_list;
  for (int i = 0; i < equations.size(); ++i) {
    auto eq = equations[i];
    double v = values[i];

    adjacent_list[eq.first].push_back(std::make_pair(eq.second, v));
    adjacent_list[eq.second].push_back(std::make_pair(eq.first, 1. / v));
  }

  std::vector<double> results(queries.size(), -1.);
  for (int i = 0; i < queries.size(); ++i)
    results[i] = BFS(queries[i].first, queries[i].second, adjacent_list);

  return results;
}

int main() {
  std::vector<std::pair<std::string, std::string>> equations = {{"a", "b"},
                                                                {"b", "c"}};
  std::vector<double> values = {2.0, 3.0};
  std::vector<std::pair<std::string, std::string>> queries = {
      {"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

  // expected: {6.0, 0.5, -1.0, 1.0, -1.0}
  std::vector<double> results = calcEquation(equations, values, queries);
  for (auto n : results) std::cout << n << " ";
  std::cout << std::endl;
  return 0;
}

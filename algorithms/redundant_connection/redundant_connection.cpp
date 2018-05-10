#include <iostream>
#include <numeric>
#include <stack>
#include <vector>

// return true if the graph is connected.
bool dfs(const std::vector<std::vector<int>>& edges,
         int ignore_edge_idx,
         int start_node,
         int node_count) {
  // Construct the adjacency linked list representation.
  // The node index starts from 1, here for convinence, graph[0] is not used.
  std::vector<std::vector<int>> graph(edges.size() + 1, std::vector<int>());
  for (size_t i = 0; i < edges.size(); ++i) {
    if (i == ignore_edge_idx) continue;
    graph[edges[i][0]].push_back(edges[i][1]);
    graph[edges[i][1]].push_back(edges[i][0]);
  }

  std::stack<int> to_be_visited;
  std::vector<int> visited(edges.size() + 1, 0);
  visited[start_node] = 1;
  for (auto n : graph[start_node]) to_be_visited.push(n);

  while (!to_be_visited.empty()) {
    int cur = to_be_visited.top();
    if (visited[cur]) {
      to_be_visited.pop();
      continue;
    }
    visited[cur] = 1;
    for (auto n : graph[cur]) to_be_visited.push(n);
  }

  return std::accumulate(visited.begin(), visited.end(), 0) == node_count;
}

std::vector<int> findRedundantConnection1(
    const std::vector<std::vector<int>>& edges) {
  // this is a brute force solution.
  for (int i = edges.size() - 1; i >= 0; --i) {
    if (dfs(edges, i, 1, edges.size())) return edges[i];
  }

  // Actually reaching here means an invalid input is given.
  return std::vector<int>(2, -1);
}

std::vector<int> findRedundantConnection(
    const std::vector<std::vector<int>>& edges) {
  // a better solution using union-find.

  // the input is a tree plus one extra edge, so the vertex number in the graph
  // is edges.size().
  std::vector<int> parents(edges.size() + 1, 0);
  for (int i = 1; i < parents.size(); ++i) parents[i] = i;

  auto getParent = [](const std::vector<int>& parents, int x) -> int {
    while (x != parents[x]) x = parents[x];
    return x;
  };
  for (auto edge : edges) {
    if (getParent(parents, edge[0]) == getParent(parents, edge[1])) return edge;

    parents[getParent(parents, edge[0])] = getParent(parents, edge[1]);
  }

  // Actually reaching here means an invalid input is given.
  return std::vector<int>(2, -1);
}

int main() {
  // std::vector<std::vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
  // std::vector<std::vector<int>> edges = {
  //     {1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};

  std::vector<std::vector<int>> edges = {
      {1, 4}, {3, 4}, {1, 3}, {1, 2}, {4, 5}};
  std::vector<int> result = findRedundantConnection(edges);

  std::cout << "[" << result[0] << " " << result[1] << "]" << std::endl;
  return 0;
}

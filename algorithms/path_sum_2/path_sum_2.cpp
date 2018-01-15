#include <iostream>
#include <numeric>
#include <vector>

#include "../utils/tree_utils.h"
#include "../utils/utils.h"

void findPaths(TreeNode* node,
               int sum,
               std::vector<int>& path,
               std::vector<std::vector<int>>& paths) {
  if (!node) return;
  path.push_back(node->val);

  if (node->left == NULL && node->right == NULL && sum == node->val)
    paths.push_back(path);

  findPaths(node->left, sum - node->val, path, paths);
  findPaths(node->right, sum - node->val, path, paths);
  path.pop_back();
}

std::vector<std::vector<int>> pathSum(TreeNode* root, int sum) {
  std::vector<std::vector<int>> paths;
  if (!root) return paths;

  std::vector<int> path;
  findPaths(root, sum, path, paths);
  return paths;
}

int main() {
  const size_t kTreeNodeNum = 10;
  const int kMinNodeVal = 2;
  const int kMaxNodeVal = 15;
  TreeNode* root =
      gen_random_binary_tree(kTreeNodeNum, kMinNodeVal, kMaxNodeVal);

  int sum = 10;
  std::vector<std::vector<int>> paths = pathSum(root, 10);

  for (auto path : paths) {
    for (auto n : path) std::cout << n << " ";
    std::cout << std::endl;
  }

  emptyTree(root);
  return 0;
}

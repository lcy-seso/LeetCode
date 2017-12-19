#include <iostream>
#include <string>
#include <vector>

#include "../utils/tree_utils.h"
#include "../utils/utils.h"

void pre_order_traverse(TreeNode* node,
                        std::vector<std::string>& paths,
                        std::string s) {
  if (!node->left && !node->right) {
    paths.push_back(s);
    return;
  }

  if (node->left)
    pre_order_traverse(
        node->left, paths, s + "->" + std::to_string(node->left->val));
  if (node->right)
    pre_order_traverse(
        node->right, paths, s + "->" + std::to_string(node->right->val));
}

std::vector<std::string> binaryTreePaths(TreeNode* root) {
  std::vector<std::string> paths;
  if (!root) return paths;

  pre_order_traverse(root, paths, std::to_string(root->val));
  return paths;
}

int main() {
  const size_t kTreeNodeNum = 10;
  const int kMinNodeVal = 2;
  const int kMaxNodeVal = 15;
  TreeNode* root =
      gen_random_binary_tree(kTreeNodeNum, kMinNodeVal, kMaxNodeVal);
  std::vector<std::string> paths = binaryTreePaths(root);
  printList<std::string>(paths);

  emptyTree(root);
  return 0;
}

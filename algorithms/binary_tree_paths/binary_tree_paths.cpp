#include <iostream>
#include <string>
#include <vector>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

int main() { return 0; }

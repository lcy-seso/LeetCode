#include <iostream>
#include <vector>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void pre_order_traverse(TreeNode* node, std::vector<TreeNode*>& all_nodes) {
  if (node == NULL) return;
  all_nodes.push_back(node);

  pre_order_traverse(node->left, all_nodes);
  pre_order_traverse(node->right, all_nodes);
}

void flatten(TreeNode* root) {
  if (!root) return;
  std::vector<TreeNode*> all_nodes;
  pre_order_traverse(root, all_nodes);

  for (size_t i = 0; i < all_nodes.size() - 1; ++i) {
    all_nodes[i]->left = NULL;
    all_nodes[i]->right = all_nodes[i + 1];
  }
  all_nodes.back()->left = NULL;
  all_nodes.back()->right = NULL;
}

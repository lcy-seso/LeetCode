#include <iostream>
#include <queue>

#include "../utils/tree_utils.h"
#include "../utils/utils.h"

int widthOfBinaryTree(TreeNode* root) {
  if (!root) return 0;
  if (root->left == NULL && root->right == NULL) return 2;

  int max_width = 0;
  int null_count = 0;
  std::queue<TreeNode*> to_be_visited;

  auto push_a_node = [](std::queue<TreeNode*>& to_be_visited,
                        const TreeNode* node,
                        int& null_count) {
    if (node->left) {
      to_be_visited.push(node->left);
      null_count++;
    }
    if (node->right) {
      to_be_visited.push(node->right);
      null_count++;
    }
  };

  push_a_node(to_be_visited, root, null_count);
  max_width = to_be_visited.size() + null_count;
  while (!to_be_visited.empty()) {
    int width = to_be_visited.size();
    null_count = 0;
    for (size_t i = 0; i < width; ++i) {
      TreeNode* front = to_be_visited.front();
      push_a_node(to_be_visited, front, null_count);
      to_be_visited.pop();
    }
    int cur_width = to_be_visited.size() + null_count;
    max_width = cur_width > max_width ? cur_width : max_width;
  }
  return max_width;
}

int main() {
  const size_t kTreeNodeNum = 25;
  const int kMinNodeVal = 2;
  const int kMaxNodeVal = 15;
  TreeNode* root =
      gen_random_binary_tree(kTreeNodeNum, kMinNodeVal, kMaxNodeVal);
  preOrderPrintTree(root);

  std::cout << std::endl
            << "Maximum tree width : " << widthOfBinaryTree(root) << std::endl;
  emptyTree(root);
  return 0;
}

#include <iostream>
#include <queue>

#include "../utils/tree_utils.h"
#include "../utils/utils.h"

int widthOfBinaryTree(TreeNode* root) {
  if (!root) return 0;
  auto push_a_node = [](std::queue<TreeNode*>& to_be_visited,
                        std::queue<size_t>& node_id,
                        size_t parent_id,
                        const TreeNode* node) {
    if (node->left) {
      to_be_visited.push(node->left);
      node_id.push(parent_id * 2);
    }
    if (node->right) {
      to_be_visited.push(node->right);
      node_id.push(parent_id * 2 + 1);
    }
  };

  std::queue<TreeNode*> to_be_visited;
  std::queue<size_t> node_id;

  push_a_node(to_be_visited, node_id, 1, root);
  if (to_be_visited.empty()) return 1;

  size_t leftmost = 0;
  size_t rightmost = 0;
  size_t max_width = 0;
  while (!to_be_visited.empty()) {
    int width = to_be_visited.size();
    for (size_t i = 0; i < width; ++i) {
      size_t cur_node_id = node_id.front();
      if (i == 0) leftmost = cur_node_id;
      if (i == width - 1) rightmost = cur_node_id;

      TreeNode* front = to_be_visited.front();
      push_a_node(to_be_visited, node_id, cur_node_id, front);
      to_be_visited.pop();
      node_id.pop();
    }

    size_t cur_width = rightmost - leftmost + 1;
    max_width = cur_width > max_width ? cur_width : max_width;
  }
  return max_width;
}

int main() {
  const size_t kTreeNodeNum = 10;
  const int kMinNodeVal = 0;
  const int kMaxNodeVal = 15;
  TreeNode* root =
      gen_random_binary_tree(kTreeNodeNum, kMinNodeVal, kMaxNodeVal);
  preOrderPrintTree(root);

  std::cout << std::endl
            << "Maximum tree width : " << widthOfBinaryTree(root) << std::endl;
  emptyTree(root);
  return 0;
}

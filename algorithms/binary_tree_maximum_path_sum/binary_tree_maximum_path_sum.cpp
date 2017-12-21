#include <iostream>
#include <limits>

#include "../utils/tree_utils.h"

int findMaxUtil(TreeNode* root, int& max_sum) {
  // There may be four situation for the maximum path:
  // The single path:
  // 1. the path from a node's left child and then add the node itself.
  // 2. the path from a node's right child and then add the node itself.
  // 3. the path only involve the current node.
  // A cross path:
  // 4. the path from a node's left child to the node and then to its right
  // child.

  if (root == NULL) return 0;

  int l = findMaxUtil(root->left, max_sum);
  int r = findMaxUtil(root->right, max_sum);

  int max_single = std::max(std::max(l, r) + root->val, root->val);

  int max_top = std::max(max_single, root->val + l + r);

  max_sum = std::max(max_sum, max_top);
  return max_single;
}

int maxPathSum(TreeNode* root) {
  int res = std::numeric_limits<int>::min();
  findMaxUtil(root, res);
  return res;
}

int main() {
  const size_t kTreeNodeNum = 10;
  const int kMinNodeVal = -15;
  const int kMaxNodeVal = 15;
  TreeNode* root =
      gen_random_binary_tree(kTreeNodeNum, kMinNodeVal, kMaxNodeVal);
  preOrderPrintTree(root);

  std::cout << "Ouput : " << std::endl << maxPathSum(root) << std::endl;

  emptyTree(root);
  return 0;
}

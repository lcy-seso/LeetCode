#include <iostream>
#include <numeric>
#include <vector>

#include "../utils/tree_utils.h"
#include "../utils/utils.h"

int sumToRootCount(TreeNode* root, const int sum) {
  if (!root) return 0;

  int count = 0;
  if (root->val == sum) count += 1;

  return count + sumToRootCount(root->left, sum - root->val) +
         sumToRootCount(root->right, sum - root->val);
}

int pathSum(TreeNode* root, int sum) {
  if (!root) return 0;

  return sumToRootCount(root, sum) + pathSum(root->left, sum) +
         pathSum(root->right, sum);
}

int main() {
  const size_t kTreeNodeNum = 10;
  const int kMinNodeVal = -5;
  const int kMaxNodeVal = 15;
  TreeNode* root =
      gen_random_binary_tree(kTreeNodeNum, kMinNodeVal, kMaxNodeVal);
  preOrderPrintTree(root);
  std::cout << std::endl;

  int sum = 10;
  int n = pathSum(root, 10);
  std::cout << std::endl << "path number : " << n << std::endl;

  emptyTree(root);
  return 0;
}

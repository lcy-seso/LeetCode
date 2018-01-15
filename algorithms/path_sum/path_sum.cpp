#include <iostream>
#include <string>
#include <vector>

#include "../utils/tree_utils.h"
#include "../utils/utils.h"

bool hasPathSum(TreeNode* root, int sum) {
  if (!root) return false;
  if (root->val == sum && root->left == NULL && root->right == NULL)
    return true;
  return hasPathSum(root->left, sum - root->val) ||
         hasPathSum(root->right, sum - root->val);
}

int main() {
  const size_t kTreeNodeNum = 10;
  const int kMinNodeVal = 2;
  const int kMaxNodeVal = 15;
  TreeNode* root =
      gen_random_binary_tree(kTreeNodeNum, kMinNodeVal, kMaxNodeVal);
  preOrderPrintTree(root);

  std::cout << std::endl
            << "has path sum : " << hasPathSum(root, 5) << std::endl;

  return 0;
}

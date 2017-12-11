#include <iostream>

#include "../utils/utils.h"

struct TreeNode {
  int val;
  size_t count_ge;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int val) : left(NULL), right(NULL), count_ge(1){};
};

TreeNode* insertNode(TreeNode* root, int val) {
  if (root == NULL)
    return new TreeNode(val);
  else if (val == root->val)
    root->count_ge++;
  else if (val < root->val)
    root->left = insertNode(root->left, val);
  else {
    root->count_ge++;
    root->right = insertNode(root->right, val);
  }
  return root;
}

int search(TreeNode* root, int target) {
  if (root == NULL)
    return 0;
  else if (root->val == target)
    return root->count_ge;
  else if (root->val < target)
    return search(root->left, target);
  else
    return root->count_ge + search(root->right, target);
}

void emptyTree(TreeNode* node) {
  if (node != NULL) {
    emptyTree(node->left);
    emptyTree(node->right);
    delete node;
  }
  node = NULL;
}

int reversePairs(const std::vector<int>& nums) {
  TreeNode* root = NULL;
  int count = 0;
  for (size_t i = 0; i < nums.size(); ++i) {
    count += search(root, nums[i] * 2 + 1);
    insertNode(root, nums[i]);
  }
  emptyTree(root);

  return count;
}

int main() {
  int kMinValue = -1;
  int kMaxValue = 15;
  // size_t kMaxLisLen = 50000;
  size_t kMaxLisLen = 10;

  int len = randint(1, kMaxLisLen);
  std::cout << "Input length : " << len << std::endl;

  std::vector<int> nums{2, 4, 3, 5, 1};

  // std::vector<int> nums;
  // genRandIntList(nums, len, kMinValue, kMaxValue);
  std::cout << "Input :" << std::endl;
  printList<int>(nums);

  std::cout << "reverse pairs = " << reversePairs(nums) << std::endl;
  return 0;
}

#include <iostream>

#include "../utils/utils.h"

struct TreeNode {
  long val;
  size_t count_ge;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int val) : val(val), left(NULL), right(NULL), count_ge(1){};
};

TreeNode* insertNode(TreeNode* head, const long val) {
  if (head == NULL) {
    return new TreeNode(val);
  } else if (val == head->val) {
    // If there exists repeated values, no need to create a new tree head.
    head->count_ge++;
  } else if (val <= head->val) {
    head->left = insertNode(head->left, val);
  } else {
    head->count_ge++;
    head->right = insertNode(head->right, val);
  }
  return head;
}

// be careful, target here may overflow.
int search(TreeNode* head, long long target) {
  if (head == NULL)
    return 0;
  else if (head->val == target)
    return head->count_ge;
  else if (head->val < target) {
    // If the value of current node is smaller than the target, then all his
    // left children are smaller than the target, as a result, it is no need to
    // search his left children.
    return search(head->right, target);
  } else {
    // If the value of current node is larger than the target, then all his
    // right children are larger than the target, as a result, it is no need to
    // search his right children, but just add the `count_ge` and search his
    // left  childen.
    return head->count_ge + search(head->left, target);
  }
}

void emptyTree(TreeNode* node) {
  if (node != NULL) {
    emptyTree(node->left);
    emptyTree(node->right);
    delete node;
  }
  node = NULL;
}

void printTree(const TreeNode* node) {
  if (node == NULL) return;
  printTree(node->left);
  std::cout << node->val << std::endl;
  printTree(node->right);
}

int reversePairs(const std::vector<long>& nums) {
  TreeNode* root = NULL;
  int count = 0;
  for (size_t i = 0; i < nums.size(); ++i) {
    long long target = nums[i] * 2 + 1;
    count += search(root, target);
    root = insertNode(root, nums[i]);
  }
  emptyTree(root);
  return count;
}

int main() {
  // A boundary case.
  std::vector<long> nums{
      2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647};
  std::cout << "Input :" << std::endl;
  printList<long>(nums);
  std::cout << "reverse pairs = " << reversePairs(nums) << std::endl;
  return 0;
}

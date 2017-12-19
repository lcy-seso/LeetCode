#pragma once

#include "utils.h"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *gen_random_binary_tree(size_t node_num,
                                 int min_node_value,
                                 int max_node_value) {
  TreeNode *root = NULL;
  if (node_num == 0) return root;

  for (size_t i = 0; i < node_num; ++i) {
    TreeNode *node = new TreeNode(randint(min_node_value, max_node_value));
    if (!root) {
      root = node;
      continue;
    }

    // find a leave node to insert the node.
    TreeNode *insert_pos = root;
    while (insert_pos->left && insert_pos->right) {
      if (randint(0, 1)) {
        // choose left or right randomly
        // if 0, choose left. if 1, choose right.
        insert_pos = insert_pos->right;
      } else
        insert_pos = insert_pos->left;
    }

    if (insert_pos->left == NULL && insert_pos->right == NULL) {
      if (randint(0, 1)) {
        insert_pos->right = node;
      } else {
        insert_pos->left = node;
      }
    } else if (insert_pos->left)
      insert_pos->right = node;
    else
      insert_pos->left = node;
  }
  return root;
}

void preOrderPrintTree(const TreeNode *root) {
  if (!root) return;
  std::cout << root->val << std::endl;
  preOrderPrintTree(root->left);
  preOrderPrintTree(root->right);
}

void emptyTree(TreeNode *root) {
  if (root) {
    emptyTree(root->left);
    emptyTree(root->right);
    delete root;
  }
  root = NULL;
}

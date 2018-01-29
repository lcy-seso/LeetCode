#include <iostream>
#include <iterator>
#include <sstream>
#include <stack>

#include "../utils/tree_utils.h"

class Codec {
private:
  void preOrderTraverse(TreeNode* root, std::string& serialized_string) {
    if (!root) {
      serialized_string += "NIL\n";
      return;
    }

    serialized_string += (std::to_string(root->val) + "\n");
    if (!root->left && !root->right) return;
    serialized_string += "(\n";
    preOrderTraverse(root->left, serialized_string);
    // serialized_string += "\n";
    preOrderTraverse(root->right, serialized_string);
    serialized_string += ")\n";
  }

  std::vector<std::string> string_split(const std::string& str,
                                        const std::string& delimiter) {
    std::stringstream ss(str);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> split(begin, end);
    std::copy(split.begin(),
              split.end(),
              std::ostream_iterator<std::string>(std::cout, delimiter.c_str()));
    return split;
  }

public:
  // Encodes a tree to a single string.
  std::string serialize(TreeNode* root) {
    if (!root) return "";

    std::string serialized_string = "(\n";
    preOrderTraverse(root, serialized_string);
    return serialized_string + ")";
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(const std::string data) {
    std::vector<std::string> split = string_split(data, "\n");
    if (split.size() < 2) return NULL;  // This is an error input.

    std::stack<TreeNode*> unfinished;
    TreeNode* helper_root = new TreeNode(0);  // this is dummy node.
    unfinished.push(helper_root);

    size_t idx = 0;
    while (idx < split.size()) {
    }
    return NULL;
  }
};

int main() {
  const size_t node_num = 5;
  const int kMinValue = -5;
  const int kMaxValue = 10;

  TreeNode* root = gen_random_binary_tree(node_num, kMinValue, kMaxValue);
  preOrderPrintTree(root);
  std::cout << std::endl;

  Codec codec;
  std::string serialized_tree = codec.serialize(root);
  std::cout << serialized_tree << std::endl;
  TreeNode* rebuilt = codec.deserialize(serialized_tree);
  preOrderPrintTree(rebuilt);

  emptyTree(root);
  emptyTree(rebuilt);

  return 0;
}

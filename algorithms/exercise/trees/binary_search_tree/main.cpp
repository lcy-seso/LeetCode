#include <iostream>
#include <random>

#include "../../../utils/utils.h"
#include "binary_search_tree.h"

int main() {
  const int kMinValue = -10;
  const int kMaxValue = 10;
  const int kMaxElementNum = 20;

  int element_num = randint(1, kMaxElementNum);
  std::cout << "element number : " << element_num << std::endl;

  BinarySearchTree<int, int> bst;
  for (size_t i = 0; i < element_num; ++i) {
    int key = randint(kMinValue, kMaxValue);
    int value = randint(kMinValue, kMaxValue);

    std::cout << "insert (" << key << " , " << value << ")" << std::endl;
    bst.insert(key, value);
  }

  std::cout << bst.getNodeNum() << " nodes in the tree." << std::endl;
  std::string mode = "in-order";

  bst.traverseTree(
      [](int key, int val) {
        std::cout << "(" << key << "," << val << ")" << std::endl;
      },
      mode);

  int* searched_val = new int;
  int key = randint(kMinValue, kMaxValue);
  std::cout << "key = " << key << std::endl;
  bool found = bst.search(key, searched_val);
  if (found)
    std::cout << key << " is found, val = " << *searched_val << "."
              << std::endl;
  else
    std::cout << key << " is not found." << std::endl;
  delete searched_val;

  return 0;
}

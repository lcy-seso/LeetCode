#include <iostream>
#include <random>

#include "../../../utils/utils.h"
#include "binary_search_tree.h"

int main() {
  const int kMinValue = -10;
  const int kMaxValue = 10;
  const int kMaxElementNum = 20;

  // int element_num = randint(1, kMaxElementNum);
  int element_num = 10;
  std::cout << "element number : " << element_num << std::endl;
  int keys[] = {12, 5, 7, 23, 17, 11, 3, 5, 16, 27};
  int values[] = {6, 6, 6, 6, 6, 6, 6, 6, 6, 6};

  BinarySearchTree<int, int> bst;

  // build the BST.
  for (size_t i = 0; i < element_num; ++i) {
    // int key = randint(kMinValue, kMaxValue);
    // int value = randint(kMinValue, kMaxValue);
    // std::cout << "insert (" << key << " , " << value << ")" << std::endl;

    bst.insert(keys[i], values[i]);
  }
  std::cout << bst.getNodeNum() << " nodes in the tree." << std::endl;

  // in-order traverse to get a sorted list.
  std::string mode = "in-order";
  bst.traverseTree(
      [](int key, int val) {
        std::cout << "(" << key << "," << val << ")" << std::endl;
      },
      mode);

  // search by the key.
  int* searched_val = new int;
  // int key = randint(kMinValue, kMaxValue);
  int key = 23;
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

#include <iostream>
#include <vector>

class Node {
public:
  int val;
  std::vector<Node*> children;

  Node() {}

  Node(int _val, std::vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

std::vector<int> postorder(const Node* root) {
  std::vector<int> results(1, 0);
  return results;
}

int main() {
  // An simple test data.
  std::vector<Node*> leaves(3);
  for (size_t i = 0; i < leaves.size(); ++i)
    leaves[i] = new Node(i + 1, std::vector<Node*>());
  Node* root = new Node(5, leaves);

  std::vector<int> results = postorder(root);
  // for (auto v : results) std::cout << v << " ";
  // std::cout << std::endl;

  return 0;
}

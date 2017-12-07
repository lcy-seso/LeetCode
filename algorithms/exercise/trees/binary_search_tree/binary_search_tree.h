#include <functional>

/*
 * Only for exercise, not soild.
 */

template <typename Key, typename Value>
struct VisitFuncType {
  using type = std::function<void(Key, Value)>;
};

template <typename Key, typename Value>
class BinarySearchTree {
public:
  BinarySearchTree() : root_(NULL), node_num_(0){};
  ~BinarySearchTree() { makeEmpty(root_); };

  /*
   * This function modify the tree in place. The prior version of the tree is
   * lost. The tree is not a persistent data structure.
   */
  void insert(Key key, Value val) {
    TreeNode* trailing_ptr = NULL;
    TreeNode* next_node_ptr = root_;

    while (next_node_ptr) {
      trailing_ptr = next_node_ptr;
      if (key < next_node_ptr->key)
        next_node_ptr = next_node_ptr->left;
      else
        next_node_ptr = next_node_ptr->right;
    }

    TreeNode* new_node_ptr = new TreeNode(key, val);
    new_node_ptr->parent = trailing_ptr;
    if (!trailing_ptr)
      root_ = new_node_ptr;
    else if (key < trailing_ptr->key)
      trailing_ptr->left = new_node_ptr;
    else
      trailing_ptr->right = new_node_ptr;
    node_num_++;
  };

  Value& search(Key key) { return static_cast<Value>(0); };

  bool del(Key key) { return false; };

  /*
   * The in order traversal of a binary tree search tree gives an ordered key
   * list.
   */
  void traverseTree(const typename VisitFuncType<Key, Value>::type& visit,
                    const std::string& mode) const {
    traverseImp(root_, visit, mode);
    std::cout << std::endl;
  };

  size_t getNodeNum() const { return node_num_; };

private:
  struct TreeNode {
    Key key;
    Value val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    TreeNode(Key key, Value val)
        : val(val), key(key), left(NULL), right(NULL), parent(NULL){};
  };

  TreeNode* root_;
  size_t node_num_;

  void traverseImp(const TreeNode* node,
                   const typename VisitFuncType<Key, Value>::type& visit,
                   const std::string& mode) const {
    if (mode != "pre-order" && mode != "in-order" && mode == "post-order") {
      std::cout << "Error value for parameter mode." << std::endl;
      return;
    }

    if (!node) return;

    if (mode == "pre-order") visit(node->key, node->val);
    traverseImp(node->left, visit, mode);
    if (mode == "in-order") visit(node->key, node->val);
    traverseImp(node->right, visit, mode);
    if (mode == "post-order") visit(node->key, node->val);
  };

  void makeEmpty(TreeNode* node) {
    if (node != NULL) {
      makeEmpty(node->left);
      makeEmpty(node->right);
      delete node;
    }
    node = NULL;
  };

  TreeNode* minimum(const TreeNode* tree_root) {
    if (!tree_root) return NULL;

    Value min_val = tree_root->val;
    TreeNode* = trailing_ptr = tree_root->left()

  };
};

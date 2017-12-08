#include <functional>

/*
 * Only for exercise, not soild.
 */

// Here Key and Value can only be basic type, it does not take self-defined
// class into consideration. Only for exercise.
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

  bool search(const Key key, Value* val_ptr) const {
    return searchImp(root_, key, val_ptr);
  };

  bool del(Key key) {
    // locate the node to be deleted.
    TreeNode* trailing_ptr = NULL;
    TreeNode* next_node_ptr = root_;
    while (next_node_ptr) {
      trailing_ptr = next_node_ptr;
      if (key == next_node_ptr->key)
        break;
      else if (key < next_node_ptr->key)
        next_node_ptr = next_node_ptr->left;
      else
        next_node_ptr = next_node_ptr->right;
    }
    if (!next_node_ptr) return false;
    // Now next_node_ptr points to the node to be deleted.

    if (!next_node_ptr->left) {
      transplant(next_node_ptr, next_node_ptr->right);
    } else if (!next_node_ptr->right) {
      transplant(next_node_ptr, next_node_ptr->left);
    } else {
      // The node to be deleted has two children.
      TreeNode* minimum_of_right = minimum(next_node_ptr->right);
      if (minimum_of_right->parent != next_node_ptr) {
        // If the node with minimum key has left children, its left children
        // should replace its parent.
        transplant(minimum_of_right, minimum_of_right->right);
        minimum_of_right->right = next_node_ptr->right;
        minimum_of_right->right->parent = minimum_of_right;
      }

      transplant(next_node_ptr, minimum_of_right);
      minimum_of_right->left = next_node_ptr->left;
      minimum_of_right->left->parent = minimum_of_right;
    }
    return true;
  };

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

  bool searchImp(TreeNode* node, const Key key, Value* val_ptr) const {
    if (node == NULL) {
      val_ptr = NULL;
      return false;
    } else if (node->key == key) {
      *val_ptr = node->val;
      return true;
    }

    if (key < node->key)
      return searchImp(node->left, key, val_ptr);
    else
      return searchImp(node->right, key, val_ptr);
  }

  TreeNode* maximum(const TreeNode* node) {
    while (node->right != NULL) node = node->right;
    return node;
  };

  TreeNode* minimum(const TreeNode* node) {
    while (node->left != NULL) node = node->left;
    return node;
  };

  void transplant(TreeNode* u, TreeNode* v) {
    // NOTE: this function dose not update v.left and v.right. This is left to
    // its caller.

    // Here v must be a left node, otherwise calling this function will cause
    // dangling pointers. This function is only used in deleting an element from
    // the BST.

    if (u->parent == NULL) {
      root_ = v;
    } else if (u == u->parent->left) {
      u->parent->left = v;
    } else {
      u->parent->right = v;
    }
    if (v) {
      // Here we allow v is NULL.
      v->parent = u->parent;
    }
  };
};

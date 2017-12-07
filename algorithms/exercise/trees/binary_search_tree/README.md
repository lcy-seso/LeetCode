- What is binary search tree (short for BST)?
    - It is a binary tree and is always represented by a linked data structure.
    - In additionn to a key and a satellite data, each node contains attributes left, right, and parent.
    - The `root` node is the only node whose parent is `NULL`.
    - The keys in a BST are always stored in such a way to satisfy the binary-search-tree property:
        - let $x$ b a node in a BST.
            1. If $y$ is a node in the left subtree of $x$, then: $y.key \leq x.key$
            1. If $y$ is a node in the right subtree of $x$, then: $y.key \geq x.key$

- Supported operation:
  1. insertion and deletion.
  1. inorder tree walk.
  1. search.
  1. tree maximum and tree minimum.
      - We can always find an element in a binary search tree whose key is a minimum by following `left` child pointer from the `root` until we encounter a `NULL`.
      - We can always find an element in a binary search tree whose key is a maximum by following `right` child pointer from the `root` until we encounter a `NULL`.
  1. successor and predecessor
      - If all keys are distinct, the successor of a node $x$ is the node with the smallest key greater than $x$.

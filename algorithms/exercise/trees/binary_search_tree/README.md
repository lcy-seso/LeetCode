- What is binary search tree (short for BST)?
    - It is a binary tree and is always represented by a linked data structure.
    - In additionn to a key and a satellite data, each node contains attributes left, right, and parent.
    - The `root` node is the only node whose parent is `NULL`.
    - The keys in a BST are always stored in such a way to satisfy the binary-search-tree property:
        - let $x$ b a node in a BST.
            1. If $y$ is a node in the left subtree of $x$, then: $y.key \leq x.key$
            1. If $y$ is a node in the right subtree of $x$, then: $y.key \geq x.key$

- Supported operation:
  1. insertion and deletion. ($O(h)$, $h$ is height of the tree.)
  1. inorder tree walk.
  1. search. ($O(h)$, $h$ is height of the tree.)
  1. tree maximum and tree minimum.
      - We can always find an element in a binary search tree whose key is a minimum by following `left` child pointer from the `root` until we encounter a `NULL`.
      - We can always find an element in a binary search tree whose key is a maximum by following `right` child pointer from the `root` until we encounter a `NULL`.
  1. successor and predecessor
      - If all keys are distinct, the successor of a node $x$ is the node with the smallest key greater than $x$.

---

- Therefore we'd like to **strike a balance between searching and insertion operations**. This is where data structures like binary search tree (BST) or binary indexed tree (BIT) prevail, which offers relatively fast performance for both operations.

---
- Many problems involving arrays can be solved by breaking down the problem into subproblems applied on subarrays and then link the solution to the original problem with those of the subproblems:
    - sequential recurrence relation
    - partition recurrence relation
- For either case, it's crucial to identify the subproblem and find efficient algorithm for approaching it.
    1. If the subproblem involves searching on "dynamic searching space", try to consider data structures that support relatively fast operations on both searching and updating (such as self-balanced BST, BIT, Segment tree, ...).
    1. If the subproblem C of partition recurrence relation involves sorting, Merge-sort would be a nice sorting algorithm to use. Also, the code could be made more elegant if the solution to the subproblem can be embedded into the merging process.
    1. If there are overlapping among the subproblems `T(i, j)`, it's preferable to cache the intermediate results for future lookup (Dynamic Programming).

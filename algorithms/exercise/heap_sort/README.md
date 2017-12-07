### Concepts
- **Complete Binary Tree**
    - A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

- **A Binary Heap**
    * A **Complete Binary Tree** where items are stored in a special order such that value in a parent node is greater(or smaller) than the values in its two children nodes.
    * The former is called as max heap and the latter is called min heap.
    * The heap can be represented by binary tree or array.
        - If the parent node is stored at index $i$ (assuming the indexing starts at 0):
        - its left child is at: $2 * i + 1$
        - its right child is at: $2 * i + 2$
---
### Operations
1. heapification.
    - The heapification procedure can be applied to a node **only if its children nodes are heapified**.
    - So the heapification must be performed **in the bottom up order**.
1. heap sort.

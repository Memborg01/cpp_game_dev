#include <cstddef>
#include <iostream>

struct Node {

  int val{0};
  Node *left;
  Node *right;
};

/**
 * Creates node that will stay in heap.
 * This must be deleted from memory manually after use.
 *
 * @Param val Value to store in node
 *
 * @Return Pointer to newly created node
 */
Node *CreateNode(int val) {
  Node *node = new Node();
  node->val = val;
  return node;
}

/**
 * Looks through Binary Tree Search nodes in Post Order
 * (See reference to Postorder Traversal at:
 * https://www.geeksforgeeks.org/dsa/tree-traversals-inorder-preorder-and-postorder/)
 * If leaf node, print value.
 *
 * @param *subtree Pointer of the subtree node
 */
void PrintLeafNode(Node *subtree) {
  if (subtree == nullptr)
    return;

  if (subtree->left == nullptr && subtree->right == nullptr) {
    std::cout << subtree->val << "\n";
    return;
  }

  PrintLeafNode(subtree->left);
  PrintLeafNode(subtree->right);
}

/**
 * Places node value at empty place in node tree
 *
 * @Param *subtree Reference to the subtree we are in.
 * @Param *value Value we want to store in the node.
 * */
void InsertValue(Node *subtree, int value) {

  if (value < subtree->val) {
    if (subtree->left == nullptr) {
      subtree->left = CreateNode(value);
      return;
    }

    InsertValue(subtree->left, value);
    return;
  }

  if (subtree->right == nullptr) {
    subtree->right = CreateNode(value);
    return;
  }

  InsertValue(subtree->right, value);
  return;
}

Node *CreateBinarySearchTree(int *num_list, size_t size) {
  Node *root = CreateNode(num_list[0]);

  for (int i = 1; i < size; ++i) {
    InsertValue(root, num_list[i]);
  }

  return root;
}

/**
 * Delete Node tree recursively.
 */
void DeleteTree(Node *subtree) {
  if (subtree == nullptr) {
    return;
  }

  DeleteTree(subtree->left);
  DeleteTree(subtree->right);
  delete subtree;
}

int main() {
  const size_t size = 9;

  int num_list[size] = {8, 3, 12, 6, 1, 4, 10, 14, 9};

  Node *root = CreateBinarySearchTree(num_list, size);

  PrintLeafNode(root);

  DeleteTree(root);
  root = nullptr;

  return 0;
}

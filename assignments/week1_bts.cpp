#include <iostream>

struct Node {

  int val{0};
  Node *left;
  Node *right;
};

/**
 * Looks through Binary Tree Search nodes in Post Order
 * (See reference to Postorder Traversal at:
 * https://www.geeksforgeeks.org/dsa/tree-traversals-inorder-preorder-and-postorder/)
 * If leaf node, print value.
 *
 * @param *subtree Pointer of the subtree node
 */
void PostOrderPrintLeaf(Node *subtree) {
  if (subtree == nullptr)
    return;

  if (subtree->left == nullptr && subtree->right == nullptr) {
    std::cout << subtree->val << "\n";
    return;
  }

  PostOrderPrintLeaf(subtree->left);
  PostOrderPrintLeaf(subtree->right);
}

/**
 * Places node value at empty place in node tree
 *
 * @Param *subtree Reference to the subtree we are in.
 * @Param *currentNode Reference to the current node we want to place in Binary
 * Tree
 * */
void PlaceValue(Node *subtree, Node *currentNode) {
  if (currentNode->val < subtree->val) {
    if (subtree->left == nullptr) {
      subtree->left = currentNode;
      return;
    }

    PlaceValue(subtree->left, currentNode);
    return;
  }

  if (subtree->right == nullptr) {
    subtree->right = currentNode;
    return;
  }

  PlaceValue(subtree->right, currentNode);
  return;
}

Node CreateBinarySearchTree(Node node_list[9]) {
  Node root = node_list[0];

  for (int i = 1; i < 9; i++) {
    if (node_list[i].val == 0) {
      return root;
    }

    PlaceValue(&root, &node_list[i]);
  }
  return root;
}

Node BTSNode(int val) {
  Node node = Node();
  node.val = val;
  return node;
}

int main() {
  Node num_list[9] = {BTSNode(8),  BTSNode(3),  BTSNode(12),
                      BTSNode(6),  BTSNode(1),  BTSNode(4),
                      BTSNode(10), BTSNode(14), BTSNode(9)};

  Node newRoot = CreateBinarySearchTree(num_list);

  PostOrderPrintLeaf(&newRoot);

  return 0;
}

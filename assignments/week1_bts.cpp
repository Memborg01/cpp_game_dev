#include <iostream>
#include <string>

struct Node {
  int val{0};
  Node *left;
  Node *right;
};

void PostOrder(Node *subtree) {
  if (subtree->left == nullptr && subtree->right == nullptr) {
    std::cout << subtree->val << "\n";
    return;
  }

  PostOrder(subtree->left);
  PostOrder(subtree->right);
}

int main() {

  Node r1_l1 = Node();
  r1_l1.val = 4;

  Node left1_l1 = Node();
  left1_l1.val = 1;
  Node left1_r1 = Node();
  left1_r1.val = 6;
  left1_r1.left = &r1_l1;

  Node left1 = Node();
  left1.val = 3;
  left1.left = &left1_l1;
  left1.right = &left1_r1;

  Node root = Node();
  root.val = 8;
  root.left = &left1;

  PostOrder(&root);

  return 0;
}

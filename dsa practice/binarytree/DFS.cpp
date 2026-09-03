// depth first search is done by three types-
// 1. Inorder traversal
// 2. Preorder traversal
// 3. PostOrder traversal

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *left, *right;
  Node(int value)
  {
    data = value;
    left = right = NULL;
  }
};

// each node is visited exactly once
// if there are N nodes in the tree
// time complexity-O(N)
// space complexity-two parts matter
// 1. Recursive call stack- i) the maximum depth of recursion=height of tree=O(h)
// ii) in worst case(skewed tree), h=N
// iii) in best case(balanced tree),h=logN
// 2. No extra data structures are used
// so, SC = O(h) where h is the height of tree
// in worst case(skewed tree)=o(N)
// in best/average case(balanced binary tree)=o(logN)

// inorder- left root right
// here we do using recursion
void inOrder(Node *root)
{
  if (root == NULL)
    return;
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

// preorder-root left right
// here we do using recursion
void preOrder(Node *root)
{
  if (root == NULL)
    return;
  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

// postorder-left right root
// here we do using recursion
void postOrder(Node *root)
{
  if (root == NULL)
    return;
  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}
int main()
{
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->right = new Node(5);

  cout << "Inorder Traversal: ";
  inOrder(root);
  cout << endl;

  cout << "Preorder Traversal: ";
  preOrder(root);
  cout << endl;

  cout << "Postorder Traversal: ";
  postOrder(root);
  cout << endl;

  return 0;
}
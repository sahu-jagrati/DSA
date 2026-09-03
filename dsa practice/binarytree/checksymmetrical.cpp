// symmetric binary tree?- it forms a mirror of itself around the centre or not
// mirror property-left=right and right =left
// we can say that- root->left=root->right
// rootleftright=rootrightleft

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *left, *right;
  Node(int val)
  {
    data = val;
    left = right = NULL;
  }
};

bool isSymmetricHelp(Node *left, Node *right)
{
  if (left == NULL || right == NULL)
    return left == right; // true
  if (left->data != right->data)
    return false;

  return (isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left));
}

// t.c=O(n)
// s.c=o(n)in worst case(skewed tree)
bool isSymmetric(Node *root)
{
  return root == NULL || isSymmetricHelp(root->left, root->right);
}

int main()
{
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(2);
  root->left->left = new Node(3);
  root->left->right = new Node(4);
  root->right->left = new Node(4);
  root->right->right = new Node(3);

  bool result = isSymmetric(root);
  cout << result << endl;

  return 0;
}
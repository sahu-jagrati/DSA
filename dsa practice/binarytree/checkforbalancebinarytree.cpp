// how to check-for every node-|height(left)-height(right)|<=1

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

// brute- time complexity-O(N)(for check each node)*O(N)(for height function) = approx.O(N^2) so we have to convert it in O(N)- how?
// space complexity-O(N) auxilliary space // in worst case when we have skewed tree 
int height(Node *root)
{
  if (root == NULL)
    return 0;
  int lh = height(root->left);
  int rh = height(root->right);

  return (1 + max(lh, rh));
}
bool check(Node *root)
{
  if (root == NULL)
    return true;
  int lh = height(root->left);
  int rh = height(root->right);
  if (abs(rh - lh) > 1)
    return false;

  bool left = check(root->left);
  bool right = check(root->right);
  if (!left || !right)
    return false; // if in any node does not return true then return false

  return true;
}

// optimal- we know whole function is depend on height so we can think about that
// time complexity=O(N)
 // space complexity-O(N) auxilliary space // in worst case when we have skewed tree
int Height(Node *root)
{
  if (root == NULL)
    return 0;
  int leftHeight = Height(root->left);
  if (leftHeight == -1)
    return -1;
  int rightHeight = Height(root->right);
  if (rightHeight == -1)
    return -1;
  if (abs(leftHeight - rightHeight) > 1)
    return -1;

  return (1 + max(leftHeight, rightHeight));
}
bool isBalancedBinaryTree(Node *root)
{
  return Height(root) != -1;
}
int main()
{
  Node *root = new Node(3);
  root->left = new Node(9);
  root->right = new Node(20);
  root->right->left = new Node(15);
  root->right->right = new Node(7);

  // bool result = check(root);
  bool result = isBalancedBinaryTree(root);
  cout << result << endl;
  return 0;
}
// diameter of binary tree-1. longest path between 2 nodes
// 2. path does not need to pass via root

#include <iostream>
#include <climits>
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

// brute-time complexity-O(N)*O(N)=O(N^2)
int height(Node *root)
{
  if (root == NULL)
    return 0;
  int leftHeight = height(root->left);
  int rightHeight = height(root->right);

  return (1 + max(leftHeight, rightHeight));
}
int diameter(Node *root)
{
  if (root == NULL)
    return 0;
  // get heights
  int lh = height(root->left);
  int rh = height(root->right);
  // get diameters of subtrees
  int leftDiameter = diameter(root->left);
  int rightDiameter = diameter(root->right);

  // diameter through root=lh+rh
  return max(lh + rh, max(leftDiameter, rightDiameter));
}
// optimal-time complexity-O(N)
// space complexity-O(N) auxiliary stack space in worst case when tree is skewed
// in best case when balanced tree-O(logN)
int Height(Node *root, int &diameter)
{
  if (root == NULL)
    return 0;
  int lh = Height(root->left, diameter);
  int rh = Height(root->right, diameter);
  diameter = max(diameter, lh + rh);
  return 1 + max(lh, rh);
}
int Diameter(Node *root)
{
  int diameter = 0;
  Height(root, diameter);
  return diameter;
}

int main()
{
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->right->left = new Node(4);
  root->right->left->left = new Node(5);
  root->right->left->left->left = new Node(6);
  root->right->right = new Node(7);
  root->right->right->right = new Node(8);
  root->right->right->right->right = new Node(9);

  int ans = diameter(root);
  cout << ans << endl;
  int result = Diameter(root);
  cout << result << endl;

  return 0;
}
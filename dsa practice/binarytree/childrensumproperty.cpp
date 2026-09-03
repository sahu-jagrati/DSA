// children sum property says - node=left+right
// you can increase and node by +1 any times
// you can only increase the value not decrease
// you have no restriction on +1. you can add as many times as you want. we don't want to find minimumu to add
// you cannot change the structure of binary tree
#include <iostream>
using namespace std;

struct TreeNode
{
  int data;
  TreeNode *left, *right;
  TreeNode(int value)
  {
    data = value;
    left = right = NULL;
  }
};
// in geeksforgeeks solution we have solution with t.c-O(N^2)
// t.c=O(N)
// s.c=O(height of binary tree) in worst case it can be O(N)
void changeTree(TreeNode *root)
{
  if (!root)
    return;

  // going up to down
  int child = 0;
  if (root->left)
    child += root->left->data;
  if (root->right)
    child += root->right->data;
  if (child >= root->data)
    root->data = child;
  else
  {
    if (root->left)
      root->left->data = root->data;
    else if (root->right)
      root->right->data = root->data;
  }

  // return back - going down to top
  int tot = 0;
  if (root->left)
    tot += root->left->data;
  if (root->right)
    tot += root->right->data;
  if (root->left || root->right)
    root->data = tot;
}

int main()
{
  TreeNode *root = new TreeNode(50);
  root->left = new TreeNode(7);
  root->right = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(1);
  root->right->right = new TreeNode(30);

  changeTree(root);
  return 0;
}
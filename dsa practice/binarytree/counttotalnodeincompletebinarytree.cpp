// count total nodes in complete binary tree in O((log N)^2) approach
// O(N) approach is simple any traversal and count
// O((logN)^2) approach is-every time we visit the node and calculate leftheight and rightheight
// if lh=rh then use the formula ((2^h)-1)
// if lh not = rh then use (1)+(left subtree)+ (right subtree) i.e. recursion

#include <bits/stdc++.h>
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

int findLeftHeight(TreeNode(*node))
{
  int height = 0;
  while (node)
  {
    height++;
    node = node->left;
  }
  return height;
}
int findRightHeight(TreeNode(*node))
{
  int height = 0;
  while (node)
  {
    height++;
    node = node->right;
  }
  return height;
}

// t.c-logN(for traversal)*logN(for find height)=O((logN)^2)
// s.c-O(logN)stack space
int countNode(TreeNode *root)
{
  if (!root)
    return 0;

  int lh = findLeftHeight(root);
  int rh = findRightHeight(root);

  if (lh == rh)
    return (1 << lh) - 1;

  return 1 + countNode(root->left) + countNode(root->right);
}

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->left->right = new TreeNode(7);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(6);

  int count = countNode(root);
  cout << count << endl;

  return 0;
}
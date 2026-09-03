// Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

// A leaf is a node with no children

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left, *right;
  TreeNode(int data)
  {
    val = data;
    left = right = NULL;
  }
};

bool hasPathSum(TreeNode *root, int targetSum)
{
  if (root == NULL)
    return false;
  if (root->left == NULL && root->right == NULL)
  {
    return targetSum == root->val;
  }
  return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}

// in int main take binary tree and target sum as a input
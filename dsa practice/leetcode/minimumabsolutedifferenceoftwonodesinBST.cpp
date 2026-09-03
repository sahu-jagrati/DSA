// Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

// example 1-
// Input: root = [4,2,6,1,3]
// Output: 1

// example 2-
// Input: root = [1,0,48,null,null,12,49]
// Output: 1

// Constraints:

// The number of nodes in the tree is in the range [2, 10^4].
// 0 <= Node.val <= 10^5

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val)
  {
    data = val;
    left = NULL;
    right = NULL;
  }
};

void inorderOfBST(TreeNode *root, vector<int> &inorder)
{
  if (root == NULL)
    return;
  inorderOfBST(root->left, inorder);
  inorder.push_back(root->data);
  inorderOfBST(root->right, inorder);
}
int minimumAbsoluteDifference(TreeNode *root)
{
  if (root == NULL)
    return 0;
  vector<int> inorder;
  inorderOfBST(root, inorder); // void function so doesn't return anything
  int minDiff = INT_MAX;
  for (int i = 0; i < inorder.size() - 1; i++)
  {
    int diff = abs(inorder[i] - inorder[i + 1]);
    if (diff < minDiff)
    {
      minDiff = diff;
    }
  }
  return minDiff;
}

int main()
{
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(7);

  cout << minimumAbsoluteDifference(root) << endl;
  return 0;
}

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

int inorder(TreeNode *root, int sum, int low, int high)
{
  if (root == NULL)
    return sum;
  inorder(root->left, sum, low, high);
  if (root->data >= low && root->data <= high)
    sum += root->data;
  inorder(root->right, sum, low, high);
  return sum;
}

int rangeSumBST(TreeNode *root, int low, int high)
{
  if (root == NULL)
    return 0;
  int sum = 0;
  int ans = inorder(root, sum, low, high);
  return ans;
}

int main()
{
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(5);
  root->left->left = new TreeNode(3);
  root->left->left->left = new TreeNode(1);
  root->left->right = new TreeNode(7);
  root->left->right->left = new TreeNode(6);
  root->right = new TreeNode(15);
  root->right->left = new TreeNode(13);
  root->right->right = new TreeNode(18);

  int low, high;
  cin >> low >> high;
  cout << rangeSumBST(root, low, high);
  return 0;
}
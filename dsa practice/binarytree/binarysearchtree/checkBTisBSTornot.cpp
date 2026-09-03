// given a BT check whether it is BST or not
// ypu have to check for whole left part and whole right part of that particular node
// so we use range method

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

bool isValid(TreeNode *root, long minVal, long maxVal)
{
  if (root == NULL)
    return true;
  if (root->data >= maxVal || root->data <= minVal)
    return false;
  return isValid(root->left, minVal, root->data) && isValid(root->right, root->data, maxVal);
}
bool isValidBST(TreeNode *root)
{
  return isValid(root, LONG_MIN, LONG_MAX);
}

int main()
{
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(1);
  root->right = new TreeNode(6);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(8);

  bool result = isValidBST(root);
  cout << result << endl;

  return 0;
}
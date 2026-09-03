// given a key, we have to find a ceil of key that is val in BST which is greater than or equal to key but val should be min as possible but greater than or equal to key 

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

// t.c-O(logN)(base 2)-height of tree
// s.c -O(1)
int ceilInBST(TreeNode *root, int key)
{
  int ceil = -1;
  while (root)
  {
    if (root->data == key)
    {
      ceil = root->data;
      return ceil;
    }

    if (key > root->data)
    {
      root = root->right;
    }
    else
    {
      ceil = root->data;
      root = root->left;
    }
  }
  return ceil;
}

int main()
{
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(5);
  root->right = new TreeNode(13);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(6);
  root->left->left->left = new TreeNode(2);
  root->left->left->right = new TreeNode(4);
  root->left->right->right = new TreeNode(9);
  root->right->left = new TreeNode(11);
  root->right->right = new TreeNode(14);

  int key;
  cout << "Enter the value of key: ";
  cin >> key;

  int result = ceilInBST(root, key);
  cout << result << endl;

  return 0;
}
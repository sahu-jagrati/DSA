// given a key, we have to find a floor of key that is val from BST which is less than or equal to key but val should max as possible but less than or equal to key

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

int floorInBST(TreeNode *root, int key)
{
  int floor = -1;
  while (root)
  {
    if (root->data == key)
    {
      floor = root->data;
      return floor;
    }
    if (key < root->data)
    {
      root = root->left;
    }
    else
    {
      floor = root->data;
      root = root->right;
    }
  }
  return floor;
}

int main()
{
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(5);
  root->right = new TreeNode(15);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(6);

  int key;
  cout << "Enter the value of key: ";
  cin >> key;

  int result = floorInBST(root, key);
  cout << result << endl;

  return 0;
}
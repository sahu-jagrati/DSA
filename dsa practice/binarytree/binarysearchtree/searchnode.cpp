// we know in binary search tree left<node<right
// and generatlly height of BST is (log N)(base 2)
// it is not necessity but in almost all the cases height is always (log N)(base 2)

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  /* data */
  int data;
  TreeNode *left, *right;
  TreeNode(int value)
  {
    data = value;
    left = right = NULL;
  }
};

// t.c=O(logN)(base 2)
// s.c-O(1)
TreeNode *searchInBST(TreeNode *root, int val)
{
  while (root != NULL && root->data != val)
  {
    root = val < root->data ? root->left : root->right;
  }
  return root;
}

int main()
{
  // take binary search tree left<node<right
  TreeNode *root = new TreeNode(8);
  root->left = new TreeNode(3);
  root->right = new TreeNode(10);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(6);
  root->left->right->left = new TreeNode(4);
  root->left->right->right = new TreeNode(7);
  root->right->right = new TreeNode(14);
  root->right->right->left = new TreeNode(13);

  int val;
  cout << "Enter the search value: ";
  cin >> val;
  TreeNode *result = searchInBST(root, val);
  cout << result->data << endl;

  return 0;
}

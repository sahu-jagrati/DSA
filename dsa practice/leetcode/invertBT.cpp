
// Given the root of a binary tree, invert the tree, and return its root.

// example 1-
// Input: root = [4,2,7,1,3,6,9] // level order given
// Output: [4,7,2,9,6,3,1]

// example 2-
// Input: root = [2,1,3]
// Output: [2,3,1]

// Example 3:
// Input: root = []
// Output: []

// Constraints:

// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int data;
  TreeNode *left, *right;
  TreeNode(int val)
  {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

// done by me fully
TreeNode *invertBT(TreeNode *root)
{
  if (root == NULL)
    return root;
  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty())
  {
    int size = q.size();
    for (int i = 0; i < size; i++)
    {
      TreeNode *curr = q.front();
      q.pop();
      // first logic is this push right part first then left part
      if (curr->right != NULL)
      {
        q.push(curr->right);
      }
      if (curr->left != NULL)
      {
        q.push(curr->left);
      }
      // second logic is this left is right and right is left
      TreeNode *temp = curr->left;
      curr->left = curr->right;
      curr->right = temp;
    }
  }
  return root;
}

void printInOrder(TreeNode *root)
{
  if (root == NULL)
    return;
  printInOrder(root->left);
  cout << root->data << " ";
  printInOrder(root->right);
}
int main()
{
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(7);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(9);

  TreeNode *ans = invertBT(root);
  printInOrder(ans);
  return 0;
}
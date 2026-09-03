// given a node that is not present in BST, we have to insert it in BST such that after insertion BST holds the property- left<node<right
// in answer you have to return a root of modify BST
// you have so many possibility of insertion with property holds
// we do by where the property holds and have null place, we insert it
// it mainly leaf position

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

// t.c-O(logN)(base 2)
//  s.c-O(1)
TreeNode *insertGivenNode(TreeNode *root, int val)
{
  if (root == NULL)
    return new TreeNode(val);
  TreeNode *curr = root;
  while (true)
  {
    if (curr->data < val)
    {
      if (curr->right != NULL)
        curr = curr->right;
      else
      {
        curr->right = new TreeNode(val);
        break;
      }
    }
    else
    {
      if (curr->left != NULL)
        curr = curr->left;
      else
      {
        curr->left = new TreeNode(val);
        break;
      }
    }
  }
  return root;
}

void printinOrder(TreeNode *root)
{
  if (root == NULL)
    return;
  printinOrder(root->left);
  cout << root->data << " ";
  printinOrder(root->right);
}
int main()
{
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(7);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->right->left = new TreeNode(5);

  int val;
  cout << "Enter the value that has to be insert: ";
  cin >> val;

  TreeNode *result = insertGivenNode(root, val);
  printinOrder(result);

  return 0;
}
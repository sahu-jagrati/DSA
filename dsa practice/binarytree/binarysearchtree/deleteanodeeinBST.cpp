// we have to delete a node and after deleting tree should be hold property of BST
// in answer, we have to return a tree after deleting and arrange according to BST property
// there can be multiple answer
// in all approach - 1st - seacrh a node
// 2nd- delete it
// now ways
// Ist way- we know left part of deleting node is always smaller than right part so we connect left part of deletenode to root of deletenode and right part of deletnode to rightmost guy of left part it is satisfy the property
// IInd way- we know right part of deleting node is always greater than left part so we connect right part of deletenode to root of deletenode and left part of deletnode to leftmost guy of right part it is satisfy the property
// these two are approaches you can use any one but we have edge case also-
// if there is no left part of delete node or right part of delete node

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
TreeNode *findLastRightOfLeft(TreeNode *root)
{
  if (root->right == NULL)
    return root;
  return findLastRightOfLeft(root->right);
}
TreeNode *helper(TreeNode *root)
{
  if (root->left == NULL)
    return root->right;
  else if (root->right == NULL)
    return root->left;
  TreeNode *rightChild = root->right;
  TreeNode *lastLeftRight = findLastRightOfLeft(root->left);
  lastLeftRight->right = rightChild;
  return root->left;
}

// t.c-O(ht of tree)
// s.c-O(1)
TreeNode *deleteNode(TreeNode *root, int key)
{
  if (root == NULL)
    return NULL;
  if (root->data == key)
    return helper(root);
  TreeNode *dummy = root;
  while (root != NULL)
  {
    if (root->data > key)
    {
      if (root->left != NULL && root->left->data == key)
      {
        root->left = helper(root->left);
        break;
      }
      else
      {
        root = root->left;
      }
    }
    else
    {
      if (root->right != NULL && root->right->data == key)
      {
        root->right = helper(root->right);
        break;
      }
      else
      {
        root = root->right;
      }
    }
  }
  return dummy;
}

void printPreOrder(TreeNode *root)
{
  if (root == NULL)
    return;
  cout << root->data << " ";
  printPreOrder(root->left);
  printPreOrder(root->right);
}
int main()
{
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(2);
  root->right = new TreeNode(7);
  root->left->right = new TreeNode(3);
  root->left->right->right = new TreeNode(4);

  int key;
  cout << "Enter the value of key: ";
  cin >> key;
  TreeNode *result = deleteNode(root, key);
  printPreOrder(result);

  return 0;
}
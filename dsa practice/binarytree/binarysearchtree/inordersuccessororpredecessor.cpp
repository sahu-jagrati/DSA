// successor means first elt which is greater than given val
// predecessor means last elt which is smaller than given val
// we have three solution
// naive solution 1st- stored inorder and inorder of BST is sorted so apply binary search ang get that elt
// t.c-O(N)(for inorder)+O(logN)(binary search)
// s.c-O(N)(for storing inorder)

// 2nd solution- perform an inorder and when we get that elt which is successor or predecessor is our answer and stop there
// t.c-O(N)
// s.c-O(1) by morris traversal no recursion

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
// 3rd solution- property of BST
// t.c-O(ht of tree)
// s.c-O(1)
TreeNode *inorderSuccessor(TreeNode *root, int val)
{
  TreeNode *successor = NULL;
  while (root != NULL)
  {
    if (root->data <= val)
    {
      root = root->right;
    }
    else
    {
      successor = root;
      root = root->left;
    }
  }
  return successor;
}

// t.c-O(ht of tree)
// s.c-O(1)
TreeNode *inorderPredecessor(TreeNode *root, int val)
{
  TreeNode *predecessor = NULL;
  while (root != NULL)
  {
    if (root->data >= val)
    {
      root = root->left;
    }
    else
    {
      predecessor = root;
      root = root->right;
    }
  }
  return predecessor;
}

int main()
{
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(7);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->left->left->left = new TreeNode(1);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(9);
  root->right->right->left = new TreeNode(8);
  root->right->right->right = new TreeNode(10);

  int val;
  cout << "Enter the value whose successor and predecessor have to find: ";
  cin >> val;
  TreeNode *successorresult = inorderSuccessor(root, val);
  cout << successorresult->data << endl;

  TreeNode *predecessorresult = inorderPredecessor(root, val);
  cout << predecessorresult->data << endl;

  return 0;
}
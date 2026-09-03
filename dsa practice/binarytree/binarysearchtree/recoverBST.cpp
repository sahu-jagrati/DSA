// recover BST means you have to swap only two nodes, not more or not less than two so that the given tree becomes BST

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

// brute solution - do any traversal - sort it - give correct inorder beacuse inorder of BST is always sorted, run pointer on correct inorder traversal and compare it with incorrect inorder traversal of tree and replace node when you get incorrect node in tree traversal
// t.c-O(N)(for any traversal)+O(NlogN)(for sorting)+O(N)(again traversal for comparison)
// s.c-O(N) for storing sorting traversal, here we do not add any recursion stack space

// efficient solution-
// swap can have two cases-
// 1. swapped nodes are not adjacent
// 2. swapped nodes are adjacent

// Ques- is there any need of storing inorder?
// no

// here in inorder traversal we want only track prev->node and current node
// we do inorder traversal but not storing it we take first, middle and last node that used to check which node is in wrong place


// t.c-O(N) simple inorder traversal
//s.c-O(1) 
class Solution
{
  TreeNode *first;
  TreeNode *prev;
  // we store middle because if swapped nodes are adjacent then we don't get last so we have to swap between first and middle
  TreeNode *middle;
  TreeNode *last;

  void inorder(TreeNode *root)
  {
    if (root == NULL)
      return;
    inorder(root->left);

    if (prev != NULL && root->data < prev->data)
    {
      // if this is first node/violation then
      if (first == NULL)
      {
        first = prev;
        middle = root;
      }
      else
      {
        last = root;
      }
    }
    prev = root;
    inorder(root->right);
  }

public:
  void recoverTree(TreeNode *root)
  {
    first = middle = last = NULL;
    prev = new TreeNode(INT_MIN);
    inorder(root);
    if (first && last)
      swap(first->data, last->data);
    else if (first && middle)
      swap(first->data, middle->data);
  }
};

void printInOrder(TreeNode *node)
{
  if (node == NULL)
    return;
  printInOrder(node->left);
  cout << node->data << " ";
  printInOrder(node->right);
}
int main()
{
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(1);
  root->right = new TreeNode(4);
  root->right->left = new TreeNode(2);

  Solution result;
  result.recoverTree(root);

  printInOrder(root);

  return 0;
}
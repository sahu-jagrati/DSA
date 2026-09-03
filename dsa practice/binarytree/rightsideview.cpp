// we can say that the last node of every level is our right view of binary tree
// or if we reverse then we can say that the first node of every level is our right view of binary tree

// we can use traversal-
// 1. if we use iterative i.e level order in this code is bit lengthy and in worst case s.c becomes so large so we don't prefer this

// 2. recursive i.e(in/pre/post order)-in this code is short and s.c=O(height of binary tree) and in worst case o(N)(skewed tree)
//  so we use recursive in which we use reverse preorder traversal
//  in preorder-root left right
//  in reverse preorder-root right left

#include <iostream>
#include <vector>
using namespace std;

struct Node
{
  int data;
  Node *left, *right;
  Node(int val)
  {
    data = val;
    left = right = NULL;
  }
};

void recursion(Node *root, int level, vector<int> &ans)
{
  if (root == NULL)
    return;
  if (ans.size() == level)
    ans.push_back(root->data);
  recursion(root->right, level + 1, ans);
  recursion(root->left, level + 1, ans);
}

// t.c=O(n)
// s.c=o(H) and in worst case O(n) skewed tree
vector<int> rightSideView(Node *root)
{
  vector<int> ans;
  recursion(root, 0, ans);
  return ans;
}

int main()
{
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->left->right->left = new Node(6);
  root->right->right = new Node(7);

  vector<int> result = rightSideView(root);
  for (auto it : result)
  {
    cout << it << " ";
  }
  return 0;
}
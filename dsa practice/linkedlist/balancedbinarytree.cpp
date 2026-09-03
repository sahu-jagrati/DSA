// A binary tree is height-balanced if, for every node, the absolute difference in height between its left and right subtrees is at most 1. This property ensures the tree's overall height remains logarithmic, \(O(\log n)\), improving search, insertion, and deletion efficiency. Common examples include AVL and Red-Black trees. Key Characteristics and Checking Methods: Definition: A node is balanced if (height(left_subtree)-height(right_subtree)<=1).Recursive Check: To verify if a tree is balanced, one must recursively check if the left and right subtrees are balanced and ensure their height difference is (<=1).Empty Nodes: An empty tree (NULL) is considered height-balanced.Rebalancing: When the property is violated during insertion or deletion, the tree is rebalanced using tree rotations (left, right, or double rotations). Common Data Structures: AVL Tree: Strict, maintains height difference (<=1).Red-Black Tree: Ensures similar heights by tracking node colors (black-balanced). If any node fails the condition, the entire tree is considered unbalanced. 

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val)
  {
    data = val;
    left = right = NULL;
  }
};

int height(TreeNode *root)
{
  if (root == NULL)
    return 0;
  int leftHeight = height(root->left);
  int rightHeight = height(root->right);
  if (leftHeight == -1 || rightHeight == -1)
    return -1;

  if (abs(leftHeight - rightHeight) > 1)
    return -1;

  return (1 + max(leftHeight, rightHeight));
}

bool isBalanced(TreeNode *root)
{
  return height(root) != -1;
}

int main()
{
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(6);
  root->right->left = new TreeNode(2);
  root->right->right = new TreeNode(4);

  cout << isBalanced(root) << endl;
  return 0;
}
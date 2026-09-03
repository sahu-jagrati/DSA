// Given a binary tree, find its minimum depth.

// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

// Note: A leaf is a node with no children.

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: 2
// Example 2:

// Input: root = [2,null,3,null,4,null,5,null,6]
// Output: 5

// Constraints:

// The number of nodes in the tree is in the range [0, 10^5].
// -1000 <= Node.val <= 1000

#include <bits/stdc++.h>
using namespace std;

// here // The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
struct TreeNode
{
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val)
  {
    data = val;
    left = NULL;
    right = NULL;
  }
};
int minDepth(TreeNode *root)
{
  // base case
  // when there is no tree
  if (root == NULL)
    return 0; // i.e no node there
  // when root have no left and right node then root only
  if (root->left == NULL && root->right == NULL)
    return 1;

  // initialize the depth of two subtrees
  int leftDepth = minDepth(root->left);
  int rightDepth = minDepth(root->right);

  // if left subtree is empty then return the depth of right subtree
  if (root->left == NULL)
  {
    return 1 + rightDepth; // we do +1 because root node itself also count
  }
  // if right subtree is empty then return the depth of left subtree
  if (root->right == NULL)
  {
    return 1 + leftDepth; // we do +1 because root node itself also count
  }
  // when we have both subtrees then return the minimum of both
  return 1 + min(leftDepth, rightDepth); // we do +1 because root node itself also count
}

int main()
{
  TreeNode *root = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->right = new TreeNode(4);
  root->right->right->right = new TreeNode(5);
  root->right->right->right->right = new TreeNode(6);
  cout << minDepth(root);
  return 0;
}
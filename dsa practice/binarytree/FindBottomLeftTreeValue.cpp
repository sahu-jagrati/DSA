// Given the root of a binary tree, return the leftmost value in the last row of the tree.

// Example 1:

// Input: root = [2,1,3]
// Output: 1
// Example 2:

// Input: root = [1,2,3,4,null,5,6,null,null,7]
// Output: 7

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -2^31 <= Node.val <= 2^31 - 1

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
    left = right = nullptr;
  }
};
// it is done by me fully

// here in this problem we want the leftmost value of the last row

// so here we do level order traversal we want leftmost value so at each level we store the leftmost value and when we reach at last row ae get the leftmost value for that row

// leftmost value means for level order traversal we use queue and we go with size of each level so for that level when i==0 it is a leftmost value

// t.c-O(n) where n is the number of total nodes because we just travel each node
// s.c-O(n) for queue
int findBottomeLeftValue(TreeNode *root)
{
  // as according to constraints there is atleast one node in a tree so I don't write for root==NULL
  queue<TreeNode *> q;
  q.push(root);
  int ans;
  while (!q.empty())
  {
    int size = q.size();
    for (int i = 0; i < size; i++)
    {
      TreeNode *curr = q.front();
      q.pop();
      if (i == 0)
        ans = curr->data;
      if (curr->left != NULL)
        q.push(curr->left);
      if (curr->right != NULL)
        q.push(curr->right);
    }
  }
  return ans;
}

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(5);
  root->right->left->left = new TreeNode(7);
  root->right->right = new TreeNode(6);
  cout << findBottomeLeftValue(root);
  return 0;
}
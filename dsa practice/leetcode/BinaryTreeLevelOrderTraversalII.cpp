// Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: [[15,7],[9,20],[3]]
// Example 2:

// Input: root = [1]
// Output: [[1]]
// Example 3:

// Input: root = []
// Output: []

// Constraints:

// The number of nodes in the tree is in the range [0, 2000].
// -1000 <= Node.val <= 1000

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
vector<vector<int>> levelOrderBottom(TreeNode *root)
{
  vector<vector<int>> ans;
  if (root == NULL)
    return ans;
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty())
  {
    int size = q.size();
    vector<int> temp;
    for (int i = 0; i < size; i++)
    {
      TreeNode *curr = q.front();
      q.pop();
      if (curr->left != NULL)
      {
        q.push(curr->left);
      }
      if (curr->right != NULL)
      {
        q.push(curr->right);
      }
      temp.push_back(curr->data);
    }
    ans.push_back(temp);
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
int main()
{
  TreeNode *root = new TreeNode(1);
  // root->left = new TreeNode(9);
  // root->right = new TreeNode(20);
  // root->right->left = new TreeNode(15);
  // root->right->right = new TreeNode(7);

  vector<vector<int>> ans = levelOrderBottom(root);
  for (auto it1 : ans)
  {
    for (auto it2 : it1)
    {
      cout << it2 << " ";
    }
    cout << endl;
  }
  return 0;
}
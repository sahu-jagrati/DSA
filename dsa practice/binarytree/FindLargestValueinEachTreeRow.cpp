// Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

// Example 1:

// Input: root = [1,3,2,5,3,null,9]
// Output: [1,3,9]
// Example 2:

// Input: root = [1,2,3]
// Output: [1,3]

// Constraints:

// The number of nodes in the tree will be in the range [0, 104].
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

// so here we want max value of each row so we do levle order traversla and get max value of that level

// t.c-O(n) where n is the number of total nodes because we just travel each node
// s.c-O(n) for queue+O(ans.size())
vector<int> largestValues(TreeNode *root)
{
  vector<int> ans;
  if (root == NULL)
    return ans;
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty())
  {
    int size = q.size();
    int maxi = q.front()->data; // for getting max value of that level, initially we put it q.front() of that row/level
    for (int i = 0; i < size; i++)
    {
      TreeNode *curr = q.front();
      q.pop();
      if (curr->data > maxi)
        maxi = curr->data;
      if (curr->left != NULL)
        q.push(curr->left);
      if (curr->right != NULL)
        q.push(curr->right);
    }
    ans.push_back(maxi); // after getting max value for each row we push it in ans array
  }
  return ans;
}

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(3);
  root->right = new TreeNode(2);
  root->left->left = new TreeNode(5);
  root->left->right = new TreeNode(3);
  root->right->right = new TreeNode(9);
  vector<int> ans = largestValues(root);
  for (auto it : ans)
  {
    cout << it << " ";
  }
  return 0;
}
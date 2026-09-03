// Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.

// example-1
// Input: root = [3,9,20,null,null,15,7]
// Output: [3.00000,14.50000,11.00000]
// Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
// Hence return [3, 14.5, 11].

// example-2
// Input: root = [3,9,20,15,7]
// Output: [3.00000,14.50000,11.00000]

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -231 <= Node.val <= 231 - 1

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
    left = NULL;
    right = NULL;
  }
};

vector<double> averageOfLevels(TreeNode *root)
{
  vector<double> ans;
  if (root == NULL)
    return ans;
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty())
  {
    int size = q.size();
    double sum = 0.0;
    for (int i = 0; i < size; i++)
    {
      TreeNode *curr = q.front();
      q.pop();
      sum += curr->data;
      if (curr->left != NULL)
        q.push(curr->left);
      if (curr->right != NULL)
        q.push(curr->right);
    }
    ans.push_back(sum / size);
  }
  return ans;
}

int main()
{
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);
  vector<double> answer = averageOfLevels(root);
  for (auto it : answer)
  {
    cout << it << " ";
  }
  return 0;
}
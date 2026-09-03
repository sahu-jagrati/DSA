// Given the root of a binary tree, return the sum of all left leaves.

// A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: 24
// Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
// Example 2:

// Input: root = [1]
// Output: 0

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// -1000 <= Node.val <= 1000

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

// t.c-O(n)(because we visit each node only once)
// s.c-O(n) in the worst case for queue
int sumOfLeaves(TreeNode *root)
{
  // edge case
  if (root == NULL)
    return 0;
  // when we have only root, neither left child nor right child then there is no left leaf so return 0
  if (root->left == NULL && root->right == NULL)
    return 0;
  int sum = 0;

  // here we do BFS
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty())
  {
    TreeNode *curr = q.front();
    q.pop();
    // here we check for current node if there is left and for that left node there is no left node and no right node means it is left leaf node so we add it value to sum and no need to push it in queue, if for current node left there is left or either right then we have push it in queue and it is not leaf node
    if (curr->left != NULL)
    {
      if (curr->left->left == NULL && curr->left->right == NULL)
        sum += curr->left->data;
      else
        q.push(curr->left);
    }
    // for right node simply push it in queue
    if (curr->right != NULL)
      q.push(curr->right);
  }
  return sum;
}

// similarly we can use DFS only we have to use stack instead of queue, remaining code is same

// t.c-O(n)(because we visit each node only once)
// s.c-O(n)(stack space) in the worst case when tree is skewed   and in average case O(height of tree)
int sumofLeaves(TreeNode *root)
{
  // edge case
  if (root == NULL)
    return 0;
  // when we have only root, neither left child nor right child then there is no left leaf so return 0
  if (root->left == NULL && root->right == NULL)
    return 0;
  int sum = 0;

  // here we do BFS
  stack<TreeNode *> st;
  st.push(root);
  while (!st.empty())
  {
    TreeNode *curr = st.top();
    st.pop();
    // here we check for current node if there is left and for that left node there is no left node and no right node means it is left leaf node so we add it value to sum and no need to push it in stack , if for current node left there is left or either right then we have push it in stack and it is not leaf node
    if (curr->left != NULL)
    {
      if (curr->left->left == NULL && curr->left->right == NULL)
        sum += curr->left->data;
      else
        st.push(curr->left);
    }
    // for right node simply push it in stack
    if (curr->right != NULL)
      st.push(curr->right);
  }
  return sum;
}

// for this problem, both DFS and bFS are equally correct
int main()
{
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);
  cout << sumOfLeaves(root);
  return 0;
}
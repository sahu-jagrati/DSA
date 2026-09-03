// Given two binary trees original and cloned and given a reference to a node target in the original tree.

// The cloned tree is a copy of the original tree.

// Return a reference to the same node in the cloned tree.

// Note that you are not allowed to change any of the two trees or the target node and the answer must be a reference to a node in the cloned tree.

// Example 1:

// Input: tree = [7,4,3,null,null,6,19], target = 3
// Output: 3
// Explanation: In all examples the original and cloned trees are shown. The target node is a green node from the original tree. The answer is the yellow node from the cloned tree.
// Example 2:

// Input: tree = [7], target =  7
// Output: 7
// Example 3:

// Input: tree = [8,null,6,null,5,null,4,null,3,null,2,null,1], target = 4
// Output: 4

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// The values of the nodes of the tree are unique.
// target node is a node from the original tree and is not null.

// Follow up: Could you solve the problem if repeated values on the tree are allowed?

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

// in this problem we have to find the address of the node in cloned tree that have same value as a target value in the original tree
// so we used DFS
TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
{
  if (target->data == cloned->data)
    return cloned;
  TreeNode *ans;
  stack<TreeNode *> st;
  st.push(cloned);
  while (!st.empty())
  {
    TreeNode *curr = st.top();
    st.pop();
    if (curr->data == target->data)
    {
      ans = curr;
      break;
    }
    if (curr->left != NULL)
      st.push(curr->left);
    if (curr->right != NULL)
      st.push(curr->right);
  }
  return ans;
}

int main()
{
  TreeNode *original = new TreeNode(7);
  original->left = new TreeNode(4);
  original->right = new TreeNode(3);
  original->right->left = new TreeNode(6);
  original->right->right = new TreeNode(19);

  TreeNode *cloned = new TreeNode(7);
  cloned->left = new TreeNode(4);
  cloned->right = new TreeNode(3);
  cloned->right->left = new TreeNode(6);
  cloned->right->right = new TreeNode(19);

  TreeNode *target = original->right;
  cout << getTargetCopy(original, cloned, target);
  return 0;
}
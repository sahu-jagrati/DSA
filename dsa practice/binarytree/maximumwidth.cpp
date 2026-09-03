// width-number of nodes in a particular level between any two nodes
// we use modest version of left child and right child to minimize overflow
// Given the root of a binary tree, return the maximum width of the given tree.

// The maximum width of a tree is the maximum width among all levels.

// The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

// It is guaranteed that the answer will in the range of a 32-bit signed integer
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
  /* data */
  int data;
  TreeNode *left, *right;
  TreeNode(int value)
  {
    data = value;
    left = right = NULL;
  }
};

// t.c=O(N) level order traversal
// s.c=O(N) queue
int maximumWidthofBinaryTree(TreeNode *root)
{
  if (!root)
    return 0;
  queue<pair<TreeNode *, int>> q;
  q.push({root, 0});
  int ans = 0;
  while (!q.empty())
  {
    int size = q.size();
    int mini = q.front().second; // to make the index starting from zero, because of minimize the overflow
    int first, last;
    for (int i = 0; i < size; i++)
    {
      int curr_id = q.front().second - mini;
      TreeNode *node = q.front().first;
      q.pop();
      if (i == 0)
        first = curr_id;
      if (i == size - 1)
        last = curr_id;
      if (node->left)
        q.push({node->left, curr_id * 2 + 1});
      if (node->right)
        q.push({node->right, curr_id * 2 + 2});
    }
    ans = max(ans, last - first + 1);
  }
  return ans;
}

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(3);
  root->right = new TreeNode(7);
  root->left->left = new TreeNode(8);
  root->right->right = new TreeNode(4);

  int result = maximumWidthofBinaryTree(root);
  cout << result << endl;

  return 0;
}

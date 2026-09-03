// we have two solution-1.recursive 2.level order
// recursive, worst case is when tree is skewed - we have to travel all nodes-O(height)
// level order, worst case when tree is full binary tree-O(N)

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
  int data;
  TreeNode *left, *right;
  TreeNode(int value)
  {
    data = value;
    left = right = NULL;
  }
  /* data */
};

// time complexity-O(N) // in this we also travel all node
// space complexity-O(N) auxilliary space // in worst case when we have skewed tree
// best case-O(logN) balanced binary tree
int maxDepth(TreeNode *root)
{
  if (root == NULL)
    return 0;
  int lh = maxDepth(root->left);
  int rh = maxDepth(root->right);

  return (1 + max(lh, rh)); // this is the formula for height
}

// time complexity-O(N) // in this we also travel all node
// space complexity-O(N) // auxilliary space
int levelOrderMaxDepth(TreeNode *root)
{
  if (root == NULL)
    return 0;
  int depth = 0;
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty())
  {
    int size = q.size();
    depth++;
    for (int i = 0; i < size; i++)
    {
      TreeNode *temp = q.front();
      q.pop();
      if (temp->left != NULL)
        q.push(temp->left);
      if (temp->right != NULL)
        q.push(temp->right);
    }
  }
  return depth;
}
int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(6);
  root->right->left->left = new TreeNode(5);

  // int height = maxDepth(root);
  int height = levelOrderMaxDepth(root);
  cout << height << endl;
  return 0;
}

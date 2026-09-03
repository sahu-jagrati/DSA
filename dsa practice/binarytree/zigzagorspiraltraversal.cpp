#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
  /* data */
  int data;
  TreeNode *left, *right;
  TreeNode()
  {
    data = 0;
    left = right = NULL;
  }
  TreeNode(int value)
  {
    data = value;
    left = right = NULL;
  }
  TreeNode(int value, TreeNode *left, TreeNode *right)
  {
    data = value;
    left = left;
    right = right;
  }
};

// time complexity-o(N)
// space complexity-O(N) auxiliary space
vector<vector<int>> zigzagLevelOrderTraversal(TreeNode *root)
{
  vector<vector<int>> result;
  if (root == NULL)
    return result;

  queue<TreeNode *> nodesQueue;
  nodesQueue.push(root);
  bool leftToRight = true;

  while (!nodesQueue.empty())
  {
    int size = nodesQueue.size();

    vector<int> row(size);
    for (int i = 0; i < size; i++)
    {
      TreeNode *node = nodesQueue.front();
      nodesQueue.pop();

      // find position to fill node's value
      int index = (leftToRight) ? i : (size - 1 - i);
      row[index] = node->data;
      if (node->left)
      {
        nodesQueue.push(node->left);
      }
      if (node->right)
      {
        nodesQueue.push(node->right);
      }
    }

    // after this level
    leftToRight = !leftToRight;
    result.push_back(row);
  }
  return result;
}
int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);

  vector<vector<int>> answer = zigzagLevelOrderTraversal(root);

  for (auto it1 : answer)
  {
    for (auto it2 : it1)
    {
      cout << it2 << " ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}

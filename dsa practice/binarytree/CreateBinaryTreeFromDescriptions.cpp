// You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

// If isLefti == 1, then childi is the left child of parenti.
// If isLefti == 0, then childi is the right child of parenti.
// Construct the binary tree described by descriptions and return its root.

// The test cases will be generated such that the binary tree is valid.

// Example 1:

// Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
// Output: [50,20,80,15,17,19]
// Explanation: The root node is the node with value 50 since it has no parent.
// The resulting binary tree is shown in the diagram.
// Example 2:

// Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
// Output: [1,2,null,null,3,4]
// Explanation: The root node is the node with value 1 since it has no parent.
// The resulting binary tree is shown in the diagram.

// Constraints:

// 1 <= descriptions.length <= 104
// descriptions[i].length == 3
// 1 <= parenti, childi <= 105
// 0 <= isLefti <= 1
// The binary tree described by descriptions is valid.

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
    left = nullptr;
    right = nullptr;
  }
};

// Key Observation

// In a binary tree:

// The root is the only node that is never a child.
// Every other node appears exactly once as a child.

// So:

// Store all parent values.
// Store all child values.
// The node that is a parent but not a child is the root.

// t.c-
// building tree:O(n)
// finding root:O(n)
// total-O(2n)=O(n)
// s.c-O(n)(for childNodes set for storing child)+O(number of nodes)(because we store each node in mpp)
TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
{
  // we used map for storing
  unordered_map<int, TreeNode *> nodes;
  // we use set to know root node so we insert only child in this
  unordered_set<int> childNodes;

  for (auto &d : descriptions)
  {
    int parent = d[0];
    int child = d[1];
    int isLeft = d[2];

    // if parent  not in map then create a new node for it
    if (!nodes.count(parent))
    {
      nodes[parent] = new TreeNode(parent); // we create parent node
    }
    // if child not in map then create a new node for it
    if (!nodes.count(child))
    {
      nodes[child] = new TreeNode(child);
    }
    // now assign child is left or right
    if (isLeft)
      nodes[parent]->left = nodes[child];
    else
      nodes[parent]->right = nodes[child];

    // insert child in set
    childNodes.insert(child);
  }

  // for getting root
  for (auto &d : descriptions)
  {
    // if parent=d[0] is not in childNodes set then it is root node so return it
    if (!childNodes.count(d[0]))
      return nodes[d[0]];
  }
  return nullptr;
}

void printpreOrderTree(TreeNode *root)
{
  if (root == NULL)
    return;
  cout << root->data << " ";
  printpreOrderTree(root->left);
  printpreOrderTree(root->right);
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> descriptions(n, vector<int>(3));
  for (int i = 0; i < n; i++)
  {
    cin >> descriptions[i][0] >> descriptions[i][1] >> descriptions[i][2];
  }
  TreeNode *root = createBinaryTree(descriptions);
  printpreOrderTree(root);
  return 0;
}
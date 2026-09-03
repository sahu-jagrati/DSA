// print all the nodes at a distance of K from target in binary tree
// in tree main concern is that we cannot travel from child to parent so for resolve this we track parent of each node
// in target we can have value of target if we have value then we can use any traversal(preorder/postorder/inorder)but when we get address of node then we use bfs traversal (level order algo)

// here we solve when we have address for value solution is in question minimum time taken to burn the binary tree from a node
#include <iostream>
#include <queue>
#include <unordered_map>
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
};

void markParent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track, TreeNode *target)
{
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty())
  {
    TreeNode *current = q.front();
    q.pop();
    if (current->left)
    {
      parent_track[current->left] = current;
      q.push(current->left);
    }
    if (current->right)
    {
      parent_track[current->right] = current;
      q.push(current->right);
    }
  }
}
// time complexity-O(N)(for markParent)+O(N)(in worst case when we travel entire tree)+O(logN)(for hashmap in cpp)
// space complexity-O(N)(for queue)+O(N)(for visited)+O(N)(for parent queue)=O(N)
vector<TreeNode *> distanceByK(TreeNode *root, TreeNode *target, int k)
{
  unordered_map<TreeNode *, TreeNode *> parent_track; // track parent of all the nodes
  markParent(root, parent_track, target);
  unordered_map<TreeNode *, bool> visited;
  queue<TreeNode *> q;
  q.push(target);
  visited[target] = true;
  int dis = 0;
  while (!q.empty())
  {
    int size = q.size();
    if (dis++ == k)
      break;
    for (int i = 0; i < size; i++)
    {
      TreeNode *current = q.front();
      q.pop();
      if (current->left && !visited[current->left])
      {
        q.push(current->left);
        visited[current->left] = true;
      }
      if (current->right && !visited[current->right])
      {
        q.push(current->right);
        visited[current->right] = true;
      }
      if (parent_track[current] && !visited[parent_track[current]])
      {
        q.push(parent_track[current]);
        visited[parent_track[current]] = true;
      }
    }
  }
  vector<TreeNode *> ans;
  while (!q.empty())
  {
    TreeNode *node = q.front();
    q.pop();
    ans.push_back(node);
  }
  return ans;
}
int main()
{
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);

  // TreeNode *target = new TreeNode(5); this creates a new node with value 5, which is not the same node inside the tree.
  TreeNode *target = root->left;
  int k; // distance
  cout << "Enter distance: ";
  cin >> k;
  vector<TreeNode *> result = distanceByK(root, target, k);
  for (auto it : result)
  {
    // cout << it << " ";  print the node address instead of value
    cout << it->data << " ";
  }
  cout << endl;
  return 0;
}

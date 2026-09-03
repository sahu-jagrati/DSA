// minimum time taken to burn the binary tree from any node
// same to question distance by k
// we use bfs traversal
// we can also use dfs cince it is a tree not graph (i.e acyclic) ans would be max of all depths from start node, simply max of distance you can go from start while maintaing visisted

#include <iostream>
#include <queue>
#include <unordered_map>
#include <map>
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

// this is when we have address of startnode
void markParent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> parent_track)
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
int minimumTimeToBurnTheBinaryTree(TreeNode *root, TreeNode *startNode)
{
  unordered_map<TreeNode *, TreeNode *> parent_track;
  markParent(root, parent_track);
  unordered_map<TreeNode *, bool> visited;
  queue<TreeNode *> q;
  q.push(startNode);
  visited[startNode] = true;
  int time = 0;
  while (!q.empty())
  {
    int size = q.size();
    int fl = 0; // fl=flag
    for (int i = 0; i < size; i++)
    {
      TreeNode *current = q.front();
      q.pop();
      if (current->left && !visited[current->left])
      {
        fl = 1;
        q.push(current->left);
        visited[current->left] = true;
      }
      if (current->right && !visited[current->right])
      {
        fl = 1;
        q.push(current->right);
        visited[current->right] = true;
      }
      if (parent_track[current] && !visited[parent_track[current]])
      {
        fl = 1;
        q.push(parent_track[current]);
        visited[parent_track[current]] = true;
      }
    }
    if (fl)
      time++;
  }
  return time;
}

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->left->right = new TreeNode(7);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(6);

  TreeNode *startNode = root->left;
  int result = minimumTimeToBurnTheBinaryTree(root, startNode);
  cout << "Minimum time to burn a binary tree from a node is: " << result << endl;

  return 0;
}

// another solution when we have value of startnode not address
// time complexity-O(N)(for markParent)+O(N)(in worst case when we travel entire tree)+O(1)(f we consider it for map )
// space complexity-O(N)(for queue)+O(N)(for visited)+O(N)(for parent queue)=O(N)
int findMaxDistance(map<TreeNode *, TreeNode *> &mpp, TreeNode *target)
{
  queue<TreeNode *> q;
  q.push(target);
  map<TreeNode *, bool> visited;
  visited[target] = true;
  int maxi = 0;
  while (!q.empty())
  {
    int size = q.size();
    int fl = 0;
    for (int i = 0; i < size; i++)
    {
      TreeNode *current = q.front();
      q.pop();
      if (current->left && !visited[current->left])
      {
        fl = 1;
        q.push(current->left);
        visited[current->left] = true;
      }
      if (current->right && !visited[current->right])
      {
        fl = 1;
        q.push(current->right);
        visited[current->right] = true;
      }
      if (mpp[current] && !visited[mpp[current]])
      {
        fl = 1;
        q.push(mpp[current]);
        visited[mpp[current]] = true;
      }
    }
    if (fl)
      maxi++;
  }
  return maxi;
}
TreeNode *bfsToMapParent(TreeNode *root, map<TreeNode *, TreeNode *> &mpp, int start)
{
  queue<TreeNode *> q;
  q.push(root);
  TreeNode *StartNode;
  while (!q.empty())
  {
    TreeNode *current = q.front();
    q.pop();
    if (current->data == start)
      StartNode = current;
    if (current->left)
    {
      q.push(current->left);
      mpp[current->left] = current;
    }
    if (current->right)
    {
      q.push(current->right);
      mpp[current->right] = current;
    }
  }
  return StartNode;
}

// another solution
int timeToBurnTree(TreeNode *root, int start)
{ // here in start we have integer value not the address so
  map<TreeNode *, TreeNode *> mpp;
  TreeNode *target = bfsToMapParent(root, mpp, start); // it first track the parent of all the node and second it return the address where the start lie in the binary tree
  int maxi = findMaxDistance(mpp, target);
  return maxi;
}
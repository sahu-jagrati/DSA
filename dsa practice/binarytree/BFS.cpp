// breadth first search-level by level

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node
{
  int data;
  Node *left, *right;
  Node()
  {
    data = 0;
    left = right = NULL;
  }
  Node(int value)
  {
    data = value;
    left = right = NULL;
  }
  Node(int value, Node *left, Node *right)
  {
    data = value;
    left = left;
    right = right;
  }
};

// chatgpt code
// time complexity-O(N) every node is visited once
// space cmplexity-
// the queue stores at most all nodes of the last level in the worst case
// in worst case(skewed tree)-queue size=O(N)
// balanced binary tree-queue size=approxO(N/2)=O(N)

void levelOrder(Node *root)
{
  if (root == NULL)
    return;
  queue<Node *> q;
  q.push(root);
  while (!q.empty())
  {
    Node *curr = q.front();
    q.pop();
    cout << curr->data << " ";
    if (curr->left != NULL)
      q.push(curr->left);
    if (curr->right != NULL)
      q.push(curr->right);
  }
}

// striver code
// time complexity-O(N) every node is visited once
// space cmplexity-O(N) in worst case(skewed tree)so, queue have to store all one by one and ans is used only for returning the answer, not for solving the problem

vector<vector<int>> LevelOrder(Node *root)
{
  vector<vector<int>> ans;
  if (root == NULL)
    return ans;
  queue<Node *> q;
  q.push(root);
  while (!q.empty())
  {
    int size = q.size();
    vector<int> level;
    for (int i = 0; i < size; i++)
    {
      Node *curr = q.front();
      q.pop();
      if (curr->left != NULL)
        q.push(curr->left);
      if (curr->right != NULL)
        q.push(curr->right);
      level.push_back(curr->data);
    }
    ans.push_back(level);
  }
  return ans;
}
int main()
{
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  cout << "Level order traversal: ";
  levelOrder(root);
  cout << endl;

  cout << "Level order traversal: ";
  vector<vector<int>> result = LevelOrder(root);
  for (const auto it : result)
  {
    for (auto it1 : it)
    {
      cout << it1 << " ";
    }
  }
  cout << endl;
  return 0;
}
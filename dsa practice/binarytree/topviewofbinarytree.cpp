// we start from left to right
//  if we draw vertical line then we can say that the first node on every line is my top view
//  here we use level order traversal
// can we use recursive order traversal-no,because like if we use inorder traversal, we visit some nodes which are not the first node at that vertical line that's why we don't use recursive traversal directly. You have to know about another logic based on height i.e the node with least height on that line.
//  so we don't prefer recursive traversal and doesn't want to implement extra logic

#include <iostream>
#include <vector>
#include <map> // we don't use unordered map because it doesn't store in sorting order
#include <queue>
using namespace std;

struct Node
{
  int data;
  Node *left, *right;
  Node(int val)
  {
    data = val;
    left = right = NULL;
  }
};
vector<int> topView(Node *root)
{
  vector<int> ans;
  if (root == NULL)
    return ans;
  map<int, int> mpp;          // store in (line,node) sorting order of line
  queue<pair<Node *, int>> q; // store in(Node,line)
  q.push({root, 0});          // initially store root node and its line
  while (!q.empty())
  {
    auto it = q.front();
    q.pop();
    Node *node = it.first;
    int line = it.second;
    if (mpp.find(line) == mpp.end())
    { // means it is the first node in that line we visit
      mpp[line] = node->data;
    }
    if (node->left != NULL)
    {
      q.push({node->left, line - 1});
    }
    if (node->right != NULL)
    {
      q.push({node->right, line + 1});
    }
  }
  for (auto it : mpp)
  {
    ans.push_back(it.second);
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
  root->left->right->left = new Node(6);
  root->right->right = new Node(7);

  vector<int> result = topView(root);
  for (auto it : result)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}
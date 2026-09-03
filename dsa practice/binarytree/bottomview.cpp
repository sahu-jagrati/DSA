// we start from left to right
//  if we draw vertical line then we can say that the last node on every line is my bottom view
//  here we use level order traversal
// can we use recursive order traversal-no,because like if we use inorder traversal, we visit some nodes which are not the last node at that vertical line that's why we don't use recursive traversal directly. You have to know about another logic based on height i.e the node with most height on that line.
//  so we don't prefer recursive traversal and doesn't want to implement extra logic

#include <iostream>
#include <vector>
#include <map>
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

vector<int> bottomView(Node *root)
{
  vector<int> ans;
  if (root == NULL)
    return ans;
  map<int, int> mpp;
  queue<pair<Node *, int>> q;
  q.push({root, 0});
  while (!q.empty())
  {
    auto it = q.front();
    q.pop();
    Node *node = it.first;
    int line = it.second;
    mpp[line] = node->data;
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
  root->left->right->left = new Node(8);
  root->left->right->right = new Node(9);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  vector<int> result = bottomView(root);
  for (auto it : result)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}
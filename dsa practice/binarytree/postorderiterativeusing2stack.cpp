#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node
{
  int data;
  Node *left, *right;
  Node(int value)
  {
    data = value;
    left = right = NULL;
  }
};

// time complexity-O(N)
//  space complexity-O(2N)in worst case O(h)=O(2N) when tree is skewed
// in best case balanced tree-O(logN)
// for two auxiliary stack
//  if u think about ans it is just storing the answer not solving the problem
vector<int> postOrderIterative(Node *root)
{
  vector<int> ans;
  if (root == NULL)
    return ans;
  stack<Node *> st1, st2;
  st1.push(root);
  while (!st1.empty())
  {
    root = st1.top();
    st1.pop();
    st2.push(root);
    if (root->left != NULL)
    {
      st1.push(root->left);
    }
    if (root->right != NULL)
    {
      st1.push(root->right);
    }
  }
  while (!st2.empty())
  {
    ans.push_back(st2.top()->data);
    st2.pop();
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
  root->left->right->right = new Node(7);
  vector<int> result = postOrderIterative(root);
  for (auto it : result)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}
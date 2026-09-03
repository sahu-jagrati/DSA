// Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

// Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

#include <bits/stdc++.h>
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

// t.c-O(no.of nodes in BT)
// s.c-O(1)
int maximumLevelSum(Node *root)
{

  int ans = 0;
  int maxi = INT_MIN;
  queue<Node *> q;
  q.push(root);
  int level = 1;
  while (!q.empty())
  {
    int size = q.size();
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
      Node *node = q.front();
      q.pop();
      sum = sum + node->data;
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }
    if (sum > maxi)
    {
      maxi = sum;
      ans = level;
    }
    level++;
  }
  return ans;
}

int main()
{
  Node *root = new Node(1);
  root->left = new Node(7);
  root->right = new Node(0);
  root->left->left = new Node(7);
  root->left->right = new Node(-8);

  int result = maximumLevelSum(root);
  cout << "Maximum level sum is: " << result << endl;

  return 0;
}
// You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.

// Example 1:

// Input: root = [1,2,3,4,5,6,7]
// Output: [1,#,2,3,#,4,5,6,7,#]
// Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
// Example 2:

// Input: root = []
// Output: []

// Constraints:

// The number of nodes in the tree is in the range [0, 212 - 1].
// -1000 <= Node.val <= 1000

// Follow-up:

// You may only use constant extra space.
// The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;
  Node *next;
  Node(int val)
  {
    data = val;
    left = NULL;
    right = NULL;
    next = NULL;
  }
};

// this is fully correct and done by me own fully
Node *connect(Node *root)
{
  if (root == NULL)
    return root;
  queue<Node *> q;
  q.push(root);
  while (!q.empty())
  {
    int size = q.size();
    for (int i = 0; i < size; i++)
    {
      Node *node = q.front();
      q.pop();
      // there is no need to check q.empty() because we go level order so for last node we have NULL only in that level otherwise we go A.T size of that level so next is q.front()
      // if (!q.empty())
      // {
      //   if (i == size - 1)
      //     node->next = NULL;
      //   else
      //     node->next = q.front();
      // }
      // else if (q.empty())
      //   node->next = NULL;
      if (i == size - 1)
        node->next = NULL;
      else
        node->next = q.front();
      if (node->left != NULL)
        q.push(node->left);
      if (node->right != NULL)
        q.push(node->right);
    }
  }
  return root;
}

// -1 represents NULL
Node *buildTree(vector<int> &arr)
{
  if (arr.empty() || arr[0] == -1)
    return nullptr;
  Node *root = new Node(arr[0]);
  queue<Node *> q;
  q.push(root);
  int i = 1;
  while (!q.empty() && i < arr.size())
  {
    Node *curr = q.front();
    q.pop();
    // left child
    if (i < arr.size() && arr[i] != -1)
    {
      curr->left = new Node(arr[i]);
      q.push(curr->left);
    }
    i++;
    // right child
    if (i < arr.size() && arr[i] != -1)
    {
      curr->right = new Node(arr[i]);
      q.push(curr->right);
    }
    i++;
  }
  return root;
}

// print every node along with its next
// level order
void printNextPointers(Node *root)
{
  if (root == NULL)
    return;
  queue<Node *> q;
  q.push(root);
  while (!q.empty())
  {
    int size = q.size();
    while (size--)
    {
      Node *node = q.front();
      q.pop();

      cout << node->data << " ";
      if (node->next)
        cout << node->next->data;
      else
        cout << "NULL" << " ";
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }
  }
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  Node *root = buildTree(arr);
  Node *ans = connect(root);
  printNextPointers(ans);
  return 0;
}

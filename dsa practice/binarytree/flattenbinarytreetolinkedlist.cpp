// flatten binary tree to linked list means like preorder that is left points to null and we have all nodes in right for more details go notes
// we don't have to create a new linked list or new data structure you only have to reaarange the binary tree
// we have 3 approach-
// 1. recursion, 2. iteration and 3. something like morrris traversal

#include <bits/stdc++.h>
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

// 1st approach- we have traverse like right left root in recursion
// t.c-O(N)
// s.c-O(N)
void flatten(TreeNode *node, TreeNode *&prev)
{
  if (!node)
    return;
  flatten(node->right, prev);
  flatten(node->left, prev);
  node->right = prev;
  node->left = NULL;
  prev = node;
}

// 2nd approach-iteration- we don't need to tell this in interview
// t.c-O(N)
// s.c-O(N)
void Flatten(TreeNode *root)
{
  stack<TreeNode *> st;
  st.push(root);
  while (!st.empty())
  {
    TreeNode *curr = st.top();
    st.pop();
    if (curr->right)
    {
      st.push(curr->right);
    }
    if (curr->left)
    {
      st.push(curr->left);
    }
    if (!st.empty())
    {
      curr->right = st.top();
    }
    curr->left = NULL;
  }
}

// 3rd approach- something like morris traversal
// t.c-O(N)
// s.c-O(1)
void flattenIII(TreeNode *root)
{
  TreeNode *curr = root;
  while (curr != NULL)
  {
    if (curr->left != NULL)
    {
      TreeNode *prev = curr->left;
      while (prev->right)
      { // same by this we go rightmost guy of left part
        prev = prev->right;
      }
      prev->right = curr->right;
      curr->right = curr->left;
      curr->left = NULL;
    }
    curr = curr->right;
  }
}
void printpreOrder(TreeNode *root)
{
  if (root == NULL)
    return;
  cout << root->data << " ";
  printpreOrder(root->left);
  printpreOrder(root->right);
}
int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(6);
  root->right->right->left = new TreeNode(7);

  TreeNode *prev = NULL;

  // run by one each

  // flatten(root, prev);
  // printpreOrder(root);
  // Flatten(root);
  // printpreOrder(root);
  flattenIII(root);
  printpreOrder(root);

  return 0;
}
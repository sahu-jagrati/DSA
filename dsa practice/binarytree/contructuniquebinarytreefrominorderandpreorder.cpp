// by having preorder and postorder- we cannot construct a unique binary tree, it give differnent tree for same preorder and postorder
// by having inorder and preorder- we can construct unique binary tree
// also by having inorder and postorder- we can construct unique binary tree
// in preorder-first element will always be a root of entire binary tree

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
TreeNode *BuildTree(vector<int> &preOrder, int prestart, int preEnd, vector<int> &inOrder, int instart, int inEnd, map<int, int> &inmap)
{
  if (prestart > preEnd || instart > inEnd)
    return NULL;

  TreeNode *root = new TreeNode(preOrder[prestart]);
  int inRoot = inmap[root->data];
  int numsLeft = inRoot - instart;

  root->left = BuildTree(preOrder, prestart + 1, prestart + numsLeft, inOrder, instart, inRoot - 1, inmap);
  root->right = BuildTree(preOrder, prestart + numsLeft + 1, preEnd, inOrder, inRoot + 1, inEnd, inmap);

  return root;
}

// time complexity--
// int inRoot-inmap[postorder[postend]] takes O(logN) and you perform this N times(once per node)
// t.c=O(NlogN)
// if using map<int,int>-t.c=O(NlogN) or if using unordered_map<int,int>-t.c=O(n) because that takes O(1) and perform n times so
// s.c=O(N)(for hashmap)+O(N)(for stack space)
TreeNode *buildTree(vector<int> &preOrder, vector<int> &inOrder)
{
  if (inOrder.size() != preOrder.size())
    return NULL;
  map<int, int> inmap;
  for (int i = 0; i < inOrder.size(); i++)
  {
    inmap[inOrder[i]] = i;
  }
  TreeNode *root = BuildTree(preOrder, 0, preOrder.size() - 1, inOrder, 0, inOrder.size() - 1, inmap);

  return root;
}
void printInorder(TreeNode *root)
{
  if (root == NULL)
    return;
  printInorder(root->left);
  cout << root->data << " ";
  printInorder(root->right);
}
int main()
{
  int n;
  cout << "Enter the number of nodes: ";
  cin >> n;
  vector<int> inOrder(n);
  vector<int> preOrder(n);
  cout << "Enter nodes for inorder: \n";
  for (int i = 0; i < n; i++)
  {
    cin >> inOrder[i];
  }
  cout << "\n Enter nodes for preorder: \n";
  for (int i = 0; i < n; i++)
  {
    cin >> preOrder[i];
  }
  TreeNode *node = buildTree(preOrder, inOrder);
  printInorder(node);

  return 0;
}
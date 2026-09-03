// similar approach as we used in inorder and preorder only here last element will always be a root of entire binary tree

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

TreeNode *BuildTree(vector<int> &postOrder, int postStart, int postEnd, vector<int> &inOrder, int inStart, int inEnd, map<int, int> &inmap)
{
  if (postStart > postEnd || inStart > inEnd)
    return NULL;

  TreeNode *root = new TreeNode(postOrder[postEnd]);
  int inRoot = inmap[postOrder[postEnd]];
  int numsLeft = inRoot - inStart;

  root->left = BuildTree(postOrder, postStart, postStart + numsLeft - 1, inOrder, inStart, inRoot - 1, inmap);
  root->right = BuildTree(postOrder, postStart + numsLeft, postEnd - 1, inOrder, inRoot + 1, inEnd, inmap);

  return root;
}

// time complexity--
// int inRoot-inmap[postorder[postend]] takes O(logN) and you perform this N times(once per node)
// t.c=O(NlogN)
// if using map<int,int>-t.c=O(NlogN) or if using unordered_map<int,int>-t.c=O(n) because that takes O(1) andperform n times so
// space complexity-O(N)(for hashmap)+O(N)(for stack space)

TreeNode *buildTree(vector<int> &postOrder, vector<int> &inOrder)
{
  if (inOrder.size() != postOrder.size())
    return NULL;

  map<int, int> inmap;
  for (int i = 0; i < inOrder.size(); i++)
  {
    inmap[inOrder[i]] = i;
  }
  TreeNode *node = BuildTree(postOrder, 0, postOrder.size() - 1, inOrder, 0, inOrder.size() - 1, inmap);
  return node;
}
void printPostOrder(TreeNode *root)
{
  if (root == NULL)
    return;
  printPostOrder(root->left);
  printPostOrder(root->right);
  cout << root->data << " ";
}
int main()
{
  int n;
  cout << "Enter the number of nodes: ";
  cin >> n;
  vector<int> inOrder(n);
  vector<int> postOrder(n);
  cout << "Enter nodes for inorder: \n";
  for (int i = 0; i < n; i++)
  {
    cin >> inOrder[i];
  }
  cout << "\n Enter nodes for postOrder: \n";
  for (int i = 0; i < n; i++)
  {
    cin >> postOrder[i];
  }
  TreeNode *node = buildTree(postOrder, inOrder);
  printPostOrder(node);

  return 0;
}
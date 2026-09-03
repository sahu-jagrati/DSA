// we have to construct bST from a preorder traversal
// we have 3 approach-
// 1st naive solution- we konw in preoreder array first elt is always a main root of tree and by property of BST we can separate elt then
// t.c-O(N*N)in worst case N for travel each node and second N for to determine left and right for each node
// s.c-O(1) only tree space we have

// 2nd solution- we know inorder of BST is always sorted, so sort preorder array and get inorder
// now, we have preorder array and inorder array, so we can construct unique BST we do this in previous question
// t.c-O(NlogN)(for sorting)+O(N)(construct tree)
// s.c-O(N)(storing inorder)

// 3rd solution- we know in BST we have range for each node but can we required lower and upper bound both- no, we can do by one also
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

// t.c-O(3N) because we travel each node three times = O(N)
// s.c-O(1) if we don't mention auxiliary stack space (i.e recursion space)
TreeNode *build(vector<int> &preorder, int &i, int bound)
{
  if (i == preorder.size() || preorder[i] > bound)
    return NULL;
  TreeNode *root = new TreeNode(preorder[i++]);

  root->left = build(preorder, i, root->data);
  root->right = build(preorder, i, bound);

  return root;
}
TreeNode *bstFromPreorder(vector<int> &preorder)
{
  int i = 0;
  return build(preorder, i, INT_MAX);
}
void printInOrder(TreeNode *root)
{
  if (root == NULL)
    return;
  printInOrder(root->left);
  cout << root->data << " ";
  printInOrder(root->right);
}
int main()
{
  int N;
  cout << "Enter the size of array: ";
  cin >> N;
  vector<int> preorder(N);
  cout << "Enter the values of preorder array: ";
  for (int i = 0; i < N; i++)
  {
    cin >> preorder[i];
  }
  TreeNode *result = bstFromPreorder(preorder);
  printInOrder(result);

  return 0;
}
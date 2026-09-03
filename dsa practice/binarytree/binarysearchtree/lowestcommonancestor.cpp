// probability of nodes can lie -
// i) both can be lie left side
// ii) both can be lie right side
// iii) one can be lie left and other can be right
// iv) also one can be a root itself i.e lca itself

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  /* data */
  int data;
  TreeNode *left, *right;
  TreeNode(int value)
  {
    data = value;
    left = right = NULL;
  }
};

// t.c-O(height of tree)
// s.c-
// in best case when tree is balanced BST-O(logN)(base 2)height of tree
// in worst case when tree is skewed BST -O(N)
TreeNode *lowestCommonAncestor(TreeNode *root, int p, int q)
{
  if (root == NULL)
    return NULL;
  int curr = root->data;
  if (curr < p && curr < q)
  {
    return lowestCommonAncestor(root->right, p, q);
  }
  if (curr > p && curr > q)
  {
    return lowestCommonAncestor(root->left, p, q);
  }
  return root;
}

int main()
{
  TreeNode *root = new TreeNode(6);
  root->left = new TreeNode(2);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(4);
  root->left->right->left = new TreeNode(3);
  root->left->right->right = new TreeNode(5);
  root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(9);

  int p, q;
  cout << "Enter values of p and q: ";
  cin >> p >> q;

  TreeNode *result = lowestCommonAncestor(root, p, q);
  cout << result->data << endl;

  return 0;
}

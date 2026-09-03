// node itself an ancestor also
// lowest common ancestor is the ancestor that exist at the deepest level
// lca(a,b)=? where a and b are two nodes in the tree

// brute force solution is by finding root to node path for both nodes like we have to find lca(4,7) so we find path of 4 to root for this t.c=O(N) and s.c=O(N) and also path of 7 to root for this t.c=O(N) and s.c=O(N)  and match element so, th last element that match is the answer
// but in this we use extra space complexity O(N) in order to store both the paths, there is an extra use of time complexity

// we do optimize-recursive traversal-DFS

#include <iostream>
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
// t.c-O(N)
// s.c-
// in best case when tree is balanced -O(logN)(base 2)height of tree
// in worst case when tree is skewed  -O(N)
Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
  if (root == NULL || root == p || root == q)
  {
    return root;
  }
  Node *left = lowestCommonAncestor(root->left, p, q);
  Node *right = lowestCommonAncestor(root->right, p, q);

  if (left == NULL)
  {
    return right;
  }
  else if (right == NULL)
  {
    return left;
  }
  else
  { // both left and right are not null,we found our result
    return root;
  }
}

// if u don't want to write this then in lowestCommonAncestor function takes 'int' type value for p and q instead of 'Node' type
Node *findNode(Node *root, int val)
{
  if (root == nullptr)
    return nullptr;
  if (root->data == val)
    return root;
  Node *left = findNode(root->left, val);
  if (left != nullptr)
    return left;
  return findNode(root->right, val);
}

int main()
{
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->right->left = new Node(8);
  root->right->right = new Node(9);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->left->right->left = new Node(6);
  root->left->right->right = new Node(7);

  Node *p = findNode(root, 4);
  Node *q = findNode(root, 7);

  Node *result = lowestCommonAncestor(root, p, q);
  cout << result->data << endl;
  return 0;
}
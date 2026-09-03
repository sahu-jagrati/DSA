// you can do with any traversal like pre/in/post/level order traversal
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

// time complexity-o(N)
// space complexity-O(N) auxilliary stack space
bool isSameTree(Node *p, Node *q)
{
  if (p == NULL || q == NULL)
    return (p == q);

  return ((p->data == q->data) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right)); // we use preorder traversal-root left right
}

int main()
{
  Node *p = new Node(1);
  p->left = new Node(2);
  p->right = new Node(3);
  p->right->left = new Node(4);
  p->right->right = new Node(5);

  Node *q = new Node(1);
  q->left = new Node(2);
  q->right = new Node(3);
  q->right->left = new Node(4);
  q->right->right = new Node(5);

  bool result = isSameTree(p, q);
  cout << result << endl;

  return 0;
}
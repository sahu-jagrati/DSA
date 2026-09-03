// initially store root node
// 1. first we start with left boundary excluding leaf nodes means - left-left-left if there will not exists left then we will go right and excluding leaf nodes
// 2. second leaf traversal - done by any normal traversal(pre/in/post) because we are printing left subtree first befor right subtree
// 3. third right boundary in the reverse direction excluding leaf nodes means- right-right-right if there will not exists right then we will go for light and excluding leaf nodes

// similar you can do for clockwise
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
  /* data */
  int data;
  Node *left, *right;
  Node()
  {
    data = 0;
    left = right = NULL;
  }
  Node(int value)
  {
    data = value;
    left = NULL;
    right = NULL;
  }
  Node(int value, Node *left, Node *right)
  {
    data = value;
    left = left;
    right = right;
  }
};

bool isLeaf(Node *node)
{
  return node != nullptr && node->left == nullptr && node->right == nullptr;
}

void addLeftBoundary(Node *root, vector<int> &res)
{
  Node *cur = root->left;
  while (cur)
  {
    if (!isLeaf(cur))
      res.push_back(cur->data);
    if (cur->left)
      cur = cur->left;
    else
      cur = cur->right;
  }
}

void addRightBoundary(Node *root, vector<int> &res)
{
  Node *cur = root->right;
  vector<int> temp;
  while (cur)
  {
    if (!isLeaf(cur))
      temp.push_back(cur->data);
    if (cur->right)
      cur = cur->right;
    else
      cur = cur->left;
  }

  // for reverse
  for (int i = temp.size() - 1; i >= 0; i--)
  {
    res.push_back(temp[i]);
  }
}

void addLeaves(Node *root, vector<int> &res)
{
  if (isLeaf(root))
  {
    res.push_back(root->data);
    return;
  }
  if (root->left)
    addLeaves(root->left, res);
  if (root->right)
    addLeaves(root->right, res);
}

// time complexity-O(H)(for left boundary)+O(H)(for right boundary)+O(N)(for normal traversal)=approx.O(N)
// space complexity-O(N) auxiliary space, we do not consider temp space because it is temporary
vector<int> printBoundaryTraversal(Node *root)
{
  vector<int> res;
  if (root == NULL)
    return res;
  // initially take root node
  if (!isLeaf(root))
    res.push_back(root->data);
  addLeftBoundary(root, res);
  ;
  addLeaves(root, res);
  addRightBoundary(root, res);

  return res;
}

int main()
{
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(7);
  root->left->left = new Node(3);
  root->left->left->right = new Node(4);
  root->left->left->right->left = new Node(5);
  root->left->left->right->right = new Node(6);
  root->right->right = new Node(8);
  root->right->right->left = new Node(9);
  root->right->right->left->left = new Node(10);
  root->right->right->left->right = new Node(11);

  vector<int> result = printBoundaryTraversal(root);
  for (auto it : result)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}

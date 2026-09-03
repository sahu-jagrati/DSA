// root to node path

// if we have parent node then it is easy because we go to parent to parent and get path but we don't have parent node
//  so we use inorder traversal, we can also use pre/post order traversal but they are few complicated
//  generally we try to use simple traversal so we get simple code and solution and can easily understand in the interview
//  we take datastructure - we always add node in ds but if not find then we remove and return false else we return directly because there is no need to go left- right and return true
//  we go left and return false if not find
//  then we go right and return false if not find
//  for clear description see in notes

// question mention that there is node always, if you just want to check exist or not then call only getPath function

#include <iostream>
#include <vector>
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

bool getPath(Node *root, vector<int> &arr, int x)
{
  if (root == NULL)
    return false;
  arr.push_back(root->data); // always
  if (root->data == x)
    return true; // when we get this we directly return no further go left-right
  if (getPath(root->left, arr, x) || getPath(root->right, arr, x))
  { // from here to last line of this function happen when root->data !=x
    return true;
  }
  arr.pop_back();
  return false;
}

// t.c=O(N)
// s.c=O(h) where h=height of binary tree
//  as we use inorder so we have recursive stack space
vector<int> path(Node *root, int b)
{ // b can be node value or node address
  vector<int> arr;
  if (root == NULL)
    return arr;
  getPath(root, arr, b);
  return arr;
}

int main()
{
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->left->right->left = new Node(6);
  root->left->right->right = new Node(7);

  int b; // node upto which we find path
  cin >> b;
  vector<int> result = path(root, b);
  for (auto it : result)
  {
    cout << it << " ";
  }
  return 0;
}
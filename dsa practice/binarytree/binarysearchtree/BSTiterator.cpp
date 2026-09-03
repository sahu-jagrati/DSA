// given BSTiteration(root)
// you have to find next and hasnext
// next signify next elt in inorder
// hasnext signify is there nextelt or not in inorder

// naive solution- stored inorder and use pointer
// t.c-O(1) here we no add inordere traversal, this is only for next and hasnext
// s.c-O(N) to store inorder

// efficient solution- we create constructor and we know inorder-left root right
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

class BSTIterator
{
private:
  stack<TreeNode *> myStack;
  void pushAll(TreeNode *node)
  {
    // for(; node!=NULL;myStack.push(node,node=node->left));  this is the short syntax of below code
    while (node != NULL)
    {
      myStack.push(node);
      node = node->left;
    }
  }

public:
  // constructor
  BSTIterator(TreeNode *root)
  {
    pushAll(root);
  }
  bool hasNext()
  {
    return !myStack.empty();
  }
  int next()
  {
    TreeNode *node = myStack.top();
    myStack.pop();
    pushAll(node->right);
    return node->data;
  }
};

// how to take tree as a input
TreeNode *buildTreeLevelOrder()
{
  int n;
  cout << "Enter number of nodes in level order: ";
  cin >> n;
  if (n == 0)
    return NULL;

  vector<int> arr(n);
  cout << "Enter level order values (use -1 for NULL): \n";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  if (arr[0] == -1)
    return NULL;
  TreeNode *root = new TreeNode(arr[0]);
  queue<TreeNode *> q;
  q.push(root);
  int i = 1;
  while (!q.empty() && i < n)
  {
    TreeNode *curr = q.front();
    q.pop();
    if (arr[i] != -1)
    {
      curr->left = new TreeNode(arr[i]);
      q.push(curr->left);
    }
    i++;
    if (i >= n)
      break;
    if (arr[i] != -1)
    {
      curr->right = new TreeNode(arr[i]);
      q.push(curr->right);
    }
    i++;
  }
  return root;
}
int main()
{
  TreeNode *root = buildTreeLevelOrder();
  cout << "BST Iterator Output: \n";
  BSTIterator it(root); // make object of class BSTIterator and call constructor
  while (it.hasNext())
  {
    cout << it.next() << " ";
  }
  cout << endl;
  return 0;
}

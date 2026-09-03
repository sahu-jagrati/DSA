// preorder iterative traversal using stack
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node
{
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
    left = right = NULL;
  }
  Node(int value, Node *left, Node *right)
  {
    data = value;
    left = left;
    right = right;
  }
};

// preorder-root left right
// time complexity-O(N)
// space complexity-o(N) which is approx O(h)(height of tree) in worst case when there is always right and left is increase their child in right see in notes
vector<int> preOrderIterative(Node *root)
{
  vector<int> ans;
  if (root == NULL)
    return ans;

  stack<Node *> st;
  st.push(root);
  while (!st.empty())
  {
    root = st.top();
    st.pop();
    ans.push_back(root->data);
    if (root->right != NULL) // we push right first instead of left because stack do LIFO operation
      st.push(root->right);
    if (root->left != NULL)
      st.push(root->left);
  }
  return ans;
}
int main()
{
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(7);
  root->left->left = new Node(3);
  root->left->right = new Node(4);
  root->left->right->left = new Node(5);
  root->left->right->right = new Node(6);

  vector<int> result = preOrderIterative(root);
  for (auto it : result)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}
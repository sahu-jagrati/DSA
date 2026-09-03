// inorder iterative traversal using stack

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node
{
  int data;
  Node *left, *right;
  Node(int value)
  {
    data = value;
    left = right = NULL;
  }
};

// time complexity-O(N)
// space complexity-O(h) where h is height of tree
// in worst case O(h)=O(N) when tree is skewed
// in best case balanced tree-O(logN)
// here we use auxiliary space stack
// auxiliary space means extra or temporary space an algorithm uses while execituing(for recursion,stack,variables,data structures,etc)
// S.C=auxiliary space + input space
vector<int> inOrderIterative(Node *root)
{
  vector<int> ans;
  stack<Node *> st;
  Node *node = root;
  while (true)
  {
    if (node != NULL)
    {
      st.push(node);
      node = node->left;
    }
    else
    {
      if (st.empty() == true)
        break;
      node = st.top();
      st.pop();
      ans.push_back(node->data);
      node = node->right;
    }
  }
  return ans;
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
  vector<int> result = inOrderIterative(root);
  for (auto it : result)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}
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

// time complexity-O(2N)-
// First while loop (while (curr != NULL || !st.empty())):
// Every node is pushed once and popped once → O(N) total.

// Inner while loop (while (!st.empty() && temp == st.top()->right)):
// Looks like it could add more, but across the entire traversal each node still only gets popped once → also O(N)
// total
// The inner while loop does not restart from scratch for every node.
// It just continues where the tree structure dictates, and across the whole traversal every node is popped once.
//  space complexity-O(N) in worst case O(h)=O(N) when tree is skewed
//  in best case balanced tree-O(logN)
// for auxiliary stack
//   if u think about ans it is just storing the answer not solving the problem
vector<int> postOrderIterative(Node *root)
{
  vector<int> ans;
  if (root == NULL)
    return ans;
  stack<Node *> st;
  Node *curr = root;
  while (curr != NULL || !st.empty())
  {
    if (curr != NULL)
    {
      st.push(curr);
      curr = curr->left;
    }
    else
    {
      Node *temp = st.top()->right;
      if (temp == NULL)
      {
        temp = st.top();
        st.pop();
        ans.push_back(temp->data);
        while (!st.empty() && temp == st.top()->right)
        {
          temp = st.top();
          st.pop();
          ans.push_back(temp->data);
        }
      }
      else
      {
        curr = temp;
      }
    }
  }
  return ans;
}
int main()
{
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(7);
  root->left->left = new Node(3);
  root->right->left = new Node(8);
  root->left->left->right = new Node(4);
  root->left->left->right->right = new Node(5);
  root->left->left->right->right->right = new Node(6);
  vector<int> result = postOrderIterative(root);
  for (auto it : result)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}
#include <iostream>
#include <vector>
#include <stack>
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

// time complexity-O(3*N) because for each node we have run 3 times
// space complexity-O(4*N)
void preInPostTraversal(TreeNode *root)
{
  stack<pair<TreeNode *, int>> st;
  st.push({root, 1});
  vector<int> pre, in, post;
  if (root == NULL)
    cout << "NULL";
  while (!st.empty())
  {
    auto it = st.top();
    st.pop();
    // part of pre
    // increment 1 to 2
    //  push the left side of the tree
    if (it.second == 1)
    {
      pre.push_back(it.first->data);
      it.second++;
      st.push(it);
      if (it.first->left != NULL)
      {
        st.push({it.first->left, 1});
      }
    }
    // this is part of in
    // increment 2 to 3
    // push right
    else if (it.second == 2)
    {
      in.push_back(it.first->data);
      it.second++;
      st.push(it);
      if (it.first->right != NULL)
      {
        st.push({it.first->right, 1});
      }
    }
    // don't push it back again means after post you don't push it back in stack
    else
    {
      post.push_back(it.first->data);
    }
  }
  cout << "\nPre order: " << endl;
  for (auto it : pre)
  {
    cout << it << " ";
  }
  cout << "\nIn order: " << endl;
  for (auto it : in)
  {
    cout << it << " ";
  }
  cout << "\nPost order: " << endl;
  for (auto it : post)
  {
    cout << it << " ";
  }
}

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  preInPostTraversal(root);
  return 0;
}
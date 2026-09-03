// we use morris traversal because in recursion traversal of inorder and preorder take t.c-O(N) and s.c- O(N) but morris traversal of inorder and preorder take t.c-O(N) and s.c O(1) which is suitable than recursuion

// in recursion we backtrack parent of child but in iteration there is no parent pointer, we have only left and right pointer

// in this approach is-
// 1st case is - if left=NULL then print root and go to right
// 2nd case is -  if left not NULL then befor going to left whichever is the rightmost guy on left subtree connect to current and after that current=current->left
// if there is no thread between rightmost guy of left and current then connect it and make current=current->left
// else if already thread exist between rightmost guy on left and current  then remove thread and make current=curremt->right

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

// t.c-
//  everytime we got o rightmost guy of left subtree-del(N)(i.e. amotized) outer while loop and
//  O(N) forinner while loop
//  t.c-O(N) approx
// s.c -O(1)
vector<int> getInorder(TreeNode *root)
{
  vector<int> inorder;
  TreeNode *curr = root;
  while (curr != NULL)
  {
    // 1st case -
    if (curr->left == NULL)
    {
      inorder.push_back(curr->data);
      curr = curr->right;
    }
    // 2nd case
    else
    {
      TreeNode *prev = curr->left;
      // by this we go to rightmost guy of left
      while (prev->right && prev->right != curr)
      {
        prev = prev->right;
      }
      // we get rightmost guy and connect it with curr
      if (prev->right == NULL)
      {
        prev->right = curr;
        curr = curr->left;
      }
      else
      {
        prev->right = NULL;
        inorder.push_back(curr->data);
        curr = curr->right;
      }
    }
  }
  return inorder;
}

// t.c-
//  everytime we got o rightmost guy of left subtree-del(N)(i.e. amotized) outer while loop and
//  O(N) forinner while loop
//  t.c-O(N) approx
// s.c -O(1)
vector<int> getPreorder(TreeNode *root)
{
  vector<int> preorder;
  TreeNode *curr = root;
  while (curr != NULL)
  {
    // 1st case -
    if (curr->left == NULL)
    {
      preorder.push_back(curr->data);
      curr = curr->right;
    }
    // 2nd case
    else
    {
      TreeNode *prev = curr->left;
      // by this we go to rightmost guy of left
      while (prev->right && prev->right != curr)
      {
        prev = prev->right;
      }
      // we get rightmost guy and connect it with curr
      if (prev->right == NULL)
      {
        prev->right = curr;
        preorder.push_back(curr->data);
        curr = curr->left;
      }
      else
      {
        prev->right = NULL;
        curr = curr->right;
      }
    }
  }
  return preorder;
}

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->right = new TreeNode(6);

  vector<int> result = getInorder(root);
  cout << "Inorder is: ";
  for (auto it : result)
  {
    cout << it << " ";
  }
  cout << endl;
  cout << "Preorder is: ";
  vector<int> answer = getPreorder(root);
  for (auto it : answer)
  {
    cout << it << " ";
  }
  cout << endl;

  return 0;
}

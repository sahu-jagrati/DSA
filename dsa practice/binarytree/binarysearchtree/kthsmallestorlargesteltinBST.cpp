// we have to find kth smallest or largest element in BST
// 1st approach- i) you can do any traversal like(in,pre,post,level)
// ii) stroe them in container like vector in cpp
// iii) sort them
// and get kth smallest elt and largest=(N-k)th smallest
// but this take t.c-O(N)(for traversal)+O(NlogN)(for sorting) and s.c-O(N)

// 2nd approach- Inorder of BST is always in sorted order so t.c-O(N) but still s.c-o(N) so for this we use cnt =0 and whenever we visit the node we cnt++ and when cnt==k return that node

// for inorder-if we use-
// i) recurstive or iterative-t.c=O(N) and s.c=O(N) for stack space
// ii) morris traversal-t.c=O(N) and s.c-O(1)

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

// t.c=O(N)
// s.c-O(1)
int kthSmallest(TreeNode *root, int k)
{
  vector<int> inorder;
  TreeNode *curr = root;
  int cnt = 0;
  int ans = -1;
  while (curr != NULL)
  {
    if (curr->left == NULL)
    {
      inorder.push_back(curr->data);
      cnt++;
      if (cnt == k)
      {
        ans = curr->data;
      }
      curr = curr->right;
    }
    else
    {
      TreeNode *prev = curr->left;
      while (prev->right && prev->right != curr)
      {
        prev = prev->right;
      }
      if (prev->right == NULL)
      {
        prev->right = curr;
        curr = curr->left;
      }
      else
      {
        prev->right = NULL;
        inorder.push_back(curr->data);
        cnt++;
        if (cnt == k)
        {
          ans = curr->data;
        }
        curr = curr->right;
      }
    }
  }
  return ans;
}

// there is no need to push elt in inorder
// t.c-O(N)
// s.c-O(1)
int kthLargest(TreeNode *root, int k, int N)
{

  TreeNode *curr = root;
  int target = N - k + 1;
  int cnt = 0;
  int ans = -1;
  while (curr != NULL)
  {
    if (curr->left == NULL)
    {

      cnt++;
      if (cnt == target)
      {
        ans = curr->data;
      }
      curr = curr->right;
    }
    else
    {
      TreeNode *prev = curr->left;
      while (prev->right && prev->right != curr)
      {
        prev = prev->right;
      }
      if (prev->right == NULL)
      {
        prev->right = curr;
        curr = curr->left;
      }
      else
      {
        prev->right = NULL;
        cnt++;
        if (cnt == target)
        {
          ans = curr->data;
        }
        curr = curr->right;
      }
    }
  }
  return ans;
}

int main()
{

  int N;
  cout << "Enter the number od nodes in Tree: ";
  cin >> N;
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(7);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(4);
  root->left->left->right = new TreeNode(2);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(8);

  int k;
  cout << "Enter the value of k: ";
  cin >> k;
  int result = kthSmallest(root, k);
  cout << "kth smallest elt: " << result << endl;

  int answer = kthLargest(root, k, N);
  cout << "kth largest elt: " << answer << endl;

  return 0;
}
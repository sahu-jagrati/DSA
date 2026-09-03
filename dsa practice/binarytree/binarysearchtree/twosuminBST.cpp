// we have to find two different elt in BST whose sum is equal to k, if exist then return true else false

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

// brute solution- write inorder which is always sorted for BST and use two pointer approach -
// t.c-O(N)(for inorder)+O(N)(for two pointer run)
// s.c-O(N)(for storing inorder)

// efficient solution- BSTIterator in this we have next() and before() by before() we get previous element
// next()- first push all left - left node right- sorted in ascending order
// before()- first push all right- opposite to next()- right node left- sorted in descending order

// by using next() and before() with two pointer we don't have to store inorder
// now we use class

// t.c-O(N) for single traversal of two pointer
// s.c-O(ht of tree)*2 - one for next() and one for before()

class BSTIterator
{
private:
  stack<TreeNode *> myStack;
  // instead of writing another function for before() we write one function for both next() and before(), you can write separate also but using one function makes good quality code

  // reverse=true - run before() function
  // reverse=false - run next() function

  bool reverse = true;
  void pushAll(TreeNode *node)
  {
    while (node != NULL)
    {
      /* code */
      myStack.push(node);
      if (reverse == true)
      {
        // i.e before() function push right
        node = node->right;
      }
      else
      {
        node = node->left;
      }
    }
  }

public:
  // contructor
  BSTIterator(TreeNode *root, bool isReverse)
  {
    reverse = isReverse;
    pushAll(root);
  }
  bool hasNext()
  {
    return !myStack.empty();
  }
  // one function for next() and before()
  int next()
  {
    TreeNode *node = myStack.top();
    myStack.pop();
    if (!reverse) // because when reverse = false now for next() we push right nodes of all root because next()  start with pushing all left nodes initially in stack
      pushAll(node->right);
    else // opposite of above for before()
      pushAll(node->left);

    return node->data;
  }
};

// here we make another class for main question to make our code quality good

class Solution
{
public:
  bool findTarget(TreeNode *root, int k)
  {
    if (root == NULL)
      return false;
    BSTIterator l(root, false); // for next() function here we make object and  call contructor
    BSTIterator r(root, true);  // for before() function here we make object and  call contructor

    // we use two pointer approach
    int i = l.next();
    int j = r.next(); // means before() func. call because we pass true in r
    while (i < j)
    {
      if (i + j == k)
        return true;
      else if (i + j < k)
        i = l.next();
      else
        j = r.next();
    }
    return false;
  }
};

int main()
{
  // you can also create tree by taking input
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(7);

  int k;
  cout << "Enter value of target: ";
  cin >> k;
  Solution exist; // here we create object of class Solution
  cout << exist.findTarget(root, k) << endl;

  return 0;
}

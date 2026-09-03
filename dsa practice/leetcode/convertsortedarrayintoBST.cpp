// Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree

// we know inorder of BST is also sorted in ascending order

// example- nums=[-10,-3,0,5,9]
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val)
  {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

// my thinking fully - i think correct but in implementation i do slight mistakes correct solution is below

// TreeNode *BST(vector<int> &nums, TreeNode *root, int low, int high)
// {
//   while (low <= high)
//   {
//     int mid = low + (high - low) / 2;
//     root->left = BST(nums, root, low, mid - 1);
//     root->right = BST(nums, root, mid + 1, high);
//   }
//   return root;
// }

// TreeNode *sortedArrayToBST(vector<int> &nums)
// {
//   int n = nums.size();
//   int low = 0, high = n - 1;
//   int mid = low + (high - low) / 2;
//   TreeNode *root = new TreeNode(nums[mid]);
//   return BST(nums, root, 0, n - 1);
// }
// Your idea is correct, but the implementation has mistakes.
// You correctly thought:
// mid element → root

// left half → root->left

// right half → root->right

// repeat same process recursively

// But in your code there are three problems:

// Problems in your code

// Using while(low <= high)

// This should be recursion, not a loop.

// You never create new nodes for left and right

// You must create new TreeNode(nums[mid]) for each recursive call.

// Passing root again is wrong

// Each recursive call should create and return its own root.

// t.c-O(n) each elt used once
//  s.c-O(log n) recursion stack(height of tree)
TreeNode *BST(vector<int> &nums, int low, int high)
{
  if (low > high)
    return NULL;
  int mid = low + (high - low) / 2;
  TreeNode *root = new TreeNode(nums[mid]);
  root->left = BST(nums, low, mid - 1);
  root->right = BST(nums, mid + 1, high);

  return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
  return BST(nums, 0, nums.size() - 1);
}
void printInOrder(TreeNode *root)
{
  if (root == NULL)
    return;
  printInOrder(root->left);
  cout << root->data << " ";
  printInOrder(root->right);
}
int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i]; // in sorted order in increasing
  }
  TreeNode *root = sortedArrayToBST(nums);
  printInOrder(root);
}
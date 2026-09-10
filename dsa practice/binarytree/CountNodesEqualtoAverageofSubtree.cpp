// Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.

// Note:

// The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
// A subtree of root is a tree consisting of root and all of its descendants.

// Example 1:

// Input: root = [4,8,5,0,1,null,6]
// Output: 5
// Explanation:
// For the node with value 4: The average of its subtree is (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4.
// For the node with value 5: The average of its subtree is (5 + 6) / 2 = 11 / 2 = 5.
// For the node with value 0: The average of its subtree is 0 / 1 = 0.
// For the node with value 1: The average of its subtree is 1 / 1 = 1.
// For the node with value 6: The average of its subtree is 6 / 1 = 6.
// Example 2:

// Input: root = [1]
// Output: 1
// Explanation: For the node with value 1: The average of its subtree is 1 / 1 = 1.

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// 0 <= Node.val <= 1000

#include <bits/stdc++.h>
using namespace std;

// here we have to check average of the values in its subtree that average==node->value or not

// and for average we need to calculate the sum of the values and the number of the values

//  so we have to start calculate average and check  from the depth of the given binary tree , we start from leaf to root node

// for leaf node sum=node->val and size=1 so avg=sum/size=node->val/1
// first we calculate for left node
// then we calculate for right node
// and for root node - sum= left->sum+right->sum+root->val
// size=left->size+right->size+1  , here we add 1 for root node itself

// then average for root node= sum/size
// we do this for each non-leaf node

// so we create a recursive function that returns the size of a node's subtree and the sum of the values of its subtree so we create a recursive function that return a pair of {sum,size}

// and we take answer as a private variable that means whenever average=sum/size == node->value in recursive function  then ans++

struct TreeNode
{
  TreeNode *left;
  TreeNode *right;
  int data;
  TreeNode(int val)
  {
    data = val;
    left = right = nullptr;
  }
};

class Solution
{
  int ans = 0;
  pair<int, int> calculateSumAndSize(TreeNode *node)
  {
    if (node == NULL)
    {
      return {0, 0}; // i.e sum=0 and size=0 means no node here
    }
    // we calculate sum and size  for left subtree
    pair<int, int> left = calculateSumAndSize(node->left);
    // we calculate sum and size  for right subtree
    pair<int, int> right = calculateSumAndSize(node->right);
    // total sum for root node of the subtree = left->sum+right->sum+root->val
    int sum = left.first + right.first + node->data;
    // total size for root node of the subtree = left->size+right->size+1  , here we add 1 for root node itself
    int size = left.second + right.second + 1;
    // average of the subtree
    int avg = sum / size;
    // check avg==node->data then ans++
    if (avg == node->data)
    {
      ans++;
    }
    return {sum, size}; // of the subtree
  }

  // t.c- we traverse each node once so O(n)
  // s.c-O(1)
public:
  int averageOfSubtree(TreeNode *root)
  {
    // you might think that calculateSumAndSize returns a pair but we don't store it here because we don't need the returned pair because its only purpose is to pass sum and size to the parent during recursion means returned the children's sum and size to the parent node because the parent needs those values to calculate its own subtree but at the very top, there is no parent waiting for the pair therefore, we only call it and ignore the returned {sum,count}.

    //     The important distinction is:

    // calculateSumAndSize() → returns pair for the parent
    // averageOfSubtree() → only wants ans, so it ignores the pair.
    calculateSumAndSize(root);
    return ans;
  }
};

int main()
{
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(8);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(1);
  root->right->right = new TreeNode(6);

  Solution ans;
  cout << ans.averageOfSubtree(root);
  return 0;
}
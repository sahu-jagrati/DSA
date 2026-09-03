// You are given the root of a full binary tree with the following properties:

// Leaf nodes have either the value 0 or 1, where 0 represents False and 1 represents True.
// Non-leaf nodes have either the value 2 or 3, where 2 represents the boolean OR and 3 represents the boolean AND.
// The evaluation of a node is as follows:

// If the node is a leaf node, the evaluation is the value of the node, i.e. True or False.
// Otherwise, evaluate the node's two children and apply the boolean operation of its value with the children's evaluations.
// Return the boolean result of evaluating the root node.

// A full binary tree is a binary tree where each node has either 0 or 2 children.

// A leaf node is a node that has zero children.

// Example 1:

// Input: root = [2,1,3,null,null,0,1]
// Output: true
// Explanation: The above diagram illustrates the evaluation process.
// The AND node evaluates to False AND True = False.
// The OR node evaluates to True OR False = True.
// The root node evaluates to True, so we return true.

// Example 2:

// Input: root = [0]
// Output: false
// Explanation: The root node is a leaf node and it evaluates to false, so we return false.

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// 0 <= Node.val <= 3
// Every node has either 0 or 2 children.
// Leaf nodes have a value of 0 or 1.
// Non-leaf nodes have a value of 2 or 3.

#include <bits/stdc++.h>
using namespace std;

// this problem is done by classic "PostOrder DFS" because we cannot evaluate a parent until both of its children are evaluated.

// suppose the tree is:
//   or(2)
//   /    \ 
// true(1) and(3)
//         /    \ 
//      false(0)  true(1)

// to evaluate the root:
// 1. Evaluate the left subtree -> true
// 2. Evaluate the right subtree:
// Evaluate left child -> false
// Evaluate right child-> true
// apply AND -> false
// 3. apply OR on true and false -> true

// notice that the parent always waits for the children results.

// base case if it is a leaf:
// if(root->left==null&&root->right==null)return root->val;  since leaf values are only 0 or 1, they automatically convert to false or true.

// recursion:
// Evaluate both children first:
// bool left= evaluate(root->left);
// bool right=evaluate(root->right);

// now check the current node: we know non-leaf node is either OR / AND
// if value is 2, means OR
// return left || right;

// if value is 3, means AND
// return left && right;

struct TreeNode
{
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val)
  {
    data = val;
    left = right = nullptr;
  }
};

// t.c-O(n) because we traverse each node once, where n is total number of nodes
// s.c-O(1)
bool evaluateTree(TreeNode *root)
{
  // we know leaf node is either true / false
  // base case if it is a leaf
  if (root->left == NULL && root->right == NULL)
    return root->data; //  since leaf values are only 0 or 1, they automatically convert to false or true.
  // evaluate both child
  bool left = evaluateTree(root->left);
  bool right = evaluateTree(root->right);

  // because we know non-leaf node is either OR / AND
  if (root->data == 2)
    return left || right;
  // else it is AND so
  return left && right;
}

int main()
{
  TreeNode *root = new TreeNode(2);
  root->left = new TreeNode(1);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(1);

  cout << evaluateTree(root);
  return 0;
}
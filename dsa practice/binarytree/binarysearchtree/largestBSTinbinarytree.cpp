// given a binary tree, we have to find a largest BST from this

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

// brute solution- use validate a BST solution here for each node and calculate toatl no. of nodes for that tree and get largest
// t.c- O(N*N) - N(for validate a BST for a node) and N(for each node run validate a BST)
// s.c -O(1)

// efficient solution-
// for each node we find largest elt of all nodes in left and smallest elt of all nodes in right and if largest<node<smallest for that node then it is BST
// we start from bottom to top
// we calculate (largest,smallest,size) for each node

// for a leaf node, we can say that it is always a BST and size=1, largest= smallest = node itself
// for NULL node- size=0, largest=INT_MIN, smallest=INT_MAX
// If not BST then size=max(left.size,right.size) and largest=INT_MAX and smallest =INT_MIN so no compariosn can done

// t.c-O(N) postorder traversal beacuse first we calculate for each node we find largest elt of all nodes in left and smallest elt of all nodes in right and this is postorder traversal - left right node
// s.c-O(1) if we avoid recusion stack space

// size=x+y+1- x(no. of nodes in left), y(no. of nodes in right), 1(node itself)

class NodeValue
{
public:
  int maxNode, minNode, maxSize;
  // constructor
  NodeValue(int minNode, int maxNode, int maxSize)
  {
    this->maxNode = maxNode;
    this->minNode = minNode;
    this->maxSize = maxSize;
  }
};

class Solution
{
private:
  // It is a post-order recursive function that returns a NodeValue object, where:

  // minNode → smallest value in this subtree

  // maxNode → largest value in this subtree

  // maxSize → size of the largest BST inside this subtree
  NodeValue largestBSTSubtreeHelper(TreeNode *root)
  {
    // case 1
    if (root == NULL)
    {
      return NodeValue(INT_MAX, INT_MIN, 0);
    }
    auto left = largestBSTSubtreeHelper(root->left);
    auto right = largestBSTSubtreeHelper(root->right);

    // case 2
    // left and right are BST and root satisfies BST
    if (left.maxNode < root->data && root->data < right.minNode)
    {
      return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), left.maxSize + right.maxSize + 1);
    }

    // case 3
    // else if parent can't be valid BST then
    return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
  }

public:
  int largestBSTSubtree(TreeNode *root)
  {
    return largestBSTSubtreeHelper(root).maxSize;
  }
};

int main()
{
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(5);
  root->right = new TreeNode(15);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(8);
  root->right->right = new TreeNode(7);

  Solution result;
  int answer = result.largestBSTSubtree(root);
  cout << answer << endl;

  return 0;
}
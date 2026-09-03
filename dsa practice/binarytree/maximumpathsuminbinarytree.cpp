// path-travel from one node to another and each node travels once
#include <iostream>
#include <climits>

using namespace std;

struct Node
{
  int data;
  Node *left, *right;
  Node(int val)
  {
    data = val;
    left = right = NULL;
  }
};

int maxPath(Node *root, int &maxi)
{
  if (root == NULL)
    return 0;
  int leftSum = max(0, maxPath(root->left, maxi)); // here we compare with 0 because of we get sum -ve in that case we start with 0 because -ve reduced the maxPathSum
  int rightSum = max(0, maxPath(root->right, maxi));
  maxi = max(maxi, leftSum + rightSum + root->data);
  return (root->data + max(leftSum, rightSum));
}

// time complexity-O(N) each node visited once
// space complexity-comes from the recusion stack(auxilliary stack space)=O(h) h=height of tree
// in worst case(skewed tree)=O(N)
// in best case(balanced tree)=O(logN)
int maxPathSum(Node *root)
{
  int maxi = INT_MIN;
  maxPath(root, maxi);
  return maxi;
}

int main()
{
  // Node *root = new Node(-10);
  // root->left = new Node(9);
  // root->right = new Node(20);
  // root->right->left = new Node(15);
  // root->right->right = new Node(7);

  Node *root = new Node(15);
  root->left = new Node(10);
  root->right = new Node(20);
  root->right->left = new Node(-30);
  root->right->right = new Node(-15);

  int result = maxPathSum(root);
  cout << result << endl;
  return 0;
}
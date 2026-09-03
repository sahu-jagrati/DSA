// basic code of binary tree

#include <iostream>
using namespace std;

// binary tree representation
// we create self defined datatype to store data,left pointer, right pointer because we have no datatype that store three of all together so we create self defined datatype struct

// using struct cann't use OOPS concept like abstraction/encapsulation/inheritance for this we have to use class in same manner for OOPS concept
// both are same only difference is OOPS concept availablity
// if using class then define data,left pointer and right pointer public and also constructor
struct Node
{
  /* data */
  int data;
  // struct Node *left;
  // struct Node *right;
  Node *left, *right; // store left and right pointer in set Node
  // we can have multiple constructor
  Node(int value)
  { // constructor
    data = value;
    left = right = NULL; // initial
  }
  Node()
  {
    data = 0;
    left = right = NULL;
  }
  Node(int value, Node *left, Node *right)
  {
    data = value;
    left = left;
    right = right;
  }
};

// for printing the binary tree we have to use binary tree traversals - BFS | DFS
int main()
{
  // struct Node *root = new Node(1); // go to constructor
  Node *root = new Node(1);
  root->left = new Node(2); // create another new node and assign value 2
  root->right = new Node(3);
  root->left->right = new Node(5);
  return 0;
}

// for taking tree as input you make separate function that take array and create according that you want level order you pass and funtion return tree
// if level order build then binary tree is taken as input is
// #include <bits/stdc++.h>
// using namespace std;

// struct Node {
//     int data;
//     Node* left;
//     Node* right;

//     Node(int val) {
//         data = val;
//         left = right = NULL;
//     }
// };

// Node* buildTree() {
//     int x;
//     cin >> x;

//     if (x == -1) return NULL;

//     Node* root = new Node(x);
//     queue<Node*> q;
//     q.push(root);

//     while (!q.empty()) {
//         Node* curr = q.front();
//         q.pop();

//         int leftVal, rightVal;
//         cin >> leftVal >> rightVal;

//         if (leftVal != -1) {
//             curr->left = new Node(leftVal);
//             q.push(curr->left);
//         }
//         if (rightVal != -1) {
//             curr->right = new Node(rightVal);
//             q.push(curr->right);
//         }
//     }
//     return root;
// }

// in main(){
// Node*root=buildTree();
// }

// you can also take binary tree by recursice way preorder
// Node* buildTree() {
//     int x;
//     cin >> x;

//     if (x == -1) return NULL;

//     Node* root = new Node(x);
//     root->left = buildTree();
//     root->right = buildTree();

//     return root;
// }

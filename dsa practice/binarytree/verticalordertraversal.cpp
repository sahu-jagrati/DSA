// in vertical order start from left to right
// write from top to bottom
// if multiple nodes have same value then okay
// if nodes are overlap then write first small value node

// here we do by level order traversing, you can do also by inorder/preorder/postorder

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
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

// time complexity-O(NlogN)(because of multiset)+O(N)(for traversal)
// let n=total number of nodes in the tree
// each node is pushed and popped from the queue once → O(n) operations.
// nodes[x][y].insert(node->data);
// Now, this line does multiple things:

// Access outer map (x): O(log V) where V = number of verticals ≤ n

// Access inner map (y): O(log L) where L = number of levels ≤ n

// Insert into multiset: O(log k) where k = number of nodes at same (x, y) (worst-case ≤ n)

// So per insertion:
// ➡️ O(log n + log n + log n) = O(log n) (asymptotically)

// Over all n nodes →
// ➡️ O(n log n) total for insertion steps

//Building the answer
// You iterate through all nodes again (flattening multiset contents).

// Each element is copied exactly once into ans.
// ➡️ O(n) traversal


// so time complexity-O(nlogn)
// space complexity-O(N) overall= O(N)+O(N)(queue)
// Let’s consider the data structures used:

// nodes map

// Stores each node once → O(n) total elements across all maps and multisets.

// queue (BFS)

// At most O(n) nodes in memory at once (in worst case for a level).

// ans vector

// Stores n elements total.

// ✅ Total Space Complexity = O(n)

// Outer map<int, …> → vertical (x-coordinate)
// Inner map<int, multiset<int>> → level (y-coordinate)
// multiset<int> → stores possibly multiple nodes with same value at same (x, y)


vector<vector<int>> verticalTraversal(Node *root)
{
  map<int, map<int, multiset<int>>> nodes;  // here in map(vertical,level,multinodes), we use multiset because in question mention we can have multiple nodes with same value so we cann't use set
  queue<pair<Node *, pair<int, int>>> todo; // here in Queue(node,vertical,level)
  todo.push({root, {0, 0}});
  while (!todo.empty())
  {
    auto p = todo.front();
    todo.pop();
    Node *node = p.first;    // p.first=node
    int x = p.second.first;  // this give vertical
    int y = p.second.second; // this give level
    nodes[x][y].insert(node->data);
    if (node->left)
    {
      todo.push({node->left, {x - 1, y + 1}});
    }
    if (node->right)
    {
      todo.push({node->right, {x + 1, y + 1}});
    }
  }
  vector<vector<int>> ans;
  for (auto p : nodes)
  {
    vector<int> col;
    for (auto q : p.second)
    {
      col.insert(col.end(), q.second.begin(), q.second.end());
    }
    ans.push_back(col);
  }
  return ans;
}
int main()
{
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(10);
  root->left->left->right = new Node(5);
  root->left->left->right->right = new Node(6);
  root->right->left = new Node(9);
  root->right->right = new Node(10);

  vector<vector<int>> result = verticalTraversal(root);
  for (auto it1 : result)
  {
    for (auto it2 : it1)
    {
      cout << it2 << " ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
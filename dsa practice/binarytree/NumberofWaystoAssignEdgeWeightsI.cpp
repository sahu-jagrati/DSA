// There is an undirected tree with n nodes labeled from 1 to n, rooted at node 1. The tree is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi.

// Initially, all edges have a weight of 0. You must assign each edge a weight of either 1 or 2.

// The cost of a path between any two nodes u and v is the total weight of all edges in the path connecting them.

// Select any one node x at the maximum depth. Return the number of ways to assign edge weights in the path from node 1 to x such that its total cost is odd.

// Since the answer may be large, return it modulo 10^9 + 7.

// Note: Ignore all edges not in the path from node 1 to x.

// Example 1:

// Input: edges = [[1,2]]

// Output: 1

// Explanation:

// The path from Node 1 to Node 2 consists of one edge (1 → 2).
// Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the number of valid assignments is 1.
// Example 2:

// Input: edges = [[1,2],[1,3],[3,4],[3,5]]

// Output: 2

// Explanation:

// The maximum depth is 2, with nodes 4 and 5 at the same depth. Either node can be selected for processing.
// For example, the path from Node 1 to Node 4 consists of two edges (1 → 3 and 3 → 4).
// Assigning weights (1,2) or (2,1) results in an odd cost. Thus, the number of valid assignments is 2.

// Constraints:

// 2 <= n <= 105
// edges.length == n - 1
// edges[i] == [ui, vi]
// 1 <= ui, vi <= n
// edges represents a valid tree.

#include <bits/stdc++.h>
using namespace std;

// let's break down our problem

// example1: 1->2
// there is only 1 edge in the path from root 1 to deepest node 2

// possible assignments:
// edges Weight:
// 1
// 2
// Path costs:
// when weight=1 then cost=1(odd)
// when weight=2 then cost=2(even)

// so answer=1

// example-2: [[1,2][1,3],[3,4],[3,5]]
// tree looks like this
//  1
// 2  3
//   4  5
// maximum depth=2
// node 4 and 5 are at depth=2
// so we choos node 4
// path: 1->3->4
// there are 2 edges
// Each edge can be assigned either 1 or 2
// let's list all possibilities.

// Edge1     Edge2      Sum       Odd?
//  1          1         2        no
//  1          2         3        yes
//  2          1         3        yes
//  2          2         4        no

// number of odd sum ways: answer=2

// Notice:
// total assignments=4=2^2
// odd assignments=2=4/2

// example with depth=3
// Suppose path contains 3 edges
// 1->2->3->4
// possible assignments:
// 111-> 3(odd)
// 112->4  (even)
// 121->4(even)
// 122->5(odd)
// 211->4(even)
// 212->5(odd)
// 221->5(odd)
// 222->even

// total assignments=8=2^3
// odd assignments:
// 111
// 122
// 212
// 221
// count=4 which is 8/2=4

// Why exactly half are odd?
// Suppose we have an assignment:
// 1 2 1  these wre weights on edges
// Sum=4(even)
// Now change only the first edge:
// 2 2 1
// SUm=5(odd)
// Parity changed.

// let's take another example
// 1 1 2
// Sum=4(even)
// Flip first edge:
// 2 1 2
// Sum=5(odd)
// Again parity changed.

// Every even assignment can be paired with exactly one odd assignment.
// 111 <->211
// 112 <->212
// 121 <->221
// 122 <->222
// One side is odd, the other is even.

// Therefore:
// number of odd assignments = number of even assignments
// SInce total assignments are: 2^d
// where d = number of edges in the path
// we get:
// odd assignments = (2^d)/2 = 2^(d-1)

// Why only maximum depth matters?
// The problem says:
// Select any one node x at maximum depth.
// Suppose maximum depth is 4.
// Then the path from root to any deepest node contains exactly: 4 edges
// The answer depends only on how many edges are in the path.

// For 4 edges:
// answer= 2^(4-1)=8
// So we don't need to know the actual path, only its length(maximum depth) we want.

// We can use BFS/DFS any for maximum Path

// so we use BFS here
// What does the BFS compute?
// example:
//    1
//  2    3
//    4     5

// BFS visits:
// node 1 at depth 0
// node 2 at depth 1
// node 3 at depth 1
// node 4 at depth 2
// node 5 at depth 2

// Maximum depth found=2
// then answer=2^(2-1)=2

// So the entire problem reduces to:

// Find maximum depth d.
// Return 2^(d-1) mod (1e9+7).

int mod = 1e9 + 7;

// we find power using bitmanipulation
long long modPow(long long a, long long b)
{
  long long result = 1;
  while (b)
  {
    if (b & 1)
    {
      result = (result * a) % mod; // we do mod because in question it says the answer may be large so return its modulus with 1e9+7
    }
    a = (a * a) % mod;
    b >>= 1;
  }
  return result;
}

// as number of nodes are n
// for calculating power t.c is : Binary exponentiation takes: O(log(maxDepth)) since maxDepth<=n: O(logn)
// so t.c-O(n)(for traversing each node by BFS)+O(edges size=n)(for adj matrix)+O(for calculating power )=O(n)+O(n)+O(logn)=O(n)
// s.c-O(n)(for queue storing each node)+O(adj size=n)
int assignEdgeWeights(vector<vector<int>> &edges)
{
  int size = edges.size();
  int n = size + 1;

  // we make adjacency matrix for edge
  vector<vector<int>> adj(n + 1); // n+1 because we have node from 1 to n
  for (auto &e : edges)
  {
    adj[e[0]].push_back(e[1]);
    adj[e[1]].push_back(e[0]);
  }

  // BFS
  queue<pair<int, int>> q;       // store node and depth
  vector<int> visited(n + 1, 0); // visited array and // n+1 because we have node from 1 to n

  // node 1 at depth 0
  // so initially we push it in q and mark as visited
  q.push({1, 0});
  visited[1] = 1;

  int maxDepth = 0;
  while (!q.empty())
  {
    int node = q.front().first;
    int depth = q.front().second;
    q.pop();

    maxDepth = max(maxDepth, depth);

    for (int neighbour : adj[node])
    {
      if (!visited[neighbour])
      {
        visited[neighbour] = 1;
        q.push({neighbour, depth + 1});
      }
    }
  }

  // answer
  // int answer = pow(2, maxDepth - 1); // we cannot use this because pow() returns a double, not an integer. For small powers it works but for large powers, precision is lost
  // return answer % mod;

  return modPow(2, maxDepth - 1);
}

int main()
{
  int size;
  cin >> size;
  vector<vector<int>> edges(size, vector<int>(2));
  for (int i = 0; i < size; i++)
  {
    cin >> edges[i][0] >> edges[i][1];
  }
  cout << assignEdgeWeights(edges);
  return 0;
}
// given an undirected graph with V vertices. We say two vertices u and v belong to single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

// Note- A province is a group of directle or indirectly connected cities and no other cities outside of the group.

// number of province means number of connected components, we already done by using dfs

// now by disjoint set we do

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
  vector<int> rank, parent, size; // we make this public because we use parent array out of class
  // constructor
  DisjointSet(int n) // n is the number of vertices
  {
    // n+1 takes because of 0 based indexing
    rank.resize(n + 1, 0);
    parent.resize(n + 1);
    size.resize(n + 1, 1);
    for (int i = 0; i <= n; i++)
    {
      parent[i] = i;
    }
  }

  // find ultimate parent
  int findUPar(int node)
  {
    if (node == parent[node])
    {
      return node;
    }
    return parent[node] = findUPar(parent[node]);
  }

  // union by rank
  void unionByRank(int u, int v)
  {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    if (ulp_u == ulp_v)
      return;
    if (rank[ulp_u] < rank[ulp_v])
    {
      parent[ulp_u] = ulp_v;
    }
    else if (rank[ulp_v] < rank[ulp_u])
    {
      parent[ulp_v] = ulp_u;
    }
    // when rank are same
    else
    {
      parent[ulp_v] = ulp_u;
      rank[ulp_u]++;
    }
  }

  // union by size
  void unionBySize(int u, int v)
  {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    if (ulp_u == ulp_v)
      return;
    if (size[ulp_u] < size[ulp_v])
    {
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    }
    // when size  are same or size[ulp_v]<size[ulp_u]
    else
    {
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    }
  }
};

// for disjoint set t.c of union is O(4*(alpha)) and for findUPar is O(4*(alpha))

// t.c-(V^2)*(4*(alpha)) in worst case when all are connected +V*(4*(alpha)) for cnt loop

// s.c-O(V)*3 for parent, rank, size array

// Time Complexity

// Traversing matrix: O(V²)

// Each union/find: ~O(α(V)) (almost constant)

// 👉 Total: O(V² * α(V)) ≈ O(V²)

// Space Complexity

// parent, rank, size arrays → O(V)
class Solution
{
public:
  int numProvinces(vector<vector<int>> &adj, int V)
  {
    DisjointSet ds(V);
    // iterate the adj matrix
    for (int i = 0; i < V; i++)
    {
      for (int j = 0; j < V; j++)
      {
        // if there is an edge btw nodes then adj[i][j]=1
        // You check every pair (i, j)

        // If there is an edge → you merge them into one set

        // Using union by size keeps tree shallow (good 👍)

        // ✔️ Even if you call union twice (i→j and j→i),
        // DSU safely ignores already-connected nodes
        if (adj[i][j] == 1)
        {
          // i and j
          ds.unionBySize(i, j); // don't do j,i it will discard in future see below
        }
      }
    }
    int cnt = 0;
    for (int i = 0; i < V; i++)
    {
      if (ds.findUPar(i) == i) // also you can do ds.parent(i) when you define parent array inside public it take O(1) time while findUpar take O(4*(alpha))
        cnt++;
    }
    return cnt;
  }
};

// in input given undirected graph with V vertice and store in adj matrix not list

int main()
{
  int n, m;
  cout << "Enter number of vertices and edges: ";
  cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>(n, 0)); // adj list
  cout << "Enter edges (u,v): \n";
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u][v] = 1;
    adj[v][u] = 1;
  }

  Solution result;
  cout << "Number of provinces is: " << result.numProvinces(adj, n) << endl;
  return 0;
}

// ✔️ Even if you call union twice (i→j and j→i),
// DSU safely ignores already-connected nodes

// Key line in your DSU (MOST IMPORTANT)
// if (ulp_u == ulp_v)
//     return;

// This single line is the reason DSU ignores duplicate unions.

// Let’s understand with a simple example
// Suppose we have 2 nodes
// 0 ---- 1

// Adjacency matrix:

// adj[0][1] = 1
// adj[1][0] = 1

// So your loops will do:

// unionBySize(0, 1);  // first time
// unionBySize(1, 0);  // second time

// First call: unionBySize(0, 1)
// Step 1: Find parents
// ulp_u = findUPar(0) = 0
// ulp_v = findUPar(1) = 1

// Different parents → merge happens

// Result:

// parent[1] = 0

// Now both belong to same set.

// Second call: unionBySize(1, 0)
// Step 1: Find parents again
// ulp_u = findUPar(1) → 0
// ulp_v = findUPar(0) → 0

// Now:

// ulp_u == ulp_v

// Step 2: DSU says:
// if (ulp_u == ulp_v)
//     return;

// 👉 Nothing happens
// 👉 DSU ignores this union

// Why ignoring is CORRECT?

// Because:

// Nodes 0 and 1 are already in the same set

// Merging again would:

// Do nothing useful

// Possibly break rank/size logic

// So DSU protects itself
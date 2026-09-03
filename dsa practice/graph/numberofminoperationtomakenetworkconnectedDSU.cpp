// you are given a graph (it can be directed or undirected but for undirected also disjiont set ignore node that are alredy connected by one way) with n vertices and m edges. You can remove one edge from anywhere and add that edge btw any two vertices in one operation.

// Find the minimum number of operation that will be required to make the graph connected.

// that is given component of graph, we have to connect all of them and make single component and
// and for connected graph the edge should be taken out from the graph don't make new edge

// How we connect component?
// If we connect any one node of one component to any one node of 2nd component then it is connected

// How many  edges required to connect n components?
// so for n components we require n-1 edges minimum and maximum can be more than n-1

// so if we got no. of connected components - nc then answer=nc-1 minimum edges but we have to take out the existing edges and reuse it. we cann't create another new edge

// so we have to cnt extra edges of the graph that after removing them graph is still connected

// we cnt extra edge because if there is no (nc-1) extra edge then we cann't connect graph from existing edge
// which data structure we use - Disjoint set union(DSU) because here at every step configuration change so for dynamically changes we use DSU and  initial configuration for disjoint set is each of the node is parent of itself

// we write all edges and do union on edge and make tree if ulp_u and ulp_v are same then they are already connected so this is extra edge

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

// t.c-
// traverse connections array -O(m) where m is connections size
// // Each union/find: ~O(α(n)) (almost constant) and n is number of vertices
// total - O(m*α(n))
// s.c - O(n) for parent,rank,size arrays
class Solution
{
public:
  // connections array denote edge array
  int makeConnected(int n, vector<vector<int>> &connections)
  {
    DisjointSet ds(n);
    int cntExtraEdges = 0;
    // iterate edge array and cnt extra edge
    for (auto it : connections)
    {
      int u = it[0];
      int v = it[1];
      if (ds.findUPar(u) == ds.findUPar(v))
      {
        cntExtraEdges++;
      }
      else
      {
        ds.unionBySize(u, v); // ✔️ Even if you call union twice (u->v and v->u), if we have undirected graph
        // DSU safely ignores already-connected nodes
      }
    }
    int cntComponent = 0;
    for (int i = 0; i < n; i++)
    {
      if (ds.parent[i] == i) // // also you can do this  when you define parent array inside public it take O(1) time while you can do ds.findUPar(i)==i also , findUpar take O(4*(alpha))
        cntComponent++;
    }
    int ans = cntComponent - 1;
    if (cntExtraEdges >= ans)
      return ans;
    return -1;
  }
};

// input type - n=9 (vertices)
// edge array-{[0,1],[0,2],[0,3],[1,2],[2,3],[4,5],[5,6],[7,8]}

int main()
{
  int n;
  cout << "Enter the numberof vertices: ";
  cin >> n;
  int m;
  cout << "Enter the size of edge array: ";
  cin >> m;
  vector<vector<int>> edge(m, vector<int>(2));
  cout << "Enter the edge array: ";
  for (int i = 0; i < m; i++)
  {
    cin >> edge[i][0] >> edge[i][1];
  }

  Solution result;
  cout << "Number of min operation to make network connected: " << result.makeConnected(n, edge) << endl;

  return 0;
}
// You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.

// Return the number of complete connected components of the graph.

// A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

// A connected component is said to be complete if there exists an edge between every pair of its vertices.

// Example 1:

// Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
// Output: 3
// Explanation: From the picture above, one can see that all of the components of this graph are complete.
// Example 2:

// Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
// Output: 1
// Explanation: The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.

// Constraints:

// 1 <= n <= 50
// 0 <= edges.length <= n * (n - 1) / 2
// edges[i].length == 2
// 0 <= ai, bi <= n - 1
// ai != bi
// There are no repeated edges.

#include <bits/stdc++.h>
using namespace std;

// First we find the connected components of an undirected graph by using a DisjointSet (Union-Find)

// then for each connected component we count the number of nodes and edges in the component

// we know a connected componenet is complete if and only if the number of edges in the component is equal to m*(m-1)/2, where m is the number of nodes in the component.

// First we declare DisjoinSet
class DisjointSet
{
public:
  vector<int> parent, size; // no need of rank array so we don't declare here
  DisjointSet(int n)
  {
    parent.resize(n + 1);
    size.resize(n + 1, 1); //  node itself count so start with 1
    for (int i = 0; i <= n; i++)
    {
      parent[i] = i;
    }
  }

  int findUPar(int node)
  {
    if (node == parent[node])
      return node;
    return parent[node] = findUPar(parent[node]);
  }

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
    // when size is same or size[ulp_v]<size[ulp_u]
    else
    {
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    }
  }
};

// n is the number of vertices
// let m is the size of edges array
// for first loop we have O(m*α(n))
// for edgecount: O(m*α(n))
// for check complete or not:O(n*α(n))
// total t.c-O(m+n)*α(n)
// s.c-O(n*2)(for parent and size array)+O(edgecount size)
int countCompleteComponents(int n, vector<vector<int>> &edges)
{
  DisjointSet ds(n); // n is the number of vertices
  // first we make connected components
  for (int i = 0; i < edges.size(); i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];
    ds.unionBySize(u, v);
  }
  // now we count the number of edges that each component have
  unordered_map<int, int> edgeCount;
  for (int i = 0; i < edges.size(); i++)
  {
    int parent = ds.findUPar(edges[i][0]); // same as edges[i][1]'s parent because if there is an edge between 0 and 1 then if 0 is parent of itself and 1's parent is 0 so same and also if we take two time then it increse the edge extra because there is an undirected edge btw nodes so we count only 1 for one edge
    edgeCount[parent]++;
  }

  // now we also want the number of vertices that each component have which is already store in size array at the root of the component

  // now we check that the connected component is complete or not
  int cnt = 0;
  // so we traverse each node and check why we traverse each node? because for getting component findUPar(node)=node means when node is parent of itself it means it is a componenet so we check for each node
  for (int i = 0; i < n; i++)
  {
    // when we say it is a component when node is itself a parent
    if (ds.findUPar(i) == i)
    {
      // number of vertices in that component is size[i]
      int vertices = ds.size[i]; // because size belongs to the DSU object.
      // numbe rof edges in that component
      int edges = edgeCount[i];
      // when connected component is complete
      if (edges == vertices * (vertices - 1) / 2)
        cnt++;
    }
  }
  return cnt;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> edges(m, vector<int>(2));
  for (int i = 0; i < m; i++)
  {
    cin >> edges[i][0] >> edges[i][1];
  }
  cout << countCompleteComponents(n, edges);
  return 0;
}
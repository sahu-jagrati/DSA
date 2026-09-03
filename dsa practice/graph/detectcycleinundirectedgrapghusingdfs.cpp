// detect a cycle in an undirected graph using dfs
// 0-indexing graph
#include <iostream>
#include <vector>
using namespace std;

// space complexity-O(n)(for visited array)+O(n)(for recursion stack space)
// time complexity-O(n)(for iscycle for loop)+O(n+2m)(for dfs)
bool detectCycleUsingDFS(int node, int parent, vector<vector<int>> &adj, vector<int> &vis)
{
  vis[node] = 1;
  // traverse all adjacent node
  for (auto neighbour : adj[node])
  {
    if (!vis[neighbour])
    {
      if (detectCycleUsingDFS(neighbour, node, adj, vis) == true)
        return true;
    }
    // if already visited
    else if (parent != neighbour)
      return true;
  }
  return false;
}
bool isCycle(int n, vector<vector<int>> &adj)
{
  vector<int> vis(n, 0);
  // if graph has components then
  for (int i = 0; i < n; i++)
  {
    if (!vis[i])
    {
      if (detectCycleUsingDFS(i, -1, adj, vis))
        return true;
    }
  }
  return false;
}
int main()
{
  int n, m;
  cout << "Enter number of vertices and edges: ";
  cin >> n >> m;
  vector<vector<int>> adj(n);
  cout << "Enter edges (u,v): \n";
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  if (isCycle(n, adj))
  {
    cout << "Graph contain cycle." << endl;
  }
  else
  {
    cout << "Graph does not conatin cycle." << endl;
  }
  return 0;
}
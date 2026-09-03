// Detect Cycle in a Directed Graph (using DFS + Recursion Stack)

#include <iostream>
#include <vector>
using namespace std;

bool dfsDirected(int start, vector<vector<int>> &adj, vector<int> &visited, vector<int> &inStack)
{
  visited[start] = 1;
  inStack[start] = 1;
  for (int neighbour : adj[start])
  {
    if (!visited[neighbour])
    {
      if (dfsDirected(neighbour, adj, visited, inStack))
      {
        return true;
      }
    }
    else if (inStack[neighbour])
    {
      return true; // back edge-cycle
    }
  }
  inStack[start] = 0; // remove from recursion stack
  return false;
}

bool containsCycle(vector<vector<int>> &adj, int n)
{
  vector<int> visited(n, 0), inStack(n, 0);
  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      if (dfsDirected(i, adj, visited, inStack))
      {
        return true;
      }
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
  cout << "Enter the edges (u,v): \n";
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  if (containsCycle(adj, n))
    cout << "Directed graph contains a cycle.\n";
  else
    cout << "Directed graph does NOT contain a cycle.\n";

  return 0;
}
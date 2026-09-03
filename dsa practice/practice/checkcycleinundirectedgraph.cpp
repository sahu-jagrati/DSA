// detect cycle in an undirected graph
#include <iostream>
#include <vector>
using namespace std;

bool dfs(int start, int parent, vector<vector<int>> &adj, vector<int> &visited)
{
  visited[start] = 1;
  for (int neighbour : adj[start])
  {
    if (!visited[neighbour])
    {
      if (dfs(neighbour, start, adj, visited))
      {
        return true;
      }
    }
    // If neighbor is visited and not parent → cycle found
    else if (neighbour != parent)
    {
      return true;
    }
  }
  return false;
}

bool containsCycle(vector<vector<int>> &adj, int n)
{
  vector<int> visited(n, 0);
  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      if (dfs(i, -1, adj, visited))
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
  cout << "Enter edges (u v):\n";
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u); // undirected graph
  }

  if (containsCycle(adj, n))
    cout << "Graph contains a cycle.\n";
  else
    cout << "Graph does NOT contain a cycle.\n";

  return 0;
}
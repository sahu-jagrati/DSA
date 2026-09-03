// undirected and 0-based graph

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfsTraversal(int n, vector<vector<int>> &adj, int start)
{
  vector<int> visited(n, 0);
  visited[start] = 1;
  queue<int> q;
  q.push(start);

  cout << "BFS Traversal starting from node " << start << ": ";
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    cout << node << " ";

    // visit all unvisited adjacent nodes
    for (auto it : adj[node])
    {
      if (!visited[it])
      {
        visited[it] = 1;
        q.push(it);
      }
    }
  }
}

int main()
{
  int n, m; // n-vertices, m-edges
  cout << "Enter number of vertices and edges: ";
  cin >> n >> m;
  vector<vector<int>> adj(n);
  cout << "Enter edges (u,v): ";
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int start;
  cout << "Enter starting vertex: ";
  cin >> start;

  bfsTraversal(n, adj, start);

  return 0;
}
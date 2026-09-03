// disconnected graph and undirected

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<vector<int>> &adj, vector<int> &visited)
{
  visited[start] = 1;
  queue<int> q;
  q.push(start);

  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    cout << node << " ";
    for (auto neighbour : adj[node])
    {
      if (!visited[neighbour])
      {
        visited[neighbour] = 1;
        q.push(neighbour);
      }
    }
  }
}

void bfsDisconnectedGraph(vector<vector<int>> &adj, int n)
{
  vector<int> visited(n, 0);
  cout << "BFS Traversal of the whole graph: ";
  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      bfs(i, adj, visited);
    }
  }
  cout << endl;
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
  bfsDisconnectedGraph(adj, n);

  return 0;
}
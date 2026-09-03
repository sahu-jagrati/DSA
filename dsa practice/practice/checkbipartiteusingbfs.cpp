// A bipartite graph is a graph where:

// 👉 The set of vertices (nodes) can be divided into two groups — say Set A and Set B —
// such that no two vertices within the same set are directly connected by an edge

// In other words:

// You can color all vertices using two colors (say Red and Blue)
// so that no two adjacent vertices share the same color.

// If this is possible → the graph is Bipartite
// If not → the graph is Not Bipartite

// using bfs

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>> &adj, int n)
{
  vector<int> color(n, -1); //-1=uncolored,0&1=two colors

  for (int start = 0; start < n; start++)
  {
    if (color[start] == -1)
    {
      color[start] = 0;
      queue<int> q;
      q.push(start);
      while (!q.empty())
      {
        int node = q.front();
        q.pop();

        for (auto neighbour : adj[node])
        {
          if (color[neighbour] == -1)
          {
            color[neighbour] = 1 - color[node];
            q.push(neighbour);
          }
          else if (color[neighbour] == color[node])
          {
            return false;
          }
        }
      }
    }
  }
  return true;
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
  if (isBipartite(adj, n))
  {
    cout << "The graph is bipartite.\n";
  }
  else
  {
    cout << "The graph is not bipartite.\n";
  }
  return 0;
}
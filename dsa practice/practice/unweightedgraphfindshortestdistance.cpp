// You’re given an unweighted graph (all edges have equal weight = 1).

// You need to find the shortest distance from a source vertex s to every other vertex.

// 👉 Since the graph is unweighted, BFS (Breadth-First Search) is the best algorithm —
// it naturally explores nodes in increasing distance order

// Algorithm Idea (Using BFS)

// Start from the source vertex s.

// Initialize a distance array:

// dist[i] = ∞ for all vertices initially

// dist[s] = 0

// Use a queue for BFS.

// For each node u you dequeue:

// For every neighbor v of u:
// if dist[v] is not yet visited (∞), set
// dist[v] = dist[u] + 1 and push v into the queue.

// Continue until the queue is empty.

// At the end, dist[i] will hold the shortest distance from s to vertex i.

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void bfsShortestDistance(vector<vector<int>> &adj, int n, int s)
{
  vector<int> dist(n, INT_MAX); // distance array
  queue<int> q;
  dist[s] = 0;
  q.push(s);
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    for (int neighbour : adj[node])
    {
      if (dist[neighbour] == INT_MAX)
      {
        dist[neighbour] = dist[node] + 1;
        q.push(neighbour);
      }
    }
  }
  cout << "Shortest distance from vertex " << s << ": ";
  for (int i = 0; i < n; i++)
  {
    if (dist[i] == INT_MAX)
    {
      cout << "Vertex " << i << " is not reachable\n";
    }
    else
    {
      cout << "Vertex " << i << ": " << dist[i] << endl;
    }
  }
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
    adj[v].push_back(u);
  }
  int s;
  cout << "Enter source vertex: ";
  cin >> s;

  bfsShortestDistance(adj, n, s);

  return 0;
}
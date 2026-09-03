// graph is undirected with unit weights
// find the shortest distance from src to all the points, if path is not possible then put -1
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// time complexity-O(n+2m)(bfs for undirected graph)
// space complexity-O(n)(for distance array)+O(n)(queue)+O(n)(ans array)
vector<int> shortestPath(int n, int m, vector<vector<int>> &adj, int src)
{
  vector<int> dist(n, 1e9);
  dist[src] = 0;
  queue<int> q;
  q.push(src);
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    for (auto neighbour : adj[node])
    {
      if (dist[node] != 1e9)
      {
        if (dist[node] + 1 < dist[neighbour])
        {
          dist[neighbour] = dist[node] + 1;
          q.push(neighbour);
        }
      }
    }
  }
  vector<int> ans(n, -1);
  for (int i = 0; i < n; i++)
  {
    if (dist[i] != 1e9)
    {
      ans[i] = dist[i];
    }
  }
  return ans;
}

// weight is unit
int main()
{
  int n, m;
  cout << "Enter number of vertices and edges: ";
  cin >> n >> m;
  vector<vector<int>> adj(n);
  cout << "Enter number of edges(u,v): \n";
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int src;
  cout << "Enter source node: ";
  cin >> src;

  vector<int> result = shortestPath(n, m, adj, src);
  for (auto it : result)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}
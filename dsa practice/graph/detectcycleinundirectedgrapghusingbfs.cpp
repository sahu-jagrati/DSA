// detect a cycle in an undirected graph using bfs
// 0-indexed graph
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// time complexity-O(n+2m)(for bfs)+O(n)(for iscycle for loop)
// space complexity-O(n)(for visited array)+O(n)(for queue)
bool detectCycleUsingBFS(int src, vector<vector<int>> &adj, vector<int> &vis)
{
  vis[src] = 1;
  queue<pair<int, int>> q; // node,parent
  q.push({src, -1});       // initially parent =-1;
  while (!q.empty())
  {
    int node = q.front().first;
    int parent = q.front().second;
    q.pop();

    // travel adjacent node
    for (auto neighbour : adj[node])
    {
      if (!vis[neighbour])
      {
        vis[neighbour] = 1;
        q.push({neighbour, node});
      }
      // if visited already
      else if (parent != neighbour)
      {
        return true;
      }
    }
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
      if (detectCycleUsingBFS(i, adj, vis))
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
  vector<vector<int>> adj(n); // adj list
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
    cout << "Graph does not contain cycle." << endl;
  }
  return 0;
}
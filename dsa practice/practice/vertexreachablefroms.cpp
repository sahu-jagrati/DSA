// A vertex v is reachable from s if there exists a path from s to v
// algo are: 1.bfs
// 2.dfs
#include <iostream>
#include <vector>
using namespace std;

void dfs(int start, vector<vector<int>> &adj, vector<int> &visited)
{
  visited[start] = 1;
  cout << start << " ";
  for (int neighbour : adj[start])
  {
    if (!visited[neighbour])
    {
      dfs(neighbour, adj, visited);
    }
  }
}
void dfsTraversal(int n, vector<vector<int>> &adj, int start)
{
  vector<int> visited(n, 0);
  dfs(start, adj, visited);
}

int main()
{
  int n, m;
  cout << "Enter number of vertices and edges: ";
  cin >> n >> m;
  vector<vector<int>> adj(n);
  cout << "Enter the edges (u,v) :\n";
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
  cout << "Vertices reachable from " << start << ": ";
  dfsTraversal(n, adj, start);
  cout << endl;

  return 0;
}

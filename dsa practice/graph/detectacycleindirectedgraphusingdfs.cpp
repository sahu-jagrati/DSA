#include <bits/stdc++.h>
using namespace std;

// t.c-O(V)(component for loop)+O(V+E)dfs for directed graph
// s.c-O(V)(visited)+O(V)(for pathVisited)+O(V)(recursion stack space)
class Solution
{
private:
  bool dfs(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &pathVisited)
  {
    visited[node] = 1;
    pathVisited[node] = 1;

    // traversing neighbour
    for (auto it : adj[node])
    {
      if (!visited[it])
      {
        // if get cycle break and return true
        if (dfs(it, adj, visited, pathVisited) == true)
        {
          return true;
        }
      }
      // if get cycle break and return true
      // if node is already visited but it has to be visited on the same path
      else if (pathVisited[it])
      {
        return true;
      }
    }
    // reaches here mean didn't find cycle
    pathVisited[node] = 0;
    return false;
  }

public:
  bool isCycle(vector<vector<int>> &adj)
  {
    int V = adj.size();
    vector<int> visited(V, 0);
    vector<int> pathVisited(V, 0);

    for (int i = 0; i < V; i++)
    {
      if (!visited[i])
      {
        if (dfs(i, adj, visited, pathVisited) == true)
        {
          return true;
        }
      }
    }
    return false;
  }
};

int main()
{
  int n, m;
  cout << "Enter number of vertices and edges: ";
  cin >> n >> m;
  vector<vector<int>> adj(n); // adj list

  // 0 indexing graph enter
  cout << "Enter edges (u,v): \n";
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v); // because of directed graph
  }
  Solution result;
  bool answer = result.isCycle(adj);
  cout << answer << endl;
  return 0;
}

// you can detect cycle in directed graph by using dfs because topo sort in DAG if topo.size==N then there is no cycle if topo.size<N then there is cycle
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  void dfs(int node, vector<int> &visited, stack<int> &st, vector<vector<int>> &adj)
  {
    visited[node] = 1;

    // traversing neighbour
    for (auto it : adj[node])
    {
      if (!visited[it])
      {
        dfs(it, visited, st, adj);
      }
    }
    st.push(node); // we push in last beacuse stack is LIFO
  }

public:
  vector<int> topoSort(int n, vector<vector<int>> &adj)
  {
    vector<int> visited(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
      if (!visited[i])
      {
        dfs(i, visited, st, adj);
      }
    }
    vector<int> topo;
    while (!st.empty())
    {
      topo.push_back(st.top());
      st.pop();
    }
    return topo;
  }
};

int main()
{

  int n, m;
  cout << "Enter number of vertices and edges: ";
  cin >> n >> m;
  vector<vector<int>> adj(n);
  cout << "Enter edges (u,v): \n";
  // directed acyclic graph
  // 0 based indexing
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  Solution result;
  vector<int> answer = result.topoSort(n, adj);
  if (answer.size() != n)
  {
    cout << "Cycle detected! Topological sort not possible.\n";
    return 0;
  }

  for (auto it : answer)
  {
    cout << it << " ";
  }
  cout << endl;
}
// given a DAG. FInd the shortest path from src(0) to all the vertex.

// we do this by topological sorting using dfs, you can also done by bfs

#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

void topoSort(int node, vector<vector<pair<int, int>>> &adj, vector<int> &vis, stack<int> &st)
{
  vis[node] = 1;
  for (auto neighbour : adj[node])
  {
    int v = neighbour.first;
    if (!vis[v])
    {
      topoSort(v, adj, vis, st);
    }
  }
  st.push(node);
}

// time complexity-O(n+m)(for topo sort)+O(n+m)(for distance while loop)
// space complexity=O(n)(recursion stack space)+O(n)(for stack)+O(n)(for visted array)+O(n)(for distance array)
vector<int> shortestPath(int n, int m, vector<vector<pair<int, int>>> &adj, int src)
{
  // topo sort
  vector<int> vis(n, 0);
  stack<int> st;
  for (int i = 0; i < n; i++)
  {
    if (!vis[i])
    {
      topoSort(i, adj, vis, st);
    }
  }
  // distance array
  vector<int> dist(n, 1e9);
  dist[src] = 0;
  while (!st.empty())
  {
    int node = st.top();
    st.pop();

    if (dist[node] != 1e9)
    {
      for (auto neighbour : adj[node])
      {
        int v = neighbour.first;
        int wt = neighbour.second;
        if (dist[node] + wt < dist[v])
        {
          dist[v] = dist[node] + wt;
        }
      }
    }
  }
  return dist;
}

// graph must be directed acyclic
int main()
{
  int n, m;
  cout << "Enter number of vertices and edges: ";
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n);
  cout << "Enter edges and weight (u,v,wt): \n";
  for (int i = 0; i < m; i++)
  {
    int u, v, wt;
    cin >> u >> v >> wt;
    adj[u].push_back({v, wt});
  }
  int src;
  cout << "Enter source node: ";
  cin >> src;

  vector<int> result = shortestPath(n, m, adj, src);
  for (auto it : result)
  {
    if (it == 1e9)
    {
      cout << "INF";
    }
    else
    {
      cout << it << " ";
    }
  }
  cout << endl;
  return 0;
}
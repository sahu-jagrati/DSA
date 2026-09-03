// given a directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of a graph is labelled with distinct integer in the range 0 to V-1.

// A node is a terminal node if there are no outgoing edges(i.e outdegree=0). A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

// Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order

// for understanding question see notes
// observation-
// any one that is a part of cycle can never be safe node.
// any one who is connected to cycle by outgoing edges also can never be safe node

// this question is similar to detect a cycle in directed graph using dfs
// we also do by bfs later here we do by dfs

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  bool dfs(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &pathVisited, vector<int> &check)
  {
    visited[node] = 1;
    pathVisited[node] = 1;
    check[node] = 0;

    // traversing neighbour
    for (auto it : adj[node])
    {
      if (!visited[it])
      {
        // if get cycle break and return true
        if (dfs(it, adj, visited, pathVisited, check) == true)
        {
          check[node] = 0;
          return true;
        }
      }
      // if get cycle break and return true
      else if (pathVisited[it])
      {
        check[node] = 0;
        return true;
      }
    }
    // reaches here mean didn't find cycle
    check[node] = 1;
    pathVisited[node] = 0;
    return false;
  }

public:
  vector<int> eventualSafeNodes(vector<vector<int>> &adj)
  {
    int V = adj.size();
    vector<int> visited(V, 0);
    vector<int> pathVisited(V, 0);
    // for nodes that are safe to check
    vector<int> check(V, 0);
    vector<int> safeNodes;

    for (int i = 0; i < V; i++)
    {
      if (!visited[i])
      {
        dfs(i, adj, visited, pathVisited, check);
      }
    }
    for (int i = 0; i < V; i++)
    {
      if (check[i] == 1)
        safeNodes.push_back(i);
    }
    return safeNodes;
  }
};

int main()
{
  int n, m;
  cout << "Enter number of vertices and edges: ";
  cin >> n >> m;
  vector<vector<int>> adj(n); // adj list

  // directed graph
  // 0 indexing graph enter
  cout << "Enter edges (u,v): \n";
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v); // because of directed graph
  }
  Solution result;
  vector<int> answer = result.eventualSafeNodes(adj);

  for (auto it : answer)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}

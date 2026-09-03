// Bridges in graph- Using Tarjan's Algorithm of time in and low time
// the concept of a “bridge” (as used in Tarjan’s algorithm) is for undirected (then we know after removing which edge we get component)  graphs only.

// In an undirected graph:

// A bridge is an edge whose removal increases the number of connected components.

// Tarjan’s condition

// low[it] > tin[node]

// relies on the fact that edges work both ways.
// In a directed graph:

// Reachability is one-way

// Removing an edge may:

// break reachability in one direction

// but not affect reachability in reverse

// So the idea of “connected components” and “back edge” is fundamentally different

// ➡️ Therefore, Tarjan’s bridge algorithm does NOT apply to directed graphs.

// bridge-if we remove any edge in the graph then the graph is divided into two or more than two component

// Tarjan's algo use some logic in dfs-
// we use two array-
// tin[]=array that store time of insertion during dfs
// low[]= min lowest time insertion of all adjacent nodes apart from parent.

// tarjan condition-
// low[it] > tin[node]

// question in leetcode - critical connections in a network
// There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

// A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

// Return all critical connections(i.e bridges) in the network in any order

#include <bits/stdc++.h>
using namespace std;

// n and V both represent total number of vertices n=V and E represent total number of edges
// s.c-O(n*3)(for visites,tin,low)+O(V+2E)(for adj to create undirected graph), bridges does not use in solve problem it only store answer so
// t.c-O(V+2E) because we use dfs traversal for undirected graph

class Solution
{
private:
  int timer = 1; // or start from 0
  void dfs(int node, int parent, vector<int> &visited, vector<vector<int>> &adj, vector<int> &tin, vector<int> &low, vector<vector<int>> &bridges)
  {
    visited[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    // neighbour
    for (auto it : adj[node])
    {
      // if neighbour is parent of node which is  already visited so leave it because of definition of low[] array
      if (it == parent)
        continue;
      // if neighbour not visited
      if (visited[it] == 0)
      {
        dfs(it, node, visited, adj, tin, low, bridges);
        // after completion when we  back track the node then
        low[node] = min(low[node], low[it]);

        // // 'node' is visited first and 'it' is its DFS child.
        // If 'it' cannot reach back to 'node' or any ancestor, then (node-it) is a bridge.
        // node visited first → 'it' is DFS child; no back-edge from it → bridge
        // Child cannot go back to parent or above → edge is a bridge

        //         Means:

        // node was visited before it

        // From it or its subtree:

        // you cannot reach back to node

        // and cannot reach any ancestor of node

        // Therefore, removing edge (node, it) disconnects the graph

        // ➡️ Edge (node, it) is a bridge

        if (low[it] > tin[node])
        {
          // then there is bridge
          bridges.push_back({it, node});
        }
      }
      // if visited neighbour already
      else
      {
        low[node] = min(low[node], low[it]);
      }
    }
  }

public:
  // n is number of vertices/server
  vector<vector<int>> bridges(int n, vector<vector<int>> &edges)
  {
    // given edges vector so we have to build the undirected graph
    vector<vector<int>> adj(n);
    for (auto it : edges)
    {
      adj[it[0]].push_back(it[1]);
      adj[it[1]].push_back(it[0]);
    }
    vector<int> visited(n, 0);
    vector<int> tin(n);
    vector<int> low(n);
    vector<vector<int>> bridges;
    // initially parent of 0 is -1, 0-based indexing
    dfs(0, -1, visited, adj, tin, low, bridges); // only one time call because all vertices are connected to each by undirected edges and we have to find bridge to get component so that's why no component initial
    return bridges;
  }
};

// input - undirected connected graph
int main()
{
  int n, m;
  cout << "Enter the number of vertices and edges: ";
  cin >> n >> m;
  vector<vector<int>> edges(m, vector<int>(2));
  cout << "Enter the edges: ";
  for (int i = 0; i < m; i++)
  {
    cin >> edges[i][0] >> edges[i][1];
  }
  Solution result;
  cout << "Number of bridges in the graph: " << endl;
  vector<vector<int>> answer = result.bridges(n, edges);
  for (auto it1 : answer)
  {
    for (auto it : it1)
    {
      cout << it << " ";
    }
    cout << endl;
  }
  return 0;
}
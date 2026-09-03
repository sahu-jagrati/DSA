// Articulation point in graph-Nodes on whose removal the graph breaks into two or more than two components

// in bridge we remove edge here we remove the nodes

// articulation point is defined on undirected graph only because articulation is somehow slight change of tarjan;s algo
// Tarjan’s algorithm (using tin[] and low[]) works only for undirected graphs.
// tin[] and low[] relies on the fact that edges work both ways.

// In a directed graph:

// Connectivity is one-way

// Removing a vertex may affect reachability in complex ways

// The concept of “connected components” is different

// ❌ So articulation point (classic definition) does not apply to directed graphs

// For articulation there is slight change in definition of tin and low arrray
// tin[] - store the time of insertion during dfs
// low[]- min lowest time insertion of all adjacent nodes apart from parent and visited nodes here visited nodes is extra which is not in bridge concept

// here condition is
// low[it]>=tin[node] && parent !=-1 is condition  // slightly change from tarjan's algo
// parent!=-1 beacuse for starting point there is a case also when starting point has only one child, so removing starting point does not provide two or more components for this after removing is still single component so for starting point with parent=-1 we count child if child is more than 1 then it is articulation point otherwise for single child not articultion point
// this is articulation point

// Given an undirected connected graph V vertices and adj list adj. You are required to find all the vertices removing(and edges through it) disconnects the graph into 2 or more components.

// Note- Indexing is zero based i.e nodes numbering from 0 to V-1. There might be loops present in the graph.

// Return a list containing all the vertices removing which turn the graph into 2 or more disconnected components in sorted order. If there are no such vertices then returns a list containing -1.

// for more details of solution see notes
#include <bits/stdc++.h>
using namespace std;

// n and V both represent total number of vertices n=V and E represent total number of edges
// t.c-O(V+2E) dfs for undirected graph
// s.c-O(V*4)(for visited,mark,tin,low) and ans only store answer not solve the problem
class Solution
{
private:
  int timer = 0; // or start from 1
  void dfs(int node, int parent, vector<int> &visited, vector<vector<int>> &adj, vector<int> &tin, vector<int> &low, vector<int> &mark)
  {
    visited[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    // traverse the neighbour
    int child = 0;
    for (auto it : adj[node])
    {
      // if neighbour is parent of node which is  already visited so leave it because of definition of low[] array
      if (it == parent)
        continue;
      // if neighbour not visited
      if (!visited[it])
      {
        dfs(it, node, visited, adj, tin, low, mark);
        // after completion when we  back track the node then
        low[node] = min(low[node], low[it]);
        // slightly change from tarjan's algo
        // parent!=-1 beacuse for starting point there is a case also when starting point has only one child, so removing starting point does not provide two or more components for this after removing is still single component so for starting point with parent=-1 we count child if child is more than 1 then it is articulation point otherwise for single child not articultion point
        // this is articula
        // this is articulation point
        if (low[it] >= tin[node] && parent != -1)
        {
          mark[node] = 1;
        }
        child++;
      }
      // if neighbour visited already
      // this time there is change in definition of low[] array
      // back edge case: update low using discovery time of visited node

      // visited guy you don't take something on the top of it why because you came by that path so if that's removed you cannot go back that's why you just take time of insertion and not the lowest it it's visited
      else
      {
        low[node] = min(low[node], tin[it]); // here we compare with tin[it] not low[it] definition of low[] array not takes visited nodes
      }
    }
    if (child > 1 && parent == -1)
    {
      mark[node] = 1;
    }
  }

public:
  vector<int> articulationPoints(int V, vector<vector<int>> &adj)
  {
    vector<int> visited(V, 0);
    vector<int> tin(V);
    vector<int> low(V);
    // for marking articulation point because we don't print same articulation point more than one times for different component
    vector<int> mark(V, 0);
    for (int i = 0; i < V; i++)
    {
      if (!visited[i])
      {
        dfs(i, -1, visited, adj, tin, low, mark);
      }
    }
    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
      if (mark[i] == 1)
      {
        ans.push_back(i);
      }
    }
    if (ans.size() == 0)
      return {-1};
    return ans;
  }
};

// input undirected connected graph
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
    // because of undirected graph
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  Solution result;
  vector<int> answer = result.articulationPoints(n, adj);
  cout << "Articulation point is: ";
  for (auto it : answer)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}
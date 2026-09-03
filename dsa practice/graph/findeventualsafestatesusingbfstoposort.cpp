// find eventual safe states using bfs topo sort
// we already done by dfs so description of question is in that
// for a given graph terminal nodes are those who have outdegree=0 and all terminal nodes are safe nodes

// as in topo sort we do by indegree

// so we reverse the all edges of given graph so that for reverse graph terminal nodes are those who have indegree=0 and we apply topo sort algo in reverse graph in same manner

#include <bits/stdc++.h>
using namespace std;

// time complexity-O(n+m)(bfs for directed graph)+O(n)(for push nodes with 0 indegree)+O(n)(for indegree+reversing graph)+O(sorting safe node)
// space complexity-O(n)(queue)+O(n)(topsort)+O(n)(indegree array)+O(reverse graph space)+O(size of safe node)
class Solution
{
public:
  vector<int> eventualSafeNodes(int V, vector<vector<int>> &adj)
  {
    // for reverse graph adjlist
    vector<vector<int>> adjReverse(V);
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
      // traverse neighbour of original graph - having edge from i to it, now in reverse graph edge is from it to i
      for (auto it : adj[i])
      {
        adjReverse[it].push_back(i);
        // calculate indegree for reverse graph
        indegree[i]++;
      }
    }
    queue<int> q;
    // for reverse graph we do topo sort
    for (int i = 0; i < V; i++)
    {
      if (indegree[i] == 0)
      {
        q.push(i);
      }
    }
    vector<int> safeNode;
    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      safeNode.push_back(node);

      // traverse neighbour in reverse graph
      for (auto it : adjReverse[node])
      {
        indegree[it]--;
        if (indegree[it] == 0)
        {
          q.push(it);
        }
      }
    }
    sort(safeNode.begin(), safeNode.end());
    return safeNode;
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
  vector<int> answer = result.eventualSafeNodes(n, adj);

  for (auto it : answer)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}
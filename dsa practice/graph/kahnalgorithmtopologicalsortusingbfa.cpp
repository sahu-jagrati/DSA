// kahn's algorithm is same in book use modify bfs in this instead of visited array we use indegree array
//  topological sort always apply in DAG(directed acyclic graph)
//  in every DAG G there is a node v with no incoming edges

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// time complexity-O(n+m)(bfs for directed graph)+O(n)(for push nodes with 0 indegree)+O(n)(for indegree)
// space complexity-O(n)(queue)+O(n)(topsort)+O(n)(indegree array)
vector<int> topoSortUsingModifyBFS(int n, vector<vector<int>> &adj)
{
  vector<int> inDegree(n, 0);
  for (int i = 0; i < n; i++)
  {
    for (auto neighbour : adj[i])
    {
      inDegree[neighbour]++; // just like hashmap
    }
  }
  queue<int> q;
  vector<int> topo;
  // push node in queue which has indegree =0
  for (int i = 0; i < n; i++)
  {
    if (inDegree[i] == 0)
      q.push(i);
  }
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    topo.push_back(node);

    // travel to neighbour,reduce indegree of neighbour, if become equal to zero then push in queue
    for (auto neighbour : adj[node])
    {
      inDegree[neighbour]--;
      if (inDegree[neighbour] == 0)
        q.push(neighbour);
    }
  }
  return topo;
}
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
  vector<int> result = topoSortUsingModifyBFS(n, adj);
  if (result.size() != n)
  {
    cout << "Cycle detected! Topological sort not possible.\n";
    return 0;
  }

  for (auto it : result)
  {
    cout << it << " ";
  }
  cout << endl;

  return 0;
}
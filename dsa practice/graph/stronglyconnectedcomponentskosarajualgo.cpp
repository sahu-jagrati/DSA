// Kosaraju's Algorithm is valid only for directed graph

// Given a directed graph with V vertices and E edges. Find the number of strongly connected components(SCC) in the graph.
// SCC definition is if we start from any one node in that component we can reach to every other node of that component is called SCC
// we have to find Number of SCC and print all SCC

// thought process is that for given directed graph if we run dfs we can travel each node of the graph because each scc is connected but when we reverse the graph after that dfs happens only in individual scc. we cann;t travel from one scc to other scc sfter reverse the graph

// so Kosaraju's Algo is-
// step -1 Sort all the edges according to finishing time by using dfs to know which nodes lie in scc1 and where we have to start we store them in stack so top guy finish in last is the elt of scc1
// step-2 reverse the graph
// step -3 do dfs by taking top elt of the stack i.e guy that finish in last
// we know after reversing dfs happens only in individual scc so number of times dfs call is equal to number of scc

#include <bits/stdc++.h>
using namespace std;

// t.c-
// step -1 dfs takes O(V+E) for directed graph we know
// step-2 reverse the graph-O(V+E)
// step -3 agian dfs O(V+E)
// total O(V+E)*3=O(V+E)

// s.c-O(V)(for stack)+O(V)(for visited array)+O(V+E)(for adjReverse)+O(no.of scc)(for ans vector to print all scc)
class Solution
{
private:
  void dfs(int node, vector<int> &visited, vector<vector<int>> &adj, stack<int> &st)
  {
    visited[node] = 1;
    // go neighbour
    for (auto it : adj[node])
    {
      if (!visited[it])
      {
        dfs(it, visited, adj, st);
      }
    }
    st.push(node);
  }
  void dfsReverse(int node, vector<int> &visited, vector<vector<int>> &adjReverse, vector<int> &temp)
  {
    visited[node] = 1;
    temp.push_back(node);
    for (auto it : adjReverse[node])
    {
      if (!visited[it])
      {

        dfsReverse(it, visited, adjReverse, temp);
      }
    }
  }

public:
  pair<int, vector<vector<int>>> kosarajuAlgorithm(int V, vector<vector<int>> &adj)
  {
    vector<int> visited(V, 0);

    // step -1
    // dfs to sort all the edges according to finish time by this we know from where we have to start SCC1, who finish in last is the member of SCC1
    stack<int> st; // store in LIFO so top guy is the first member of SCC1
    for (int i = 0; i < V; i++)
    {
      if (!visited[i])
      {
        dfs(i, visited, adj, st);
      }
    }

    // step -2 reverse the grpah
    vector<vector<int>> adjReverse(V);
    for (int i = 0; i < V; i++)
    {
      // we also unvisit the node because we visit again when we do dfs on stack node for reverse graph
      visited[i] = 0;
      for (auto it : adj[i])
      {
        adjReverse[it].push_back(i);
      }
    }
    // start  dfs in stack top and count scc
    int scc = 0;
    vector<vector<int>> ans;
    while (!st.empty())
    {
      int node = st.top();
      st.pop();

      if (!visited[node])
      {
        vector<int> temp;

        scc++;
        dfsReverse(node, visited, adjReverse, temp);
        ans.push_back(temp);
      }
    }
    return {scc, ans}; // return no.of scc and print all scc
  }
};

// directed connected graph
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
  pair<int, vector<vector<int>>> answer = result.kosarajuAlgorithm(n, adj);
  cout << "Number of strongly connected components: " << answer.first << endl;
  cout << "Print all scc is: ";
  for (auto it1 : answer.second)
  {
    for (auto it : it1)
    {
      cout << it << " ";
    }
    cout << endl;
  }

  return 0;
}
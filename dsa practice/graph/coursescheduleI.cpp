// given There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// prerequisites is an array of pair of courses
// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

// in simple terms-
// check if the prerequisites relatioships form a cycle
// if there is no cycle,  you can finish all coursess- return true
// if there is a cycle, some course depend on each other forever- return false

// this is same to topo sort - apply in DAG- if there is an edge from u to v than u appears befor v.

// same here if 0 is depend on 1 than there is edge from 1 to 0 i.e [0,1]

// also done by detect cycle in directed graph using dfs
// or topo sort using bfs for detect cycle

// here we use  detect cycle in directed graph using dfs
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
        if (dfs(it, adj, visited, pathVisited) == false)
        {
          return false;
        }
      }
      // if get cycle break and return true
      // if node is already visited but it has to be visited on the same path
      else if (pathVisited[it])
      {
        return false;
      }
    }
    // reaches here mean didn't find cycle
    pathVisited[node] = 0;
    return true;
  }

public:
  // N-numcourses
  bool canFinish(int N, vector<vector<int>> prerequisites)
  {
    // build graph from prerequisites
    vector<vector<int>> adj(N);
    // for(auto &p:prerequisites){
    //     int a=p[0];
    //     int b=p[1];
    //     adj[b].push_back(a);  // b->a
    // }
    for (auto p : prerequisites)
    {
      adj[p[1]].push_back(p[0]); // edge btw p[1] to p[0]
    }
    vector<int> visited(N, 0);
    vector<int> pathVisited(N, 0);

    for (int i = 0; i < N; i++)
    {
      if (!visited[i])
      {
        if (dfs(i, adj, visited, pathVisited) == false)
        {
          return false;
        }
      }
    }
    return true;
  }
};

// input type-{[1,0],[2,1],[3,2]}
int main()
{
  int numCourses;
  cout << "Enter number of total courses: ";
  cin >> numCourses;
  int n;
  cout << "Enter number of  prerequisites pairs: ";
  cin >> n;
  vector<vector<int>> prerequisites(n, vector<int>(2));
  cout << " Enter courses for prerequisites: ";
  for (int i = 0; i < n; i++)
  {

    cin >> prerequisites[i][0] >> prerequisites[i][1];
  }

  Solution result;
  bool answer = result.canFinish(numCourses, prerequisites);
  cout << answer << endl;
  return 0;
}
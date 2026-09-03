// in this you have to return the ordering of course
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

// this we done by topo sort using bfs

#include <bits/stdc++.h>
using namespace std;

// time complexity-O(n+m)(bfs for directed graph)+O(n)(for push nodes with 0 indegree)+O(n)(for indegree)
// space complexity-O(n)(queue)+O(n)(topsort)+O(n)(indegree array)
class Solution
{
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
  {
    // build graph
    vector<vector<int>> adj(numCourses);
    for (auto &p : prerequisites)
    {
      int a = p[0];
      int b = p[1];
      adj[b].push_back(a); // b->a
    }
    vector<int> indegree(numCourses, 0);

    // making indegree array
    for (int i = 0; i < numCourses; i++)
    {
      for (auto neighbour : adj[i])
      {
        indegree[neighbour]++;
      }
    }

    queue<int> q;
    vector<int> topo;
    for (int i = 0; i < numCourses; i++)
    {
      if (indegree[i] == 0)
      {
        q.push(i);
      }
    }
    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      topo.push_back(node);
      for (auto neighbour : adj[node])
      {
        indegree[neighbour]--;
        if (indegree[neighbour] == 0)
        {
          q.push(neighbour);
        }
      }
    }
    if (topo.size() == numCourses)
      return topo;
    return {};
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
  vector<int> answer = result.findOrder(numCourses, prerequisites);
  for (auto it : answer)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}
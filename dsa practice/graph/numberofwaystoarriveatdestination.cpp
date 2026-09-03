// You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

// You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

// Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

// logic of saying, the number of times we get shortest path to destination is answer is actually wrong. We have to track back and notice how many time did the node actually arrived by other paths also, because for arrived at one node we can have different path so we cann't say that we come to node only from one way directly

// as usual we apply djikstra for shortest path, here we have  no negative cycle and edge

// we have to count ways also to reach that node how many times from different path so with distance array we have way array
// we use priority queue because here we have different edge weight

#include <bits/stdc++.h>
using namespace std;

// t.c.= ElogV for djikstra algo also we use PQ not queue where E is total number of edges and V is total number of nodes and V=n
// s.c-O(n)(for dist array)+O(n)(for ways array)+O(n)(in worst for PQ)
class Solution
{
public:
  int countPaths(int n, vector<vector<int>> &roads)
  {
    vector<vector<pair<int, long long>>> adj(n);
    // build graph
    for (auto it : roads)
    {
      adj[it[0]].push_back({it[1], it[2]});
      adj[it[1]].push_back({it[0], it[2]});
    }

    // {dist,node}
    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<pair<long long, int>>>
        pq;
    vector<int> ways(n, 0);
    vector<long long> dist(n, LLONG_MAX);
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0});

    int mod = (int)(1e9 + 7);
    while (!pq.empty())
    {
      long long dis = pq.top().first;
      int node = pq.top().second;
      pq.pop();

      if (dis > dist[node])
        continue; // no need to go neighbour

      // traverse neighbour

      for (auto it : adj[node])
      {
        int adjnode = it.first;
        long long edW = it.second;
        // first time
        if (dis + edW < dist[adjnode])
        {
          dist[adjnode] = dis + edW;
          pq.push({dis + edW, adjnode});
          ways[adjnode] = ways[node] % mod;
        }
        // second or more time visit
        else if (dis + edW == dist[adjnode])
        {
          ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
        }
      }
    }
    return ways[n - 1] % mod;
  }
};

// input type - n=7
// roads-{[0,1,2],[0,6,7],[0,4,5],[1,2,3],[1,3,3],[2,5,1],[3,5,1],[3,6,3],[4,6,2],[5,6,1]}

int main()
{
  int n;
  cout << "Enter the number of nodes: ";
  cin >> n;
  int m;
  cout << "Enter the size of roads array: ";
  cin >> m;
  vector<vector<int>> roads(m, vector<int>(3));
  cout << "Enter the value of roads array (positive value only): ";
  for (int i = 0; i < m; i++)
  {
    cin >> roads[i][0] >> roads[i][1] >> roads[i][2];
  }
  Solution result;
  cout << result.countPaths(n, roads) << endl;
  return 0;
}
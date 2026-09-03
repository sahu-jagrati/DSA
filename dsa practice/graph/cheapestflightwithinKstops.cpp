// there are n cities and m edges connected by some number of flights. You are given an array flights where flights[i]=[fromi,toi,pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
// You are also given three integers src,destination,& K, return the cheapest price from src to destination with atmost K stops

// we want shortest path from sc to destionation with atmost K stops
// so we think about djikstra algo but we don't use djikstra by giving priority to cost-{cost,node,stops} because
// whenever we store in terms of cost, when we reached to destination is wrong
// so we have to store everything in terms of stop-{stop,node,cost}
// cost is not first priority of judgement, stops is first priority of judgement

// hence we give stop as priority , as we use priority queue in djikstra to get minimal distance at top because edges have different edge weight so going from one node to other we have different edge weight but here we increase stop by +1  so, going from one node to other we only increse by 1 so if we use queue instead of priority queue then also we get stop in queue in increasing order so there is no need to use of priority queue, we use queue here which reduce logV factor also

// as usual we apply djikstra for shortest path, here we have  no negative cycle and edge
// we can use priority queue but here priority queue does not required because stop increasing by only +1 not different for city to city
// so we take queue which do this and reduce logV factor also. since increase is constant also so we use queue not PQ which give shortest number of stops

#include <bits/stdc++.h>
using namespace std;

// for djikstra algo t.c-ElogV
// we use djikstra algo but we don't use priority queue, instead of this we use queue which reduce logV factor of djikstra algo so t.c is only E where E is total number of edges
// t.c - E - total number of edges - filghts.size()
// s.c- O(n)(for cost array)+O(adj.size=n+E)+O(queue size=E in worst case) = O(n+E)
class Solution
{
public:
  int cheapestFlight(int n, vector<vector<int>> &flights, int src, int dest, int K)
  {
    // n is number of cities, not flights size
    // build the graph
    vector<vector<pair<int, int>>> adj(n);
    for (auto it : flights)
    {
      adj[it[0]].push_back({it[1], it[2]});
    }
    vector<int> cost(n, 1e9); // cost array similar to distance array that we make in similar question
    cost[src] = 0;
    //{stops,{node,cost}}
    // not use PQ because of constant increasing in stops
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});

    while (!q.empty())
    {
      auto it = q.front();
      int stop = it.first;
      int node = it.second.first;
      int cst = it.second.second;
      q.pop();

      if (stop > K)
        continue; // no need to go for adjacent neighbour
      // traverse to neighbour
      for (auto iter : adj[node])
      {
        int adjnode = iter.first;
        int edW = iter.second;

        if (cst + edW < cost[adjnode] && stop <= K)
        {
          cost[adjnode] = cst + edW;
          q.push({stop + 1, {adjnode, cst + edW}});
        }
      }
    }
    if (cost[dest] == 1e9)
    {
      return -1;
    }
    return cost[dest];
  }
};

// input type-n=4,src=0, dest=3
// flights-{{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}}

int main()
{
  int n;
  cout << "Enter the number of cities: ";
  cin >> n;
  int m;
  cout << "Enter th flights size: ";
  cin >> m;
  vector<vector<int>> flights(m, vector<int>(3));
  cout << "Enter the value for flights array ([fromcity,tocity,cost]): ";
  for (int i = 0; i < m; i++)
  {
    cin >> flights[i][0] >> flights[i][1] >> flights[i][2];
  }
  int src, dest;
  cout << "Enter the source and destination city: ";
  cin >> src >> dest;

  int K;
  cout << "Enter the number of stops: ";
  cin >> K;
  Solution result;
  cout << result.cheapestFlight(n, flights, src, dest, K) << endl;

  return 0;
}
// given There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

// Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

// Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

// given undirected graph, we have to find shortest distance from each node to each node and it is atmost threshold distance and count for each city that how many city they can be reachable through some path and whose distance is atmost threshold distance
// take the city that reach to other cities less
// if there are multiple cities with same number of city that they travel then take the city that is greater in number

// which algo we use
// we have to find shortest distance from each node to each node so we use floyd warshall algo- multiple src alog

// we can be done using dijkstra as well for each node run dijkstra

// first we use floyd warshall here

#include <bits/stdc++.h>
using namespace std;

// t.c-O(edges.size)(for dist create loop)+O(n)(for node to node itself dist)+O(n^3)(main loop)+O(n^2)(for city count)=O(n^3)
// s.c-O(n^2)for dist array
class Solution
{
public:
  int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
  {
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    // because we have bidirectional weighted  graph
    for (auto it : edges)
    {
      dist[it[0]][it[1]] = it[2];
      dist[it[1]][it[0]] = it[2];
    }
    for (int i = 0; i < n; i++)
      dist[i][i] = 0;
    for (int k = 0; k < n; k++)
    {
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < n; j++)
        {
          if (dist[i][k] == 1e9 || dist[k][j] == 1e9)
            continue;
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
    int cntCity = n; // initially i.e how many city with smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold,
    int cityNo = -1; // to take city with greatest number if multiple city occur

    for (int city = 0; city < n; city++)
    {
      int cnt = 0;
      for (int adjCity = 0; adjCity < n; adjCity++)
      {
        if (dist[city][adjCity] <= distanceThreshold)
        {
          cnt++;
        }
      }
      if (cnt <= cntCity)
      {
        cntCity = cnt;
        cityNo = city;
      }
    }
    return cityNo;
  }
};

// ipnut type- n=4 number of city
// m=4 edge array size
// edge array-{[0,1,3],[1,2,1],[2,3,1],[3,1,4]} // bidirectional weighted graph we have
// threshold distance =4
// answer of this is 3rd city with 0 based indexing
int main()
{
  int n;
  cout << "Enter the number of city: ";
  cin >> n;
  int m;
  cout << "Enter the size of edge array: ";
  cin >> m;
  vector<vector<int>> edges(n, vector<int>(3));
  cout << "Enter the value for edge array (we have city so positive value distance): ";
  for (int i = 0; i < n; i++)
  {
    cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
  }
  int thresholddistance;
  cout << "Enter the threshold distance: ";
  cin >> thresholddistance;

  Solution result;
  cout << "City with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold is " << result.findTheCity(n, edges, thresholddistance) << endl;
  return 0;
}

// dijkstra algo for each node

// t.c for dijkstra is ElogV
// here we run dijkstra for each node so V*ElogV
// E is total number of edges - m*2 where m is edges array size and graph is bidirectional so 2 multiply and V=n
// t.c- O(n*((2*m*log(n))+n)(for dijkstra loop and cnt loop)+ O(m)(for making adj list)
// s.c-O(n)(for dist array)+O(adj.size)

// class Solution
// {
// public:
//   int findCity(int n, vector<vector<int>> &edges, int distanceThreshold)
//   {
//     // adj list
//     vector<vector<pair<int, int>>> adj(n);
//     for (auto it : edges)
//     {
//       adj[it[0]].push_back({it[1], it[2]});
//       adj[it[1]].push_back({it[0], it[2]});
//     }

//     // {distance,node}
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

//     int cityNo = -1;
//     int cityCount = 1e9; // or can be take n or Max but greater than or equal to n then we

//     // for each node run dijkstra
//     for (int i = 0; i < n; i++)
//     {
//       // distance array
//       vector<int> dist(n, 1e9);
//       dist[i] = 0;
//       pq.push({0, i});
//       while (!pq.empty())
//       {
//         int dis = pq.top().first;
//         int node = pq.top().second;
//         pq.pop();

//         // traverse the neighbour
//         for (auto it : adj[node])
//         {
//           int adjnode = it.first;
//           int edw = it.second;
//           if (dis + edw < dist[adjnode])
//           {
//             dist[adjnode] = dis + edw;
//             pq.push({dis + edw, adjnode});
//           }
//         }
//       }
//       int count = 0;
//       // for city =i;
//       for (int adjcity = 0; adjcity < n; adjcity++)
//       {
//         if (dist[adjcity] < distanceThreshold)
//         {
//           count++;
//         }
//       }
//       if (count <= cityCount)
//       {
//         cityCount = count;
//         cityNo = i;
//       }
//     }
//     return cityNo;
//   }
// };
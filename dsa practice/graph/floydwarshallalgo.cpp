// given the problem is to find the shortest distance between every pair of vertices in a given edge- weighted directed graph. The graph is represnted as an adjacency matrix, and the matrix denotes the weight of the edges (if it exists) else -1.
// Do it in place means don't make any cost matrix do in given adjacency matrix. Also there is no mention of negative cycle so remain it.

// proper floydwarshall algo we do below

#include <bits/stdc++.h>
using namespace std;

// t.c -O(n^3) for main loop +O(n^2)for temporary conversion loop=O(n^3)
// s.c-O(n^2) for matrix because we use matrix to solve the problem so it also consider as a space
// sapce that is we used to solve a problem is consider for s.c
class Solution
{
public:
  void shortest_distance(vector<vector<int>> &matrix)
  {
    int n = matrix.size();

    // we convert -1 into 1e9
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (matrix[i][j] == -1)
        {
          matrix[i][j] = (int)1e9;
        }
        if (i == j)
          matrix[i][j] = 0;
      }
    }
    for (int k = 0; k < n; k++)
    {
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < n; j++)
        {
          matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
        }
      }
    }

    // to detect negative cycle
    // also we convert matrix in 1e9 so no problem with -1
    for (int i = 0; i < n; i++)
    {
      if (matrix[i][i] < 0)
      {
        cout << "Negative cycle exists." << endl;
      }
    }
    // convert back to remaining 1e9 to -1
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (matrix[i][j] == 1e9)
        {
          matrix[i][j] = -1;
        }
      }
    }
  }
};

// input type - given adjacency matrix-e.g.- {{0,1,43},{1,0,6},{-1,-1,0}}

// e.g.- {{0,2,-1,-1},{1,0,3,-1},{-1,-1,0,-1},{3,5,4,0}}

// for node to node itself we can say distance =0 and -1 represent there is no edge btw that two nodes

// the input is adjacency matrix that we used to store graph

// we can have directed or undirected graph both

int main()
{
  int n;
  cout << "Enter the size of matrix: ";
  cin >> n;
  vector<vector<int>> matrix(n, vector<int>(n));
  cout << "Enter the value for matrix: ";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> matrix[i][j];
    }
  }
  Solution result;
  result.shortest_distance(matrix);
  cout << "Shortest path between every node is: \n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}

// proper floyd warshall algo-

// we used this algo for shortest path with multi source

// multi source means here we find shortest path from each node to each node

// while in djikstar or bellman ford we find shortest path from source node to for remaining node but in this algo we find shortest path between each node to each node

// so there are multiple src
// also detect negative cycle

// intution is simple brute -
// go via every vertex/node
// i.e like example go 0 to 1 via each node given in graph
// like we have to find dist[i][j] then we go i to j via each node say that node k
// dist[i][j]=min(dis[i][j],dis[i][k]+dis[k][j])
// now k can directly that node or k also we get by some different path
// we do like something that is precomputed like dynamic programming

// here we have directed graph so we store it in adjacency matrix called cost
// in cost if there is no edge between node then give it 1e9
// and for node to node give it 0
// for undirected graph conver it in directed graph

// now we first move via vertex 0 and chnage distance in cost matrix, then via 1 change distance in same cost matrix in which we apply via 0, then via 2 and so on and in last we get matrix in which we have shortest path btw every node

// how to detect negative cycle-
// for node to node itself cost[i][i]=0 always
// so if the cost of any node to node itself is <0 i.e cost[i][i]<0 then there is negative cycle exist

// for detail description see notes

// if given ajcanceny matrix then make cost matrix or given graph then build cost matrix

// djiksta can't detect -ve cycle
// but if no negative cycle then apply djikstra for each individual node and t.c-V*(ElogV), where ElogV for djikstra and V for each node

// given adjaceecy matrix
// vector<vector<int>> cost(n, vector<int>(n));
// for (int i = 0; i < n; i++)
// {
//   for (int j = 0; j < n; j++)
//   {
//     if (adj[i][j] == -1)
//     {
//       cost[i][j] = (int)1e9;
//     }
//     if (i == j)
//       cost[i][j] = 0;
//   }
// }

// // main loop
// for (int via = 0; via < n; via++)
// {
//   for (int i = 0; i < n; i++)
//   {
//     for (int j = 0; j < n; j++)
//     {
//       cost[i][j] = min(cost[i][j], cost[i][via] + cost[via][j]);
//     }
//   }
// }

// // to detect negative cycle
// for (int i = 0; i < n; i++)
// {
//   if (cost[i][i] < 0)
//   {
//     cout << "negative cycle exist" << endl;
//   }
// }

// return cost; // matrix that have shortest path btw each node
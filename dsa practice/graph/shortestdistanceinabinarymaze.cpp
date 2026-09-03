// given a n*m grid where elt can either 0 or 1. You need to find the shortest distance btw a given source cell to a destination cell. The path can onlt be created out of a cell if its value is 1.
// If the path is not possible btw source cell and destination cell then return -1.
// also we move only in four direction - top,right,left,bottom

// moving from one cell to another cell, you move distance =1.

// for shortest path we know djikstra algo, which is apply using priority queue or set
// as usual we apply djikstra for shortest path, here we have  no negative cycle and edge
// we use priority queue in djikstra to get minimal distance at top because edges have different edge weight so going from one node to other we have different edge weight but here we have same edge weight which is 1 so, going from one node to other we only increse by 1 so if we use queue instead of priority queue then also we get distance in queue in increasing order so there is no need to use of priority queue, we use queue here which reduce logV factor also. since increase is constant also so we use queue not PQ

// there is edge case also when source cell = destination cell then return 0
// also DP won't work as the value on any cell is path dependent, so it won't work. It works in the maze which has two direction movements in the right and bottom, & the future cells would never be visited.

// here we have 2D matrix so distance array is also 2D matrix

#include <bits/stdc++.h>
using namespace std;

// t.c is ElogV for djikstra algo- where E is total number of edges and V is total no. of nodes, we use djikstra algo but we don't use priority queue, instead of this we use queue which reduce logV factor of djikstra algo
// so t.c is only E where E is total number of edges

// E-n*m*4
// t.c-E
// so, t.c-O(n*m*4)
// s.c-O(n*m)(for queue storing all nodes in worst case)+O(n*m)(for dist array)

class Solution
{
public:
  int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
  {
    int n = grid.size();
    int m = grid[0].size();

    // edge case
    if (source.first == destination.first && source.second == destination.second)
    {
      return 0;
    }
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    // not use PQ because of constant increasing in distance
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {source.first, source.second}});
    dist[source.first][source.second] == 0;
    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};
    while (!q.empty())
    {
      auto it = q.front();
      int dis = it.first;
      int row = it.second.first;
      int col = it.second.second;
      q.pop();
      // move in four direction
      for (int i = 0; i < 4; i++)
      {
        // neighbour row and column
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && dis + 1 < dist[nrow][ncol])
        {
          dist[nrow][ncol] = dis + 1;
          if (nrow == destination.first && ncol == destination.second)
          {
            return dis + 1;
          }
          q.push({dis + 1, {nrow, ncol}});
        }
      }
    }
    return -1;
  }
};

// input type-{{1,1,1,1},{1,1,0,1},{1,1,1,1,},{1,1,0,0},{1,0,0,0}}
int main()
{
  int n, m;
  cout << "Enter the row and column :";
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));
  cout << "Enter the value of grid either 0 or 1: ";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
    }
  }
  cout << "Enter source cell: ";
  pair<int, int> source;
  cin >> source.first >> source.second;
  pair<int, int> destination;
  cout << "Enter destination cell: ";
  cin >> destination.first >> destination.second;

  Solution result;
  cout << result.shortestPath(grid, source, destination) << endl;

  return 0;
}
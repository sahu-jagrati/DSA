// You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

// A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

// Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

// you have to find all possible path and take max of absolute difference of height of cells for each path and then take the min of max efforts i.e the answer

// here we use priority queue because we want minimal difference
// priority queue-{diff,{row,col}}

// Once I reached the destination taking out the PQ, not while inserting is the answer i.e when inserting in PQ and we get destination we cann't stop and we cann't conclude here, we stop when we take out the destination from the PQ itself

#include <bits/stdc++.h>
using namespace std;

// t.c-ElogV for djikstra algo where E is total number of edges and V is total no. of nodes
// in heights matrix - E is n*m*4 because for every node there is four edge in 4 direction
// and V is n*m no. of nodes

// so, t.c-O(n*m*4*log(n*m))
// s.c-O(n*m)(for priority queue storing all nodes in worst case)+O(n*m)(for dist array)

class Solution
{
public:
  int minimumEffortPath(vector<vector<int>> &heights)
  {
    //{diff,{row,col}} // priority queue we use is min-heap store shortest at top
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;

    int n = heights.size();
    int m = heights[0].size();

    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[0][0] = 0;
    pq.push({0, {0, 0}});
    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};
    while (!pq.empty())
    {
      auto it = pq.top();
      pq.pop();
      int diff = it.first;
      int row = it.second.first;
      int col = it.second.second;

      if (row == n - 1 && col == m - 1)
        return diff;

      // we move in 4 direction
      for (int i = 0; i < 4; i++)
      {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
        {
          int newEffort = max(abs(heights[row][col] - heights[nrow][ncol]),
                              diff);
          if (newEffort < dist[nrow][ncol])
          {
            dist[nrow][ncol] = newEffort;
            pq.push({newEffort, {nrow, ncol}});
          }
        }
      }
    }
    return 0;
  }
};

// input type-{{1,2,2},{3,8,2},{5,3,5}}
// src always-{0,0} and destination always-{n-1,m-1}
int main()
{
  int n, m;
  cout << "Enter the row and column: ";
  cin >> n >> m;
  vector<vector<int>> heights(n, vector<int>(m));
  cout << "Enter the value in heights matrix (it can be any): ";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> heights[i][j];
    }
  }
  Solution result;
  cout << result.minimumEffortPath(heights) << endl;

  return 0;
}
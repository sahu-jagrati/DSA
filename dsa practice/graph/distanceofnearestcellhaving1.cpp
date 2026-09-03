// given a binary grid of n*m. fid the distance of the nearest 1 in the grid for each cell.
// the distance is calculated as |i1-i2|+|j1-j2| where i1,j1 are the row and column number of the current cell and i2,j2 are the row and column number of the nearest cell having value 1.
// if cell has value 1 then for it distance of nearest 1 is 0 because it itself is nearest and
// we don't calculate diagonal distance, for moving diagonal we go column and row wise

// which algo use
// if we use dfs-then it go in depth which will give wrong nearest distance

// so we use bfs algo-similar to rotten orange quetion
// we move only in four direction

#include <bits/stdc++.h>
using namespace std;

// s.c-O(N*M)(for queue space)+O(N*M)(for visited)+O(N*M)(for dist matrix=O(N*M))
// t.c-O(N*M)(for marking visited matrix)+O(N*M)(pushing all nodes in queue  )+O(N*M*4)(move in 4 direction for each node)-O(N*M)
class Solution
{
public:
  vector<vector<int>> distanceOfNearest1(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();
    // we use this as  a good engineer we don't interrupt with input data
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, 0));

    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == 1)
        {
          q.push({{i, j}, 0});
          visited[i][j] = 1;
        }
        else
        {
          visited[i][j] = 0;
        }
      }
    }
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};
    while (!q.empty())
    {
      int row = q.front().first.first;
      int col = q.front().first.second;
      int dis = q.front().second;
      q.pop();
      dist[row][col] = dis;
      for (int i = 0; i < 4; i++)
      {
        // neighbour row and column
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] == 0)
        {
          q.push({{nrow, ncol}, dis + 1});
          visited[nrow][ncol] = 1;
        }
      }
    }
    return dist;
  }
};

int main()
{
  int n, m;
  cout << "Enter the row and column size: ";
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));
  cout << "Enter the row and column value (it can be 0 and 1): ";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
    }
  }
  Solution result;
  vector<vector<int>> answer = result.distanceOfNearest1(grid);
  for (auto row : answer)
  {
    for (auto it : row)
    {
      cout << it << " ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
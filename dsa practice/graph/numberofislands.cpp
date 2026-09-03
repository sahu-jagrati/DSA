// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water

// we can move only in 4 direction

// we can do by dfs and bfs both
// here we do by bfs algo
// in question number of distinct island we do by dfs algo
#include <bits/stdc++.h>
using namespace std;

// t.c -N*M(for for loops) + (N*M*4)(for bfs run)
// s.c-(N*M)(for visited)+(N*M)(for queue in worst case)-O(N*M)
class Solution
{
public:
  void bfs(int row, int col, vector<vector<char>> &grid,
           vector<vector<int>> &visited)
  {
    int n = grid.size();
    int m = grid[0].size();

    visited[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});

    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};
    while (!q.empty())
    {
      int row = q.front().first;
      int col = q.front().second;
      q.pop();

      // we can move in 4 direction
      for (int i = 0; i < 4; i++)
      {
        // neighbour row and col
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            grid[nrow][ncol] == '1' && !visited[nrow][ncol])
        {
          q.push({nrow, ncol});
          visited[nrow][ncol] = 1;
        }
      }
    }
  }

  int numIslands(vector<vector<char>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();

    // create visited because we don;t do any process on i/p data
    vector<vector<int>> visited(n, vector<int>(m, 0));

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (!visited[i][j] && grid[i][j] == '1')
        {
          cnt++;
          bfs(i, j, grid, visited);
        }
      }
    }
    return cnt;
  }
};

// input type- {{0,1,1,0},{0,1,1,0},{0,0,1,0},{1,1,0,1}}
int main()
{
  int n, m;
  cout << "Enter the row and column size: ";
  cin >> n >> m;
  vector<vector<char>> mat(n, vector<char>(m));
  cout << "Enter the row and column value with either 0 or 1: ";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> mat[i][j];
    }
  }

  Solution result;
  int answer = result.numIslands(mat);
  cout << answer << endl;

  return 0;
}
// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

// Example 1:

// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
// Example 2:

// Input: grid = [[1,2,3],[4,5,6]]
// Output: 12

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 200
// 0 <= grid[i][j] <= 200

#include <bits/stdc++.h>
using namespace std;

// we use short trick here
// this problem is done by me own fully

// recursion solution-top-down approach
// x-row
// y-col
int f1(int x, int y, vector<vector<int>> &grid)
{
  // base case
  if (x == 0 && y == 0)
    return grid[0][0];
  // if out of bounds, return large number because we want minPAth so large number easily ignored
  if (x < 0 || y < 0)
    return 1e9;

  int up = f1(x - 1, y, grid) + grid[x][y];
  int left = f1(x, y - 1, grid) + grid[x][y];

  return min(up, left);
}

// memoization solution-top-down approach
// x-row
// y-col
// t.c-O(m*n) we calls for each cell
// s.c-O(m+n)(recursion stack space)+O(m*n)dp matrix space
int f2(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
  // base case
  if (x == 0 && y == 0)
    return grid[0][0];
  // if out of bounds, return large number because we want minPAth so large number easily ignored
  if (x < 0 || y < 0)
    return 1e9;

  if (dp[x][y] != -1)
    return dp[x][y];
  int up = f2(x - 1, y, grid, dp) + grid[x][y];
  int left = f2(x, y - 1, grid, dp) + grid[x][y];

  return dp[x][y] = min(up, left);
}

// tabulation solution
// t.c-O(m*n)
// s.c-O(m*n)dp matrix space
int f3(vector<vector<int>> &grid)
{
  int m = grid.size();
  int n = grid[0].size();
  vector<vector<int>> dp(m, vector<int>(n));
  dp[0][0] = grid[0][0];
  // first for going 0th row cell we have only 1 way to reach any cell of 0th row
  for (int j = 1; j < n; j++)
  {
    dp[0][j] = dp[0][j - 1] + grid[0][j];
  }
  // similar for 0th col. cells there is only 1 way to reach any cell of 0th column
  for (int i = 1; i < m; i++)
  {
    dp[i][0] = dp[i - 1][0] + grid[i][0];
  }
  // for remaining cells
  // we want minimum so we take min of all ways A.T short trick
  for (int i = 1; i < m; i++)
  {
    for (int j = 1; j < n; j++)
    {
      dp[i][j] = min(dp[i - 1][j] + grid[i][j], dp[i][j - 1] + grid[i][j]);
    }
  }
  return dp[m - 1][n - 1];
}

// space optimization solution
// t.c-O(m*n)
// s.c-O(n) for prev and temp array
int f4(int m, int n, vector<vector<int>> &grid)
{
  vector<int> prev(n, 0); // for previous row
  for (int i = 0; i < m; i++)
  {
    vector<int> temp(n, 0); // for current row
    for (int j = 0; j < n; j++)
    {
      if (i == 0 && j == 0)
      {
        temp[j] = grid[0][0];
        continue;
      }
      int up = grid[i][j];
      if (i > 0)
      {
        up += prev[j];
      }
      else
      {
        up += 1e9;
      }
      int left = grid[i][j];
      if (j > 0)
      {
        left += temp[j - 1];
      }
      else
      {
        left += 1e9;
      }
      temp[j] = min(up, left);
    }
    prev = temp;
  }
  return prev[n - 1];
}
int minPathSum(vector<vector<int>> &grid)
{
  int m = grid.size();
  int n = grid[0].size();

  // recursion solution
  // return f1(m - 1, n - 1, grid);

  // memoization solution
  // vector<vector<int>> dp(m, vector<int>(n, -1));
  // return f2(m - 1, n - 1, grid, dp);

  // tabulation solution
  return f3(grid);
}

int main()
{
  int m, n;
  cin >> m >> n;
  vector<vector<int>> grid(m, vector<int>(n));
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> grid[i][j];
    }
  }
  cout << minPathSum(grid);
  return 0;
}
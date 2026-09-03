// You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The testcases are generated so that the answer will be less than or equal to 2 * 109.

// Example 1:

// Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
// Output: 2
// Explanation: There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right
// Example 2:

// Input: obstacleGrid = [[0,1],[0,0]]
// Output: 1

// Constraints:

// m == obstacleGrid.length
// n == obstacleGrid[i].length
// 1 <= m, n <= 100
// obstacleGrid[i][j] is 0 or 1.

// Hint 1
// Use dynamic programming since, from each cell, you can move to the right or down.
// Hint 2
// assume dp[i][j] is the number of unique paths to reach (i, j). dp[i][j] = dp[i][j -1] + dp[i - 1][j]. Be careful when you encounter an obstacle. set its value in dp to 0.

// we do here in similar way that we do in UniquePath question, only here we careful with an obstacle

#include <bits/stdc++.h>
using namespace std;

// in this there is an additional of base case when we get obstaclegrid[i][j]=1 we cann't take that way and all things are same as UniquePath problem

// recursion solution
// x- row
// y- col
int f1(int x, int y, vector<vector<int>> &obstacleGrid)
{
  // additional base case
  if (x >= 0 && y >= 0 && obstacleGrid[x][y] == 1)
    return 0; // means we cann't take that way so return 0 for that way

  // all are remain same as of Unique Path problem
  if (x == 0 || y == 0)
    return 1;
  if (x < 0 || y < 0)
    return 0;

  int up = f1(x - 1, y, obstacleGrid);
  int left = f1(x, y - 1, obstacleGrid);

  return up + left;
}

// memoization solution
// t.c-O(m*n) because we go each cell
// s.c-O(m*n) for dp matrix
int f2(int x, int y, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp)
{
  // additional base case
  if (x >= 0 && y >= 0 && obstacleGrid[x][y] == 1)
    return 0;
  if (x == 0 || y == 0)
    return 1;
  if (x < 0 || y < 0)
    return 0;

  if (dp[x][y] != -1)
    return dp[x][y];
  int up = f2(x - 1, y, obstacleGrid, dp);
  int left = f2(x, y - 1, obstacleGrid, dp);

  return dp[x][y] = up + left;
}

// tabulation solution
// t.c-O(m+n+m*n)=O(m*n) because we go each cell
// s.c-O(m*n) for dp matrix
int f3(int m, int n, vector<vector<int>> &obstacleGrid)
{
  vector<vector<int>> dp(m, vector<int>(n, -1));
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      // additional base case
      if (obstacleGrid[i][j] == 1)
      { // we cann't take that way
        dp[i][j] = 0;
        continue;
      }
      if (i == 0 && j == 0)
      {
        dp[i][j] = 1;
        continue;
      }
      int up = 0;
      int left = 0;
      if (i > 0)
      {
        up = dp[i - 1][j];
      }
      if (j > 0)
      {
        left = dp[i][j - 1];
      }
      dp[i][j] = up + left;
    }
  }
  return dp[m - 1][n - 1];
}

// space optimization solution
// t.c-O(m*n) because we are iterating through each cell in the grid once.
// s.c-O(n), for prev and temp arrays of size n
int f4(int m, int n, vector<vector<int>> &obstacleGrid)
{
  vector<int> prev(n, 0);
  for (int i = 0; i < m; i++)
  {
    vector<int> temp(n, 0); // current row
    for (int j = 0; j < n; j++)
    {
      if (obstacleGrid[i][j] == 1)
      {
        temp[j] = 0;
        continue;
      }
      if (i == 0 && j == 0)
      {
        temp[j] = 1;
        continue;
      }
      int up = 0;
      int left = 0;
      if (i > 0)
      {
        up = prev[j];
      }
      if (j > 0)
      {
        left = temp[j - 1];
      }
      temp[j] = up + left;
    }
    prev = temp;
  }
  return prev[n - 1];
}
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
  int m = obstacleGrid.size();
  int n = obstacleGrid[0].size();
  // recursion solution
  // return f1(m - 1, n - 1, obstacleGrid);

  // memoization solution
  // vector<vector<int>> dp(m, vector<int>(n, -1));
  // return f2(m - 1, n - 1, obstacleGrid, dp);

  // tabulation solution
  // return f3(m, n, obstacleGrid);

  // space optimization solution
  return f4(m, n, obstacleGrid);
}

int main()
{
  int m, n;
  cin >> m >> n;
  vector<vector<int>> obstacleGrid(m, vector<int>(n));
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> obstacleGrid[i][j];
    }
  }
  cout << uniquePathsWithObstacles(obstacleGrid);
  return 0;
}
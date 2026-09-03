// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The test cases are generated so that the answer will be less than or equal to 2 * 109.

// Example 1:

// Input: m = 3, n = 7
// Output: 28
// Example 2:

// Input: m = 3, n = 2
// Output: 3
// Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Down -> Down
// 2. Down -> Down -> Right
// 3. Down -> Right -> Down

// Constraints:

// 1 <= m, n <= 100

#include <bits/stdc++.h>
using namespace std;

// recursion solution- start from top-down approach so from cell (m-1,n-1) we can go up or left opposite of given movement in question down and right
// x-row
// y-col
int f1(int x, int y)
{
  // base case when we either in 0th row or in 0th column
  if (x == 0 || y == 0)
  {
    return 1;
  }
  if (x < 0 || y < 0)
    return 0;
  int left = f1(x, y - 1); // left because in recursion we go top-down
  int up = f1(x - 1, y);   // same here up because we go top-dowm

  return left + up; // because we want all possible ways so A.T short trick sum of all stuffs
}

// memoization solution-top down approach
// x-row
// y-col
// t.c-O(m*n) because we go each cell
// s.c-O(m*n) for dp matrix
int f2(int x, int y, vector<vector<int>> &dp)
{
  // base case
  if (x == 0 || y == 0)
  {
    return 1;
  }
  if (x < 0 || y < 0)
    return 0;
  if (dp[x][y] != -1)
    return dp[x][y];

  int left = f2(x, y - 1, dp);
  int up = f2(x - 1, y, dp);

  return dp[x][y] = left + up;
}

// tabulation solution
// t.c-O(m+n+m*n)=O(m*n) because we go each cell
// s.c-O(m*n) for dp matrix
int f3(int m, int n)
{
  vector<vector<int>> dp(m, vector<int>(n, -1));
  // first for going 0th row cell we have only 1 way to reach any cell of 0th row
  for (int j = 0; j < n; j++)
  {
    dp[0][j] = 1;
  }
  // similar for 0th col. cells there is only 1 way to reach any cell of 0th column
  for (int i = 0; i < m; i++)
  {
    dp[i][0] = 1;
  }
  // for remaining cells
  // we want all possible ways to reach upto that cell so we sum up all ways A.T short trick
  for (int i = 1; i < m; i++)
  {
    for (int j = 1; j < n; j++)
    {
      // because we can move either right or down so from previous cells calculation we calculate it
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }
  return dp[m - 1][n - 1];
}

// space optimization-
// Observe the relationship obtained in the tabulation approach: dp[i][j] = dp[i-1][j] + dp[i][j-1]. We notice that to calculate dp[i][j], we only need the values from the previous row and the current row. This allows us to optimize the space usage.
// Instead of maintaining the entire 2D dp array, we can use two arrays, one for the current row (let's call it temp) and one for the previous row (let's call it prev).
// Initially, initialize the prev array to all zeros to represent the starting point. The temp array will hold the current row's values during the iteration.
// For each row, use the prev array (representing the previous row) and the temp array (representing the current row) to compute the values of dp[i][j].
// After processing the current row, set prev to be equal to temp, so that in the next iteration, prev will represent the previous row, and temp will be ready to hold the new row's values.
// At the end of the process, prev[n-1] will store the final result, which contains the total number of ways to reach the destination in the grid. This provides the answer in a space-efficient manner using only two rows.

// t.c-O(m*n) because we are iterating through each cell in the grid once.
// s.c-O(n), for prev and temp arrays of size n
int f4(int m, int n)
{
  /* Initialize a vector to represent
        the previous row of the grid.*/
  vector<int> prev(n, 0);

  // Iterate through the rows of the grid.
  for (int i = 0; i < m; i++)
  {
    /* Create a temporary vector to
            represent the current row.*/
    vector<int> temp(n, 0);
    for (int j = 0; j < n; j++)
    {
      // base case
      if (i == 0 && j == 0)
      {
        temp[j] = 1;
        continue;
      }
      // Initialize variables to store the number of ways from the cell above (up) and left (left).
      int up = 0;
      int left = 0;
      // if we are not at the first row(i>0), update 'up' with the value from the previous row

      if (i > 0)
        up = prev[j];
      // if we are not at the first column(j>0) update 'left' with the value from current row
      if (j > 0)
        left = temp[j - 1];

      // calculate the number of ways to reach the current cell
      temp[j] = up + left;
    }
    // update the previous row with current row
    prev = temp;
  }
  return prev[n - 1];
}

// we use short trick
// i do this problem by own without any help
int uniquePaths(int m, int n)
{
  // recursion solution
  // return f1(m - 1, n - 1);

  // memoization solution
  // vector<vector<int>> dp(m, vector<int>(n, -1));
  // return f2(m - 1, n - 1, dp);

  // tabulation solution
  // return f3(m, n);

  // space optimization solution
  return f4(m, n);
}

int main()
{
  int m, n;
  cin >> m >> n;
  cout << uniquePaths(m, n);
  return 0;
}
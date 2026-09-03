// You are given an m x n integer matrix grid, and three integers x, y, and k.

// The integers x and y represent the row and column indices of the top-left corner of a square submatrix and the integer k represents the size (side length) of the square submatrix.

// Your task is to flip the submatrix by reversing the order of its rows vertically.

// Return the updated matrix.

// Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], x = 1, y = 0, k = 3

// Output: [[1,2,3,4],[13,14,15,8],[9,10,11,12],[5,6,7,16]]

// Explanation:

// The diagram above shows the grid before and after the transformation.
// Input: grid = [[3,4,2,3],[2,3,4,2]], x = 0, y = 2, k = 2

// Output: [[3,4,4,2],[2,3,2,3]]

// Explanation:

// The diagram above shows the grid before and after the transformation.

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 50
// 1 <= grid[i][j] <= 100
// 0 <= x < m
// 0 <= y < n
// 1 <= k <= min(m - x, n - y)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> reverseSubmatrix(vector<vector<int>> &grid, int x, int y, int k)
{
  int n = grid.size();
  int m = grid[0].size();

  for (int i = y; i < (y + k); i++)
  {
    int j = x, l = x + k - 1;
    while (j <= l)
    {
      swap(grid[j][i], grid[l][i]);
      j++;
      l--;
    }
  }
  return grid;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
    }
  }
  int x, y, k;
  cin >> x >> y >> k;
  vector<vector<int>> answer = reverseSubmatrix(grid, x, y, k);
  for (auto it1 : answer)
  {
    for (auto it2 : it1)
    {
      cout << it2 << " ";
    }
    cout << endl;
  }
  return 0;
}
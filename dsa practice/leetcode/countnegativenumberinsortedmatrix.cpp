// Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

// Example 1:

// Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
// Output: 8
// Explanation: There are 8 negatives number in the matrix.
// Example 2:

// Input: grid = [[3,2],[1,0]]
// Output: 0

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 100
// -100 <= grid[i][j] <= 100

// Follow up: Could you find an O(n + m) solution

#include <bits/stdc++.h>
using namespace std;

// brute force is using two for loop and check each elt one by one
// t.c-O(m*n)
// s.c-O(1)
int cntNegatives(vector<vector<int>> &grid)
{
  int m = grid.size();
  int n = grid[0].size();
  int cnt = 0;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (grid[i][j] < 0)
        cnt++;
    }
  }
  return cnt;
}

// better solution using binary search row wise

// int countNegatives(vector<vector<int>> &grid)
// {
//   int m = grid.size();
//   int n = grid[0].size();
//   int cnt = 0;
//   for (int i = 0; i < m; i++)
//   {
//     int low = 0, high = n - 1;
//     while (low <= high)
//     {
//       int mid = low + (high - low) / 2;
//       if (grid[i][mid] < 0)
//         cnt += (n - mid + 1);
//       else
//         low = mid + 1;
//     }
//   }
//   return cnt;
// }

// above solution is done by fully me but i do two mistake first indexing is 0-based so in cnt we add (n-mid) not (n-mid+1)
// second mistake is i don't update high if we get <0 at grid[i][mid] then i have to check for mid-1 also if there is also <0 then

// rewrite better solution in correct way

// t.c-O(mlogn)
// s.c-O(1)
int countNegatives(vector<vector<int>> &grid)
{
  int m = grid.size();
  int n = grid[0].size();
  int cnt = 0;
  for (int i = 0; i < m; i++)
  {
    int low = 0, high = n - 1;
    int firstNeg = n;
    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (grid[i][mid] < 0)
      {
        // cnt += (n - mid); // we add (n-mid) in cnt because indexing is 0-based not add (n-mid+1) but this will add negative multiple times if there are several negatives in the row.
        // Binary search continues and may hit another negative earlier depending on arrangement, causing overcount.

        // We should instead find the first negative index and then count once
        firstNeg = mid;
        high = mid - 1; // search for first negative
      }
      else
        low = mid + 1;
    }
    cnt += (n - firstNeg);
  }
  return cnt;
}

// optimize solution is using a pointer starting from top-right corner because matrix is sorted in decreasing order so if negative number exists it should be in right side

// t.c-O(m+n)
// s.c-O(1)

int countNegative(vector<vector<int>> &grid)
{
  int m = grid.size();
  int n = grid[0].size();

  int row = 0, col = n - 1; // for a pointer we use single pointer only
  int cnt = 0;
  while (row < m && col >= 0)
  {
    if (grid[row][col] < 0)
    {
      cnt += (m - row); // if we get negative number then in that column all are negative from that row to last row, we talk about column because column also sorted in decreasing order
      col--; // then go to next column and check that also
    }
    else
      row++; // if that elt is not negative then we jump to next row and check for that row
  }
  return cnt;
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

  cout << cntNegatives(grid) << endl;
  cout << countNegative(grid) << endl;
  cout << countNegatives(grid) << endl;
  return 0;
}
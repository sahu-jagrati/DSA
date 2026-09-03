// Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.

// In one shift operation:

// Element at grid[i][j] moves to grid[i][j + 1].
// Element at grid[i][n - 1] moves to grid[i + 1][0].
// Element at grid[m - 1][n - 1] moves to grid[0][0].
// Return the 2D grid after applying shift operation k times.

// Example 1:

// Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
// Output: [[9,1,2],[3,4,5],[6,7,8]]
// Example 2:

// Input: grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
// Output: [[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]
// Example 3:

// Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
// Output: [[1,2,3],[4,5,6],[7,8,9]]

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m <= 50
// 1 <= n <= 50
// -1000 <= grid[i][j] <= 1000
// 0 <= k <= 100

// Hint 1
// Simulate step by step. move grid[i][j] to grid[i][j+1]. handle last column of the grid.
// Hint 2
// Put the matrix row by row to a vector. take k % vector.length and move last k of the vector to the beginning. put the vector to the matrix back the same way.

#include <bits/stdc++.h>
using namespace std;

// given that in one shift operation :
// Element at grid[i][j] moves to grid[i][j + 1].
// Element at grid[i][n - 1] moves to grid[i + 1][0].
// Element at grid[m - 1][n - 1] moves to grid[0][0].

// this is whole done in one shift because when we move grid[i][j] to grid[i][j+1] then each elts also shift by one place so in that case last elt come to first place i.e grid[m-1][n-1] comes to grid[0][0] and last elt of any row comes to first elt of next row i.e grid[i][n-1] comes to grid[i+1][0] so these three moves happens in just one shift operation
// and A.T.Q we have to shift k times

// so I used hint 2
// what I am doing is that -
// i) I convert the 2d matrix into 1D array
// ii) then I right rotate the 1D array by k place so for that first I ensure that k is with in the range-[0 to m*n] like if arr=[-1] and k=2 then (size<k) so we do k=k*size where size=m*n which is the size of temp array
// iii) after rotate we convert back the 1D array into 2D matrix

// why we convert 2D into 1D? because we have to shift the elts k times and in 2D we have to check for each row last column then last row so instead of that we convert it in 1D so we don't need to check extra we easily shift elt and then convert back it to 2D from 1D

// in 2D we shift elt by k place, we can start from any elt in matrix and shift it k place , answer is same because shifting one elt we move other elts also from their place, it is similar to problem "rightRotatebyDplace 1D array" in that problem we right rotate the 1D array i.e we shift the elt by d place and here in this problem in 2D matrix we apply shift operation in which we shift elts by k place so we convert 2D to 1D and apply rightRotate and then convert back 1D to 2D

void reverse(vector<int> &temp, int start, int end)
{
  while (start < end)
  {
    int temp1 = temp[start];
    temp[start] = temp[end];
    temp[end] = temp1;
    start++;
    end--;
  }
}
void rightRotateByKPlace(vector<int> &temp, int size, int k)
{
  k = k % size;
  reverse(temp, 0, size - k - 1);
  reverse(temp, size - k, size - 1);
  reverse(temp, 0, size - 1);
}

vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
{
  int m = grid.size();
  int n = grid[0].size();
  vector<int> temp;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      temp.push_back(grid[i][j]);
    }
  }
  rightRotateByKPlace(temp, m * n, k);
  vector<vector<int>> ans(m, vector<int>(n));
  int i = 0;
  for (int j = 0; j < m; j++)
  {
    for (int k = 0; k < n; k++)
    {
      ans[j][k] = temp[i];
      i++;
    }
  }
  return ans;
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
  int k;
  cin >> k;
  vector<vector<int>> ans = shiftGrid(grid, k);

  for (auto arr : ans)
  {
    for (auto it : arr)
    {
      cout << it << " ";
    }
  }

  return 0;
}
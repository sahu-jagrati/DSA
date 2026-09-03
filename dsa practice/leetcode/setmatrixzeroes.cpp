// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.

// Example 1:

// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]
// Example 2:

// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

// Constraints:

// m == matrix.length
// n == matrix[0].length
// 1 <= m, n <= 200
// -2^31 <= matrix[i][j] <= 2^31 - 1

// Follow up:

// A straightforward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?

// we try for marking the row and col as -1 that have 0 but range of matrix[i][j] is INT_MIN to INT_MAX so we can't use -1 or any other integer as a marker
// But the constraint says values can be from INT_MIN to INT_MAX, so:
// 👉 -1 might already exist in the matrix

// That means:

// You cannot distinguish between:
// original -1
// marked -1

// ➡️ This will produce wrong answers
// when range is from 0 to INT_MAX then we can use marker approach see in array folder this approach

// Don’t use -1, INT_MIN, or any fixed value as marker
// ❌ Don’t assume any value is “safe”
// 🔥 Key Insight

// When constraints allow full integer range,
// 👉 Never modify values blindly for marking

#include <bits/stdc++.h>
using namespace std;

// better approach
// s.c-O(m+n) for row and col vector
// we use row and col vectorto track the row that has to be zero
// Works for all values
// ✔ No conflict
void setZeroes(vector<vector<int>> &matrix)
{
  int m = matrix.size();    // row
  int n = matrix[0].size(); // col

  vector<int> row(m, 0), col(n, 0);
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (matrix[i][j] == 0)
      {
        row[i] = 1;
        col[j] = 1;
      }
    }
  }
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (row[i] == 0 || col[j] == 0)
      {
        matrix[i][j] = 0;
      }
    }
  }
}

// optimal approach-
// s.c-O(1)
// use first row and first column as markers

void setzeroes(vector<vector<int>> &matrix)
{
  int m = matrix.size();
  int n = matrix[0].size();

  bool firstRow = false, firstCol = false; // for checking that index 0 row and index 0 col has zero or not

  // check first column
  for (int i = 0; i < m; i++)
  {
    if (matrix[i][0] == 0)
      firstCol = true;
  }
  // check first row
  for (int j = 0; j < n; j++)
  {
    if (matrix[0][j] == 0)
      firstRow = true;
  }
  // use first row and col as markers
  for (int i = 1; i < m; i++)
  {
    for (int j = 1; j < n; j++)
    {
      if (matrix[i][j] == 0)
      {
        // any row and col has zero then we mark 0 in firstrow of that col and firstcol of that row
        matrix[i][0] = 0;
        matrix[0][j] = 0;
      }
    }
  }
  // update matrix
  for (int i = 1; i < m; i++)
  {
    for (int j = 1; j < n; j++)
    {
      // if that row firstcol is 0 or that col forstrow is 0 than whole row and col is 0
      if (matrix[i][0] == 0 || matrix[0][j] == 0)
      {
        matrix[i][j] = 0;
      }
    }
  }
  // first column then in the col0 all row elt is 0
  if (firstCol)
  {
    for (int i = 0; i < m; i++)
    {
      matrix[i][0] = 0;
    }
  }
  // first row then in row0 all col elt is 0
  if (firstRow)
  {
    for (int j = 0; j < n; j++)
    {
      matrix[0][j] = 0;
    }
  }
}

int main()
{
  int m, n;
  cin >> m >> n;
  vector<vector<int>> matrix(m, vector<int>(n));
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> matrix[i][j];
    }
  }
  setzeroes(matrix);
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
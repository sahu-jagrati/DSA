// There is an m x n matrix that is initialized to all 0's. There is also a 2D array indices where each indices[i] = [ri, ci] represents a 0-indexed location to perform some increment operations on the matrix.

// For each location indices[i], do both of the following:

// Increment all the cells on row ri.
// Increment all the cells on column ci.
// Given m, n, and indices, return the number of odd-valued cells in the matrix after applying the increment to all locations in indices.

// Example 1:

// Input: m = 2, n = 3, indices = [[0,1],[1,1]]
// Output: 6
// Explanation: Initial matrix = [[0,0,0],[0,0,0]].
// After applying first increment it becomes [[1,2,1],[0,1,0]].
// The final matrix is [[1,3,1],[1,3,1]], which contains 6 odd numbers.
// Example 2:

// Input: m = 2, n = 2, indices = [[1,1],[0,0]]
// Output: 0
// Explanation: Final matrix = [[2,2],[2,2]]. There are no odd numbers in the final matrix.

// Constraints:

// 1 <= m, n <= 50
// 1 <= indices.length <= 100
// 0 <= ri < m
// 0 <= ci < n

// Follow up: Could you solve this in O(n + m + indices.length) time with only O(n + m) extra space?

#include <bits/stdc++.h>
using namespace std;

// first we try to print the matrix after conversion
vector<vector<int>> cells(int m, int n, vector<vector<int>> &indices)
{
  vector<vector<int>> matrix(m, vector<int>(n, 0));
  int size = indices.size();
  for (int i = 0; i < size; i++)
  {
    int row = indices[i][0];
    int col = indices[i][1];
    for (int j = 0; j < n; j++)
    {
      matrix[row][j] += 1;
    }
    for (int k = 0; k < m; k++)
    {
      matrix[k][col] += 1;
    }
  }
  return matrix;
}

// this is brute solution that i think fully
// t.c-O(size*(n+m))+O(m*n)(for cnt)
// s.c-O(m*n) for matrix array
int oddCells(int m, int n, vector<vector<int>> indices)
{

  vector<vector<int>> matrix(m, vector<int>(n, 0));
  int size = indices.size();
  for (int i = 0; i < size; i++)
  {
    int row = indices[i][0];
    int col = indices[i][1];
    for (int j = 0; j < n; j++)
    {
      matrix[row][j] += 1;
    }
    for (int k = 0; k < m; k++)
    {
      matrix[k][col] += 1;
    }
  }
  int cnt = 0;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (matrix[i][j] % 2 == 1)
        cnt++;
    }
  }
  return cnt;
}

// better solution-
// Maintain two arrays:
// row[m] → number of times each row is incremented
// col[n] → number of times each column is incremented
// A cell value becomes:
// matrix[i][j] = row[i] + col[j]
// A cell is odd if:
// (row[i] + col[j]) % 2 == 1
// Final value of cell (i,j) = row[i] + col[j]
// If (row[i] + col[j]) % 2 == 1 → it is odd

// t.c-O(size of indices)+O(m*n)
// s.c-O(m+n) for row and col array
int oddcells(int m, int n, vector<vector<int>> &indices)
{
  vector<int> row(m, 0);
  vector<int> col(n, 0);
  for (int i = 0; i < indices.size(); i++)
  {
    row[indices[i][0]]++;
    col[indices[i][1]]++;
  }
  int cnt = 0;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if ((row[i] + col[j]) % 2 == 1)
        cnt++;
    }
  }
  return cnt;
}

// optimized approach - jo mere ko samajh nhi aaya
// We can avoid the m × n loop using count of odd rows and odd columns.

// Formula:

// odd_cells = (odd_rows * (n - odd_cols)) + ((m - odd_rows) * odd_cols)

// Code:

// int oddCells(int m, int n, vector<vector<int>>& indices)
// {
//     vector<int> row(m,0), col(n,0);

//     for(auto &it:indices){
//         row[it[0]] ^= 1;
//         col[it[1]] ^= 1;
//     }

//     int oddRow=0, oddCol=0;

//     for(int x:row) oddRow+=x;
//     for(int x:col) oddCol+=x;

//     return oddRow*(n-oddCol) + (m-oddRow)*oddCol;
// }
// Complexity

// Time: O(k + m + n) ✅ (best)

// Space: O(m + n)

// If you want, I can also explain the logic behind the final formula (very commonly asked in interviews and LeetCode discussions).

// yes

// Let’s understand why the formula works in the optimized solution.

// We keep two arrays:

// row[i] → how many times row i was incremented

// col[j] → how many times column j was incremented

// A cell value becomes:

// matrix[i][j] = row[i] + col[j]

// A cell is odd if:

// (row[i] + col[j]) % 2 == 1

// This happens when:

// one is odd and the other is even

// Case 1: Odd Row + Even Column

// If a row is incremented odd times and the column even times, then:

// odd + even = odd

// Number of such cells:

// odd_rows × (n − odd_cols)

// because:

// odd_rows rows have odd increments

// (n - odd_cols) columns have even increments

// Case 2: Even Row + Odd Column
// even + odd = odd

// Number of such cells:

// (m − odd_rows) × odd_cols

// because:

// (m - odd_rows) rows are even

// odd_cols columns are odd

// Total Odd Cells
// odd_cells =
// (odd_rows × (n − odd_cols)) +
// ((m − odd_rows) × odd_cols)
// Example

// Suppose:

// m = 2 , n = 3
// indices = [[0,1],[1,1]]

// After processing:

// row = [1,1]
// col = [0,2,0]

// Convert to parity (odd/even):

// row = [1,1]   -> odd_rows = 2
// col = [0,0,0] -> odd_cols = 0

// Now apply formula:

// odd_cells =
// (2 × (3 − 0)) + ((2 − 2) × 0)
// = 2 × 3
// = 6

// So 6 cells are odd.

// Why XOR (^=1) is used

// In the optimized code:

// row[it[0]] ^= 1;
// col[it[1]] ^= 1;

// ^=1 toggles parity:

// 0 -> 1 (even → odd)
// 1 -> 0 (odd → even)

// So we only track odd/even, not the exact count.

// This makes the algorithm O(k + m + n) instead of O(m × n).

// ✅ Interview Tip:
// Whenever a problem asks about odd/even after many increments, try to track parity instead of full values.

int main()
{
  int m, n, size;
  cin >> m >> n >> size;
  vector<vector<int>> indices(size, vector<int>(2));
  for (int i = 0; i < size; i++)
  {
    cin >> indices[i][0] >> indices[i][1];
  }
  vector<vector<int>> answer = cells(m, n, indices);
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
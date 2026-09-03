// Given a 2D integer array matrix, return the transpose of matrix.

// The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

// Example 1:

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[1,4,7],[2,5,8],[3,6,9]]
// Example 2:

// Input: matrix = [[1,2,3],[4,5,6]]
// Output: [[1,4],[2,5],[3,6]]

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 1000
// 1 <= m * n <= 10^5
// -10^9 <= matrix[i][j] <= 10^9

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>> &matrix)
{
  int m = matrix.size();
  int n = matrix[0].size();
  vector<vector<int>> transpose(n, vector<int>(m));
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      transpose[j][i] = matrix[i][j];
    }
  }
  return transpose;
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
  vector<vector<int>> answer = transpose(matrix);
  for (auto it : answer)
  {
    for (auto it1 : it)
    {
      cout << it1 << " ";
    }
    cout << endl;
  }
  return 0;
}
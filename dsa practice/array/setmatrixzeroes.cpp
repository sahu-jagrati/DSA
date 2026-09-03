// in this we think that constraints are:
// 0<=matrix[i][j]<= 2^31 - 1
// that' why in brute we can use -1 as a marker if we have range INT_MIN to INT_MAX then we cann't use -1 as a marker see this question in leetcode folder

// n=matrix.size() - rows
// m-matrix[0].size() - cols

#include <iostream>
#include <vector>
using namespace std;

// brute approach- time complexity-O((n*m)*(n+m))+O(n*m) here, n*m for i and j loop and n+m for markrow and markcolumn and n*m for again i and j loop for -1 to 0 so, time complexity is approx.(n^3)
// space complexity-O(1)
// n-row
// m-col
void markRow(vector<vector<int>> &arr, int n, int m, int i)
{
  // mark that row all elts to -1
  for (int j = 0; j < m; j++)
  {
    if (arr[i][j] != 0)
    {
      arr[i][j] = -1;
    }
  }
}

void markColumn(vector<vector<int>> &arr, int n, int m, int j)
{
  // mark that col all elts to -1
  for (int i = 0; i < n; i++)
  {
    if (arr[i][j] != 0)
    {
      arr[i][j] = -1;
    }
  }
}

void setmatrixzeroes(vector<vector<int>> &arr, int n, int m)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (arr[i][j] == 0)
      {
        markRow(arr, n, m, i);
        markColumn(arr, n, m, j);
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (arr[i][j] == -1)
      {
        arr[i][j] = 0;
      }
    }
  }
}

// better approach- time complexity-O(n*m)+O(n*m)=O(2*n*m)
// space complexity-O(n)+O(m) for row array and column array
void setMatrixzeroes(vector<vector<int>> &arr, int n, int m)
{
  int col[m] = {0};
  int row[n] = {0};
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (arr[i][j] == 0)
      {
        row[i] = 1;
        col[j] = 1;
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (row[i] == 1 || col[j] == 1)
      {
        arr[i][j] = 0;
      }
    }
  }
}

// in brute force s.c-O(1) and better approach s.c-O(n+m) but opposite in t.c in brute it take more time but less space while in better it take less time but take more space

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> arr(n, vector<int>(m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
    }
    cout << endl;
  }
  setmatrixzeroes(arr, n, m);
  // setMatrixzeroes(arr, n, m);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
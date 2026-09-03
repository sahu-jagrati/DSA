// matrix is of n by m
// adjacent cells elts are not same
// in 2d array peak elt is which is greater than top,bottom,left,right elt
// there can be multiple peak but we have to find any one peak
// and whole matrix is surrounded by -1

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// brute- check for each elt-
// time complexity-O(n*m)
// space complexity-o(1)
vector<int> peak(vector<vector<int>> &matrix, int n, int m)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int curr = matrix[i][j];
      bool top = (i == 0 || curr > matrix[i - 1][j]);
      bool bottom = (i == n - 1 || curr > matrix[i + 1][j]);
      bool left = (j == 0 || curr > matrix[i][j - 1]);

      bool right = (j == m - 1 || curr > matrix[i][j + 1]);
      if (top && bottom && left && right)
      {
        return {i, j};
      }
    }
  }
  return {-1, -1};
}

// better - find largest element of matrix
// time complexity-O(n*m)
// space complexity-O(1)
vector<int> Peak(vector<vector<int>> &matrix, int n, int m)
{
  int largest = INT_MIN;
  int row = -1;
  int col = -1;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (matrix[i][j] > largest)
      {
        largest = matrix[i][j];
        row = i;
        col = j;
      }
    }
  }
  return {row, col};
}

// optimize is optimize version of 1d array
// in this we do binary search in row and in mid value column we find max element which is greater than top and bottom so, we have to check for left and right if left is greater than max then right half cancel otherwise left half cancel
// there is a possibilty that both can be greater than in that case we go any half because we want any one peak not all
int maxElt(vector<vector<int>> &matrix, int n, int m, int col)
{
  int index = -1;
  int maxi = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    int j = col;
    if (matrix[i][j] > maxi)
    {
      maxi = matrix[i][j];
      index = i;
    }
  }
  return index;
}

// time complexity-O(log m(base 2))*O(n)
// space complexity-O(1)
vector<int> PeakElt(vector<vector<int>> &matrix, int n, int m)
{
  int low = 0, high = m - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    int row = maxElt(matrix, n, m, mid); // beacuse we want that row in which we get max for checking left and right because top and bottom already check in taking max
    int left = mid - 1 >= 0 ? matrix[row][mid - 1] : -1;
    int right = mid + 1 < m ? matrix[row][mid + 1] : -1;
    if (left < matrix[row][mid] && matrix[row][mid] > right)
      return {row, mid};
    else if (left > matrix[row][mid])
      high = mid - 1;
    else
      low = mid + 1;
  }
  return {-1, -1};
}
int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> matrix(n, vector<int>(m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> matrix[i][j];
    }
  }
  // vector<int> result = peak(matrix, n, m);
  // vector<int> result = Peak(matrix, n, m);
  vector<int> result = PeakElt(matrix, n, m);
  for (auto it : result)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}
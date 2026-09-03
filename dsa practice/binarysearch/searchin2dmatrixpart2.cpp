// matrix is of n by m
// in matrix each individual row is sorted
// each individual column is sorted
// like {[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]}
// you have to find target and if found thhen return row and column number and if not found return [-1,-1]

#include <iostream>
#include <vector>
using namespace std;

// brute-
// time complexity-O(n*m)
// space complexity-O(1)
vector<int> search(vector<vector<int>> &matrix, int n, int m, int target)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (matrix[i][j] == target)
        return {i + 1, j + 1};
    }
  }
  return {-1, -1};
}

// optimize-
// we know individual row is sorted
// so we can apply binary search in individual row
int binarysearch(vector<int> &arr, int m, int target)
{
  int low = arr[0];
  int high = arr[m - 1];
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
      return mid;
    else if (arr[mid] < target)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}
// time complexity-O(n*log m(base 2))
// space complexity_O(1)
vector<int> Search(vector<vector<int>> &matrix, int n, int m, int target)
{
  for (int i = 0; i < n; i++)
  {
    int ans = binarysearch(matrix[i], m, target);
    if (ans != (-1))
    {
      return {i, ans};
    }
  }
  return {-1, -1};
}

// more optimize-
// in matrix each individual row is sorted
// each individual column is sorted
// if we stand at matrix[0][4] from this position you can see that in bottom we are increasing and in left we are decreasing so over all we go from decreasing to increasing
// same if we satnd at matrix[4][0]-on going top we decreasing and ongoing right we increasing
// so start from any one corner from matrix[0][4] or matrix[4][0]
// we can't start from arr[0][0] or arr[4][4]
// we don't use binary seacrh here but we do elimination
// time complexity- int worst case-O(n+m)
// space complexity-O(1)
vector<int> SearchIn(vector<vector<int>> &matrix, int n, int m, int target)
{
  int row = 0;
  int col = m - 1;
  while (row < n && col >= 0)
  {
    if (matrix[row][col] == target)
      return {row, col};
    else if (matirx[row][col] < target)
      row++;
    else
      col--;
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
  int target;
  cin >> target;
  // vector<int> result = search(matrix, n, m, target);
  vector<int> result = Search(matrix, n, m, target);
  for (auto it : result)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}
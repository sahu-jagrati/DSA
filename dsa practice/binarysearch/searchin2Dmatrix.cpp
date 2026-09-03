// entire matrix is sorted like {[3 4 7 9],[12 13 16 18],[20 21 23 29]}
// size of row and column can be different
#include <iostream>
#include <vector>
using namespace std;

// brute-
// time complexity-O(n*m)
// space complexity-O(1)
bool search(vector<vector<int>> &matrix, int n, int m, int target)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (matrix[i][j] == target)
        return true;
    }
  }
  return false;
}

// optimize-
// in matrix each row is sorted so instead of checking each elt we can go for individual row and check last and first  elt of that row if it is smaller than increase row and check for another one in that we get larger any last one then target is in that row which is sorted so do binary search in that row
bool binarysearch(vector<int> &arr, int target)
{
  int m = arr.size();
  int low = 0, high = m - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
      return true;
    else if (arr[mid] < target)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return false;
}
// time complexity-O(n*1)+O(log m(base 2))=O(n) // because if() run only 1 time
// space complexity -O(1)
bool Search(vector<vector<int>> matrix, int n, int m, int target)
{
  for (int i = 0; i < n; i++)
  {
    if (matrix[i][0] <= target && target <= matrix[i][m - 1])
    {
      return binarysearch(matrix[i], target); // matrix[i] is of individual array
    }
  }
  return false;
}

// more optimize- if i flattened the 2D array in 1D array in my brain not in real of size n*m then we can use directly binary searh
// in real also you can flattened but it take extra time so flattend in brain
// low =0 , high=n*m-1 then mid is like 5 then how we convert it in 2d coordinate
// row=mid/m;
// col=mid%m;
// what intution behind that?
// every row has m numbers so divide mid by m we get row
// and in column when we do % m we get remainder

// time complexity-O(log (n*m)(base 2))
// space complexity-O(1)
bool searchIn(vector<vector<int>> &matrix, int n, int m, int target)
{
  int low = 0, high = n * m - 1;
  while (low <= high)
  {
    /* code */
    int mid = low + (high - low) / 2;
    int row = mid / m;
    int col = mid % m;
    if (matrix[row][col] == target)
      return true;
    else if (matrix[row][col] < target)
      low = mid + 1; // do in 1d array
    else
      high = mid - 1;
  }
  return false;
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
  // bool result = search(matrix, n, m, target);
  // bool result = Search(matrix, n, m, target);
  bool result = searchIn(matrix, n, m, target);
  cout << result << endl;
  return 0;
}

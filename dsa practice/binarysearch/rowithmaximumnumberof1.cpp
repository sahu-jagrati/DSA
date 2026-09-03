// matrix has only 0/1
// each individual row is sorted
// row and column can be of different size
// if more than one row has same 1s then return low index row

#include <iostream>
#include <vector>
using namespace std;

// brute-time complexity-O(n*m)
// space complexity-O(1)
int maximum1(vector<vector<int>> &matrix, int n, int m)
{
  int index = -1, maxcnt = -1;
  for (int i = 0; i < n; i++)
  {
    int cntrow = 0;
    for (int j = 0; j < m; j++)
    {
      if (matrix[i][j] == 1)
      {
        cntrow++;
      }
    }
    if (cntrow > maxcnt)
    { // we don't use greater than equal to because we want max1 in low index row
      maxcnt = cntrow;
      index = i;
    }
  }
  return (index);
}

// optimize-
// we have each row sorted
// we can optimize inner loop of brute solution by using binary search in individual row
// because we have to figue 1st 1 only after that no. of 1 =m-that index of 1st 1
// so use lowerbound(1)
// upperbound(0)
// firstoccurence(1)

// NOTE -> in binary search you cannot change row traversal, you only optimize each row
int lower_bound(vector<int> &arr, int n, int target)
{
  int low = 0, high = n - 1;
  int ans = n;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (arr[mid] >= target)
    {
      ans = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return ans;
}
// time complexity-O(n*log (m)(base 2))
// space complexity -O(1)
int Maximum1(vector<vector<int>> &matrix, int n, int m)
{
  int index = -1;
  // int maxcnt = -1;
  int maxcnt = 0; // because when there is no 1 in any row then in that case lowerbound function will return arr.size() in that case m-cnt=0 in that case  return -1 not any index
  for (int i = 0; i < n; i++)
  {
    int cnt = lower_bound(matrix[i], m, 1); // matrix[i] is 1D array
    int numberOf1 = m - cnt;
    if (numberOf1 > maxcnt)
    {
      maxcnt = numberOf1;
      index = i;
    }
  }
  return index;
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
  // int result = maximum1(matrix, n, m);
  int result = Maximum1(matrix, n, m);
  cout << result << endl;
  return 0;
}

// in matrix-n is odd
// m is odd
// n*m=odd
// row wise sorted matrix
// median is the middle number of sorted array

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <climits>
using namespace std;

// brute - convert 2d in 1d array and sort it and get median
// time complexity-O(n*m)+(n*m)(log (n*m))(for sorting)
// space complexity-O(n*m)
int median(vector<vector<int>> &matrix, int n, int m)
{
  vector<int> ls;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      ls.push_back(matrix[i][j]);
    }
  }
  sort(ls.begin(), ls.end());
  return ls[(n * m) / 2];
}

// optimize-
// we have row wise sotred matrix
// we have to find median
// so can we use binary search?
// we can use binary search on answer range
// answer range-[min(matrix),max(matrix)]
// our intution is that we have to find ((no.ofelts in matrix)<=range elt)>(n*m)/2
int upperBound(vector<int> &arr, int m, int x)
{ // row wise
  int low = 0, high = m - 1;
  int ans = m; // hypothetically if not return arr.size();
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (arr[mid] > x)
    {
      ans = mid;
      high = mid - 1; // because we want smallest index;
    }
    else
      low = mid + 1;
  }
  return ans;
}
int countSmallerEquals(vector<vector<int>> &matrix, int n, int m, int mid)
{
  int cnt = 0;
  // here we can use upperbound(mid) for calculating no.of elts<=mid row wise
  for (int i = 0; i < n; i++)
  {
    int index = upperBound(matrix[i], m, mid);
    cnt += index;
  }
  return cnt;
}
// in constraints smallest =1 and largest =10^9
// time  complexity-O(n)(for low and high)+O((log (10^9) (base2))*(n*log m(base 2)))
// space complexity-O(1)
int Median(vector<vector<int>> &matrix, int n, int m)
{
  int low = INT_MAX;
  int high = INT_MIN;
  // for low and high we have to check only first and last column because row wise sorted matrix
  for (int i = 0; i < n; i++)
  {
    low = min(low, matrix[i][0]);
    high = max(high, matrix[i][m - 1]);
  }
  int required = (n * m) / 2;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    // we don't have to compute for all range elts for no.of elts that is less than = to range elts, we have only for mid elts
    int smallerEquals = countSmallerEquals(matrix, n, m, mid);
    if (smallerEquals <= required)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return low;
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
  // int result = median(matrix, n, m);
  int result = Median(matrix, n, m);
  cout << result << endl;
  return 0;
}
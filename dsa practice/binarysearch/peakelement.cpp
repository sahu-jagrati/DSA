// array can be linear increasing or linear decreasing  in that case assume both side there is -infinity
// or first increasing and then decreasing
// more than one peak element can be exist
// array can have duplicates
// but consecutive not equals
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// brute-time complexity-O(n)
vector<int> peak(vector<int> &arr)
{
  int n = arr.size();
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    if ((i == 0 || arr[i - 1] < arr[i]) && (i == n - 1 || arr[i] > arr[i + 1]))
      ans.push_back(arr[i]);
  }
  return ans;
}
// optimal-
// having 1 peak only- time complexity-O(log n(base 2))
int Peak(vector<int> &arr)
{
  int n = arr.size();
  if (n == 1)
    return arr[0];
  if (arr[0] > arr[1])
    return arr[0];
  if (arr[n - 1] > arr[n - 2])
    return arr[n - 1];
  int low = 1, high = n - 2;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    // if mid is peak
    if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
      return arr[mid];
    // if before mid, array is linear increasing
    else if (arr[mid - 1] < arr[mid])
      low = mid + 1;
    // right of mid is linear decreasing
    // when arr[mid-1]>arr[mid]
    else
      high = mid - 1;
  }
  return -1;
}

// having multiple peaks but find only one peak (any) and also arr[i-1]!=arr[i] i.e consecutive not equals
// time complexity-O(log n(base 2))
int peakElement(vector<int> &arr)
{
  int n = arr.size();
  if (n == 1)
    return arr[0];
  if (arr[0] > arr[1])
    return arr[0];
  if (arr[n - 1] > arr[n - 2])
    return arr[n - 1];
  int low = 1, high = n - 2;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    // if mid is peak
    if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
      return arr[mid];
    // if before mid array is linear increasing
    else if (arr[mid - 1] < arr[mid])
      low = mid + 1;
    // right of mid is linear decreasing
    else if (arr[mid] > arr[mid + 1])
      high = mid - 1;
    else
    {
      low = mid + 1; // this is extra case because when mid is the minimum element between two peaks
    }
  }
  return -1;
}
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  // vector<int> result = peak(arr);
  // for (auto it : result)
  // {
  //   cout << it << " ";
  // }
  // cout << endl;
  // int ans = Peak(arr);
  int ans = peakElement(arr);
  cout << ans << endl;
  return 0;
}

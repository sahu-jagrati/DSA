// find i s.t i=arr[i]
#include <iostream>
#include <vector>
using namespace std;

// t.c=O(n) if array is unsorted
int index(vector<int> &arr, int n)
{
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == i)
      return i;
  }
  return -1;
}

// t.c=O(logn) if array is sorted
int findIndex(vector<int> &arr, int n)
{
  int low = 0, high = n - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (arr[mid] == mid)
      return mid;
    else if (arr[mid] > mid)
      high = mid - 1;
    else
      low = mid + 1;
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
  // int result = index(arr, n); // if array unsorted
  int result = findIndex(arr, n); // if array sorted
  cout << result << endl;
  return 0;
}
// find max elt when array is first increasing and then decreasing
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// t.c=O(logn)
// s.c-O(1)
int max(vector<int> &arr, int n)
{
  int low = 0, high = n - 1;
  int maxi = INT_MIN;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if ((mid == 0 || arr[mid] > arr[mid - 1]) && (mid == n - 1 || arr[mid] > arr[mid + 1]))
      return arr[mid];
    else if (mid < n - 1 && arr[mid] < arr[mid + 1])
      low = mid + 1;
    else
      high = mid - 1;
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
  int result = max(arr, n);
  cout << result << endl;
  return 0;
}
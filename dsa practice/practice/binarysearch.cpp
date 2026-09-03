#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binary(vector<int> &arr, int target)
{
  int n = arr.size();
  sort(arr.begin(), arr.end());
  int low = 0, high = n - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
      return mid;
    else if (arr[mid] > target)
      high = mid - 1;
    else
      low = mid + 1;
  }
  return -1;
}

// array is sorted
int recursive(vector<int> &arr, int low, int high, int n, int target)
{
  if (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
      return mid;
    else if (arr[mid] > target)
      return recursive(arr, low, mid - 1, n, target);
    else
      return recursive(arr, mid + 1, high, n, target);
  }
  return -1;
}
int main()
{
  int n;
  ;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int target;
  cin >> target;

  // int result = binary(arr, target);
  // cout << result << endl;

  int answer = recursive(arr, 0, n - 1, n, target);
  cout << answer << endl;
  return 0;
}
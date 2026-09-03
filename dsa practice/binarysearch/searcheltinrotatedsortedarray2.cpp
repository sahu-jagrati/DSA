// search element in rotated sorted array having duplicates elt
#include <iostream>
#include <vector>
using namespace std;

// time complexity-O(log n(base 2)) in average case
// in worst case, time complexity can be approx. O(n/2) because near about half of the array is trim and in last we compare
bool search(vector<int> &arr, int target)
{
  int n = arr.size();
  int low = 0, high = n - 1;
  bool ans = false;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] == target)
      return true;
    if (arr[low] == arr[mid] && arr[mid] == arr[high])
    { // this is the case where unique elt solution fail
      low = low + 1;
      high = high - 1;
      continue;
    }
    // check sorted half
    // if left half is sorted
    if (arr[low] <= arr[mid])

    {
      if (arr[low] <= target && target <= arr[mid])
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    // if right half is sorted
    else
    {
      if (arr[mid] <= target && target <= arr[high])
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }
  }
  return false;
}
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  // assume we have rotated sorted array
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int target;
  cin >> target;
  bool result = search(arr, target);
  cout << result << endl;
  return 0;
}
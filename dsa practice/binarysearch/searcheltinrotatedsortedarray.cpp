// search element in rotated sorted array(unique elements)
#include <iostream>
#include <vector>
using namespace std;

// time complexity-O(log n(base 2))
// and space complexity-O(1)
int search(vector<int> &arr, int target)
{
  int n = arr.size();
  int low = 0, high = n - 1;
  int ans = -1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] == target)
      return mid;
    // identify the sorted half-left/right
    // if left half is sorted
    if (arr[low] <= arr[mid])
    {
      if (arr[low] <= target && target <= arr[mid])
        high = mid - 1;
      else
        low = mid + 1;
    }
    // if right half is  sorted
    else
    {
      if (arr[mid] <= target && target <= arr[high])
        low = mid + 1;
      else
        high = mid - 1;
    }
  }
  return -1;
}
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  // assuming you have rotated sorted array
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int target;
  cin >> target;
  int result = search(arr, target);
  cout << result << endl;
  return 0;
}
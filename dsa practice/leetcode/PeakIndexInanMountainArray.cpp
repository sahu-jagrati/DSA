// You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

// Return the index of the peak element.

// Your task is to solve it in O(log(n)) time complexity.

// Example 1:

// Input: arr = [0,1,0]

// Output: 1

// Example 2:

// Input: arr = [0,2,1,0]

// Output: 1

// Example 3:

// Input: arr = [0,10,5,2]

// Output: 1

// Constraints:

// 3 <= arr.length <= 105
// 0 <= arr[i] <= 106
// arr is guaranteed to be a mountain array.

#include <bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
  int n = arr.size();
  int low = 0, high = n - 1;
  int ans;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if ((arr[mid - 1] < arr[mid] || (mid - 1) > 0) && (arr[mid] > arr[mid + 1] || (mid + 1) < n))
    {
      ans = mid;
      break;
    }
    else if (arr[mid] <= arr[mid + 1])
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return ans;
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
  int result = peakIndexInMountainArray(arr);
  cout << result;
  return 0;
}
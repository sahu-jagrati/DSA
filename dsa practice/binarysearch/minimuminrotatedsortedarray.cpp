// there is very case in finding minimum in rotated sorted array so see in diary

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// this we do for unique elements
// time complexity-O(log n(base 2))
int minimum(vector<int> &arr)
{
  int n = arr.size();
  int ans = INT_MAX;
  int low = 0, high = n - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    // ans = min(ans, arr[mid]); // not required beacuse check in right half
    // check sorted half
    // left half
    if (arr[low] <= arr[mid])
    {
      ans = min(ans, arr[low]);
      low = mid + 1;
    }
    // right half
    else
    {
      ans = min(ans, arr[mid]);
      high = mid - 1;
    }
  }
  return ans;
}
// we can optimize 1st one
int Minimum(vector<int> &arr)
{
  int n = arr.size();
  int ans = INT_MAX;
  int low = 0, high = n - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    // ans = min(ans, arr[mid]);  // not required beacuse check in right half
    // search space is already sorted
    // then always arr[low]is will be smaller
    // in that search space
    if (arr[low] <= arr[high])
    {
      ans = min(ans, arr[low]);
      break;
    }
    // check sorted half
    // left half
    if (arr[low] <= arr[mid])
    {
      ans = min(ans, arr[low]);
      low = mid + 1;
    }
    // right half
    else
    {
      ans = min(ans, arr[mid]);
      high = mid - 1;
    }
  }
  return ans;
}

// array having duplicates
// time complexity-Best case: O(1)(first check finds min)
// average case(few duplicates)-O(log n(base 2))
// worst case (all duplicates)-O(n/2) i.e. approx.O(n)
int minimumInDuplicates(vector<int> &arr)
{
  int n = arr.size();
  int low = 0, high = n - 1;
  int ans = INT_MAX;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    // ans = min(ans, arr[mid]); // not required beacuse check in right half
    if ((arr[low] == arr[mid]) && (arr[mid] == arr[high]))
    {
      low = low + 1;
      high = high - 1;
      continue;
    }
    // search space is already sorted
    // then always arr[low]is will be smaller
    // in that search space
    if (arr[low] <= arr[high])
    {
      ans = min(ans, arr[low]);
      break;
    }
    // check sorted half
    // left half
    if (arr[low] <= arr[mid])
    {
      ans = min(ans, arr[low]);
      low = mid + 1;
    }
    // right half
    else
    {
      ans = min(ans, arr[mid]);
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
  // int result = minimum(arr);
  // int result = Minimum(arr);
  int result = minimumInDuplicates(arr);
  cout << result << endl;
  return 0;
}
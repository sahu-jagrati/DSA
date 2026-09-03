// how many times  has an array been rotated?
//  find minimum in rotated sorted array, there index is the no. of times has an array been rotated

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// for unique element
// we are doing optimize one (see other in minimum part  of rotated sorted array )
int MinimumIndex(vector<int> &arr)
{
  int n = arr.size();
  int ans = INT_MAX;
  int low = 0, high = n - 1;
  int index = -1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    // search space is already sorted
    // then always arr[low]is will be smaller
    // in that search space
    if (arr[low] <= arr[high])
    {
      if (arr[low] < ans)
      {
        ans = arr[low];
        index = low;
      }
      break;
    }
    // check sorted half
    // left half
    if (arr[low] <= arr[mid])
    {
      if (arr[low] < ans)
      {
        ans = arr[low];
        index = low;
      }
      low = mid + 1;
    }
    // right half
    else
    {
      if (arr[mid] < ans)
      {
        ans = arr[mid];
        index = mid;
      }
      high = mid - 1;
    }
  }
  return index;
}

// having duplicates
// time complexity-Best case: O(1)(first check finds min)
// average case(few duplicates)-O(log n(base 2))
// worst case (all duplicates)-O(n/2) i.e. approx.O(n)
int minimumIndex(vector<int> &arr)
{
  int n = arr.size();
  int ans = INT_MAX;
  int low = 0, high = n - 1;
  int index = -1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if ((arr[low] == arr[mid]) && (arr[mid] == arr[high]))
    {
      if (arr[low] < ans)
      {
        ans = arr[low];
        index = low;
      }
      if (arr[high] < ans)
      {
        ans = arr[high];
        index = high;
      }
      low = low + 1;
      high = high - 1;
      continue;
    }
    // search space is already sorted
    // then always arr[low]is will be smaller
    // in that search space
    if (arr[low] <= arr[high])
    {
      if (arr[low] < ans)
      {
        ans = arr[low];
        index = low;
      }
      break;
    }

    // check sorted half
    // left half
    if (arr[low] <= arr[mid])
    {
      if (arr[low] < ans)
      {
        ans = arr[low];
        index = low;
      }
      low = mid + 1;
    }
    // right half
    else
    {
      if (arr[mid] < ans)
      {
        ans = arr[mid];
        index = mid;
      }
      high = mid - 1;
    }
  }
  return index;
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

  // int result = MinimumIndex(arr);
  int result = minimumIndex(arr);
  cout << result << endl;
  return 0;
}
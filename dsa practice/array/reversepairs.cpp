// reverse pairs-in this we have to find no.of pairs which follow given condition-(i<j&&arr[i]>2*arr[j])

#include <iostream>
#include <vector>
using namespace std;

// brute solution-time complexity-approx.O(n^2) and space complexity-O(1)
int reversepairs(vector<int> &arr)
{
  int n = arr.size();
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (arr[i] > (2 * arr[j]))
      {
        count += 1;
      }
    }
  }
  return count;
}

// optimal solution-time complexity-Time complexity of each part
// Merge Sort Split
// The recursion tree has log₂(n) levels (since we divide into halves at each step).

// merge function-
// Merges two sorted halves in O(n) time at each recursion level.

// countPairs function
// Two-pointer approach:

// right only moves forward across the whole function.

// Over all iterations of i, right increments at most (high - mid) times = O(n/2).

// So total cost:

// Outer loop: O(n/2)

// Inner pointer moves: O(n/2) (total, not per outer loop)

// Combined: O(n/2 + n/2) = O(n)

//  total combining
// At each recursion level:

// Merge step: O(n)

// Count pairs: O(n)

// Combined per level: O(n)+O(n)=O(2n)=O(n)

// Number of levels: log₂(n)
// T(n)=O(nlogn)
// space complexity-O(n) for temp array for distorted the original array
void merge(vector<int> &arr, int low, int mid, int high)
{
  vector<int> temp;
  int left = low;
  int right = mid + 1;
  while (left <= mid && right <= high)
  {
    if (arr[left] <= arr[right])
    {
      temp.push_back(arr[left]);
      left++;
    }
    else
    {
      temp.push_back(arr[right]);
      right++;
    }
  }
  while (left <= mid)
  {
    temp.push_back(arr[left]);
    left++;
  }
  while (right <= high)
  {
    temp.push_back(arr[right]);
    right++;
  }
  for (int i = low; i <= high; i++)
  {
    arr[i] = temp[i - low];
  }
}
int countPairs(vector<int> &arr, int low, int mid, int high)
{
  int cnt = 0;
  int right = mid + 1;
  for (int i = low; i <= mid; i++)
  {
    while (right <= high && arr[i] > 2 * arr[right])
      right++;
    cnt += right - (mid + 1);
  }
  return cnt;
}
int mergeSort(vector<int> &arr, int low, int high)
{
  int cnt = 0;
  if (low >= high)
    return cnt;
  int mid = (low + high) / 2;
  cnt += mergeSort(arr, low, mid);
  cnt += mergeSort(arr, mid + 1, high);
  cnt += countPairs(arr, low, mid, high);
  merge(arr, low, mid, high);
  return cnt;
}
int reversePairs(vector<int> &arr)
{
  int n = arr.size();
  return mergeSort(arr, 0, n - 1);
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
  int result = reversepairs(arr);
  cout << result << endl;
  return 0;
}

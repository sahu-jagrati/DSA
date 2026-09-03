// gurantee that other elts. occurs twice and only one single elet. occur once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// brute approach- check left and right of index
// time complexity-O(n)
int single(vector<int> &arr)
{
  sort(arr.begin(), arr.end());
  int n = arr.size();
  if (n == 1)
    return arr[0];
  for (int i = 0; i < n; i++)
  {
    if (i == 0)
    {
      if (arr[i] != arr[i + 1])
        return arr[i];
    }
    else if (i == n - 1)
    {
      if (arr[i] != arr[i - 1])
        return arr[i];
    }
    else
    {
      if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
        return arr[i];
    }
  }
  return -1;
}

// time complexity-O(log n(base 2))
// s.c-O(1)
// we use here binary search so array should be sorted
int Single(vector<int> &arr)
{
  int n = arr.size();
  // edge cases
  if (n == 1)
    return arr[0];
  if (arr[0] != arr[1])
    return arr[0];
  if (arr[n - 1] != arr[n - 2])
    return arr[n - 1];
  // eliminate left and right half by using index-(even,odd)- so single element in right half, so eliminate left half & (odd,even)- so single element in left half, so eliminate right half
  int low = 1, high = n - 2;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
      return arr[mid];
    // eliminate left half
    if (((mid % 2 == 1) && (arr[mid - 1] == arr[mid])) || ((mid % 2 == 0) && (arr[mid] == arr[mid + 1])))
      low = mid + 1;
    // eliminate right half
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
  // int result = single(arr);
  int result = Single(arr);
  cout << result << endl;
  return 0;
}

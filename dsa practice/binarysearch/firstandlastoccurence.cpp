#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// time complexity=O(n)
vector<int> firstAndLastOccurence(vector<int> &arr, int target)
{
  int n = arr.size();
  int first = -1, last = -1;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == target)
    {
      if (first == -1)
        first = i;
      last = i;
    }
  }
  return {first, last};
}

// using lower bound and upper bound-time complexity-2*O(log n(base 2)) and space complexity-O(1)
int lowerBound(vector<int> &arr, int target)
{
  int n = arr.size();
  int low = 0, high = n - 1;
  int ans = n;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] >= target)
    {
      ans = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return ans;
}
int upperBound(vector<int> &arr, int target)
{
  int n = arr.size();
  int low = 0, high = n - 1;
  int ans = n;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] > target)
    {
      ans = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return ans;
}
vector<int> firstAndLast(vector<int> &arr, int target)
{
  int n = arr.size();
  int lb = lowerBound(arr, target);
  int ub = upperBound(arr, target);
  if (lb == n || arr[lb] != target)
    return {-1, -1};
  return {lb, ub - 1};
}

// by using binary search proper-time complexity-2*O(log n(base 2)) and space complexity-O(1)

int first(vector<int> &arr, int target)
{
  int n = arr.size();
  int low = 0, high = n - 1;
  int first = -1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] == target)
    {
      first = mid;
      high = mid - 1; // because we find first so in right we get more then mid
    }
    else if (arr[mid] < target)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return first;
}

int last(vector<int> &arr, int target)
{
  int n = arr.size();
  int low = 0, high = n - 1;
  int last = -1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] == target)
    {
      last = mid;
      low = mid + 1;
    }
    else if (arr[mid] < target)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return last;
}
vector<int> fAndL(vector<int> &arr, int target)
{
  int f = first(arr, target);
  int l = last(arr, target);
  if (f == -1)
    return {-1, -1};
  return {f, l};
}
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  // we assume array is sorted
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int target;
  cin >> target;
  // vector<int> result = firstAndLastOccurence(arr, target);
  vector<int> result = firstAndLast(arr, target);
  // vector<int> result = fAndL(arr, target);
  for (auto it : result)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}
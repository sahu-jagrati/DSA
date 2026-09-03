// we assume array is sorted
// floor-largest number in an array <= target
// ceil-smallest number in an array >=target - this is lower bound problem but only care about that if not exist return -1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// time complexity-O(log n(base 2))
int ceil(vector<int> &arr, int target)
{
  int n = arr.size();
  int low = 0, high = n - 1;
  int ans = -1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] >= target)
    {
      ans = arr[mid];
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return ans;
}

// time complexity-O(log n(base 2))
int floor(vector<int> &arr, int target)
{
  int n = arr.size();
  int low = 0, high = n - 1;
  int ans = -1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] <= target)
    {
      ans = arr[mid];
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
  int target;
  cin >> target;
  int result1 = ceil(arr, target);
  int result2 = floor(arr, target);
  cout << result1 << endl;
  cout << result2 << endl;
  return 0;
}
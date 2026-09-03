// if the target present in the array then return the index
// if target is not present in the array, then insert it in correct position by maintaining the sorting and return the index
// it is same of lower_bound
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// time complexity-O(log n(base 2))
int searchInsertPosition(vector<int> &arr, int target)
{
  int n = arr.size();
  int low = 0, high = n - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] == target)
    {
      return mid;
    }
    else if (arr[mid] > target)
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }

  return low; // position where targett is inserted when not present in array
}
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  // we assume that we have sorted array
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int target;
  cin >> target;
  int result = searchInsertPosition(arr, target);
  cout << result << endl;

  return 0;
}
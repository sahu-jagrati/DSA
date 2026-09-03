
// upper bound-smallest index s.t a[index]>target
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// time complexity-O(log n(base 2))
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
  int result = upperBound(arr, target);
  cout << result << endl;
  auto it = upper_bound(arr.begin(), arr.end(), target);
  cout << it - arr.begin() << endl;
  cout << *it << endl;
  return 0;
}
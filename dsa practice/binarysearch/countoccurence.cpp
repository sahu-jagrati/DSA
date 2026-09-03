#include <iostream>
#include <vector>
using namespace std;

// time complexity-2*O(log n(base 2))

int firstOccurence(vector<int> &arr, int target)
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

int lastOccurence(vector<int> &arr, int target)
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
  int f = firstOccurence(arr, target);
  int l = lastOccurence(arr, target);
  if (f == -1)
    return {-1, -1};
  return {f, l};
}
int countOccurence(vector<int> &arr, int target)
{
  int n = arr.size();
  vector<int> ans = fAndL(arr, target);
  if (ans.at(0) == -1)
    return 0;
  return ans.at(1) - ans.at(0) + 1;
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
  int result = countOccurence(arr, target);
  cout << result << endl;
  return 0;
}

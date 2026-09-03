#include <iostream>
#include <vector>
using namespace std;

// brute approach-generate all subarray
// time complexity- approx. O(n^3)
// space complexity-O(1)
int maximumsubarraysum(vector<int> &arr)
{
  int INT_MIN = -2147483648;
  int maxi = INT_MIN;
  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      int sum = 0;
      for (int k = i; k < j; k++)
      {
        sum += arr[k];
      }
      maxi = max(sum, maxi);
    }
  }
  return maxi;
}

// better approach-
// time complexity- approx. O(n^2)
// space complexity-O(1)
int maximumSubarraysum(vector<int> &arr)
{
  int INT_MIN = -2147483648;
  int maxi = INT_MIN;
  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    int sum = 0;
    for (int j = i; j < n; j++)
    {
      sum += arr[j];
      maxi = max(maxi, sum);
    }
  }
  return maxi;
}

// optimal appproach- kadane's Algorithm
// time complexity-O(n)
// space complexity-O(1)
int maximumSubarraySum(vector<int> &arr)
{
  // for printing the subarray with maximum sum
  int ansStart = -1;
  int ansEnd = -1;
  int INT_MIN = -2147483648;
  int maxi = INT_MIN;
  int n = arr.size();
  int sum = 0;
  int start;
  for (int i = 0; i < n; i++)
  {
    if (sum == 0)
    {
      start = i;
    }
    sum += arr[i];
    if (sum > maxi)
    {
      maxi = sum;
      ansStart = start;
      ansEnd = i;
    }
    if (sum < 0)
    {
      sum = 0;
    }
  }
  if (maxi < 0)
  {
    return 0;
  }
  for (int i = ansStart; i <= ansEnd; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
  return maxi;
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
  // int result = maximumsubarraysum(arr);
  // int result = maximumSubarraysum(arr);
  int result = maximumSubarraySum(arr);
  cout << result << endl;
  return 0;
}

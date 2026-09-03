#include <iostream>
#include <vector>
#include <map>
using namespace std;

// brute approach-
// i) time complexity-approx. O(n^3) and space complexity - O(1)
int longest(vector<int> &arr, int target)
{
  int n = arr.size();
  int length = 0; // initial length of subarray
  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      int sum = 0;
      for (int k = i; k < j; k++)
      {
        sum += arr[k];
      }
      if (sum == target)
      {
        length = max(length, j - i);
      }
    }
  }
  return length;
}

// ii) time complexity-approx. O(n^2) and space complexity - O(1)
int longestSubarray(vector<int> &arr, int k)
{
  int n = arr.size();
  int length = 0; // initial length of subarray
  for (int i = 0; i < n; i++)
  {
    int sum = 0;
    for (int j = i; j < n; j++)
    {
      sum += arr[j];
      if (sum == k)
      {
        length = max(length, j - i + 1);
      }
    }
  }
  return length;
}

// better approach-
// i) for positive only no zeroes-
int longestSubarrayWith(vector<int> &arr, long long k)
{
  map<long long, int> preSumMap;
  long long sum = 0;
  int maxLen = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    sum += arr[i];
    if (sum == k)
    {
      maxLen = max(maxLen, i + 1);
    }
    int remaining = sum - k;
    if (preSumMap.find(remaining) != preSumMap.end())
    {
      int len = i - preSumMap[remaining];
      maxLen = max(maxLen, len);
    }
    preSumMap[sum] = i;
  }
  return maxLen;
}
// this code also works for negatives or for positive as well as negatives with zeroes or
// ii) for positive with zeroes - arr[]={ 2,0,0,3} and k=3 so in this maxlen is 3{0,0,3} not 1{3}
// time complexity - O(nlogn) in case of ordered map and in case of unordered map - O(n*1) or in worst case - O(n*n) when there is collisions
// space complexity- O(n) in worst case when all prefix sum is different

int longestSubarrayWithSum(vector<int> &arr, long long k)
{
  map<long long, int> preSumMap;
  long long sum = 0;
  int maxLen = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    sum += arr[i];
    if (sum == k)
    {
      maxLen = max(maxLen, i + 1);
    }
    long long remaining = sum - k;
    if (preSumMap.find(remaining) != preSumMap.end())
    {
      int len = i - preSumMap[remaining];
      maxLen = max(maxLen, len);
    }

    // this block adds the current prefixsum(sum) into the map if it's not already present
    // To **store the first occurrence of a particular prefix sum (sum) at index i.

    // This is important because we want the longest subarray with sum k.

    // So, if the same sum appears again later, we don’t overwrite the earlier (smaller) index.
    if (preSumMap.find(sum) == preSumMap.end())
    {
      preSumMap[sum] = i;
    }
  }
  return maxLen;
}
// this ii) better approach is the optimal approach for array having positive as well as negative

// optimal approach for array having only positive with zeroes- two pointer
// time complexity - O(2n) and space complexity is O(1)
// Outer Loop:
// right moves from 0 to n - 1, i.e., at most n steps.

// Inner Loop:
// left also moves from 0 to n - 1, but only in total across all iterations.
// e.g. - arr[]=[1,2,3,1,1,1,1,3,3]  and k=6, in this last sum = 9>6 so in this case we move left pointer until we get less than 6 or equal to 6 so in this almost we iterate totally in array in worst case

// Since each element is added once (to sum) and removed at most once, both right and left pointers together make at most 2n total moves.
long long longestSubarrayWithSumK(vector<int> &arr, int k)
{
  int left = 0, right = 0;
  long long sum = arr[0];
  int maxlen = 0;
  int n = arr.size();
  while (right < n)
  {
    while (left <= right && sum > k)
    {
      sum -= arr[left];
      left++;
    }
    if (sum == k)
    {
      maxlen = max(maxlen, right - left + 1);
    }
    right++;
    if (right < n)
    {
      sum += arr[right];
    }
  }
  return maxlen;
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
  int k;
  cin >> k;
  // int result = longest(arr, k);
  // int result = longestSubarray(arr, k);
  // int result = longestSubarrayWith(arr, k);
  // int result = longestSubarrayWithSum(arr, k);
  int result = longestSubarrayWithSumK(arr, k);
  cout << result << endl;
  return 0;
}
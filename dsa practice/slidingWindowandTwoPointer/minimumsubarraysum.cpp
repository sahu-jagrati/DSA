// Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

// Example 1:
// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.

// Example 2:
// Input: target = 4, nums = [1,4,4]
// Output: 1

// Example 3:
// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0

// Constraints:

// 1 <= target <= 10^9
// 1 <= nums.length <= 10^5
// 1 <= nums[i] <= 10^4

#include <bits/stdc++.h>
using namespace std;

// naive solution- geneate all subarray with given condition
// t.c-O(n^2) where n is size of array
// s.c-O(1)
int minimum(vector<int> &nums, int target)
{
  int n = nums.size();
  int minlen = INT_MAX;
  for (int i = 0; i < n; i++)
  {
    long long sum = 0;
    for (int j = i; j < n; j++)
    {
      sum += nums[j];
      if (sum >= target)
        minlen = min(minlen, j - i + 1);
    }
  }
  if (minlen == INT_MAX)
    return 0;
  return minlen;
}

// optimal solution-two pointer/sliding window
// t.c-O(N(outer while loop)+N(inner while loop))=O(2N) where N is size of array
// s.c-O(1)
int minSubArrayLen(int target, vector<int> &nums)
{
  int minlen = INT_MAX;
  int n = nums.size();
  int l = 0, r = 0;
  long long sum = 0;

  // run n time
  while (r < n)
  {
    sum += nums[r];

    // this while loop not run n length every time, in worst case it is run n length at a single time throughout the whole journey
    while (sum >= target)
    {
      minlen = min(minlen, r - l + 1);
      sum -= nums[l];
      l++; // shrink the current window until the zeros<=k
    }
    r++; // expand the window
  }
  if (minlen == INT_MAX)
    return 0;
  return minlen;
}

int main()
{
  int n;
  cout << "Enter the size of an array: ";
  cin >> n;
  vector<int> nums(n);
  cout << "Enter the elt of an array: ";
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  int target;
  cout << "Enter the value of target: ";
  cin >> target;
  int answer = minimum(nums, target);
  // int answer = minSubArrayLen(target, nums);
  cout << "Minimum size subarray sum: " << answer << endl;
  return 0;
}
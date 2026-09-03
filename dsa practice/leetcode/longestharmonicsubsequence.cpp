// We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

// Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

// Example 1:

// Input: nums = [1,3,2,2,5,2,3,7]

// Output: 5

// Explanation:

// The longest harmonious subsequence is [3,2,2,2,3].

// Example 2:

// Input: nums = [1,2,3,4]

// Output: 2

// Explanation:

// The longest harmonious subsequences are [1,2], [2,3], and [3,4], all of which have a length of 2.

// Example 3:

// Input: nums = [1,1,1,1]

// Output: 0

// Explanation:

// No harmonic subsequence exists.

// Constraints:

// 1 <= nums.length <= 2 * 10^4
// -10^9 <= nums[i] <= 10^9

#include <bits/stdc++.h>
using namespace std;

// first we sort the array because we want difference of max value and min value
// then we use sliding window approach in which we wnat only max and min value of current window
// subsequence means it is a part of array and can be continous or can not be

int findLHS(vector<int> &nums)
{
  int n = nums.size();
  sort(nums.begin(), nums.end());
  int maxLen = 0; // if not get then return 0;
  int l = 0, r = 0;
  while (r < n)
  {
    // we want only difference of nums[r]-nums[l]
    while (nums[r] - nums[l] > 1)
    {
      // shrink the window
      l++;
    }
    if (nums[r] - nums[l] == 1) // because we want only that length in which max value-min value == 1 and we already sort the array so
    {
      maxLen = max(maxLen, r - l + 1);
    }
    r++; // expand the window
  }
  return maxLen;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  int answer = findLHS(nums);
  cout << answer << endl;
  return 0;
}
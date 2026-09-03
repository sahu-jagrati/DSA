// You are given an integer array nums and an integer target.

// Return the number of subarrays of nums in which target is the majority element.

// The majority element of a subarray is the element that appears strictly more than half of the times in that subarray.

// Example 1:

// Input: nums = [1,2,2,3], target = 2

// Output: 5

// Explanation:

// Valid subarrays with target = 2 as the majority element:

// nums[1..1] = [2]
// nums[2..2] = [2]
// nums[1..2] = [2,2]
// nums[0..2] = [1,2,2]
// nums[1..3] = [2,2,3]
// So there are 5 such subarrays.

// Example 2:

// Input: nums = [1,1,1,1], target = 1

// Output: 10

// Explanation:

// ​​​​​​​All 10 subarrays have 1 as the majority element.

// Example 3:

// Input: nums = [1,2,3], target = 4

// Output: 0

// Explanation:

// target = 4 does not appear in nums at all. Therefore, there cannot be any subarray where 4 is the majority element. Hence the answer is 0.

// Constraints:

// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 10^​​​​​​​9
// 1 <= target <= 10^9

#include <bits/stdc++.h>
using namespace std;

// brute force - by generating all subarrays with three for loops
// we use unordered hashmap so for each update/check in the hashmap is O(1)
// total t.c-O(n^3)
// s.c - O(n) for hashmap in worst case
int countMajoritySubarrays(vector<int> &nums, int target)
{
  int n = nums.size();
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      unordered_map<int, int> mpp;
      for (int k = i; k <= j; k++)
      {
        mpp[nums[k]]++;
      }
      if (mpp.count(target))
      {
        if (mpp[target] > (j - i + 1) / 2)
        {
          cnt += 1;
        }
      }
    }
  }
  return cnt;
}

// better solution- by using two for loops
// we use unordered hashmap so for each update/check in the hashmap is O(1)
// total t.c-O(n^2)
// s.c - O(n) for hashmap in worst case
int countMajoritysubarrays(vector<int> &nums, int target)
{
  int n = nums.size();
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    unordered_map<int, int> mpp;
    for (int j = i; j < n; j++)
    {
      mpp[nums[j]]++;
      if (mpp.count(target))
      {
        if (mpp[target] > (j - i + 1) / 2)
        {
          cnt += 1;
        }
      }
    }
  }
  return cnt;
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
  int target;
  cin >> target;
  // cout << countMajoritySubarrays(nums, target);
  cout << countMajoritysubarrays(nums, target);
  return 0;
}
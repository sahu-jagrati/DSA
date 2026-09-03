// Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

// Example 1:

// Input: nums = [3,10,5,25,2,8]
// Output: 28
// Explanation: The maximum result is 5 XOR 25 = 28.
// Example 2:

// Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
// Output: 127

// Constraints:

// 1 <= nums.length <= 2 * 10^5
// 0 <= nums[i] <= 2^31 - 1

#include <bits/stdc++.h>
using namespace std;

// brute force solution but this gives TLE for large array
int findMaximumXOR(vector<int> &nums)
{
  int n = nums.size();
  int maxXor = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      // xor is a reserved keyword in C++ so we use xorr
      int xorr = 0;
      xorr = xorr ^ nums[i];
      xorr = xorr ^ nums[j];
      if (xorr > maxXor)
        maxXor = xorr;
    }
  }
  return maxXor;
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
  cout << findMaximumXOR(nums);
  return 0;
}
// Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

// You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

// Example 1:

// Input: nums = [1,2,1,3,2,5]
// Output: [3,5]
// Explanation:  [5, 3] is also a valid answer.
// Example 2:

// Input: nums = [-1,0]
// Output: [-1,0]
// Example 3:

// Input: nums = [0,1]
// Output: [1,0]

// Constraints:

// 2 <= nums.length <= 3 * 10^4
// -2^31 <= nums[i] <= 2^31 - 1
// Each integer in nums will appear twice, only two integers will appear once.

#include <bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int> &nums)
{
  int n = nums.size();
  unordered_map<int, int> mpp;
  for (int i = 0; i < n; i++)
    mpp[nums[i]]++;
  vector<int> ans; // ans is of only 2 size mention in question
  for (auto it : mpp)
  {
    if (it.second == 1)
      ans.push_back(it.first);
  }
  return ans;
}

// but question say do in linear runtime and constant space
// we use xor
// we know - 1. a^a=0 and 2. a^0=a
// 🧠 Intuition (Very Important)
// Same numbers cancel out using XOR
// Only a and b remain → a ^ b
// We find a bit where they differ
// Split array → now each group has one unique number
// Works for:

// positive numbers
// negative numbers
// mixed arrays
// t.c-O(n)
// s.c-O(1)
vector<int> findSingleNumbers(vector<int> &nums)
{
  long long xr = 0; // we use long long for large numbers
  // step-1 xor of all elts- so we get xr=a^b (where a and b are the two unique numbers)
  for (int x : nums)
  {
    xr ^= x;
  }
  // step-2 find rightmost set bit- which is a bit where a and b differ.
  int rightmostSetBit = xr & (-xr);
  int num1 = 0, num2 = 0;
  // step -3 divide into two groups
  //   Group 1 → bit is set
  // Group 2 → bit is not set

  // Then XOR separately.s
  for (int x : nums)
  {
    if (x & rightmostSetBit)
      num1 ^= x; // because 0^x=x
    else
      num2 ^= x; // for a^a=0 and a^0=a
  }
  return {num1, num2};
}
int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  vector<int> ans = singleNumber(nums);
  cout << ans[0] << " " << ans[1];
  return 0;
}
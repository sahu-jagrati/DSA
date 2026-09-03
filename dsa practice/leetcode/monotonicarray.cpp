// An array is monotonic if it is either monotone increasing or monotone decreasing.

// An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

// Given an integer array nums, return true if the given array is monotonic, or false otherwise.

// Example 1:

// Input: nums = [1,2,2,3]
// Output: true
// Example 2:

// Input: nums = [6,5,4,4]
// Output: true
// Example 3:

// Input: nums = [1,3,2]
// Output: false

// Constraints:

// 1 <= nums.length <= 10^5
// -10^5 <= nums[i] <= 10^5

#include <bits/stdc++.h>
using namespace std;

bool monotonic(vector<int> &nums)
{
  int n = nums.size();
  bool increasing = true, decreasing = true;
  for (int i = 1; i < n; i++)
  {
    if (nums[i] > nums[i - 1])
      decreasing = false;
    else if (nums[i - 1] > nums[i])
      increasing = false;
  }
  return increasing || decreasing;
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
  bool answer = monotonic(nums);
  cout << answer << endl;
  return 0;
}
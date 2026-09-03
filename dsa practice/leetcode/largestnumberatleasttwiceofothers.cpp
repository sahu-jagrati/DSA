// You are given an integer array nums where the largest integer is unique.

// Determine whether the largest element in the array is at least twice as much as every other number in the array. If it is, return the index of the largest element, or return -1 otherwise.

// Example 1:

// Input: nums = [3,6,1,0]
// Output: 1
// Explanation: 6 is the largest integer.
// For every other number in the array x, 6 is at least twice as big as x.
// The index of value 6 is 1, so we return 1.
// Example 2:

// Input: nums = [1,2,3,4]
// Output: -1
// Explanation: 4 is less than twice the value of 3, so we return -1.

// Constraints:

// 2 <= nums.length <= 50
// 0 <= nums[i] <= 100
// The largest element in nums is unique.

#include <bits/stdc++.h>
using namespace std;

int dominantIndex(vector<int> &nums)
{
  int n = nums.size();
  int largestelt = INT_MIN;
  int indexOfLargestElt = -1;
  for (int i = 0; i < n; i++)
  {
    if (largestelt < nums[i])
    {
      largestelt = nums[i];
      indexOfLargestElt = i;
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (i != indexOfLargestElt && 2 * nums[i] > largestelt)
      return -1;
  }
  return indexOfLargestElt;
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
  int answer = dominantIndex(nums);
  cout << answer << endl;
  return 0;
}
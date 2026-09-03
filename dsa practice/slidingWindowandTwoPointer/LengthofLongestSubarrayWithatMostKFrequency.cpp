// You are given an integer array nums and an integer k.

// The frequency of an element x is the number of times it occurs in an array.

// An array is called good if the frequency of each element in this array is less than or equal to k.

// Return the length of the longest good subarray of nums.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:

// Input: nums = [1,2,3,1,2,3,1,2], k = 2
// Output: 6
// Explanation: The longest possible good subarray is [1,2,3,1,2,3] since the values 1, 2, and 3 occur at most twice in this subarray. Note that the subarrays [2,3,1,2,3,1] and [3,1,2,3,1,2] are also good.
// It can be shown that there are no good subarrays with length more than 6.
// Example 2:

// Input: nums = [1,2,1,2,1,2,1,2], k = 1
// Output: 2
// Explanation: The longest possible good subarray is [1,2] since the values 1 and 2 occur at most once in this subarray. Note that the subarray [2,1] is also good.
// It can be shown that there are no good subarrays with length more than 2.
// Example 3:

// Input: nums = [5,5,5,5,5,5,5], k = 4
// Output: 4
// Explanation: The longest possible good subarray is [5,5,5,5] since the value 5 occurs 4 times in this subarray.
// It can be shown that there are no good subarrays with length more than 4.

// Constraints:

// 1 <= nums.length <= 10^5
// 1 <= nums[i] <= 10^9
// 1 <= k <= nums.length

#include <bits/stdc++.h>
using namespace std;

// we use sliding window approach here to solve this problem
// I solve this problem by own fully
// we want maxLength of subarray having frequency of each elt less than or equal to k
// so for storing frequency for each elt we use unordered map because it take O(1) in average
// so first we insert elt by increasing its frequency in map
// then we check if frequency of that elt >k then we shrink our window means l++ until the frequency of current elt is <=k
// after that when frequency of current elt is <=k we calculate the maxLength
// after that we increase r each time until r<n

// t.c-O(n(for outer loop)+n(for inner while loop))=O(2n), never be O(n^2) because each time we never removed n elts from the map,  where n is size of array nums
// s.c-O(n) in worst case for map to storing all elts having frequency 1
int maxSubarrayLength(vector<int> &nums, int k)
{
  int n = nums.size();
  int maxLength = 0;
  int l = 0, r = 0;
  unordered_map<int, int> mpp;
  while (r < n)
  {
    mpp[nums[r]]++;
    while (mpp[nums[r]] > k)
    {
      mpp[nums[l]]--;

      l++;
    }
    if (mpp[nums[r]] <= k)
    {
      maxLength = max(maxLength, r - l + 1);
    }
    r++;
  }
  return maxLength;
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
  int k;
  cin >> k;
  cout << maxSubarrayLength(nums, k);
  return 0;
}
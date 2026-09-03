// You are given an integer array nums and an integer k.

// An integer x is almost missing from nums if x appears in exactly one subarray of size k within nums.

// Return the largest almost missing integer from nums. If no such integer exists, return -1.

// A subarray is a contiguous sequence of elements within an array.

// Example 1:

// Input: nums = [3,9,2,1,7], k = 3

// Output: 7

// Explanation:

// 1 appears in 2 subarrays of size 3: [9, 2, 1] and [2, 1, 7].
// 2 appears in 3 subarrays of size 3: [3, 9, 2], [9, 2, 1], [2, 1, 7].
// 3 appears in 1 subarray of size 3: [3, 9, 2].
// 7 appears in 1 subarray of size 3: [2, 1, 7].
// 9 appears in 2 subarrays of size 3: [3, 9, 2], and [9, 2, 1].
// We return 7 since it is the largest integer that appears in exactly one subarray of size k.

// Example 2:

// Input: nums = [3,9,7,2,1,7], k = 4

// Output: 3

// Explanation:

// 1 appears in 2 subarrays of size 4: [9, 7, 2, 1], [7, 2, 1, 7].
// 2 appears in 3 subarrays of size 4: [3, 9, 7, 2], [9, 7, 2, 1], [7, 2, 1, 7].
// 3 appears in 1 subarray of size 4: [3, 9, 7, 2].
// 7 appears in 3 subarrays of size 4: [3, 9, 7, 2], [9, 7, 2, 1], [7, 2, 1, 7].
// 9 appears in 2 subarrays of size 4: [3, 9, 7, 2], [9, 7, 2, 1].
// We return 3 since it is the largest and only integer that appears in exactly one subarray of size k.

// Example 3:

// Input: nums = [0,0], k = 1

// Output: -1

// Explanation:

// There is no integer that appears in only one subarray of size 1.

// Constraints:

// 1 <= nums.length <= 50
// 0 <= nums[i] <= 50
// 1 <= k <= nums.length

// Hint 1
// Solve the problem for three different cases: k = 1, k = n, and 1 < k < n
// Hint 2
// If k = 1, return the largest element that occurs exactly once in nums
// Hint 3
// If k = n, return the largest element in nums
// Hint 4
// If 1 < k < n, all elements different from nums[0] and nums[n - 1] will occur in more than one subarray of size k. Hence, the answer is the largest of nums[0] and nums[n - 1] if they both occur exactly once in the array. If one of them occurs more than once, return the other. If both of them occur more than once, return -1.

#include <bits/stdc++.h>
using namespace std;

// An integer x is almost missing from nums if x appears in exactly one subarray of size k within nums means if we take an any subarray of size k then x is appear only in one subarray then we can say x is missing integer there is no boundary how many times x exist but it has to be in only one subarray of size k means suppose x exist 2 times in nums then both x should be only in one subsarray of size k if they also appear in other subarray then x is not missing integer so from this we can say that frequency of x in nums should be 1

// so from given question I conclude that, for x should be missing integer its frequency should be 1 and it appear only in one subarray of size k

// I used hint to solve this problem

// t.c-
// unordered map takes O(1) at an average
// O(n)(for frequency counting)+O(n)(if k==1 or k==n )
// s.c-O(n) in worst case when all integers with frequency 1 for map
int largestInteger(vector<int> &nums, int k)
{
  int n = nums.size();
  // we take unordered map to store frquency of elt
  unordered_map<int, int> mpp;
  for (int i = 0; i < n; i++)
  {
    mpp[nums[i]]++;
  }
  // when k==1 means we want subarray of size 1 if nums[i] have frequency > 1 then there can be more than one subarray of size 1 having nums[i] so we want largest element that occurs exactly once in nums so it appear only in one subarray of size 1
  if (k == 1)
  {
    int largest = -1;
    for (int i = 0; i < n; i++)
    {
      if (mpp[nums[i]] == 1)
      {
        largest = max(largest, nums[i]);
      }
    }
    return largest;
  }
  // when k==n means subarray is an entire array so there is only one subarray for k==n which is entire nums so from that largest elt in nums is larget missing integer because here size of subarray is k==n means there is no other subarray so any elt cannot appear in other arrays because we have only one subarray for k==n so in that whoever is largest elt is our answer no matter how many times it appears because it appear only in subarray
  if (k == n)
  {
    int largest = -1;
    for (int i = 0; i < n; i++)
    {
      largest = max(largest, nums[i]);
    }
    return largest;
  }
  // when 1<k<n  in that case all elts different from nums[0] and nums[n-1] will occur in more than one subarray of size k example : nums=[3,9,2,1,7],k=2 here we want subarray of size 2 if talk about elt different from nums[0] and nums[n-1] like 9 it appears in two subarray of size k=2 which are [3,9] , [9,2] similarly all remaining elts different from nums[0] and nums[n-1] occur in more than one subarray so these cannot be missing integer because they appear in more than one subarray. Hence the answer is the largest of nums[0] and nums[n-1] if they both occur exactly once in the array. If one of them occurs more than once, return the other. If both of them occur more than once,return -1. i.e if there frequency is only 1 then answer is max(nums[0],nums[n-1]) because frequency is 1 so whatever k in between 1 to n they appear exactly in one subarray of size k like example: nums=[3,9,7,2,1,7],k=4 if we see nums[0] have frequency 1 and nums[n-1]=7 having frequnecy = 2 so here answer is nums[0]=3 because for nums[0] there is only one subarray of size k=4 in which it appear which is [3,9,7,2] while for nums[n-1]=7 there are three subarray in which 7 appear these are: [3,9,7,2],[9,7,2,1],[7,2,1,7]
  else
  {
    if (mpp[nums[0]] == 1 && mpp[nums[n - 1]] == 1)
      return max(nums[0], nums[n - 1]);
    else if (mpp[nums[0]] == 1 && mpp[nums[n - 1]] != 1)
      return nums[0];
    else if (mpp[nums[0]] != 1 && mpp[nums[n - 1]] == 1)
      return nums[n - 1];
  }
  return -1; // when no missing integer exists
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
  cout << largestInteger(nums, k);
  return 0;
}
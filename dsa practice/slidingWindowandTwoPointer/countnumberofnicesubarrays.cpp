// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

// Return the number of nice sub-arrays.

// Example 1:
// Input: nums = [1,1,2,1,1], k = 3
// Output: 2
// Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

// Example 2:
// Input: nums = [2,4,6], k = 1
// Output: 0
// Explanation: There are no odd numbers in the array.

// Example 3:
// Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
// Output: 16

// Constraints:

// 1 <= nums.length <= 50000
// 1 <= nums[i] <= 10^5
// 1 <= k <= nums.length

#include <bits/stdc++.h>
using namespace std;

// this problem is similar to binary subarrays with given sum that we do previous
// if in our problem if we replace odd number with 1 and even number with 0 then it become binary array so we have to find binary subarray with sum=k and same here we want number of k odd in the subarray so like

// example- nums=[1,5,2,1,1],k=3
// convert in binary array- nums=[1,1,0,1,1],k=3

// where 1 represent nums[i] is odd number and 0 represent nums[i] is even number

// so number of subarray with sum=k is our answer
// here we have subarray-[1,1,0,1],[1,0,1,1] with sum=3=k only these so answer = 2

// we use two pointer/sliding window for getting subarray with given sum=k
// for conversion of nums to binary nums we can say if nums[i]%2 because for odd it give 1 and for even it give 0

// we have to count number of subarray with sum = k after conversion so we cannot calculate this directly by two pointers
// we do this by pattern-3 of two pointers/sliding window
// if we directly use two pointers here it is difficult to count subarray with sum=k
// it give wrong answer, we cannot figure out where to move l and r because we looking for sum=k so
// so we use pattern -3 of two pointers/sliding window whenever we are not sure about shrinking and expanding
//  number of subarray with sum = k  is equal to (x-y) where
// x=  number of subarray with sum <=k
// y= number of subarray with sum <=k-1
int numberOfSubarraysWithSumLessThank(vector<int> &nums, int goal)
{
  if (goal < 0)
    return 0;
  int n = nums.size();
  // run n times
  int l = 0, r = 0, sum = 0, cnt = 0;
  while (r < n)
  {
    sum += (nums[r] % 2); // after convert odd and even number to 1 and 0
    //  inner while loop not run n length every time, in worst case it is run n length at a single time throughout the whole journey
    while (sum > goal)
    {
      sum = sum - (nums[l] % 2);
      l++;
    }
    // when sum<=goal, number of subarray is (r-l+1) length of that subarray so we add to cnt
    // because when the largest subarray is valid then its subarray are also valid so we add length to cnt
    cnt = cnt + (r - l + 1);
    r++;
  }
  return cnt;
}

// O(N(outer while loop)+N(inner while loop)
//  inner while loop not run n length every time, in worst case it is run n length at a single time throughout the whole journey
// t.c-O(2*(2*N)) where N is size of nums array
// s.c-O(1)
int numberOfNiceSubarray(vector<int> &nums, int k)
{
  int cnt1 = numberOfSubarraysWithSumLessThank(nums, k);
  int cnt2 = numberOfSubarraysWithSumLessThank(nums, k - 1);
  return cnt1 - cnt2;
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
  int answer = numberOfNiceSubarray(nums, target);
  cout << answer << endl;
  return 0;
}
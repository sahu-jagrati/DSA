// binary subarray with sum/count subarray sum equals to k

// we already done the problem count subarray with sum=k in that array has +ve,-ve numbers here we have only binary(0 and 1)
// for already done problem we have optimal solution - hashing that take t.c-O(N) when we consider map takes O(1) time or if take logarithmic then take it also and s.c-O(N where N is size of array)

// here this optimal solution also can use but we have only binary in our array so we can opitimize it more by space complexity
// by using two pointer/sliding window

// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

// A subarray is a contiguous part of the array.

// Example 1:
// Input: nums = [1,0,1,0,1], goal = 2
// Output: 4
// Explanation: The 4 subarrays are with goal=2
// [1,0,1]
// [1,0,1,0]
// [0,1,0,1]
// [1,0,1]

// Example 2:

// Input: nums = [0,0,0,0,0], goal = 0
// Output: 15

// Constraints:

// 1 <= nums.length <= 3 * 104
// nums[i] is either 0 or 1.
// 0 <= goal <= nums.length

// if we directly use two pointers here it is difficult to count subarray with sum=goal
// it give wrong answer, we cannot figure out where to move l and r because we looking for sum=k so
// so we use pattern -3 of two pointers/sliding window whenever we are not sure about shrinking and expanding

//  number of subarray with sum = goal  is equal to (x-y) where
// x=  number of subarray with sum <=goal
// y= number of subarray with sum <=goal-1

// for more details see notes
// for brute sol. - generate all subarrays with sum<=k, then sum<=k-1 and get(x-y) for sum=k we do this approach in various question already
// better solu- hashing done in array playlist

#include <bits/stdc++.h>
using namespace std;

int numberOfSubarraysWithSumLessThanGoal(vector<int> &nums, int k)
{
  if (k < 0)
    return 0;
  int n = nums.size();
  int l = 0, r = 0, sum = 0, cnt = 0;
  // run n times
  while (r < n)
  {
    sum += nums[r];
    //  inner while loop not run n length every time, in worst case it is run n length at a single time throughout the whole journey
    while (sum > k)
    {
      sum = sum - nums[l];
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
// s.c-O(1) we optimize s.c from more hashing solution
int numSubarraysWithSum(vector<int> &nums, int goal)
{
  int cnt1 = numberOfSubarraysWithSumLessThanGoal(nums, goal);
  int cnt2 = numberOfSubarraysWithSumLessThanGoal(nums, goal - 1);
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
  int answer = numSubarraysWithSum(nums, target);
  cout << answer << endl;
  return 0;
}

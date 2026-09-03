// Given an integer array nums and an integer k, return the number of good subarrays of nums.

// A good array is an array where the number of different integers in that array is exactly k.

// For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
// A subarray is a contiguous part of an array.

// Example 1:

// Input: nums = [1,2,1,2,3], k = 2
// Output: 7
// Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
// Example 2:

// Input: nums = [1,2,1,3,4], k = 3
// Output: 3
// Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].

// Constraints:

// 1 <= nums.length <= 2 * 10^4
// 1 <= nums[i], k <= nums.length

// we want subarray that have exactly k different integer and integere can be repeated but no.of different integers are exactly k

#include <bits/stdc++.h>
using namespace std;

// naive solution- generate all subarray with exactly k different integers
// we use map for count different integers

// t.c-O(n^2) and we think unorderedmap take O(1) to insert in average case
// s.c-O(n) for mpp in worst case when array has all integers distinct and k=n
// where n is size of array
int numberOfSubarrayWithExactlykDifferentIntgers(vector<int> &nums, int k)
{
  int n = nums.size();
  int cnt = 0;
  unordered_map<int, int> mpp; // store<integer,frequency>
  for (int i = 0; i < n; i++)
  {
    mpp.clear();
    for (int j = i; j < n; j++)
    {
      mpp[nums[j]]++;
      // when subarray has exactly k different integers
      if (mpp.size() == k)
        cnt = cnt + 1;
      else if (mpp.size() > k)
        break;
    }
  }
  return cnt;
}

// optimal solution- // if we directly use two pointers here it is difficult to count subarray with exactly k different integers
// it give wrong answer, we cannot figure out where to move l and r because we looking for exactly k so
// so we use pattern -3 of two pointers/sliding window whenever we are not sure about shrinking and expanding

//  number of subarray with exactly k different integers  is equal to (x-y) where
// x=  number of subarray with <= k different integers and
// y= number of subarray with <= (k-1) different integers

// also use map to cnt frequency

// t.c-O(n(outer while looop)+n(inner while loop))=O(2*n) and we think unorderedmap take O(1) to insert in average case, where n is size of array nums
// s.c-O(n) for mpp  when in worst case when array has all integers distinct and k=n
// where n is size of array
int numberOfSubarrayWithlessThanorEqualTokDifferentIntgers(vector<int> &nums, int goal)
{
  if (goal < 0)
    return 0;
  int n = nums.size();
  int l = 0, r = 0, cnt = 0;
  unordered_map<int, int> mpp; // store<integer,frequency>

  // run n times
  while (r < n)
  {
    mpp[nums[r]]++;

    //  inner while loop not run n length every time, in worst case it is run n length at a single time throughout the whole journey
    while (mpp.size() > goal)
    {
      mpp[nums[l]]--;
      if (mpp[nums[l]] == 0)
        mpp.erase(nums[l]);
      l = l + 1;
    }
    // when mpp size <=goal
    //  number of subarray is (r-l+1) length of that subarray so we add to cnt
    // because when the largest subarray is valid then its subarray are also valid so we add length to cnt
    cnt = cnt + (r - l + 1);
    r++;
  }
  return cnt;
}

// t.c-O(2*(2n)) for both function
int numberOfSubarrayWithExactlykDifferentIntger(vector<int> &nums, int k)
{
  int cnt1 = numberOfSubarrayWithlessThanorEqualTokDifferentIntgers(nums, k);
  int cnt2 = numberOfSubarrayWithlessThanorEqualTokDifferentIntgers(nums, k - 1);
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
  int k;
  cout << "Enter the value of k: ";
  cin >> k;
  // int answer = numberOfSubarrayWithExactlykDifferentIntgers(nums, k);
  int answer = numberOfSubarrayWithExactlykDifferentIntger(nums, k);
  cout << "NUmber of Subarray with exactly k different integers: " << answer << endl;
  return 0;
}
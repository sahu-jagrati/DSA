// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

// flip means you can change 0 to 1
// so we want consecutive 1's after flip at most k 0's

// Example 1:
// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// for this if i) we flip starting 2 0's to 1 then no.of consecutive 1's are 5
// ii) if we flip second and third 0's to 1 then  no.of consecutive 1's are 6
// iii)if we flip third and last 0's to 1 then  no.of consecutive 1's are 6

// so max len of consecutive 1's after flip at most k 0's is 6
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

// Example 2:
// Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
// Output: 10
// Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

// Constraints:

// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.
// 0 <= k <= nums.length

#include <bits/stdc++.h>
using namespace std;

// our question is find max consecutive 1's after flip at most k 0's
// so we can say that our question is that find longest subarraywith atmost k zeros means longest subarray that have 1 but zero can atmost k

// naive solution- generate all subarrays with atmost k zeros

// t.c-O(n^2) approx. where n is size of array
// s.c-O(1)
int maxOnes(vector<int> &nums, int k)
{
  int n = nums.size();
  int maxlen = 0;
  for (int i = 0; i < n; i++)
  {
    int zeros = 0;
    for (int j = i; j < n; j++)
    {
      if (nums[j] == 0)
        zeros++;
      if (zeros <= k)
      {
        maxlen = max(maxlen, j - i + 1);
      }
      // if zeros>k
      else
      {
        break;
      }
    }
  }
  return maxlen;
}

// better solution-two pointers/sliding window- pattern 2-better solution
// this is also optimal solution when we want to print subarray of maxlen
// here we now only find maxlen

// t.c-O(N(outer while loop)+N(inner while loop))=O(2N) where N is size of array
// s.c-O(1)
int maxConsecutiveOnes(vector<int> &nums, int k)
{
  int n = nums.size();
  int l = 0, r = 0;
  int maxlen = 0;
  int zeros = 0;
  // run n time
  while (r < n)
  {
    if (nums[r] == 0)
      zeros++;

    // this while loop not run n length every time, in worst case it is run n length at a single time throughout the whole journey
    while (zeros > k)
    {
      if (nums[l] == 0)
        zeros--;
      l++; // shrink the current window until the zeros<=k
    }
    if (zeros <= k)
    {
      maxlen = max(maxlen, r - l + 1);
    }
    r++; // expand the window
  }
  return maxlen;
}

// optimal solution- this is only when we want only maxlen, not want to print maxlen subarray

// pattern2-optimal solution- remove inner while loop of better solution
// here we don't shrink l until the zeros>k, here we shrink l only by one place to match current len to maxlen and not go current len to beyond maxlen because we know maxlen till that so no need to go beyond that if maxlen incerease then we move forward
// so whenever zeros>k we shrink l only by 1 to macth curr len to maxlen only, not shrink l completely to valid the given condition(zeros<=k)

// t.c-O(N) only for outer while loop where N is size of array
// s.c-O(1)
int maxConsecutiveOnesAfterFlip(vector<int> &nums, int k)
{
  int n = nums.size();
  int l = 0, r = 0;
  int maxlen = 0;
  int zeros = 0;
  // run n time
  while (r < n)
  {
    if (nums[r] == 0)
      zeros++;

    // we move l only by 1, so now take O(1)
    if (zeros > k)
    {
      if (nums[l] == 0)
        zeros--;
      l++; // shrink the current window until the zeros<=k
    }
    if (zeros <= k)
    {
      maxlen = max(maxlen, r - l + 1);
    }
    r++; // expand the window
  }
  return maxlen;
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

  // int maxlen = maxOnes(nums, k);
  // int maxlen = maxConsecutiveOnes(nums, k);
  int maxlen = maxConsecutiveOnesAfterFlip(nums, k);
  cout << "Maximum number of consecutive 1's after flip atmost k 0's: " << maxlen << endl;
  return 0;
}
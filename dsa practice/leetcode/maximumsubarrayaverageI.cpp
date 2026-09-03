// You are given an integer array nums consisting of n elements, and an integer k.

// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10^(-5) will be accepted.

// Example 1:

// Input: nums = [1,12,-5,-6,50,3], k = 4
// Output: 12.75000
// Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
// Example 2:

// Input: nums = [5], k = 1
// Output: 5.00000

// Constraints:

// n == nums.length
// 1 <= k <= n <= 10^5
// -10^4 <= nums[i] <= 10^4

#include <bits/stdc++.h>
using namespace std;

// similar to longest harmonic subsequence, only difference is here we want subarray and not want to sort array because we want whole window of fixed size k here not only max and min value of window

double findMaxAverage(vector<int> &nums, int k)
{
  int n = nums.size();
  double maxAverage = INT_MIN;
  int l = 0, r = 0;
  double sum = 0;
  while (r < n)
  {
    sum += nums[r];
    while (r - l + 1 > k)
    {
      sum -= nums[l];
      l++; // shrink the window
    }
    // we want maxaverage of fixed size window which is k
    if (r - l + 1 == k)
    {
      maxAverage = max(maxAverage, sum / k);
    }
    r++; // expand the window
  }
  return maxAverage;
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
  double answer = findMaxAverage(nums, k);
  // Any answer with a calculation error less than 10^(-5) will be accepted.
  cout << fixed << setprecision(6) << answer << endl;
  return 0;
}
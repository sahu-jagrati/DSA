// You are given an integer array nums.

// The digit range of an integer is defined as the difference between its largest digit and smallest digit.

// For example, the digit range of 5724 is 7 - 2 = 5.

// Return the sum of all integers in nums whose digit range is equal to the maximum digit range among all integers in the array.

// Example 1:

// Input: nums = [5724,111,350]

// Output: 6074

// Explanation:

// i	nums[i]	Largest	Smallest	Digit Range
// 0	5724	7	2	5
// 1	111	1	1	0
// 2	350	5	0	5
// The maximum digit range is 5. The integers with this digit range are 5724 and 350, so the answer is 5724 + 350 = 6074.

// Example 2:

// Input: nums = [90,900]

// Output: 990

// Explanation:

// i	nums[i]	Largest	Smallest	Digit Range
// 0	90	9	0	9
// 1	900	9	0	9
// The maximum digit range is 9. Both integers have this digit range, so the answer is 90 + 900 = 990.

// Constraints:

// 1 <= nums.length <= 100
// 10 <= nums[i] <= 10^5

#include <bits/stdc++.h>
using namespace std;

int digitRange(int num)
{
  // as in constraint mention all number are two digit so we get mininmum and maximum digit both
  int maxi = INT_MIN;
  int mini = INT_MAX;
  while (num > 0)
  {
    int digit = num % 10;
    num /= 10;
    maxi = max(maxi, digit);
    mini = min(mini, digit);
  }
  return maxi - mini;
}
// firstly I think I use unordered map to store digitRange for each nums[i] but here in nums[i] there can be duplicate so for same nums[i] in mpp there can be overwrite values so we first calculate maxdigitRange and then calculate sum of nums[i] having maxDigitRange

// n is the size of given array
// and let d is the maximum number of digits in any number
// so digitrange() funcn runs d times because for each digit
// and here we have for loop
// so total t.c-O(n*d)*2 for two for loops
// s.c-O(1)
int maxDigitRange(vector<int> &nums)
{
  int n = nums.size();
  int maxDigitRange = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    maxDigitRange = max(maxDigitRange, digitRange(nums[i]));
  }
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    if (digitRange(nums[i]) == maxDigitRange)
    {
      sum += nums[i];
    }
  }
  return sum;
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
  cout << maxDigitRange(nums);
  return 0;
}
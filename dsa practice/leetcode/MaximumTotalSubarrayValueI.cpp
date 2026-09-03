// You are given an integer array nums of length n and an integer k.

// You need to choose exactly k non-empty subarrays nums[l..r] of nums. Subarrays may overlap, and the exact same subarray (same l and r) can be chosen more than once.

// The value of a subarray nums[l..r] is defined as: max(nums[l..r]) - min(nums[l..r]).

// The total value is the sum of the values of all chosen subarrays.

// Return the maximum possible total value you can achieve.

// Example 1:

// Input: nums = [1,3,2], k = 2

// Output: 4

// Explanation:

// One optimal approach is:

// Choose nums[0..1] = [1, 3]. The maximum is 3 and the minimum is 1, giving a value of 3 - 1 = 2.
// Choose nums[0..2] = [1, 3, 2]. The maximum is still 3 and the minimum is still 1, so the value is also 3 - 1 = 2.
// Adding these gives 2 + 2 = 4.

// Example 2:

// Input: nums = [4,2,5,1], k = 3

// Output: 12

// Explanation:

// One optimal approach is:

// Choose nums[0..3] = [4, 2, 5, 1]. The maximum is 5 and the minimum is 1, giving a value of 5 - 1 = 4.
// Choose nums[0..3] = [4, 2, 5, 1]. The maximum is 5 and the minimum is 1, so the value is also 4.
// Choose nums[2..3] = [5, 1]. The maximum is 5 and the minimum is 1, so the value is again 4.
// Adding these gives 4 + 4 + 4 = 12.

// Constraints:

// 1 <= n == nums.length <= 5 * 10^​​​​​​​4
// 0 <= nums[i] <= 10^9
// 1 <= k <= 10^5

#include <bits/stdc++.h>
using namespace std;

// as we want maximum total value
// and total value is the sum of the 'values' of all 'k' subarray
// and the 'values' of a subarray nums[l...r] is difference of max(nums[l...r]) and min(nums[l...r]) i.e max(nums[l...r])-min(nums[l...r])

// and also given that You need to choose exactly k non-empty subarrays nums[l..r] of nums. Subarrays may overlap, and the exact same subarray (same l and r) can be chosen more than once.
// means we can use same subarray infinite times

// as we know that the whole array is also a subarray
// and we want max(totalValue) for that if we take whole array and get max(given array) and min(given array) and take difference of them and we want exactly 'k' subarray so we multiply 'k' with the difference of max and min elt of whole array because we can use any subarray infinite times so for maxtotal value we want max difference and for max difference we take whole array as a subarray 'k' times

// t.c-O(n)
// s.c-O(1)
long long maxTotalValue(vector<int> &nums, int k)
{
  int n = nums.size();
  int maxElt = INT_MIN;
  int minElt = INT_MAX;
  for (int i = 0; i < n; i++)
  {
    if (nums[i] > maxElt)
      maxElt = nums[i];
    if (nums[i] < minElt)
      minElt = nums[i];
  }
  long long diff = (maxElt - minElt);
  return (k * diff);
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
  cout << maxTotalValue(nums, k);
  return 0;
}
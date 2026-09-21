// You are given an array of positive integers nums, and a positive integer k.

// You are allowed to perform an operation once on nums, where in each operation you can remove any non-overlapping prefix and suffix from nums such that nums remains non-empty.

// You need to find the x-value of nums, which is the number of ways to perform this operation so that the product of the remaining elements leaves a remainder of x when divided by k.

// Return an array result of size k where result[x] is the x-value of nums for 0 <= x <= k - 1.

// A prefix of an array is a subarray that starts from the beginning of the array and extends to any point within it.

// A suffix of an array is a subarray that starts at any point within the array and extends to the end of the array.

// Note that the prefix and suffix to be chosen for the operation can be empty.

// Example 1:

// Input: nums = [1,2,3,4,5], k = 3

// Output: [9,2,4]

// Explanation:

// For x = 0, the possible operations include all possible ways to remove non-overlapping prefix/suffix that do not remove nums[2] == 3.
// For x = 1, the possible operations are:
// Remove the empty prefix and the suffix [2, 3, 4, 5]. nums becomes [1].
// Remove the prefix [1, 2, 3] and the suffix [5]. nums becomes [4].
// For x = 2, the possible operations are:
// Remove the empty prefix and the suffix [3, 4, 5]. nums becomes [1, 2].
// Remove the prefix [1] and the suffix [3, 4, 5]. nums becomes [2].
// Remove the prefix [1, 2, 3] and the empty suffix. nums becomes [4, 5].
// Remove the prefix [1, 2, 3, 4] and the empty suffix. nums becomes [5].
// Example 2:

// Input: nums = [1,2,4,8,16,32], k = 4

// Output: [18,1,2,0]

// Explanation:

// For x = 0, the only operations that do not result in x = 0 are:
// Remove the empty prefix and the suffix [4, 8, 16, 32]. nums becomes [1, 2].
// Remove the empty prefix and the suffix [2, 4, 8, 16, 32]. nums becomes [1].
// Remove the prefix [1] and the suffix [4, 8, 16, 32]. nums becomes [2].
// For x = 1, the only possible operation is:
// Remove the empty prefix and the suffix [2, 4, 8, 16, 32]. nums becomes [1].
// For x = 2, the possible operations are:
// Remove the empty prefix and the suffix [4, 8, 16, 32]. nums becomes [1, 2].
// Remove the prefix [1] and the suffix [4, 8, 16, 32]. nums becomes [2].
// For x = 3, there is no possible way to perform the operation.
// Example 3:

// Input: nums = [1,1,2,1,1], k = 2

// Output: [9,6]

// Constraints:

// 1 <= nums[i] <= 10^9
// 1 <= nums.length <= 10^5
// 1 <= k <= 5

#include <bits/stdc++.h>
using namespace std;

// brute force: generate all subarrays:

// t.c-O(n^2)
// s.c-O(k)result array

vector<long long> resultArray(vector<int> &nums, int k)
{
  int n = nums.size();
  vector<long long> result(k);
  for (int i = 0; i < n; i++)
  {
    long long product = 1;
    for (int j = i; j < n; j++)
    {
      product *= nums[j];
      long long remainder = product % k;
      result[remainder]++;
    }
  }
  return result;
}

// brute force gives signed integer overflow for very large integer multiplication

// optimized solution:
// Hint 1
// Use dynamic programming.
// Hint 2
// Define dp[i][r] as the count of subarrays ending at index i whose product modulo k equals r.
// Hint 3
// Compute dp[i][r] for each index i in nums and sum over all indices to get the final counts for each remainder.

// Hint:
// when an array product is P and remainder is r when divided by k (i.e P%k=r) and now if we add an element x in the array then the new remainder becomes r*(x%k)%k

// using the above formula we can make a transition at each index to extend a subarray from previous index which has a remainder of j and after extending the remainder becomes j*(nums[i]%k)%k

// t.c-O(n*k)
// s.c-O(n*k)(for dp)+O(k)(for result)
vector<long long> result_Array(vector<int> &nums, int k)
{
  int n = nums.size();
  // initially count =0
  vector<vector<long long>> dp(n, vector<long long>(k, 0));
  vector<long long> result(k, 0);

  for (int i = 0; i < n; i++)
  {
    // subarray containing only nums[i]
    int remainder = nums[i] % k;
    dp[i][remainder]++;
    // Extend all subarrays ending at i-1 by adding nums[1] in them
    if (i > 0)
    {
      for (int r = 0; r < k; r++)
      {
        if (dp[i - 1][r] == 0)
          continue;
        int newRemainder = (r * 1LL * (nums[i] % k)) % k;
        dp[i][newRemainder] += dp[i - 1][r];
      }
    }
    // add dp[i] to the final answer
    for (int r = 0; r < k; r++)
    {
      result[r] += dp[i][r];
    }
  }
  return result;
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
  vector<long long> ans = result_Array(nums, k);
  for (auto it : ans)
  {
    cout << it << " ";
  }
  return 0;
}
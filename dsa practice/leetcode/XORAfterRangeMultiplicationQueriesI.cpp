// You are given an integer array nums of length n and a 2D integer array queries of size q, where queries[i] = [li, ri, ki, vi].

// For each query, you must apply the following operations in order:

// Set idx = li.
// While idx <= ri:
// Update: nums[idx] = (nums[idx] * vi) % (109 + 7)
// Set idx += ki.
// Return the bitwise XOR of all elements in nums after processing all queries.

// Example 1:

// Input: nums = [1,1,1], queries = [[0,2,1,4]]

// Output: 4

// Explanation:

// A single query [0, 2, 1, 4] multiplies every element from index 0 through index 2 by 4.
// The array changes from [1, 1, 1] to [4, 4, 4].
// The XOR of all elements is 4 ^ 4 ^ 4 = 4.
// Example 2:

// Input: nums = [2,3,1,5,4], queries = [[1,4,2,3],[0,2,1,2]]

// Output: 31

// Explanation:

// The first query [1, 4, 2, 3] multiplies the elements at indices 1 and 3 by 3, transforming the array to [2, 9, 1, 15, 4].
// The second query [0, 2, 1, 2] multiplies the elements at indices 0, 1, and 2 by 2, resulting in [4, 18, 2, 15, 4].
// Finally, the XOR of all elements is 4 ^ 18 ^ 2 ^ 15 ^ 4 = 31.​​​​​​​​​​​​​​

// Constraints:

// 1 <= n == nums.length <= 10^3
// 1 <= nums[i] <= 10^9
// 1 <= q == queries.length <= 10^3
// queries[i] = [li, ri, ki, vi]
// 0 <= li <= ri < n
// 1 <= ki <= n
// 1 <= vi <= 10^5

#include <bits/stdc++.h>
using namespace std;

int xorAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
{
  int q = queries.size();
  int mod = (1e9 + 7);
  for (int i = 0; i < q; i++)
  {
    int idx = queries[i][0];
    int r = queries[i][1];
    int k = queries[i][2];
    int v = queries[i][3];
    while (idx <= r)
    {
      if (idx < nums.size())
      {
        // we use long long because constraint of v is very large and after product it become so large so there can be signed int overflow so we used long long 
        long long prod =(long long)nums[idx] *(long long) v;
        nums[idx] = prod % mod;
      }
      idx += k;
    }
  }
  int xorr = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    xorr = xorr ^ nums[i];
  }
  return xorr;
}
int main()
{
  int n, q;
  cin >> n >> q;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  vector<vector<int>> queries(q, vector<int>(4));
  for (int i = 0; i < q; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      cin >> queries[i][j];
    }
  }
  cout << xorAfterQueries(nums, queries);
  return 0;
}
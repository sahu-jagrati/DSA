// You are given an integer array nums of length n and an integer array queries.

// Let gcdPairs denote an array obtained by calculating the GCD of all possible pairs (nums[i], nums[j]), where 0 <= i < j < n, and then sorting these values in ascending order.

// For each query queries[i], you need to find the element at index queries[i] in gcdPairs.

// Return an integer array answer, where answer[i] is the value at gcdPairs[queries[i]] for each query.

// The term gcd(a, b) denotes the greatest common divisor of a and b.

// Example 1:

// Input: nums = [2,3,4], queries = [0,2,2]

// Output: [1,2,2]

// Explanation:

// gcdPairs = [gcd(nums[0], nums[1]), gcd(nums[0], nums[2]), gcd(nums[1], nums[2])] = [1, 2, 1].

// After sorting in ascending order, gcdPairs = [1, 1, 2].

// So, the answer is [gcdPairs[queries[0]], gcdPairs[queries[1]], gcdPairs[queries[2]]] = [1, 2, 2].

// Example 2:

// Input: nums = [4,4,2,1], queries = [5,3,1,0]

// Output: [4,2,1,1]

// Explanation:

// gcdPairs sorted in ascending order is [1, 1, 1, 2, 2, 4].

// Example 3:

// Input: nums = [2,2], queries = [0,0]

// Output: [2,2]

// Explanation:

// gcdPairs = [2].

// Constraints:

// 2 <= n == nums.length <= 10^5
// 1 <= nums[i] <= 5 * 10^4
// 1 <= queries.length <= 10^5
// 0 <= queries[i] < n * (n - 1) / 2

#include <bits/stdc++.h>
using namespace std;

// first we try brute force
// let gcdPair array size is s then for sorting it take O(s*log(s))
// t.c-O(n*n)(for calculating gcdPair array)+O(s*log(s))(for sorting gcdPair array)+O(m)(for calculating ans array)
// s.c-O(gcdPair.size())+O(ans.size())

// as in t.c we hvae O(n*n) so when n=10^5 then n*n = 10^10 so this solution gives time limit exceed
vector<int> gcdValues(vector<int> &nums, vector<long long> &queries)
{
  int n = nums.size();
  vector<int> gcdPairs;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      int gcd = __gcd(nums[i], nums[j]);
      gcdPairs.push_back(gcd);
    }
  }
  sort(gcdPairs.begin(), gcdPairs.end());
  int m = queries.size();
  vector<int> ans(m);
  for (int i = 0; i < m; i++)
  {
    ans[i] = gcdPairs[queries[i]];
  }
  return ans;
}

// optimized solution
vector<int> gcdValue(vector<int> &nums, vector<long, long> &queries)
{
  sort(nums.begin(), nums.end());
  int maxi = nums[nums.size() - 1];

  vector<int> freq(maxi + 1);
  for (int x : nums)
  {
    freq[x]++;
  }

  // cnt[g]=numbers divisible by g
  vector<int> cnt(maxi + 1);
  for (int g = 1; g <= maxi; g++)
  {
    for (int j = g; j <= maxi; j += g)
    {
      cnt[g] += freq[j];
    }
  }
  // exact[g] = pairs having gcd exactly g
  vector<long long> exact(maxi + 1);

  for (int g = 1; g <= maxi; g++)
    exact[g] = 1LL * cnt[g] * (cnt[g] - 1) / 2;

  for (int g = maxi; g >= 1; g--)
  {
    for (int j = 2 * g; j <= maxi; j += g)
      exact[g] -= exact[j];
  }

  vector<long long> pref(maxi + 1);

  for (int g = 1; g <= maxi; g++)
    pref[g] = pref[g - 1] + exact[g];

  vector<int> ans;

  for (long long q : queries)
  {
    int g = lower_bound(pref.begin(), pref.end(), q + 1) - pref.begin();
    ans.push_back(g);
  }

  return ans;
}
int main()
{
  int n;
  cout << "Enter array size: ";
  cin >> n;
  vector<int> nums(n);
  cout << "Enter elts of an array: ";
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  int m;
  cout << "Enter query array size: ";
  cin >> m;
  vector<long long> queries(m);
  cout << "Enter elts in query array: ";
  for (int i = 0; i < m; i++)
  {
    cin >> queries[i];
  }
  vector<int> ans = gcdValues(nums, queries);
  for (auto it : ans)
  {
    cout << it << " ";
  }
  return 0;
}
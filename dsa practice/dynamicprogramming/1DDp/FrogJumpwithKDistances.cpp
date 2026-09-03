// Problem Statement:

// A frog wants to climb a staircase with n steps. Given an integer array heights, where heights[i] contains the height of the ith step, and an integer k. To jump from the ith step to the jth step, the frog requires abs(heights[i] - heights[j]) energy, where abs() denotes the absolute difference. The frog can jump from the ith step to any step in the range [i + 1, i + k], provided it exists. Return the minimum amount of energy required by the frog to go from the 0th step to the (n-1)th step.

// Examples
// Example 1:
// Input: heights = [10, 5, 20, 0, 15], k = 2
// Output: 15
// Explanation:
// 0th step -> 2nd step, cost = abs(10 - 20) = 10
// 2nd step -> 4th step, cost = abs(20 - 15) = 5
// Total cost = 10 + 5 = 15.

// Example 2:
// Input: heights = [15, 4, 1, 14, 15], k = 3
// Output: 2
// Explanation:
// 0th step -> 3rd step, cost = abs(15 - 14) = 1
// 3rd step -> 4th step, cost = abs(14 - 15) = 1
// Total cost = 1 + 1 = 2.

#include <bits/stdc++.h>
using namespace std;

// memoization solution-
// t.c-O(n*k)  where n is the number of stairs and k is the maximum jump allowed. For each index, we compute up to k recursive calls, each memoized
// s.c-O(n) for dp array
int f1(int index, vector<int> &heights, int k, vector<int> &dp)
{
  if (index == 0)
    return 0;
  if (dp[index] != -1)
    return dp[index];

  int minSteps = INT_MAX;
  // Try all possible jumps from 1 to k
  for (int j = 1; j <= k; j++)
  {
    if (j <= index)
    {
      minSteps = min(minSteps, f1(index - j, heights, k, dp) + abs(heights[index] - heights[index - j]));
    }
  }
  return dp[index] = minSteps;
}

// tabulation solution-
// t.c-O(n*k) We process n elements and for each we check up to k previous jumps maximum for each elts.
// s.c-O(n) for dp array
int f(int n, vector<int> &heights, int k)
{
  vector<int> dp(n, INT_MAX);
  // from 0th step you cann't go down because it's last step,  because the frog starts there with no cost
  dp[0] = 0;
  for (int i = 1; i < n; i++)
  {
    // Try all possible jumps from 1 to k
    for (int j = 1; j <= k; j++)
    {
      if (j <= i)
      {
        dp[i] = min(dp[i], dp[i - j] + abs(heights[i] - heights[i - j]));
      }
    }
  }
  return dp[n - 1];
}
int minEnergy(vector<int> &heights, int k)
{
  int n = heights.size();
  // memoization solution
  vector<int> dp(n, -1);
  return f1(n - 1, heights, k, dp);
  // tabulation solution
  // return f(n, heights, k);
}

int main()
{
  int n;
  cin >> n;
  vector<int> heights(n);
  for (int i = 0; i < n; i++)
  {
    cin >> heights[i];
  }
  int k;
  cin >> k;
  cout << minEnergy(heights, k);
  return 0;
}
// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

// You can either start from the step with index 0, or the step with index 1.

// Return the minimum cost to reach the top of the floor.

// Example 1:

// Input: cost = [10,15,20]
// Output: 15
// Explanation: You will start at index 1.
// - Pay 15 and climb two steps to reach the top.
// The total cost is 15.
// Example 2:

// Input: cost = [1,100,1,1,1,100,1,1,100,1]
// Output: 6
// Explanation: You will start at index 0.
// - Pay 1 and climb two steps to reach index 2.
// - Pay 1 and climb two steps to reach index 4.
// - Pay 1 and climb two steps to reach index 6.
// - Pay 1 and climb one step to reach index 7.
// - Pay 1 and climb two steps to reach index 9.
// - Pay 1 and climb one step to reach the top.
// The total cost is 6.

// Constraints:

// 2 <= cost.length <= 1000
// 0 <= cost[i] <= 999

#include <bits/stdc++.h>
using namespace std;

// i do this problem by own fully
int startAt0(int n, vector<int> &cost)
{
  vector<int> dp(n + 1, 0);
  dp[0] = cost[0];
  for (int i = 1; i <= n; i++)
  {
    int left = INT_MAX;
    if (i != n)
    {
      left = dp[i - 1] + cost[i];
    }
    int right = INT_MAX;
    if (i > 1 && i != n)
      right = dp[i - 2] + cost[i];

    if (i == n)
    {
      left = dp[i - 1];
      right = dp[i - 2];
    }
    dp[i] = min(left, right);
  }
  return dp[n];
}

int startAt1(int n, vector<int> &cost)
{
  vector<int> dp(n + 1, 0);
  dp[0] = cost[0];
  dp[1] = cost[1];
  for (int i = 2; i <= n; i++)
  {
    int left = INT_MAX;
    if (i != n)
      left = dp[i - 1] + cost[i];
    int right = INT_MAX;
    if (i > 2 && i != n)
      right = dp[i - 2] + cost[i];

    if (i == n)
    {
      left = dp[i - 1];
      right = dp[i - 2];
    }
    dp[i] = min(left, right);
  }
  return dp[n];
}

int minCostClimbingStairs(vector<int> &cost)
{
  int n = cost.size();
  return min(startAt0(n, cost), startAt1(n, cost));
}

int main()
{
  int n;
  cin >> n;
  vector<int> cost(n);
  for (int i = 0; i < n; i++)
  {
    cin >> cost[i];
  }
  cout << minCostClimbingStairs(cost);
  return 0;
}
// You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

// Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

// Example 1:

// Input: k = 2, prices = [2,4,1]
// Output: 2
// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
// Example 2:

// Input: k = 2, prices = [3,2,6,5,0,3]
// Output: 7
// Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

// Constraints:

// 1 <= k <= 100
// 1 <= prices.length <= 1000
// 0 <= prices[i] <= 1000

#include <bits/stdc++.h>
using namespace std;

// this problem is same to same to Buy and Sell Stock III only difference is that in problem Buy and Sell Stock III we can do atmost two transactions while here we can do atmost 'k' transactions i.e 'k' can be anything so we copy that code

// recursion
// t.c-exponential
// s.c-O(n) for auxiliary stack space
// capacity means transactions
int f1(int index, int buy, int capacity, vector<int> &prices, int n)
{
  // base case
  // when capacity is exhausted
  if (capacity == 0)
    return 0;
  // when all days are exhausted
  if (index == n)
    return 0;

  // when allowed to buy
  if (buy == 1)
  {
    return max(-prices[index] + f1(index + 1, 0, capacity, prices, n), 0 + f1(index + 1, 1, capacity, prices, n));
  }
  // when not allowed to buy
  return max(prices[index] + f1(index + 1, 1, capacity - 1, prices, n), 0 + f1(index + 1, 0, capacity, prices, n));
}

// memoization
// t.c-O(n*2*k)
// s.c-O(n*2*k)(for dp)+O(n) for auxiliary stack space
// capacity means transactions
int f2(int index, int buy, int capacity, vector<int> &prices, int n, vector<vector<vector<int>>> &dp)
{
  // base case
  // when capacity is exhausted
  if (capacity == 0)
    return 0;
  // when all days are exhausted
  if (index == n)
    return 0;

  if (dp[index][buy][capacity] != -1)
    return dp[index][buy][capacity];
  // when allowed to buy
  if (buy == 1)
  {
    return dp[index][buy][capacity] = max(-prices[index] + f2(index + 1, 0, capacity, prices, n, dp), 0 + f2(index + 1, 1, capacity, prices, n, dp));
  }
  // when not allowed to buy
  return dp[index][buy][capacity] = max(prices[index] + f2(index + 1, 1, capacity - 1, prices, n, dp), 0 + f2(index + 1, 0, capacity, prices, n, dp));
}

// tabulation
// t.c-O(n*2*k)
// s.c-O(n*2*k) for dp
int f3(vector<int> &prices, int n, int k)
{
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
  // you can write base case or not because we already initialize dp with 0
  // 1. base case when capacity==0
  for (int index = 0; index <= n; index++)
  {
    for (int buy = 0; buy <= 1; buy++)
    {
      dp[index][buy][0] = 0;
    }
  }
  // 2. base case when index==n
  for (int buy = 0; buy <= 1; buy++)
  {
    for (int capacity = 0; capacity <= 2; capacity++)
    {
      dp[n][buy][capacity] = 0;
    }
  }
  // we alrady done with index=n so for index go from n-1 to 0
  for (int index = n - 1; index >= 0; index--)
  {
    for (int buy = 0; buy <= 1; buy++)
    {
      // we alrady done with capacity=0 so for capacity go from 1 to k
      for (int capacity = 1; capacity <= k; capacity++)
      {
        // when allowed to buy
        if (buy == 1)
        {
          dp[index][buy][capacity] = max(-prices[index] + dp[index + 1][0][capacity], 0 + dp[index + 1][1][capacity]);
        }
        // when not allowed to buy
        else
        {
          dp[index][buy][capacity] = max(prices[index] + dp[index + 1][1][capacity - 1], 0 + dp[index + 1][0][capacity]);
        }
      }
    }
  }
  return dp[0][1][k];
}

// space optimization
// t.c-O(n*2*k)
// s.c-O(2*k) for two 2D array
int f4(vector<int> &prices, int n, int k)
{
  // we makes two 2D array for storing ahead and curr rows
  vector<vector<int>> ahead(2, vector<int>(k + 1, 0));
  vector<vector<int>> curr(2, vector<int>(k + 1, 0));
  // we can write base case or not because we already initialize  with 0 so here we don't write base case alag se

  // we alrady done with index=n in base case so for index go from n-1 to 0
  for (int index = n - 1; index >= 0; index--)
  {
    for (int buy = 0; buy <= 1; buy++)
    {
      // we alrady done with capacity=0 in base case so for capacity go from 1 to k
      for (int capacity = 1; capacity <= k; capacity++)
      {
        // when allowed to buy
        if (buy == 1)
        {
          curr[buy][capacity] = max(-prices[index] + ahead[0][capacity], 0 + ahead[1][capacity]);
        }
        // when not allowed to buy
        else
        {
          curr[buy][capacity] = max(prices[index] + ahead[1][capacity - 1], 0 + ahead[0][capacity]);
        }
      }
    }
    ahead = curr;
  }
  return ahead[1][k];
}

// we also copy another solution of the problem Buy and Sell Stock III and do with atmost 'k' transactions

// so we done this with dp[n][4] when we can do atmost 2 transactions so transactions values are 0 ,1,2,3  so here we can do atmost 'k' transactions so dp[n][2*k] i.e. you may buy at most k times and sell at most k times. so even index for buy and odd index for sell

// recursion solution of this
// t.c-exponential
// s.c-O(n) for auxiliary stack space
int F1(int index, int transactions, vector<int> &prices, int n, int k)
{
  // base case
  if (index == n || transactions == 2 * k)
    return 0;

  // when we are allowed to buy
  if (transactions % 2 == 0)
  {
    return max(-prices[index] + F1(index + 1, transactions + 1, prices, n, k), 0 + F1(index + 1, transactions, prices, n, k));
  }
  // when we are not allowed to buy
  return max(prices[index] + F1(index + 1, transactions + 1, prices, n, k), 0 + F1(index + 1, transactions, prices, n, k));
}

// memoization
// t.c-O(n*(2*k))
// s.c-O(n*(2*k))(for dp)+O(n) for auxiliary stack space
int F2(int index, int transactions, vector<int> &prices, int n, vector<vector<int>> &dp, int k)
{
  // base case
  if (index == n || transactions == 2 * k)
    return 0;

  if (dp[index][transactions] != -1)
    return dp[index][transactions];

  // when we are allowed to buy
  if (transactions % 2 == 0)
  {
    return dp[index][transactions] = max(-prices[index] + F1(index + 1, transactions + 1, prices, n, k), 0 + F1(index + 1, transactions, prices, n, k));
  }
  // when we are not allowed to buy
  return dp[index][transactions] = max(prices[index] + F1(index + 1, transactions + 1, prices, n, k), 0 + F1(index + 1, transactions, prices, n, k));
}

// tabulation
// t.c-O(n*(2*k))
// s.c-O(n*(2*k))(for dp)
int F3(vector<int> &prices, int n, int k)
{
  vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
  // you can write base case or not because we already initialize  with 0
  // base case
  // when index==n
  for (int transactions = 0; transactions <= 2 * k; transactions++)
    dp[n][transactions] = 0;
  // when transactions=2*k
  for (int index = 0; index <= n; index++)
    dp[index][2 * k] = 0;

  // index=n we already done in base case
  for (int index = n - 1; index >= 0; index--)
  {
    // transaction=2*k we already done in base case
    for (int transactions = 0; transactions < 2 * k; transactions++)
    {
      // when we are allowed to buy
      if (transactions % 2 == 0)
      {
        dp[index][transactions] = max(-prices[index] + dp[index + 1][transactions + 1], 0 + dp[index + 1][transactions]);
      }
      // when we are not allowed to buy
      else
      {
        dp[index][transactions] = max(prices[index] + dp[index + 1][transactions + 1], 0 + dp[index + 1][transactions]);
      }
    }
  }
  return dp[0][0];
}

// space optimization
// t.c-O(n*(2*k))
// s.c-O((2*k)) for two 2D array
int F4(vector<int> &prices, int n, int k)
{
  vector<int> ahead(2 * k + 1, 0);
  vector<int> curr(2 * k + 1, 0);
  // // we can write base case or not because we already initialize  with 0 so here we don't write base case alag se

  // index=n  already done in base case
  for (int index = n - 1; index >= 0; index--)
  {
    // transaction=2*k we already done in base case
    for (int transactions = 0; transactions < 2 * k; transactions++)
    {
      // when we are allowed to buy
      if (transactions % 2 == 0)
      {
        curr[transactions] = max(-prices[index] + ahead[transactions + 1], 0 + ahead[transactions]);
      }
      // when we are not allowed to buy
      else
        curr[transactions] = max(prices[index] + ahead[transactions + 1], 0 + ahead[transactions]);
    }
    ahead = curr;
  }
  return ahead[0];
}

// assume buy=1 means you can buy and buy=0 means you cannot buy
int maxProfit(int k, int n, vector<int> &prices)
{
  // recursion start from 0th index with buy=1 and capacity=k
  // return f1(0, 1, k, prices, n);

  // memoization
  // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
  // return f2(0, 1, k, prices, n, dp);

  // tabulation
  // return f3(prices, n, k);

  // space optimization
  // return f4(prices, n, k);

  // for another solution
  // recursion start with index=0 and transactions=0
  // return F1(0, 0, prices, n, k);

  // memoization
  // vector<vector<int>> dp(n, vector<int>(2 * k, -1));
  // return F2(0, 0, prices, n, dp, k);

  // tabulation
  // return F3(prices, n, k);

  // space optimization
  return F4(prices, n, k);
}
int main()
{
  int n;
  cin >> n;
  vector<int> prices(n);
  for (int i = 0; i < n; i++)
  {
    cin >> prices[i];
  }
  int k;
  cin >> k;
  cout << maxProfit(k, n, prices);
  return 0;
}

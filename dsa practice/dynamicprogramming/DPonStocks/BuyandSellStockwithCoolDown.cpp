// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

// After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

// Example 1:

// Input: prices = [1,2,3,0,2]
// Output: 3
// Explanation: transactions = [buy, sell, cooldown, buy, sell]
// Example 2:

// Input: prices = [1]
// Output: 0

// Constraints:

// 1 <= prices.length <= 5000
// 0 <= prices[i] <= 1000

#include <bits/stdc++.h>
using namespace std;

// this problem is same to problem Buy and Sell Stock II in that we also do infinite transactions only difference is here is that // After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

// so here what we do is that when we sell the stock we skip the one day i.e cooldown the day and remaining code is same from the problem Buy and Sell Stock II

// recursion
// t.c- exponential
// s.c-O(n)(for auxiliary stack space)
int f1(int index, int buy, vector<int> &prices, int n)
{
  // base case
  // here base case is slight change from the problem Buy and Sell Stock II because when we do index+2 so if index=n-1 then index+2=n+1 so it is >=n means all the days are exahausted already so return 0
  if (index >= n)
    return 0;

  // when we are allowed to buy
  if (buy == 1)
  {
    return max(-prices[index] + f1(index + 1, 0, prices, n), 0 + f1(index + 1, 1, prices, n));
  }
  // else when we are not allowed to buy then sell or not sell so if we sell then we skip one day or if we don't sell then move to next day
  return max(prices[index] + f1(index + 2, 1, prices, n), 0 + f1(index + 1, 0, prices, n));
}

// memoization
// t.c-O(n*2)
// s.c-O(n*2)(for dp)+O(n)(for auxiliary stack space)
int f2(int index, int buy, vector<int> &prices, int n, vector<vector<int>> &dp)
{
  // base case
  // here base case is slight change from the problem Buy and Sell Stock II because when we do index+2 so if index=n-1 then index+2=n+1 so it is >=n means all the days are exahausted already so return 0
  if (index >= n)
    return 0;

  if (dp[index][buy] != -1)
    return dp[index][buy];
  // when we are allowed to buy
  if (buy == 1)
  {
    return dp[index][buy] = max(-prices[index] + f2(index + 1, 0, prices, n, dp), 0 + f2(index + 1, 1, prices, n, dp));
  }
  // else when we are not allowed to buy then sell or not sell so if we sell then we skip one day or if we don't sell then move to next day
  return dp[index][buy] = max(prices[index] + f2(index + 2, 1, prices, n, dp), 0 + f2(index + 1, 0, prices, n, dp));
}

// tabulation
// t.c-O(n*2)
// s.c-O(n*2) for dp
int f3(vector<int> &prices, int n)
{
  // here in tabulation we declare dp[n+2][2], n+2 because if index=n-1 then for index+2 it is n+1 so
  vector<vector<int>> dp(n + 2, vector<int>(2, 0));
  // base case
  // in recursion we have if(index>=n) buy can be anything and we know buy can be 0/1 so we have to do for when index==n and when index==n+1
  // we can write base case or not because we already declare dp with 0
  dp[n][0] = dp[n][1] = 0;
  dp[n + 1][0] = dp[n + 1][1] = 0;

  for (int index = n - 1; index >= 0; index--)
  {
    for (int buy = 0; buy <= 1; buy++)
    {
      // when we are allowed to buy
      if (buy == 1)
      {
        dp[index][buy] = max(-prices[index] + dp[index + 1][0], 0 + dp[index + 1][1]);
      }
      // else when we are not allowed to buy then sell or not sell so if we sell then we skip one day or if we don't sell then move to next day
      else
      {
        dp[index][buy] = max(prices[index] + dp[index + 2][1], 0 + dp[index + 1][0]);
      }
    }
  }
  return dp[0][1];
}
// in tabulation
// one thing we can also do is we can omit internal for loop and run direclty for buy=1 and buy 0 like this
// t.c-O(n)
// s.c-O(n*2) for dp
int f4(vector<int> &prices, int n)
{
  // here in tabulation we declare dp[n+2][2], n+2 because if index=n-1 then for index+2 it is n+1 so
  vector<vector<int>> dp(n + 2, vector<int>(2, 0));
  // base case
  // in recursion we have if(index>=n) buy can be anything and buy can be 0/1 so we have to do for when index==n and when index==n+1
  // we can write base case or not because we already declare dp with 0
  dp[n][0] = dp[n][1] = 0;
  dp[n + 1][0] = dp[n + 1][1] = 0;

  for (int index = n - 1; index >= 0; index--)
  {
    // we omit internal buy for loop and directly do for buy=1 and buy=0 once for each index
    // when buy=1 run this once for each index
    dp[index][1] = max(-prices[index] + dp[index + 1][0], 0 + dp[index + 1][1]);

    // when not buy run this also once for each index
    dp[index][0] = max(prices[index] + dp[index + 2][1], 0 + dp[index + 1][0]);
  }
  return dp[0][1];
}
// for space optimization from 2D matrix to 1D array  we want two ahead rows and 1 curr rows because for calculating dp[index][buy] we want dp[index+1][]nad dp[index+2][] so we want (index+1) row as well as (index+2) row

// t.c-O(n)
// s.c-O(2*3)for three 1D array
int f5(vector<int> &prices, int n)
{
  vector<int> ahead2(2, 0);
  vector<int> ahead1(2, 0);
  vector<int> curr(2, 0);
  // we can write base case or not because we already declare  with 0 so here we don't write base case alag se

  for (int index = n - 1; index >= 0; index--)
  {
    // we omit internal buy for loop and directly do for buy=1 and buy=0 once for each index
    // when buy=1 run this once for each index
    curr[1] = max(-prices[index] + ahead1[0], 0 + ahead1[1]);

    // when not buy run this also once for each index
    curr[0] = max(prices[index] + ahead2[1], 0 + ahead1[0]);
    ahead2 = ahead1;
    ahead1 = curr;
  }
  return ahead1[1];
}

// assume buy=1 means you can buy and buy=0 means you cannot buy
int maxProfit(vector<int> &prices, int n)
{
  // recursion start from index=0 and buy=1 means we are allowed to buy
  // return f1(0, 1, prices, n);

  // memoization
  // vector<vector<int>> dp(n, vector<int>(2, -1));
  // return f2(0, 1, prices, n, dp);

  // tabulation
  // return f3(prices, n);

  // tabulation by omiting internal for loop
  // return f4(prices, n);

  // space optimization by convert 2D matraix into three 1D array
  return f5(prices, n);
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
  cout << maxProfit(prices, n);
  return 0;
}
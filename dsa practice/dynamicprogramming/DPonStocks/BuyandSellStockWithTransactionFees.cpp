// You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

// Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

// Note:

// You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
// The transaction fee is only charged once for each stock purchase and sale.

// Example 1:

// Input: prices = [1,3,2,8,4,9], fee = 2
// Output: 8
// Explanation: The maximum profit can be achieved by:
// - Buying at prices[0] = 1
// - Selling at prices[3] = 8
// - Buying at prices[4] = 4
// - Selling at prices[5] = 9
// The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
// Example 2:

// Input: prices = [1,3,7,5,10,3], fee = 3
// Output: 6

// Constraints:

// 1 <= prices.length <= 5 * 10^4
// 1 <= prices[i] < 5 * 10^4
// 0 <= fee < 5 * 10^4

#include <bits/stdc++.h>
using namespace std;

// this problem is same to problem Buy and Sell Stock II in that we also do infinite transactions only difference is here is that // you need to pay the transaction fee for each transaction.

// when we complete the transaction when we sell the stock that we buy it in previous
// so here what we do is that when we sell the stock we also pay the transaction fee with it so we minus the fee and remaining code is same from the problem Buy and Sell Stock II
// in question given that // The transaction fee is only charged once for each stock purchase and sale. so we can pay fee when we buy the stock or we pay the fee when we sell the stock so here we pay the fee when we sell the stock in our solution you can do in either one

// recursion
// t.c- exponential
// s.c-O(n)(for auxiliary stack space)
int f1(int index, int buy, vector<int> &prices, int n, int fee)
{
  // base case samea as Buy and Sell Stock II problem
  if (index == n)
    return 0;

  // when we are allowed to buy
  if (buy == 1)
  {
    return max(-prices[index] + f1(index + 1, 0, prices, n, fee), 0 + f1(index + 1, 1, prices, n, fee));
  }
  // when we are not allowed tp buy then we sell or not sell so when we sell then one transactions is complete so we pay the fee there and when we don't sell then we don't pay fee
  return max(prices[index] - fee + f1(index + 1, 1, prices, n, fee), 0 + f1(index + 1, 0, prices, n, fee));
}

// memoization
// t.c-O(n*2)
// // s.c-O(n*2)(for dp)+O(n)(for auxiliary stack space)
int f2(int index, int buy, vector<int> &prices, int n, int fee, vector<vector<int>> &dp)
{
  // base case samea as Buy and Sell Stock II problem
  if (index == n)
    return 0;

  if (dp[index][buy] != -1)
    return dp[index][buy];
  // when we are allowed to buy
  if (buy == 1)
  {
    return dp[index][buy] = max(-prices[index] + f2(index + 1, 0, prices, n, fee, dp), 0 + f2(index + 1, 1, prices, n, fee, dp));
  }
  // when we are not allowed tp buy then we sell or not sell so when we sell then one transactions is complete so we pay the fee there and when we don't sell then we don't pay fee
  return dp[index][buy] = max(prices[index] - fee + f2(index + 1, 1, prices, n, fee, dp), 0 + f2(index + 1, 0, prices, n, fee, dp));
}

// tabulation
// t.c-O(n*2)
// s.c-O(n*2) for dp
int f3(vector<int> &prices, int n, int fee)
{
  vector<vector<int>> dp(n + 1, vector<int>(2, 0));
  // base case
  // in recursion we have if(index==n) buy can be anything and we know buy can be 0/1 so we have to do for when index==n
  // we can write base case or not because we already declare dp with 0
  dp[n][0] = dp[n][1] = 0;

  for (int index = n - 1; index >= 0; index--)
  {
    for (int buy = 0; buy <= 1; buy++)
    {
      // when we are allowed to buy
      if (buy == 1)
      {
        dp[index][buy] = max(-prices[index] + dp[index + 1][0], 0 + dp[index + 1][1]);
      }
      // when we are not allowed tp buy then we sell or not sell so when we sell then one transactions is complete so we pay the fee there and when we don't sell then we don't pay fee
      else
      {
        dp[index][buy] = max(prices[index] - fee + dp[index + 1][1], 0 + dp[index + 1][0]);
      }
    }
  }
  return dp[0][1];
}
// space optimization
// t.c-O(n*2)
// s.c-O(2*2) for two 1d array
int f4(vector<int> &prices, int n, int fee)
{
  vector<int> ahead(2, 0);
  vector<int> curr(2, 0);
  // we can write base case or not because we already declare  with 0 so here we don't write base case alag se
  for (int index = n - 1; index >= 0; index--)
  {
    for (int buy = 0; buy <= 1; buy++)
    {
      // when we are allowed to buy
      if (buy == 1)
      {
        curr[buy] = max(-prices[index] + ahead[0], 0 + ahead[1]);
      }
      // when we are not allowed tp buy then we sell or not sell so when we sell then one transactions is complete so we pay the fee there and when we don't sell then we don't pay fee
      else
      {
        curr[buy] = max(prices[index] - fee + ahead[1], 0 + ahead[0]);
      }
    }
    ahead = curr;
  }
  return ahead[1];
}
// we can also solve this with using four variables for more details see problem Buy and Sell Stock II
// t.c-O(n)
// s.c-O(1)
int f5(int n, vector<int> &prices, int fee)
{
  // four variables
  int aheadBuy, aheadNotBuy, currBuy, currNotBuy; // meand when buy=1 so Buy and when buy=0 so NotBuy
  // base case when index==n
  aheadBuy = aheadNotBuy = 0;

  for (int index = n - 1; index >= 0; index--)
  {
    // buy can either 0 or 1
    // when buy=1 perform once for each index
    currBuy = max(-prices[index] + aheadNotBuy, 0 + aheadBuy);
    // when buy=0 perform once for each index
    currNotBuy = max(prices[index] - fee + aheadBuy, 0 + aheadNotBuy);

    aheadBuy = currBuy;
    aheadNotBuy = currNotBuy;
  }
  return aheadBuy;
}
// assume buy=1 means you can buy and buy=0 means you cannot buy
int maxProfit(vector<int> &prices, int n, int fee)
{
  // recursion start from index=0 and buy=1 means we are allowed to buy
  // return f1(0, 1, prices, n, fee);

  // memoization
  // vector<vector<int>> dp(n, vector<int>(2, -1));
  // return f2(0, 1, prices, n, fee, dp);

  // tabulation
  // return f3(prices, n, fee);

  // space optimization
  // return f4(prices, n, fee);

  // with four varaibles
  return f5(n, prices, fee);
}
int main()
{
  int n;
  cin >> n;
  vector<int> prices(n);
  for (int i = 0; i < n; i++)
    cin >> prices[i];
  int fee;
  cin >> fee;
  cout << maxProfit(prices, n, fee);
  return 0;
}
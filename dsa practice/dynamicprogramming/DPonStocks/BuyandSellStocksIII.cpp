// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete at most two transactions.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

// Example 1:

// Input: prices = [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
// Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
// Example 2:

// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
// Example 3:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.

// Constraints:

// 1 <= prices.length <= 10^5
// 0 <= prices[i] <= 10^5

#include <bits/stdc++.h>
using namespace std;

// so for understanding this problem we have to understand the problem Buy ans Sell Stocks II

// in part II of this problem(i.e Buy ans Sell Stocks II) we can do as many like infinite transactions but we make sure that we must sell the stock before we buy again

// but in this problem part III we can do max at most two transactions not more than two transactions so we are basically limiting the number of transactions that we are doing  in part II we have unlimited transactions but here we can do atmost two transactions here we are limited.

// so how can we do at max two transactions
// let's take an example:
// prices[]=[3,3,5,0,0,3,1,4]
// i) you can buy at day=2 with price =3 and sell at day=3 with price=5 so profit=5-3=2 and for second transaction you can buy at day=4 with price =0 and sell at day=6 with price=3 so profit=3-0=3 so total profit =2+3=5
// ii)  you can buy at day=2 with price =3 and sell at day=3 with price=5 so profit=5-3=2 and for second transaction you can buy at day=7 with price =1 and sell at day=8 with price=4 so profit=4-1=3 so total profit =2+3=5
// iii) you can buy at day=4 with price =0 and sell at day=6 with price=3 so profit=3-0=3 and for second transaction you can buy at day=7 with price =1 and sell at day=8 with price=4 so profit=4-1=3 so total profit =2+3=6

// so max profit we get here =6 is the maximum profit we can make by buy-sell,buy-sell so here we'd have done at max two transactions
// now this problem is an extension of the Buy and Sell Stock II

// in problem Buy and Sell Stock II in recursion we have two parameters - index,buy and we start from 0th index with buy=1 means we can buy it and we go with two cases if(buy) or else not buy and if(buy) then in that we go with max(take,nottake) or when we do not buy then we go with max(sell,notsell) this is we done in that problem where we had infinite transactions now instead of infinite we can make atmost two transactions so now we are putting a bound so can we relate this to the knapsack problem where we are saying we cannot do more than this we are allowed to do atmost two transactions

// so now in this problem III with parameters (index,buy) we do in problem II we have one extra parameter cap(i.e capacity) like this is the maximum number of transactio we can do (index,buy,cap)

// recursion we start with index=0
// initial we start with f(0,1,2) means with index=0 we can buy so buy=1 and capacity=2 (maximum)

// f(index,buy,capacity){

// i) base case
// 1. base case when we have exhausted all the days so index==n
// if(index==n) return 0; because we'll not get anything from the market
// 2. base case when we also exhaust the max number of transcations i.e when capacity==0in that we also not  get anything from the market so
// if(capacity==0) return 0

// ii) expolore possibilities
// 1. if we are allowed to buy then in that we have also two cases : i) we buy on that day(i.e take) ii) we do not buy on that day(i.e not take)
// i) when we buy on that day we then we take minus of prices[index] and we move to next index with buy=0 means we cannot buy on next day until we sell this and capacity still same because if we are performing a buy transaction so can we say it is the complete transaction? no the transaction is not completed yet because we are performing a buy only here it is completed whe we done buy and sell both so for buy only the transactions is yet not completed so capacity still remain same so : -prices[index]+f(index+1,0,capacity)
// ii) we not buy on that day we move to the next day so buy=1 and capacity still same so : 0+f(index+1,1,capacity)
// return max(take,notTake)=max(-prices[index]+f(index+1,0,capacity),0+f(index+1,1,capacity))

// 2. if we are not allowed to buy then we sell in this also we have two cases: i) we sell on this day ii) we do not sell on this day we move to next day sell on that
// i) if we sell then we take plus of prices[inde] and move to next index with buy=1 because now we sell the previous stock and we can buy next stock and for capacity so now we are performing a sell so obviously in the previous past we would have performed a buy and now we're performing a sell so can i say can i say we're completing one complete transaction which eventually means the number of transaction will get reduced by one  so we capacity-1 so we have : prices[index]+f(index+1,1,capacity-1)
// ii) we say we don't sell in this day then buy=0 and capacity still same because we don't perform sell so we have: 0+f(index+1,0,capacity)
// return max(sell,notsell)=max(prices[index]+f(index+1,1,capacity-1), 0+f(index+1,0,capacity))
//}

// so this is we done with slight changes in problem Buy and Sell Stock II to solve this problem Buy and Sell Stocks III which is bounded with number of transactions which says we can do atmost two transactions

// t.c for recursion-exponential
// s.c-O(n) for auxiliary stack space where n is size of prices array

// for optimize this we do memoization beause there are overlapping subproblemsso we apply memoization

// so in changing  parameters we have (index,buy,capacity)
// and index go from 0 to n-1 so maximum n and buy can be 0/1 so maximum 2 values and capacity can be 0/1/2 so maximum 3 values so we declare dp[n][2][3]
// so t.c for memoization-O(n*2*3)
// s.c-O(n*2*3)(for dp)+O(n)(for auxiliary stack space )

// recursion
int f1(int index, int buy, int capacity, vector<int> &prices, int n)
{
  // base case
  // 1. when capacity is exhausted
  if (capacity == 0)
    return 0;
  // 2. when all days are exhausted
  if (index == n)
    return 0;

  // when allowed to buy:max(take,nottake) and transaction is complete when we do both buy and sell both by doing only buy does not complete transaction so capacity still same
  if (buy)
  {
    return max(-prices[index] + f1(index + 1, 0, capacity, prices, n), 0 + f1(index + 1, 1, capacity, prices, n));
  }
  // when not allowed to buy so sell so max(sell,notsell)
  // whne we sell then one complete transaction done so decrease capacity by 1 and when not sell so capacity still remain same
  // else
  return max(prices[index] + f1(index + 1, 1, capacity - 1, prices, n), 0 + f1(index + 1, 0, capacity, prices, n));
}

// memoization dp declare of dp[n][2][3]
int f2(int index, int buy, int capacity, vector<int> &prices, int n, vector<vector<vector<int>>> &dp)
{
  // base case
  // 1. when capacity is exhausted
  if (capacity == 0)
    return 0;
  // 2. when all days are exhausted
  if (index == n)
    return 0;

  if (dp[index][buy][capacity] != -1)
    return dp[index][buy][capacity];
  // when allowed to buy:max(take,nottake) and transaction is complete when we do both buy and sell both by doing only buy does not complete transaction so capacity still same
  if (buy)
  {
    dp[index][buy][capacity] = max(-prices[index] + f2(index + 1, 0, capacity, prices, n, dp), 0 + f2(index + 1, 1, capacity, prices, n, dp));
  }
  // when not allowed to buy so sell so max(sell,notsell)
  // whne we sell then one complete transaction done so decrease capacity by 1 and when not sell so capacity still remain same
  else
    dp[index][buy][capacity] = max(prices[index] + f2(index + 1, 1, capacity - 1, prices, n, dp), 0 + f2(index + 1, 0, capacity, prices, n, dp));

  return dp[index][buy][capacity];
}

// tabulation
// rules
// 1. write base case
// 2. write changing parameters in opposite fashion of recusion
// 3. copy the recurrence

// 1. base case
// in recursion we have base case: i) if(capacity==0)  and ii) if(index==n)
// i) if(capacity==0) then index can be anything from 0 to n-1 and buy can be anything from 0 to 1
// ii) if(index==n) then buy can be anything from 0 to 1 and capacity can be anything from 0 to 2

// 2. in recursion: for index we go from 0 to n-1 so in tabulation we go from n-1 to 0 abd buy and capacity go in same manner or can be take in opposite manner

// 3. copy the recurrence

// t.c-O(n*2*3)
// s.c-O(n*2*3) for dp
int f3(vector<int> &prices, int n)
{
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
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

  // we already done with index==n in base case so index here go from n-1 to 0
  for (int index = n - 1; index >= 0; index--)
  {
    for (int buy = 0; buy <= 1; buy++)
    {
      // we alrady done with capacity=0 in base case so for capacity go from 1 to 2
      for (int capacity = 1; capacity <= 2; capacity++)
      {
        // when allowed to buy:max(take,nottake) and transaction is complete when we do both buy and sell both by doing only buy does not complete transaction so capacity still same
        if (buy == 1)
        {
          dp[index][buy][capacity] = max(-prices[index] + dp[index + 1][0][capacity], 0 + dp[index + 1][1][capacity]);
        }
        // when not allowed to buy so sell so max(sell,notsell)
        // whne we sell then one complete transaction done so decrease capacity by 1 and when not sell so capacity still remain same
        else
          dp[index][buy][capacity] = max(prices[index] + dp[index + 1][1][capacity - 1], 0 + dp[index + 1][0][capacity]);
      }
    }
  }
  return dp[0][1][2];
}

// space optimization by converting 3D into 2D
// as in tabulation code for calculating dp[index][buy][capacity] we want dp[index+1][buy][capacity] values
// like if index=n-1 then for calculating dp[n-1][buy][capacity] we want values of dp[n][buy][capacity] and for calculating dp[n-2][buy][capacity] we want dp[n-1][buy][capacity] values only does not want dp[n][buy][capacity] so do we need to store entire dp matrix? no because we only want the ahead row means for n-1 we want nth row and for n-2 we want (n-1)th row and for n-3 we want (n-2)th row so we just want ahead row not entire matrix

// t.c-O(n*2*3)
// s.c-O(2*3)=O(1) = constant
int f4(vector<int> &prices, int n)
{
  // we makes two 2D array for storing ahead and curr rows
  vector<vector<int>> ahead(2, vector<int>(3, 0));
  vector<vector<int>> curr(2, vector<int>(3, 0));
  // we can write base case or not because we already initialize  with 0 so here we don't write base case alag se

  // we already done with index==n in base case so index here go from n-1 to 0
  for (int index = n - 1; index >= 0; index--)
  {
    for (int buy = 0; buy <= 1; buy++)
    {
      // we alrady done with capacity=0 in base case so for capacity go from 1 to 2
      for (int capacity = 1; capacity <= 2; capacity++)
      {
        // when allowed to buy:max(take,nottake) and transaction is complete when we do both buy and sell both by doing only buy does not complete transaction so capacity still same
        if (buy == 1)
        {
          curr[buy][capacity] = max(-prices[index] + ahead[0][capacity], 0 + ahead[1][capacity]);
        }
        // when not allowed to buy so sell so max(sell,notsell)
        // whne we sell then one complete transaction done so decrease capacity by 1 and when not sell so capacity still remain same
        else
          curr[buy][capacity] = max(prices[index] + ahead[1][capacity - 1], 0 + ahead[0][capacity]);
      }
    }
    ahead = curr;
  }
  return ahead[1][2];
}

// this is another solution of given problem with
// so we done this with dp[n][4]

// recursion solution of this
int F1(int index, int transactions, vector<int> &prices, int n)
{
  // base case
  if (index == n || transactions == 4)
    return 0;

  // when we are allowed to buy
  if (transactions % 2 == 0)
  {
    return max(-prices[index] + F1(index + 1, transactions + 1, prices, n), 0 + F1(index + 1, transactions, prices, n));
  }
  // when we are not allowed to buy
  return max(prices[index] + F1(index + 1, transactions + 1, prices, n), 0 + F1(index + 1, transactions, prices, n));
}
// memoization
int F2(int index, int transactions, vector<int> &prices, int n, vector<vector<int>> &dp)
{
  // base case
  if (index == n || transactions == 4)
    return 0;

  if (dp[index][transactions] != -1)
    return dp[index][transactions];

  // when we are allowed to buy
  if (transactions % 2 == 0)
  {
    return dp[index][transactions] = max(-prices[index] + F1(index + 1, transactions + 1, prices, n), 0 + F1(index + 1, transactions, prices, n));
  }
  // when we are not allowed to buy
  return dp[index][transactions] = max(prices[index] + F1(index + 1, transactions + 1, prices, n), 0 + F1(index + 1, transactions, prices, n));
}

// tabulation
int F3(vector<int> &prices, int n)
{
  vector<vector<int>> dp(n + 1, vector<int>(5, 0));
  // you can write base case or not because we already initialize  with 0
  // base case
  // when index==n
  for (int transactions = 0; transactions <= 4; transactions++)
    dp[n][transactions] = 0;
  // when transactions=4
  for (int index = 0; index <= n; index++)
    dp[index][4] = 0;

  // index=n we already done in base case
  for (int index = n - 1; index >= 0; index--)
  {
    // transaction=4 we already done in base case
    for (int transactions = 0; transactions < 4; transactions++)
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
int F4(vector<int> &prices, int n)
{
  vector<int> ahead(5, 0);
  vector<int> curr(5, 0);
  // // we can write base case or not because we already initialize  with 0 so here we don't write base case alag se

  // index=n  already done in base case
  for (int index = n - 1; index >= 0; index--)
  {
    // transaction=4 we already done in base case
    for (int transactions = 0; transactions < 4; transactions++)
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
int maxProfit(vector<int> &prices, int n)
{
  // recursion we start from 0th index and in initial we can buy so buy=1 and also in starting maximum transactions(i.e capacity)=2
  // return f1(0, 1, 2, prices, n);

  // memoization
  // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
  // return f2(0, 1, 2, prices, n, dp);

  // tabualtion
  // return f3(prices, n);

  // space optimization
  // return f4(prices, n);

  // with other solutions
  // recursion start with index=0 and transactions=0
  // return F1(0, 0, prices, n);

  // memoization
  // vector<vector<int>> dp(n, vector<int>(4, -1));
  // return F2(0, 0, prices, n, dp);

  // tabulation
  // return F3(prices, n);

  // space optimization
  return F4(prices, n);
}

int main()
{
  int n;
  cin >> n;
  vector<int> prices(n);
  for (int i = 0; i < n; i++)
    cin >> prices[i];
  cout << maxProfit(prices, n);
  return 0;
}

// above solution is one of the ways to do this problem but if we go across solutions in different sites we will see there are a couple of other solutions which are also discussed
// one of them is when  where they do not use this dp[n][2][3] instead of that they use an dp[n][4] that is one of the solution and the other one is where they use four different variables

// using four different variables to solve this problem is not intutive don't tell this one in interview

// here we discussed dp[n][4] solution
// what did we do we stated let's start at the day=0 with give him a permission of buy so buy=1 and have a maximu capacity=2 transactions and then keep on doing buy sell buy sell and whenener the sell is happening do a capacity-1 that's what we do that in above solution

// now if I say I will not have buy instead of that I will have an f(index,transaction) so if I'm performing two transactions can I say this means buy sell buy sell only means we can perform buy sell only two times so if I number them means 0 for buy, 1 for sell, 2 for buy, 3 for sell so can I say I'm performing a buy in an even index and performing sell in an odd index so I can start from 0 and then I can go 1 then I can go 2 then I can go to 3 and whenever I'm performing a transaction I move to the next if we carefully see I move to the next so instead of carrying a buy which tells me whether to buy and sell what I did was I converted this capacity=2 into capacity=4 and just tried to express buy and sell via the transactions numbers this is the slight change that we will do

// f(index,transaction){
// so the base case will become
// 1. when we reached the end means index==n
// 2. when we have performed all the transactions so
// if(index==n||transactions==4) return 0

// when we can buy when the transaction is an even index
// if(transaction%2==0){
// we can buy or not buy so max(take,nottake)
// when we buy we do transactions+1 or when we don't buy transaction as it is so
// return max(-prices[index]+f(index+1,transactions+1),0+f(index+1,transactions))
//}
// // when we cannot buy when transaction is an odd index
// else{
// we can sell or notsell so max(sell,notsell)
// return max(prices[index]+f(index+1,transactiosn+1),0+f(index+1,transactions))
//}
//}

// // so we done this with dp[n][4]

// // recursion solution of this
// int F1(int index, int transactions, vector<int> &prices, int n)
// {
//   // base case
//   if (index == n || transactions == 4)
//     return 0;

//   // when we are allowed to buy
//   if (transactions % 2 == 0)
//   {
//     return max(-prices[index] + F1(index + 1, transactions + 1, prices, n), 0 + F1(index + 1, transactions, prices, n));
//   }
//   // when we are not allowed to buy
//   return max(prices[index] + F1(index + 1, transactions + 1, prices, n), 0 + F1(index + 1, transactions, prices, n));
// }

// memoization
// t.c-O(n*4)
// s.c-O(n*4)(for dp)+O(n)for auxiliary stack space
// int F2(int index, int transactions, vector<int> &prices, int n, vector<vector<int>> &dp)
// {
//   // base case
//   if (index == n || transactions == 4)
//     return 0;

//   if (dp[index][transactions] != -1)
//     return dp[index][transactions];

//   // when we are allowed to buy
//   if (transactions % 2 == 0)
//   {
//     return dp[index][transactions] = max(-prices[index] + F1(index + 1, transactions + 1, prices, n), 0 + F1(index + 1, transactions, prices, n));
//   }
//   // when we are not allowed to buy
//   return dp[index][transactions] = max(prices[index] + F1(index + 1, transactions + 1, prices, n), 0 + F1(index + 1, transactions, prices, n));
// }

// // tabulation
// int F3(vector<int> &prices, int n)
// {
//   vector<vector<int>> dp(n + 1, vector<int>(4, 0));
//   // base case
//   // when index==n
//   for (int transactions = 0; transactions < 4; transactions++)
//     dp[n][transactions] = 0;
//   // when transactions=4
//   for (int index = 0; index <= n; index++)
//     dp[index][4] = 0;

// index=n we already done in base case
//   for (int index = n - 1; index >= 0; index--)
//   {
// transaction=4 we already done in base case
//     for (int transactions = 0; transactions < 4; transactions++)
//     {
//       // when we are allowed to buy
//       if (transactions % 2 == 0)
//       {
//         dp[index][transactions] = max(-prices[index] + dp[index + 1][transactions + 1], 0 + dp[index + 1][transactions]);
//       }
//       // when we are not allowed to buy
//      else
//  dp[index][transactions] = max(prices[index] + dp[index + 1][transactions + 1], 0 + dp[index + 1][transactions]);
//     }
//   }
//   return dp[0][0];
// }

// space optimization
// int F4(vector<int> &prices, int n)
// {
//   vector<int> ahead(5, 0);
//   vector<int> curr(5, 0);
//   // // we can write base case or not because we already initialize  with 0 so here we don't write base case alag se

//   // index=n  already done in base case
//   for (int index = n - 1; index >= 0; index--)
//   {
//     // transaction=4 we already done in base case
//     for (int transactions = 0; transactions < 4; transactions++)
//     {
//       // when we are allowed to buy
//       if (transactions % 2 == 0)
//       {
//         curr[transactions] = max(-prices[index] + ahead[transactions + 1], 0 + ahead[transactions]);
//       }
//       // when we are not allowed to buy
//       else
//         curr[transactions] = max(prices[index] + ahead[transactions + 1], 0 + ahead[transactions]);
//     }
//     ahead = curr;
//   }
//   return ahead[0];
// }
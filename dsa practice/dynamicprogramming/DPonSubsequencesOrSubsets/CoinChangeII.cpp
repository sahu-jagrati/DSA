// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

// You may assume that you have an infinite number of each kind of coin.

// The answer is guaranteed to fit into a signed 32-bit integer.

// Example 1:

// Input: amount = 5, coins = [1,2,5]
// Output: 4
// Explanation: there are four ways to make up the amount:
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1
// Example 2:

// Input: amount = 3, coins = [2]
// Output: 0
// Explanation: the amount of 3 cannot be made up just with coins of 2.
// Example 3:

// Input: amount = 10, coins = [10]
// Output: 1

// Constraints:

// 1 <= coins.length <= 300
// 1 <= coins[i] <= 5000
// All the values of coins are unique.
// 0 <= amount <= 5000

// as we already done problem MinimumCoins or CoinChange where the question is same only difference is that in that question we find minimum number of coins required to get target and here in this question we have to find all the ways to get target so in that question we take min(take,nottake) here we take sum(take,notTake) to get all ways

// so here in this question we have to return only total no. of ways that make target so if we make target by one combination then we return 1 or it we don't make target by a combination then we return 0 so

// and also here we can use any type of coin infinite times in that problem also we use any type coin infinite times so  we solve that problem if take that coin then still we stand at the same index to get that we take that coin more or not and if we nottake that coin then we move nextcoin

// so we start with the same procedure of the problem MinimumCoin only return value change here

// This is a Coin Change II problem where we want to count the total number of ways to make a target sum using an unlimited supply of given coins. For every coin, we have two choices: either take it (and stay at the same index since coins are unlimited), or not take it (and move to the previous index). By exploring these choices recursively and storing results using DP, we can efficiently solve the problem.

// Approach

// Define a recursive function countWaysToMakeChangeUtil(ind, T) which returns the number of ways to form sum T using coins up to index ind.
// Base case: If ind == 0, we can only form T if it is divisible by the first coin. when we at coins[0]
// At each step:
// Not Taken: move to the previous index.
// Taken: stay at the same index and reduce T by the current coin’s value.
// Use a DP table dp[ind][T] to store results and avoid recomputation.
// The final answer is countWaysToMakeChange(n-1, target).

// for more description of solution see MinimumCoin file

#include <bits/stdc++.h>
using namespace std;

// recursion here we do top-down so we go from index n-1 to 0 so we get base case at 0
// t.c for recursion- here is greater than O(2^n) in this problem it is greater than O(2^n) because for a particular index we're taking it and we're still standing on the same index so in order to analyze this you have to say that for every index the options that you have is not exactly 2^n it can go beyond that thereby we can like in general interview you don't have to explain this much you can call it as exponential because you cannot theoretically prove the t.c so you can call it as exponential

// s.c for recursion-O(n) can we say this? no because it's way more that that why because if you are standing at the same index the auxiliary space is not O(n) it can go beyond of that like assuming the minimum coin denomination is coin=1 and at max it can go upto O(target) assuming it reduces by one one one one it can go to target so again
// so s.c-O(target)
int f1(int index, int target, vector<int> &coins)
{
  // base case
  // index==0 and we have a single elt then
  if (index == 0)
  {
    if (target % coins[0] == 0)
    {
      // then we take coins
      return 1; // so there is one way
    }
    else
      return 0;
  }
  // if we nottake that coin then move to next coin with same target
  int notTake = f1(index - 1, target, coins);
  // if we take that coin so initially we take=0 because first we have to check that coins[index] is enough to get target
  int take = 0;
  // we still stand at the same index because we can take any coin infinite times
  if (coins[index] <= target)
    take = f1(index, target - coins[index], coins);

  return take + notTake; // return all ways to get target
}

// memoization
// t.c for memoization-O(n*amount)
// s.c-O(n*amount)(for dp)+O(amount)(around for auxiliary satck space )
int f2(int index, int target, vector<int> &coins, vector<vector<int>> &dp)
{
  // base case
  // index==0 and we have a single elt then
  if (index == 0)
  {
    if (target % coins[0] == 0)
    {
      // then we take coins
      return 1;
    }
    else
      return 0;
  }

  if (dp[index][target] != -1)
    return dp[index][target];
  // if we nottake that coin then move to next coin with same target
  int notTake = f2(index - 1, target, coins, dp);
  // if we take that coin so initially we take=0 because first we have to check that coins[index] is enough to get target
  int take = 0;
  // we still stand at the same index because we can take any coin infinite times
  if (coins[index] <= target)
    take = f2(index, target - coins[index], coins, dp);

  return dp[index][target] = take + notTake; // return all ways to get target
}

// tabulation
// so in recursion we go top-down approach from n-1 to 0 for index and for target we go from original target to 0
// so in tabulation we go from bottom-up from 0 to n-1 for index  and for target go from 0 to original target
// t.c-O(n*amount)
// s.c-O(n*amount) for dp

// as  constraints can be large so you can also use long instead of int to store
int f3(int n, int amount, vector<int> &coins)
{
  vector<vector<long>> dp(n, vector<long>(amount + 1, 0));
  // base case
  for (int target = 0; target <= amount; target++)
  {
    if (target % coins[0] == 0)
    {
      dp[0][target] = 1; // when index==0 and if condition satisfy then there is 1 way so return 1
    }
    else
      dp[0][target] = 0;
    // or Else condition is automatically fulfilled,
    // as dp array is initialized to zero
  }
  // index=0 already done in base case
  for (int index = 1; index < n; index++)
  {
    for (int target = 0; target <= amount; target++)
    {
      long notTake = dp[index - 1][target];
      long take = 0;
      if (coins[index] <= target)
        take = dp[index][target - coins[index]]; // we still stand at the same index because we can take any coin infinite times
      dp[index][target] = take + notTake;
    }
  }
  return dp[n - 1][amount];
}
// space optimization
// t.c-O(n*amount)
// s.c-O(amount) for prev,curr

// as  constraints can be large so you can also use long instead of int to store
int f4(int n, int amount, vector<int> &coins)
{
  vector<long> prev(amount + 1, 0);
  // base case
  for (int target = 0; target <= amount; target++)
  {
    if (target % coins[0] == 0)
      prev[target] = 1;
    // Else condition is automatically fulfilled,
    //  as prev array is initialized to zero
  }
  // index=0 already done in base case
  for (int index = 1; index < n; index++)
  {
    vector<long> curr(amount + 1, 0);
    for (int target = 0; target <= amount; target++)
    {
      long notTake = prev[target];
      long take = 0;
      if (coins[index] <= target)
        take = curr[target - coins[index]];
      curr[target] = take + notTake;
    }
    prev = curr;
  }
  return prev[amount];
}
int numberOfWays(int amount, vector<int> &coins)
{
  int n = coins.size();

  // recursion
  // return f1(n - 1, amount, coins);

  // memoization
  // vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
  // return f2(n - 1, amount, coins, dp);

  // tabulation
  // return f3(n, amount, coins);

  // space optimization
  return f4(n, amount, coins);
}

int main()
{
  int n;
  cin >> n;
  vector<int> coins(n);
  for (int i = 0; i < n; i++)
    cin >> coins[i];
  int amount;
  cin >> amount;
  cout << numberOfWays(amount, coins);
  return 0;
}
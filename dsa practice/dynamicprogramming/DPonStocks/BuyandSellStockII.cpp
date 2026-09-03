// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.

// Find and return the maximum profit you can achieve.

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
// Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
// Total profit is 4 + 3 = 7.
// Example 2:

// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// Total profit is 4.
// Example 3:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

// Constraints:

// 1 <= prices.length <= 3 * 10^4
// 0 <= prices[i] <= 10^4

#include <bits/stdc++.h>
using namespace std;

// in part I of this problem it were allowed to buy once and sell once stock but over here you can buy as many times as you want and you can sell as many times as you want.

// let's take an example:
// prices[]=[7,1,5,3,6,4]

// so what are you doing is you go to the market and you say I buy on day=2 with price=1 and sell on day=3 with price=5 so profit=5-1=4 and here we can buy and sell as many times so next we buy on day=4 with price=3 and sell it on day=5 with price=6 so profit=6-3=3 so total profit=7

// in other ways like I say I buy on day=2 and sell on day=4 so profit=3-1=2 but the thing that you cannot do is that you cannot go something like this you cannot buy continously and then you sell continuously means like you cannot do like that first we buy in day=2 and day=3 and then we sell on day=4 and day=5 so we cannot do this if you are buying then before performing the next buy you have to sell so buy and then you have to sell then again you can buy any day and sell you can't be like buy buy buy then sell sell sell that is strictly not allowed

// so other way is you buy on day=2 and sell on day=5 so profit=6-1=5 so you can perform buy sell as many times as you want only with the condition that before buying a stock you should have sold out the previous holding stocks so you can perform buy sell as many times and have to maximize the profit

// in this example the maximum profit we have=7

// so how will we actually solve this particular problem ?
// let's analyze this problem and try to approach
// so take an example
// prices[]=[5,1,5,3,6,4]

// so let's asssumne I will be starting over day=1 which have price=7 generically what can we do be like we can buy it and then we can sell it on any day and we can buy on other day and sell it on other day so there are a lot of ways like we can do a buy sell and whenver there are lot of ways what do we do? we try all ways and get the best possible answer from all ways and for try all ways we know one thing which is recursion

// and rules of recursion are:

// i) express everything in terms of index
// over here we have 1D array so we have index also then Do we need any other parameters? we need to think on this now we have done problems like knapsack where we have to take care if our bag was full or not now over here if we are standing at any day what decision can we make it on it we can buy or we cannot buy. How did we understand because we know if we are at day=1  before this we have not bought anything but if we are standing on day=3 or any other day then what decision can we make what if we bought someone here means in previous then you cannot buy here for sure you can sell it so what idea we are getting is on any index we have to know whether we have bought anything previously or not because if we bought in previously then we cannot buy it because if we buy then first we have to sell then we can buy next or if previous guy was sold then we can buy so we have to know if any guys were bought before or any guys were sold so do we have an allowance of buying so we can say we have to carry something like buy a varible which tells me can we buy or not buy if someone has bought this and he has not sold it so over here we definitely cannot buy so we have to carry a variable as buy which tells me can we buy that stock if we cann we'll either decided to buy or we'll skip it and go acroos and if we cannot buy then there are two options either sell it or don't sell

// so we take (index,buy) as a parameters for recursion

// ii) expore possibilities on that day

// iii) we are looking for best possible answer so try to add up what are we trying to make profits try to add up.  if we are buying then it is as a minus if we are selling it as a plus.
// whatever we are doing we wanting maximum profits so take the max of all profits
// iv) base case

// write the recurrence
// f(index,buy)
// assume buy=1 means you can buy and buy=0 means you cannot buy

// here in recursion we start from index=0 so bottom-up approach

// assuming the array is [7,1,5,3,6,4] and assuming we start at index=0 and can we say at f(0,buy) we have complete  liberty of buying because that's the first guy that's the first guy i'm giving you complete liberty of buying so we have f(0,1) means at index=0 we can buy
// so f(0,1) what it signifies- it tells we start on 0th index with buy, what max profit we can give

// f(index,buy){

// i) base case
// we are trying on every day when do we end up when we have tried on every day we have exhausted the days so we can be like when we exhaust the days that means when we reach the index==n
// if(index==n){
// whenever we come to the nth index there is no profit but we have to be careful over here what if we actually a bought a stock and we did not sell it so there wil be a problem right so coming across when we end all the days so there is no profit to be made but you have invested some moneymeans buy=0 that means you are still holding a stock means you have invested a money  minus so that won't matter so you will return 0 no more money you will get from the market because you are done so if you have gone with something it will be negative value so that will not be considered into your answer so return 0
// return 0
// }

// ii) explore possibilites
// there can be two possibilites : i) whether there will be a buy like I am allowed to buy then buy=1 ii) I am not allowed to buy then buy=0

// i) when I am allowed to buy so buy=1
// if(buy){
// so if I am allowed to buy then like if when we are at f(0,1) means index=0 and we can buy so we will definitely buy it or we will say this is too costly so let's not buy this and move to the next guy means if we buy there is also two cases: i) we can take ii) or nottake this guy like dp on subsequences we do so buy or notbuy also so assume just for an example if we decide to buy it on day=1 so price=7 and sell it on day=3 with price=5 so what is the profit? profit=5-7=-2 so we are adding -7 to answer wherener we are buying so whenever we are buying we add minus of price and whenever we are selling it we add plus of price so can I say if we decide to buy on that day then we will add minus of price on the profit and move to next guy which is index+1 (because we go from index 0 to n-1) and if we bought in index then he cannot buy at index+1 so he has to sell so buy=0
// profit=  (-prices[index])+f(index+1,0)  // take possibilitiy when we can buy
// next we say we are not interseted to buy on this because the price looks huge so if we are not interested to buy so we go across the next day and we are not buy on index so we can buy on index+1 so buy=1 for next guy so

// profit=0+f(index+1,1)  // not take possibility when we can buy
// as we want max of all profits so profit=max(take,notTake)
// profit=max(-prices[index]+f(index+1,0),0+f(index+1,1))
//}
// ii) possibilites: I am not allowed to buy so so we can sell it
// else{
// if we are not buying then we have to sell
// assume like we are at day=4 with price=3 and we say we are not intersted to sell because the price is very ow so we are not interested to sell or we can be like at day=5 with price =6 so here the price is very high so let's sell it so there is also two cases when we are not buying: i) we can sell it ii) or we cannot sell it
// i) we are not allowed to buy and we sell it then in profit we add the price and we move to the next guy and for the next guy we can buy it becase we sell the previous guy so buy=1
// profit= prices[index]+f(index+1,1) // case not buy and sell
// ii) we are not allowed to buy and we also not sell it then in profit we add 0 and we move to the next guy and for the next guy we cannot buy it because here we not sell previous guy till now then buy=0
// profit=0+f(index+1,0) // not buy and not sell
// we want max so
// profit=max(prices[index]+f(index+1,1),0+f(index+1,0));
//}

// return profit
//}

// t.c for recursion-O(2^n) because for every index you can either buy or not buy then in that we have two cases so if we buy or else we don't buy two cases
// s.c for recursion -O(n) auxiliary stack space

// there can be overlapping subproblems so we apply memoization
// and there are two changing parameters (index,buy)  so we make 2D dp array and index maximum value is n-1 and buy can be either 0 or 1 so declare dp[n][2]

// t.c for memoizaion: O(n*2)
// s.c-O(n*2)(for dp)+O(n)(for auxiliary stack space)

// recursion
long f1(int index, int buy, vector<int> &prices, int n)
{
  // base case when we exhausted the days and can be invest some money so return 0 because we cannot return profit to be negative
  if (index == n)
    return 0;

  long profit = 0; // we take every time profit because we don't compare with profit we add up price
  // when we can buy means buy=1
  if (buy)
  {
    // there is also two case either we take or not take
    profit = max(-prices[index] + f1(index + 1, 0, prices, n), 0 + f1(index + 1, 1, prices, n));
  }
  // when we can not buy means buy=0 that is we alrady bought the stock now we have to sell it first then we can buy next stock
  else
  {
    // there is also two case we sell with this price or not sell with this price and move to next
    profit = max(prices[index] + f1(index + 1, 1, prices, n), 0 + f1(index + 1, 0, prices, n));
  }
  return profit;
}

// memoization
int f2(int index, int buy, vector<int> &prices, vector<vector<int>> &dp, int n)
{
  // base case  when we exhausted the days and can be invest some money so return 0 because we cannot return profit to be negative
  if (index == n)
    return 0;
  if (dp[index][buy] != -1)
    return dp[index][buy];
  long profit = 0; // we take every time profit because we don't compare with profit we add up price
  // when we can buy means buy=1
  if (buy)
  {
    // there is also two case either we take or not take
    profit = max(-prices[index] + f1(index + 1, 0, prices, n), 0 + f1(index + 1, 1, prices, n));
  }
  // when we can not buy means buy=0 that is we alrady bought the stock now we have to sell it first then we can buy next stock
  else
  {
    // there is also two case we sell with this price or not sell with this price and move to next
    profit = max(prices[index] + f1(index + 1, 1, prices, n), 0 + f1(index + 1, 0, prices, n));
  }
  return dp[index][buy] = profit;
}

// tabulation
// rules for tabulation
// 1. write base case
// 2. write changing parameters in opposite fashion of recursion
// 3. copy the recurrence

// 1. base case
// in recursion we have base case: if(index==n) return 0
// so in tabulation we have to declare dp[n+1][2] because for index==n we want dp[n] so we decalre dp[n+1][2]
// and for buy we have two values only 0/1 so for every value of buy if index==n we return 0 so dp[n][0]=dp[n][1]=0;

// 2. changing parameters
// as in recursion for index we go from 0 to n-1
// so in tabulation we go opposite so here index go from n-1 to 0 abd for buy we can either go from 0 to 1 or can go from 1 to 0

// t.c for tabulation-O(n*2)
// s.c for tabulation-O(n*2) for dp
int f3(int n, vector<int> &prices)
{
  vector<vector<int>> dp(n + 1, vector<int>(2, 0));
  // base case when index==n and buy can be any 0/1 so
  dp[n][0] = dp[n][1] = 0;

  // iterations
  for (int index = n - 1; index >= 0; index--)
  {
    // for buy you can also go from 1 to 0
    for (int buy = 0; buy <= 1; buy++)
    {
      long profit = 0; // we take every time profit because we don't compare with profit we add up price
                       // when we can buy means buy=1
      if (buy)
      {
        // there is also two case either we take or not take
        profit = max(-prices[index] + dp[index + 1][0], 0 + dp[index + 1][1]);
      }
      // when we can not buy means buy=0 that is we alrady bought the stock now we have to sell it first then we can buy next stock
      else
      {
        // there is also two case we sell with this price or not sell with this price and move to next
        profit = max(prices[index] + dp[index + 1][1], 0 + dp[index + 1][0]);
      }
      dp[index][buy] = profit;
    }
  }
  return dp[0][1];
}

// space optimization
// as in tabulation code for calculating dp[index][buy] we want dp[index+1][buy] values
// like if index=n-1 then for calculating dp[n-1][buy] we want values of dp[n][buy] and for calculating dp[n-2][buy] we want dp[n-1][buy] values only does not want dp[n][buy] so do we need to store entire dp matrix? no because we only want the ahead row means for n-1 we want nth row and for n-2 we want n-1 row and for n-3 we want n-2 row so we just want ahead row not entire matrix and also we have only two columns beacuse buy can be either 0 or 1 so you can either make a two size 1D array or take two variables

// t.c-O(n*2)
// s.c-O(2*2)=O(1) for ahead and curr array
int f4(int n, vector<int> &prices)
{
  // we make here size=2 1D array
  vector<int> ahead(2, 0), curr(2, 0); // here we take ahead because for index=n-1 we want nth row means for calculating dp[index] we want values of dp[index+1] so
  // and for nth row we have base case
  ahead[0] = ahead[1] = 0; // base case when index==n and we know buy can either 0 or 1
  for (int index = n - 1; index >= 0; index--)
  {
    for (int buy = 0; buy <= 1; buy++)
    {
      long profit = 0; // we take every time profit because we don't compare with profit we add up price
                       // when we can buy means buy=1
      if (buy)
      {
        // there is also two case either we take or not take
        profit = max(-prices[index] + ahead[0], 0 + ahead[1]);
      }
      // when we can not buy means buy=0 that is we alrady bought the stock now we have to sell it first then we can buy next stock
      else
      {
        // there is also two case we sell with this price or not sell with this price and move to next
        profit = max(prices[index] + ahead[1], 0 + ahead[0]);
      }
      curr[buy] = profit;
    }
    ahead = curr;
  }
  return ahead[1];
}

// in above space optimization code we are using size=2 1D array for ahead and curr so the space is O(2*2) for ahead and curr instead of this you can also use a variables to write it but it does not affect it does not make more optimize it it's still the same thing if we are using a four variables - two for ahead and two for current

// space optimization by taking four variables instead of size=2 1D arrays ahead and curr but it does not affect it does not make more optimize it it's still the same thing

// so we declare four variables
// aheadBuy, aheadNotBuy, currBuy, currNotBuy i.e buy=1 means you can buy and buy=0 means you cannot buy
// as basically index goes from n-1 to 0 and buy go from 0 to 1 which is like buy is either 0 or 1 so whenevr buy=0 else part gets executed and whenever buy=1 if part gets executed so if we omit the buy for loop because since buy is 0 and 1  both will executed once so waht they will do is they will first execute the 0th guy then they will execute the 1 and they'll store it so we can also do the same thing

// as we see our above space optimization code then curr[buy]=profit
// whennver buy=0 what happens ? when buy=0 means currNotBuy=max(prices[index]+aheadBuy,0+aheadNotBuy)
// whenver buy=1 what happens? when buy=1 means currBuy=max(-prices[index]+aheadNotBuy,0+aheadBuy)

// in next step aheadBuy=currBuy
// and aheadNotBuy=CurrNotBuy

// t.c-O(n)
// s.c-O(1)
int f5(int n, vector<int> &prices)
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
    currNotBuy = max(prices[index] + aheadBuy, 0 + aheadNotBuy);

    aheadBuy = currBuy;
    aheadNotBuy = currNotBuy;
  }
  return aheadBuy;
}

int maxProfit(vector<int> &prices)
{
  int n = prices.size();

  // recursion here we start from index=0 and for index=0 we can buy it because from index=0 there is no prevous
  // return f1(0, 1, prices, n);

  // memoization
  // vector<vector<int>> dp(n, vector<int>(2, -1));
  // return f2(0, 1, prices, dp, n);

  // tabulation
  // return f3(n, prices);

  // space optimization usinh size=2 1D arrays ahead and curr
  // return f4(n, prices);

  // space optimization using four variables
  return f5(n, prices);
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
  cout << maxProfit(prices);
  return 0;
}
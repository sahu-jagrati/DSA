// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
// Example 2:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.

// Constraints:

// 1 <= prices.length <= 10^5
// 0 <= prices[i] <= 10^4

#include <bits/stdc++.h>
using namespace std;

// In question given that we want to maximize our profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.it means first you have to buy the stock then you can sell it means if you buy the stock at i=1 then you can sell it day from 2<=i<=n where n is size of array meand you cannot sell it i==0 because you buy it at i=1 so at i=0 you have no stock so first buy then sell.

// and you are only allowed to do this transaction like buying and selling can only be done once.

// here index=0 means day 1
// index=1 means day 2,index=2 means day 3 and so on

// let's take an example
// prices=[7,1,5,3,6,4] , n=6
// so day 1 have price=7
// day 2 have price =1
// day 3 have price =5
// day 4 have price =3
// day 5 have price =6
// day 6 have price =4

// so you have to decide a day when you buy a stock
// and you have to decide a day when you sell a stock

// let assume we buy a stock on day 2 so price =1 and we asking you when will you sell it? so you will be selling it on day=5 which have price=6 so profit=6-1=5
// and question states that you have to maximize the profit and we know in order to sell a stock we have to first buy the stock means we don't say like we buy the stock at day=2 and sell it on day=1 no it's wrong because first you have to buy a stock then you can sell it.

// another way like we buy on day=2 and sell it on day=3 so profit=5-1=4 which is less than previous profit

// and you are only allowed to do this transaction like buying and selling can only be done once.

// So how do you approach this problem?
// Now in order to approach this problem just assume we have prices=[7,1,5,3,6,4]

// optimal approach-

// now if we are selling the stock on day 6 having price=4 so When you will try to buy it? You will definitely try to buy it on the day which is the minimum price because if you buy it on day=3 then price=5 then you will have loss=4-5=-1
// so If you are selling on ith day then you buy on the minimum price from day=1 to day=(i-1)
// So can I say I will try for every day and definitely we cannot buy and sell on the same day because the profit will be 0 and that won't make any sense because we want to make profit we don't want to make losses.

// so we start from day=2 because for day=1 we cannot it so if we are selling on day=2 then we buy on the minimum price from day=1 to day=(i-1) which is day=(2-1)=1 so only day=1 for day=2 we buy so profit=1-7=-1 negative so not considered
// for day=3 we can buy from day=1 and day=2 so minimum price we get at day=2 which is 1 so profit=5-1=4
// for day=4 we can buy from day=1,day=2,day=3 so minimum price we get at day=2 which is 1 so profit=3-1=2
// for day=5 we can buy from day=1,day=2,day=3,day=4 so minimum price we get at day=2 which is 1 so profit 6-1=5
// for day=6 we can buy from day=1,day=2,day=3,day=4,day=5 so minimum price we get at day=2 which is 1 so profit=4-1=3

// so maximum profit we get is 5 , so answer=5
// so we can say  for every guy if we can keep a track of the minimal on the left our problem will be done

// so we know one thing for sure is that  the mini(i.e minimum) as of now is the first guy is the minimum because for day=2 we can buy it from day=1 and I know the profit=0 like we are not interested in making negative profit if we are making negative profit then we will not buy and sell or we'll buy and sell it on the same day so the profit will be zero.

// mini=price[0], profit=0
// Now can I say
// for(i=1;i<n;i++){
// so whenever we are at i=1 the price[0] is the minimal so can I say the cost it will cost is
// cost=selling price-buying price=price[i]-mini;
// profit=max(profit,cost);
// now when i=2 we have to take minimum price from day=1 and day=2 which is from i=0 and from i=1 so before moving to the next guy before doing an i++ we just need to make sure that the mini is updated by the current price so
// mini=min(mini,price[i]); so that on the next iteration we keep a track of the minimal. so while moving we are keeping a track of all the minimals of price[i] so for the next day we will be having the minimal
//}
// answer=profit

// t.c-O(n)
// s.c-O(1)
// so why dp here because by using mini we remember the past and update it according to next
int maximumProfit(vector<int> &prices)
{
  int n = prices.size();
  int mini = prices[0]; // for tracking minimum price
  int maxProfit = 0;    // because we cannot make negative profit
  // we go from i=1 to n-1 because for if we sell on day=1 that is i==0 we have no day to buy it so we cannot take i=0
  for (int i = 1; i < n; i++)
  {
    // cost price = selling price-buying price and we know buying price is the minimum price form day=1 to day=i-1 whcih we store in mini and selling price is the price[i]
    int cost = prices[i] - mini;
    maxProfit = max(maxProfit, cost);
    // and update mini for next day iteration
    mini = min(mini, prices[i]);
  }
  return maxProfit;
}

// as above is optimal approach
// this is brute force approach
// We try every possible pair of days (buy day and sell day after buy) and calculate the profit. The maximum profit among all these pairs is our answer. If no profit is possible, return 0.
// Loop through all days to consider each as a possible buy day.
// For each buy day, loop through all future days to consider them as sell days.
// Calculate the profit for each (buy, sell) pair.
// Track the maximum profit seen.

int maximumprofit(vector<int> &prices)
{
  int n = prices.size();
  int maxProfit = 0;
  //  // Loop through each day as a potential buy day
  for (int i = 0; i < n; i++)
  {
    // Loop through each future day as a potential sell day
    // we can sell it on day from i+1 to n-1 because if we sell it on same day we get profit =0 and we cannot sell day previoue because we have to first buy then sell
    for (int j = i + 1; j < n; j++)
    {
      int profit = prices[j] - prices[i];
      maxProfit = max(maxProfit, profit);
    }
  }
  return maxProfit;
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
  cout << maximumProfit(prices); // optimal approach
  // cout << maximumprofit(prices); // brute force approach
  return 0;
}
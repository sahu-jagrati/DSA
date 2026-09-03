// A shop is selling candies at a discount. For every two candies sold, the shop gives a third candy for free.

// The customer can choose any candy to take away for free as long as the cost of the chosen candy is less than or equal to the minimum cost of the two candies bought.

// For example, if there are 4 candies with costs 1, 2, 3, and 4, and the customer buys candies with costs 2 and 3, they can take the candy with cost 1 for free, but not the candy with cost 4.
// Given a 0-indexed integer array cost, where cost[i] denotes the cost of the ith candy, return the minimum cost of buying all the candies.

// Example 1:

// Input: cost = [1,2,3]
// Output: 5
// Explanation: We buy the candies with costs 2 and 3, and take the candy with cost 1 for free.
// The total cost of buying all candies is 2 + 3 = 5. This is the only way we can buy the candies.
// Note that we cannot buy candies with costs 1 and 3, and then take the candy with cost 2 for free.
// The cost of the free candy has to be less than or equal to the minimum cost of the purchased candies.
// Example 2:

// Input: cost = [6,5,7,9,2,2]
// Output: 23
// Explanation: The way in which we can get the minimum cost is described below:
// - Buy candies with costs 9 and 7
// - Take the candy with cost 6 for free
// - We buy candies with costs 5 and 2
// - Take the last remaining candy with cost 2 for free
// Hence, the minimum cost to buy all candies is 9 + 7 + 5 + 2 = 23.
// Example 3:

// Input: cost = [5,5]
// Output: 10
// Explanation: Since there are only 2 candies, we buy both of them. There is not a third candy we can take for free.
// Hence, the minimum cost to buy all candies is 5 + 5 = 10.

// Constraints:

// 1 <= cost.length <= 100
// 1 <= cost[i] <= 100

#include <bits/stdc++.h>
using namespace std;

// in this problem we have to buy two candies for getting third candy free and for getting free candy, the free candy cost should be less than or equal to each two candy we buy and we want minimum cost of buying all the candies.

// so first we sort the cost array because if we buy maximum cost candy then minimum cost candy we get free because it's cost is less than or equal to candy that we buy.

int minimumCost(vector<int> &cost)
{
  int n = cost.size();
  sort(cost.begin(), cost.end());
  int sum = 0;
  // if n<=2 so we have to buy all candy and we get no free candy
  if (n <= 2)
  {
    for (int i = 0; i < n; i++)
      sum += cost[i];
    return sum;
  }
  // we start from buying two maximum cost consecutive candy and skip the third candy because it's free on buying two candy and we already sort the cost array
  int i = n - 1;
  while (i >= 0)
  {
    // because we have to buy two candy for getting third candy free and we start from last so we have to check i-1 also in bound or not
    if (i - 1 >= 0)
    {
      sum += cost[i] + cost[i - 1];
    }
    // if i-1 not in bound then we take only ith candy and it's always the candy of 0th index becaiuse for that we don't have i-1
    else
    {
      sum += cost[i];
    }
    i -= 3; // because we have to skip the third candy because it's free on buying two candy
  }
  return sum;
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
  cout << minimumCost(cost);
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

// time complexity- O(nlogn)(for sorting)+ O(n)(for selection) = O(nlogn)
// space complexity=O(n)

// Function to solve 0/1 Knapsack and reconstruct chosen items
pair<int, vector<int>> knapsack(vector<int> &weights, vector<int> &values, int W)
{
  int n = weights.size();
  vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

  // Build DP table
  for (int i = 1; i <= n; i++)
  {
    for (int w = 1; w <= W; w++)
    {
      if (weights[i - 1] <= w)
      {
        dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
      }
      else
      {
        dp[i][w] = dp[i - 1][w];
      }
    }
  }

  // Maximum total value
  int maxValue = dp[n][W];

  // Reconstruct items
  vector<int> chosen;
  int i = n, w = W;
  while (i > 0 && w > 0)
  {
    if (dp[i][w] != dp[i - 1][w])
    {
      chosen.push_back(i); // item i taken
      w -= weights[i - 1];
    }
    i--;
  }

  reverse(chosen.begin(), chosen.end());
  return {maxValue, chosen};
}

int main()
{
  vector<int> weights = {2, 3, 4, 5};
  vector<int> values = {3, 4, 5, 8};
  int W = 5;

  pair<int, vector<int>> result = knapsack(weights, values, W);

  cout << "Maximum Total Value = " << result.first << endl;
  cout << "Items selected (1-based index): ";
  for (int item : result.second)
    cout << item << " ";
  cout << endl;

  return 0;
}

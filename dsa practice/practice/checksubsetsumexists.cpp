#include <bits/stdc++.h>
using namespace std;

bool subsetSumExists(vector<int> &S, int T)
{
  int n = S.size();
  vector<vector<bool>> dp(n + 1, vector<bool>(T + 1, false));

  // Base Case
  for (int i = 0; i <= n; i++)
    dp[i][0] = true;

  // DP Table
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= T; j++)
    {
      if (S[i - 1] > j)
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - S[i - 1]];
    }
  }

  return dp[n][T];
}

int main()
{
  vector<int> S = {3, 34, 4, 12, 5, 2};
  int T = 9;

  if (subsetSumExists(S, T))
    cout << "Subset with sum " << T << " exists.\n";
  else
    cout << "No subset with sum " << T << " exists.\n";

  return 0;
}

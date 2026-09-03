#include <bits/stdc++.h>
using namespace std;

// time complexity-O(n*T)
// space complexity-O(n*T),can be optimized to O(T) if only existence needed

bool subsetSumExists(vector<int> &S, int T, vector<int> &subset)
{
  int n = S.size();
  vector<vector<bool>> dp(n + 1, vector<bool>(T + 1, false));

  // Base case: sum 0 is always possible
  for (int i = 0; i <= n; i++)
    dp[i][0] = true;

  // Fill table
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

  // If no subset found
  if (!dp[n][T])
    return false;

  // Reconstruct one valid subset
  int i = n, j = T;
  while (i > 0 && j > 0)
  {
    // If the current value is same as above, this item wasn't taken
    if (dp[i][j] == dp[i - 1][j])
      i--;
    else
    {
      subset.push_back(S[i - 1]);
      j -= S[i - 1];
      i--;
    }
  }

  reverse(subset.begin(), subset.end());
  return true;
}

int main()
{
  vector<int> S = {3, 34, 4, 12, 5, 2};
  int T = 9;

  vector<int> subset;
  bool exists = subsetSumExists(S, T, subset);

  if (exists)
  {
    cout << "Subset with sum " << T << " exists.\n";
    cout << "One such subset: ";
    for (int num : subset)
      cout << num << " ";
    cout << endl;
  }
  else
  {
    cout << "No subset with sum " << T << " exists.\n";
  }

  return 0;
}

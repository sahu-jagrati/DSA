#include <bits/stdc++.h>
using namespace std;

// time complexity-O(n+m+n*m)=O(n*m)
// space complexity=O(n*m)for auxiliary stack space of dp array
int lenghtOfLongestCommonSubsequence(string &s, string &t)
{
  int n = s.size();
  int m = t.size();

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
  for (int i = 0; i <= n; i++)
    dp[i][0] = 0;
  for (int j = 0; j <= m; j++)
    dp[0][j] = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (s[i - 1] == t[j - 1])
      {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[n][m];
}

// TIME COMPLEXITY-O(n*m)(for tabulation)+O(n+m)(for backtracking)
// space complexity-O(n*m)(for auxiliary stack space of dp array)+O(ans.length)
string longestCommonSubsequence(string &s, string &t)
{
  int n = s.size();
  int m = t.size();

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
  for (int i = 0; i <= n; i++)
    dp[i][0] = 0;
  for (int j = 0; j <= m; j++)
    dp[0][j] = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (s[i - 1] == t[j - 1])
      {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  int length = dp[n][m];
  // string ans = "";
  // for (int i = 0; i < length; i++)
  // {
  //   ans += '$';
  // }
  string ans(length, '$');
  int index = length - 1;
  int i = n, j = m;
  while (i > 0 && j > 0)
  {
    if (s[i - 1] == t[j - 1])
    {
      ans[index] = s[i - 1];
      index--;
      i--, j--;
    }
    else if (dp[i - 1][j] > dp[i][j - 1])
    {
      i--;
    }
    else
    {
      j--;
    }
  }
  return ans;
}

int main()
{
  string s, t;
  cout << "Enter String: \n";
  cin >> s >> t;

  int length = lenghtOfLongestCommonSubsequence(s, t);
  string result = longestCommonSubsequence(s, t);

  cout << "Length of LCS: " << length << endl;
  cout << "LCS: " << result << endl;

  return 0;
}
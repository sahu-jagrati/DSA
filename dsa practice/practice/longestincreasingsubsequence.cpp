#include <bits/stdc++.h>
using namespace std;

// time complexity-O(n^2)(for dp(nested loop))+O(n)(for reconstruction)=O(n^2)
// space complexity-O(n)(for dp(nested loop))+O(n)(for reconstruction)=O(n)

pair<int, vector<int>> LIS(vector<int> &A)
{
  int n = A.size();
  vector<int> dp(n, 1), parent(n, -1);

  int maxLen = 1, lastIndex = 0;

  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (A[j] < A[i] && dp[j] + 1 > dp[i])
      {
        dp[i] = dp[j] + 1;
        parent[i] = j;
      }
    }
    if (dp[i] > maxLen)
    {
      maxLen = dp[i];
      lastIndex = i;
    }
  }

  // Reconstruct the LIS
  vector<int> lis;
  for (int i = lastIndex; i != -1; i = parent[i])
    lis.push_back(A[i]);
  reverse(lis.begin(), lis.end());

  return {maxLen, lis};
}

int main()
{
  vector<int> A = {11, 17, 5, 8, 6, 4, 7, 12, 3};

  pair<int, vector<int>> result = LIS(A);

  cout << "Length of LIS: " << result.first << endl;
  cout << "LIS Sequence: ";
  for (int x : result.second)
    cout << x << " ";
  cout << endl;

  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, vector<int>> weightedIndependentSet(vector<int> &w, int n)
{
  if (n == 0)
    return {0, {}};
  vector<int> dp(n + 1, 0);
  dp[1] = w[0];
  for (int i = 2; i <= n; i++)
  {
    dp[i] = max(dp[i - 1], w[i - 1] + dp[i - 2]);
  }
  vector<int> selectedVertices;
  int i = n;
  while (i >= 1)
  {
    if (dp[i] == dp[i - 1])
    {
      i = i - 1;
    }
    else
    {
      selectedVertices.push_back(i);
      i = i - 2;
    }
  }
  reverse(selectedVertices.begin(), selectedVertices.end());

  return {dp[n], selectedVertices};
}

int main()
{
  int n;
  cout << "Enter the number of vertices: ";
  cin >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++)
  {
    cin >> w[i];
  }
  auto result = weightedIndependentSet(w, n);
  cout << "Maximum total weight: " << result.first << endl;
  for (int it : result.second)
  {
    cout << "v" << it << " ";
  }
  cout << endl;
  return 0;
}
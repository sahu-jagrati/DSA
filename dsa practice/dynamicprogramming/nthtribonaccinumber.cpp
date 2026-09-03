// The Tribonacci sequence Tn is defined as follows:

// T0 = 0, T1 = 1, T2 = 1, and T(n+3) = T(n) + T(n+1) + T(n+2) for n >= 0.

// Given n, return the value of Tn.

// Example 1:

// Input: n = 4
// Output: 4
// Explanation:
// T_3 = 0 + 1 + 1 = 2
// T_4 = 1 + 1 + 2 = 4
// Example 2:

// Input: n = 25
// Output: 1389537

// Constraints:

// 0 <= n <= 37
// The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.

#include <bits/stdc++.h>
using namespace std;

// t.c-approx-O(n)
// s.c-O(38) =O(1) for dp array

// done by me fully
int tribonacciNumber(int n)
{
  if (n == 0)
    return 0;
  if (n == 1 || n == 2)
    return 1;
  // vector<int>dp(n+1);
  // as in constraint n range is given
  vector<int> dp(38); // 0<=n<=37
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 1;

  for (int i = 3; i <= n; i++)
  {
    dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1]; // as in the formula- T(n+3) = T(n) + T(n+1) + T(n+2) for n >= 0. So, we assume n+3=k so we can get T(k)=T(k-3)+T(k-2)+T(k-1) and in question it is ask T(n) so k= n here
  }
  return dp[n];
}

int main()
{
  int n;
  cin >> n;
  int answer = tribonacciNumber(n);
  cout << answer << endl;
  return 0;
}
// how to convert recursive to tabulation

#include <iostream>
#include <vector>
using namespace std;

// time complexity-O(n)
// space complexity-O(n)(for array just) here we have no recursion stack space // so we can see how we optimize space complexity
int fib(int n, vector<int> &dp)
{
  dp[0] = 0;
  dp[1] = 1; // here we go from base case to the main problem

  // we know fib(n-1)+fib(n-2) we use when n>=2
  for (int i = 2; i <= n; i++)
  {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  return dp[n];
}

int main()
{
  int n;
  cin >> n;
  vector<int> dp(n + 1, -1);
  cout << fib(n, dp) << endl;

  // now optimize more space complexity-O(n) to O(1)

  // time complexity-O(n)
  // space complexity-O(1)  // optimize space complexity
  int prev2 = 0; // denots the dp[0]
  int prev = 1;  // denote the dp[1]

  for (int i = 2; i <= n; i++)
  {
    int curri = prev + prev2; // denote the dp[i]=dp[i-1]+dp[i-2]
    prev2 = prev;
    prev = curri;
  }
  cout << prev << endl; // because when i=n+1 then curri=prev

  return 0;
}
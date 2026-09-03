// memoization also known as recursion solution

// we do for finding fibonacci(n)

#include <iostream>
#include <vector>
using namespace std;

// time complexity-O(n)
// space complexity-O(n)(for recursive stack space)+O(n)(for dp array)

// in this we go from answer to base case
int fib(int n, vector<int> &dp)
{
  if (n <= 1)
    return n;
  // If already computed, return stored value
  if (dp[n] != -1)
    return dp[n];
  // Otherwise compute and store
  return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

int main()
{
  int n;
  cin >> n;
  vector<int> dp(n + 1, -1);
  cout << fib(n, dp) << endl;
  return 0;
}
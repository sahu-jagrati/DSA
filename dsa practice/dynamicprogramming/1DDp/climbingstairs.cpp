// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

// Constraints:

// 1 <= n <= 45

#include <bits/stdc++.h>
using namespace std;

// Why This Works
// This is basically:
// dp[i]=dp[i−1]+dp[i−2]

// Because:

// From step i-1, you take 1 step

// From step i-2, you take 2 steps

// So it becomes Fibonacci-like- (it’s the standard Fibonacci DP approach

// t.c-O(n)
// s.c-O(n) for dp array
int climbStairs(int n)
{
  if (n <= 2)
    return n;
  vector<int> dp(n + 1, 0);
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= n; i++)
  {
    dp[i] = dp[i - 1] + dp[i - 2]; // we go upto i-1 and i-2 because each time we can either climb 1 or 2 steps
  }
  return dp[n];
}

// we can optimize space
// t.c-O(n)
// s.c-O(1)
int climbingStairs(int n)
{
  if (n <= 2)
    return n;
  int prev1 = 1; // dp[1]
  int prev2 = 2; // dp[2]

  for (int i = 3; i <= n; i++)
  {
    int curr = prev1 + prev2;
    prev1 = prev2;
    prev2 = curr;
  }
  return prev2;
}
int main()
{
  int n;
  cout << "Enter the step: ";
  cin >> n;

  // int answer = climbStairs(n);
  int answer = climbingStairs(n);
  cout << "Number of ways to reach top: " << answer << endl;
  return 0;
}

// using short trick
// first we convert our problem in index
// index here is like 0 to n
// do all possible stuff according to problem statement
// we can jump either 1 step or 2 step

// f(nreturn 1)
// {
// if(n<=2)return n  edge case when we are at first step we go to it only by one way so that's it

// do all stuff
// left=f(n-1) // we can go either 1 step at one move if we goe down from nth step
// right=f(n-2) // or we can go 2 step at one move so
// we have to count all possible ways so sum of all stuffs
// return left+right;
//}

// think about edge cases if we at n=1 we manage it
// but when we at n=2 so f(2-2) is what so we have to manage it also

// now it becomes like fibonacci problem
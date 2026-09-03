// Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

// The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.

// Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.

// Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.

// Example 1:

// Input: piles = [5,3,4,5]
// Output: true
// Explanation:
// Alice starts first, and can only take the first 5 or the last 5.
// Say she takes the first 5, so that the row becomes [3, 4, 5].
// If Bob takes 3, then the board is [4, 5], and Alice takes 5 to win with 10 points.
// If Bob takes the last 5, then the board is [3, 4], and Alice takes 4 to win with 9 points.
// This demonstrated that taking the first 5 was a winning move for Alice, so we return true.
// Example 2:

// Input: piles = [3,7,2,3]
// Output: true

// Constraints:

// 2 <= piles.length <= 500
// piles.length is even.
// 1 <= piles[i] <= 500
// sum(piles[i]) is odd.

#include <bits/stdc++.h>
using namespace std;

// recursion
// t.c-O(2^n)
// s.c-O(n)auxiliary stack space
int f1(int i, int j, vector<int> &piles)
{
  if (i == j)
    return piles[i];
  int takeLeft = piles[i] - f1(i + 1, j, piles);
  int takeRight = piles[j] - f1(i, j - 1, piles);
  return max(takeLeft, takeRight);
}

// memoization
// t.c-O(n^2)
// s.c-O(n^2)(for dp)+O(n)auxiliary stack space
int f2(int i, int j, vector<int> &piles, vector<vector<int>> &dp)
{
  if (i == j)
    return piles[i];
  if (dp[i][j] != -1)
    return dp[i][j];
  int takeLeft = piles[i] - f2(i + 1, j, piles, dp);
  int takeRight = piles[j] - f2(i, j - 1, piles, dp);
  return dp[i][j] = max(takeLeft, takeRight);
}

// tabulation
// t.c-O(n^2)
// s.c-O(n^2)(for dp)
int f3(vector<int> &piles, int n)
{
  vector<vector<int>> dp(n, vector<int>(n, 0));
  // base case
  for (int i = 0; i < n; i++)
    dp[i][i] = piles[i]; // when i==j

  // length of subarray
  for (int len = 2; len <= n; len++)
  {
    for (int i = 0; i + len - 1 < n; i++)
    {
      int j = i + len - 1;
      int takeLeft = piles[i] - dp[i + 1][j];
      int takeRight = piles[j] - dp[i][j - 1];

      dp[i][j] = max(takeLeft, takeRight);
    }
  }
  return dp[0][n - 1] > 0;
}

bool stoneGame(vector<int> &piles)
{
  int n = piles.size();
  // recursion
  // return f1(0, n - 1, piles) > 0;

  // memoization
  vector<vector<int>> dp(n, vector<int>(n, -1));
  return f2(0, n - 1, piles, dp) > 0;
}

int main()
{
  int n; // n is even
  cin >> n;
  vector<int> piles(n);
  for (int i = 0; i < n; i++)
    cin >> piles[i];
  cout << stoneGame(piles);
  return 0;
}

// this is the code that I'm thinking which is pass the testcase but it is incorrect
// because here in problem both ALice and Bob both play optimally means Alice wants to maximize his chances of winning but Bob also play optimally, so he wants to prevent ALice from Winning
// in my code I use || on both turns
// This means:
// Alice wins if either of his moves works. ✅
// Bob also helps Alice by choosing a move that lets Alice win.❌
// Bob should instead choose the move that is worst for Alice.
// So it should be || for Alice turn and && for Bob turn
// Why &&?
// Suppose Bob has two possible moves.
// If either move makes Alice lose, Bob will choose that move.
// Therefore, Alice can only guarantee a win if he still wins regardless of which move Bob picks.

// Hence Bob's turn uses &&.

// also in my solution passing score1 and score 2 through recursion works conceptually, but it's not suitable for DP because the state depends on these values.

// recursion
// bool f1(int i, int j, int k, int score1, int score2, vector<int> &piles)
// {
//   if (i > j)
//     return score1 > score2;
//   if (k == 0)
//   {
//     return f1(i + 1, j, 1, score1 + piles[i], score2, piles) || f1(i, j - 1, 1, score1 + piles[j], score2, piles);
//   }
//   return f1(i + 1, j, 0, score1, score2 + piles[i], piles) || f1(i, j - 1, 0, score1, score2 + piles[j], piles);
// }
// memoization
// we have three changing parameters (i,j,k)
// where i go from 0 to n-1 , j go from n-1 to 0 and k has two values either 0 or 1 so we declare dp[n][n][2]

// bool f2(int i, int j, int k, int score1, int score2, vector<int> &piles, vector<vector<vector<int>>> &dp)
// {
//   if (i > j)
//     return score1 >= score2;
//   if (dp[i][j][k] != -1)
//     return dp[i][j][k];
//   if (k == 0)
//   {
//     return dp[i][j][k] = f2(i + 1, j, 1, score1 + piles[i], score2, piles, dp) || f2(i, j - 1, 1, score1 + piles[j], score2, piles, dp);
//   }
//   return dp[i][j][k] = f2(i + 1, j, 0, score1, score2 + piles[i], piles, dp) || f2(i, j - 1, 0, score1, score2 + piles[j], piles, dp);
// }
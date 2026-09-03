// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

// Example 1:

// Input: text1 = "abcde", text2 = "ace"
// Output: 3
// Explanation: The longest common subsequence is "ace" and its length is 3.
// Example 2:

// Input: text1 = "abc", text2 = "abc"
// Output: 3
// Explanation: The longest common subsequence is "abc" and its length is 3.
// Example 3:

// Input: text1 = "abc", text2 = "def"
// Output: 0
// Explanation: There is no such common subsequence, so the result is 0.

// Constraints:

// 1 <= text1.length, text2.length <= 1000
// text1 and text2 consist of only lowercase English characters.

// To find the Longest Common Subsequence of two strings, we need to have the 2D DP table where each cell at position (i, j) stores the length of the LCS between the prefixes of the two strings up to indices i and j.

// we do recursion call of f(i,j) where initial call is f(n-1,m-1)
// let assume there are two strings s1 and s2
// s1.length=m and s2.length=n
// so we make dp[n][m]
// we take i and j where i move on s1 string and j move on s2 string
// if (s1[i]==s2[j]) then we add 1 in length and check previous length by dp
// dp[i][j]=1+dp[i-1][j-1]
// if (s1[i]!=s2[j]) then there are 2 case happens
// i) if we move i only one step then s1[i-1] match with current s2[j]
// ii) if we move j only one step then s2[j-1] macth with current s1[i]
// and take max of both
// we move back because we do recursion top-down approach

// let's code

#include <bits/stdc++.h>
using namespace std;

// recursion top-down approach in this we  for i we go from n-1 to 0 and j we go from m-1 to 0
// we pass the string by reference because every time we go with a new string
// t.c-O(2^(n+m))
// s.c-O(n+m) for auxiliary stack space
int f1(int i, int j, string &s1, string &s2)
{
  // base case
  if (i < 0 || j < 0)
    return 0;

  // if char match
  if (s1[i] == s2[j])
    return 1 + f1(i - 1, j - 1, s1, s2);

  // if don't match then
  return max(f1(i - 1, j, s1, s2), f1(i, j - 1, s1, s2));
}
// memoization
// t.c-O(n*m)
// s.c-O(n*m)(for dp)+O(n+m)(for auxiliary stack space)
int f2(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
  // base case
  if (i < 0 || j < 0)
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j];

  if (s1[i] == s2[j])
    dp[i][j] = 1 + f2(i - 1, j - 1, s1, s2, dp);
  else
    dp[i][j] = max(f2(i - 1, j, s1, s2, dp), f2(i, j - 1, s1, s2, dp));

  return dp[i][j];
}

// tabulation bottom-up aaproach for i we go from 0 to n-1 and for j we go from 0 to m-1

// rules:
// i) copy the base case
// ii) write down the changing parameters in opposite manner from recursion means in recursion we go top-down then here we go bottom-up
// iii) copy the recurrence

// now the base case
// in recursion we call f(i,j){
// and base case is if(i<0||j<0)return 0; in recursion we get i<0 or j<0
//}

// but here in tabulation we can't write cases for -1 because how do we write like dp[-1][j] or dp[i][-1] that's not possible so what we do is we do a shifting of index in order to write a tabulation, we can write tabulation whithout shifting of index but we learn here tabulation using shifting of index
// so there was index : -1,0,1,2,....,n-1 and we were calling these indexes like how did the function start in recursion f(n-1,m-1) can I do a right shift of the index and I say I will call f(n,m) but over here I will say n means n-1, 1 means 0 , 0 means -1 and so on I shifted the index one right so if we are shifting it one right so can I say f(i,j) if you have shifted i,j like initially i is n and j is m so can I say every i you are giving should be treated as i-1 and every j should be treated as j-1 because that is the meaning beecause as of now we send i and j in terms of one shifted index so can I say instead of (i<0||j<0) can I write (i==0||j==0) because we shift one index right so the base case has been changed .
// if(i==0||j==0)return 0 how can I write this in terms of dp
// what does i==0 means it means for i==0, j can be anything from 0 t0 m-1 and what does j==0 means it means i can be anything from 0 to n-1 sp dp[0][j]==0 when i==0 and when j==0 so dp[i][0]=0

// t.c-O(n*m)
// s.c-O(n*m) for dp
int f3(int n, int m, string s1, string s2)
{
  // one index right shift
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); // we take initial value as -1 because later length can be 0 also  or you can take 0 because for length 0 it remain as it is 0
  // base case
  // when i==0, j can be anything from 0 to m
  for (int j = 0; j <= m; j++)
    dp[0][j] = 0;
  // when j==0, i can be anything from 0 to n
  for (int i = 0; i <= n; i++)
    dp[i][0] = 0;

  // for remaining
  // we do one right shift so we go upto <=n and <=m
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      // but i means i-1 and j means j-1 for a string traversal
      if (s1[i - 1] == s2[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  return dp[n][m]; // because we shift one right
}

// space optimization
// t.c-O(n*m)
// s.c-O(m) we make row of size m
int f4(int n, int m, string s1, string s2)
{
  vector<int> prev(m + 1, 0), curr(m + 1, 0);
  // base case
  // we have single row only so we write when i==0
  for (int j = 0; j <= m; j++)
    prev[j] = 0; // if you don't want then  also there is no need to write base case because we already start with 0
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (s1[i - 1] == s2[j - 1])
        curr[j] = 1 + prev[j - 1];
      else
        curr[j] = max(prev[j], curr[j - 1]);
    }
    prev = curr;
  }
  return prev[m];
}
int longestCommonSubsequence(string text1, string text2)
{
  int n = text1.size();
  int m = text2.size();

  // recursion
  // return f1(n - 1, m - 1, text1, text2);

  // memoization
  // vector<vector<int>> dp(n, vector<int>(m, -1));
  // return f2(n - 1, m - 1, text1, text2, dp);

  // tabulation
  // return f3(n, m, text1, text2);

  // space optimization
  return f4(n, m, text1, text2);
}

int main()
{
  string text1, text2;
  cin >> text1 >> text2;
  cout << longestCommonSubsequence(text1, text2);
  return 0;
}
// Problem Statement: Given a string, Find the longest palindromic subsequence length in given string.

// A palindrome is a sequence that reads the same backwards as forward.
// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

// Examples
// Example 1:
// Input:
//  s = "eeeme"
// Output:
//  4
// Explanation:
//  The longest palindromic subsequence is "eeee", which has a length of 4.

// Example 2:
// Input:
//  s = "annb"
// Output:
//  2
// Explanation:
//  The longest palindromic subsequence is "nn", which has a length of 2.

// Example 1:

// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic subsequence is "bbbb".
// Example 2:

// Input: s = "cbbd"
// Output: 2
// Explanation: One possible longest palindromic subsequence is "bb".

// Constraints:

// 1 <= s.length <= 1000
// s consists only of lowercase English letters.

// how do we solve this problem?
// the first method that comes to mind is definitely a way that say generate all the subsequences and how can you generate all the subsequences - by using two methods - i) recursion ii) power set method and then check for palindrome and pick up the longest one this is the brute force solution

// if we try to optimize those brute force then we have to write a recursive solution and think of something but can we solve this using something that we learned in previous problem longest common subsequence because we will try to take this problem into that arena so how we will try?

// what does the problem actually mean so for that let's take an example : let's take a bigger string
// s="bbabcbcab"
// and for this longest palindromic subsequence is 'babcbab' of length=7 now something to observe if we take one pointer at front and one pointer at back of string and then we start traverse string like here in this example front=0 and back=n-1 pointers where n is the size of string so now s[0]match with s[n-1] then we move s[2] match with s[n-2] then s[3] match with s[n-4] then c is someone in between so it matches from the front and from the back so can I say this if we try to write the string s  in the reverse order let's assume this s1='bbabcbcab' and in reverse it is s2='bacbcbabb' so if I try to write  the given string in reverse order then can I say this longest palindromic subsequence for this string 'babcbac' is that and can we try to connect s1 and s2 to longest common subsequence ? yes we can if we take the string s1 and the string s2 and if we try to find the longest common subsequence of both the strings because since we've written the string in the reverse order we will find these exact same same string in s2 as well because we've written that in the reverse order that's what palindrome is so what I can say is instead of thinking of any other way to solve this problem we solve it by longest common subsequence like given string is s1 then take reverse of it and find the longest common subsequence of s1 and s2 and since we can intuitively see that what is palindrome it's the reverse is same so why don't we write the reverse of s1 and if the reverse is same so some portion which is same and when we write them reverse should also be same then we get the palindrome and if there is a portion of string which is present in s1 as well and is present in s2 as well then what do we call it? we call that as common subsequence and what do we require? we require the longest common subsequece so can I say I know one thing for sure if I just attach the longest term to these s1 and s2 then the longest is bound to be the longest palindromic subsequence because s2 is written in the reverse order it's not in the same order it's in the reverse order so whichever string will match it's simce it's the reverse thereby we can call them as palindromes because a string which is in a normal way and the string which is in the reverse way if they are matching we know they called as palindrome so basically if we get the longest common subsequence of both the strings which is bound to be a palindromic because s2 is nothing but the reverse of s1

// so solve this problem we just call the code of longest common subsequence and pass the s1 and s2 where s2 is reverse of s1

#include <bits/stdc++.h>
using namespace std;

// recursion code of longest common subsequence
// t.c-O(2^(n+m))
// s.c-O(n+m) for auxiliary stack space
// since s2 is the reverse of s so having same size so m=n
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

// memoization code of longest common subsequence
// t.c-O(n*m)
// s.c-O(n*m)(for dp)+O(n+m)(for auxiliary stack space)
// since s2 is the reverse of s so having same size so m=n
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

// tabulation code of longest common subsequence

// t.c-O(n*m)
// s.c-O(n*m) for dp
// since s2 is the reverse of s so having same size so m=n
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

// space optimization code of longest common subsequence

// t.c-O(n*m)
// s.c-O(m) we make row of size m
//   // since s2 is the reverse of s so having same size so m=n
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

// so in this problem we just pass second string as reverse of given string and all are same of longest common subsequence
int longestPalindromeSubseq(string s)
{
  // first we find reverse of s
  string s2 = s;
  reverse(s2.begin(), s2.end());

  int n = s.size();
  // since s2 is the reverse of s so having same size so m=n
  // recursion
  // return f1(n - 1, n - 1, s, s2);

  // memoization
  // vector<vector<int>> dp(n, vector<int>(n, -1));
  // return f2(n - 1, n - 1, s, s2, dp);

  // tabulation
  // return f3(n, n, s, s2);

  // space optimization
  return f4(n, n, s, s2);
}

int main()
{
  string s;
  cin >> s;
  cout << longestPalindromeSubseq(s);
  return 0;
}
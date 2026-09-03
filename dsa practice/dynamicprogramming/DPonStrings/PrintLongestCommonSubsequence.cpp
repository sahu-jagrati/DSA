// Problem Description: Given two strings str1 and str2, print the longest common subsequence of the two strings.

// A subsequence of a string is a list of characters of the string where zero or more characters are deleted and they should be in the same order in the subsequence as in the original string.

// Examples
// Input: str1 = "abcd", str2="bdef"
// Output: "bd"
// Explanation: LCS of two strings is "bd".
// Input: str1 = "apple" str2 = "waffle"
// Output: "ale"
// Explanation: LCS of two strings is "ale".

#include <bits/stdc++.h>
using namespace std;

// for this first see code of LongestCommonSubsequence
// in that we do that if s1[i]==s2[j] then we move to dp[i-1][j-1] and if they do not match then we go max(dp[i-1][j],dp[i][j-1]) so it's clear that when they match take that character and move diagonally and when they don't match then move max(dp[i-1][j],dp[i][j-1])

// To find the Longest Common Subsequence of two strings, we need to have the 2D DP table where each cell at position (i, j) stores the length of the LCS between the prefixes of the two strings up to indices i and j.

// To make this 2D DP table we can follow any of the approach that we learned while finding the length of the Longest Common Subsequence.
// Once the DP table is completely filled, start from the bottom-right corner (n,m) of the table, where n and m are the lengths of the two strings.
// Compare the characters of the two strings at positions i-1 and j-1:
// If they match, this character is part of the LCS. Add this character to the LCS string (building it backwards) and move diagonally up-left i-1, j-1) in the DP table.
// If they do not match, move in the direction of the larger DP value between dp[i-1][j] and dp[i][j-1]. This step helps trace the path of the optimal solution:
// If dp[i-1][j] is greater than dp[i][j-1], move up to (i-1, j). Otherwise, move left to i, j-1.
// Continue this process until you reach the top row or leftmost column (i == 0 or j==0).
// Reverse the collected characters since the reconstruction starts from the end.
// The reversed string is the actual LCS between the two strings.

// in tabulation solution of LongestCommonSubsequemce where we find the length of longest common subsequence we do by shift one right index means in that i=1 means 0, i=n means n-1
// so on I shifted the index by  right one step so if we are shifting it one right so can I say f(i,j) if you have shifted i,j like initially i is n and j is m so can I say every i you are giving should be treated as i-1 and every j should be treated as j-1 because that is the meaning beecause as of now we send i and j in terms of one shifted index

// copy the tabulation code of LCS

// for visually knowing how to print longest common subsequence take example and filled dp table then examine it you know how we print it then

// t.c-O(n*m)(for dp filled)+O(n+m)(for print we traverse both string in worst case  )
// s.c-O(n*m)for dp
string printLCS(string text1, string text2)
{
  int n = text1.size();
  int m = text2.size();

  // copy tabulation code of longest common subsequence
  // we take n+1 and m+1 because we shifted the  index right by one step
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
  // base case when i==0
  for (int j = 0; j <= m; j++)
    dp[0][j] = 0;
  // when j==0
  for (int i = 0; i <= n; i++)
    dp[i][0] = 0;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (text1[i - 1] == text2[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  // now we got the filled dp matrix and length of longest common subsequence is at dp[n][m]
  int length = dp[n][m];
  // so print LCS size is also equal to length
  string ans = "";
  // for just fill ans by $
  for (int i = 0; i < length; i++)
  {
    ans += '$';
  }

  // for print longest common subsequence we start from dp[n][m]
  // and if we start from back then the string we get is in reverse order so we take index for ans string start from length-1 so it start filling from last index so we don't have to reverse in last

  int index = length - 1;
  int i = n, j = m;
  // as in tabulation we shifted the index right by one step  so i and j should be >0 because when i==0 or j==0 then i-1 or j-1 give -1 so for that we don't take i==0 and j==0
  while (i > 0 && j > 0)
  {
    // check string
    // when character match
    if (text1[i - 1] == text2[j - 1])
    {
      // then character add in ans
      ans[index] = text1[i - 1];
      // and we move both i and j by i-1 and j-1 as we do in dp when they are equal
      i--, j--;
      index--;
    }
    // when the character don't match then max of dp
    else if (dp[i - 1][j] > dp[i][j - 1])
    {
      // then move left
      i--;
    }
    else
    {
      j--; // when dp[i-1][j]<dp[i][j-1] so we move up
    }
  }

  return ans; // we don't do reverse because we already start index from last
}

int main()
{
  string text1, text2;
  cin >> text1 >> text2;
  cout << printLCS(text1, text2);
  return 0;
}
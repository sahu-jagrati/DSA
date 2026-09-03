// Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

// In one step, you can delete exactly one character in either string.

// Example 1:

// Input: word1 = "sea", word2 = "eat"
// Output: 2
// Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
// Example 2:

// Input: word1 = "leetcode", word2 = "etco"
// Output: 4

// Constraints:

// 1 <= word1.length, word2.length <= 500
// word1 and word2 consist of only lowercase English letters.

// this problem is similar to problem Minimum insertions or deletions to convert string A to Bin that we make string A to B by inserting some char or delete some char in string A only to convert in B while in this problem we have only delete operations on both string so by using longest common subsequence of word1 and word2 we get a length of longest common subsequence this is the length og common subsequence which is in both string so now if we delete remaining characters from both the strings except longest common then we get minimum number of steps to make word1 and word2 same
// // let length=length of the longest common subsequence.
// Minimum number of steps required=(n-length)+(m-length)=(n+m-2*length)
// where n is size of str1 and m is size of str2

#include <bits/stdc++.h>
using namespace std;

// so we just copy the space optimization code of longest common subsequence for recursion,meoization,tabualtion see in it file
// t.c-O(n*m)
// s.c-O(m) for prev,curr
int longestCommonSubsequence(int n, int m, string str1, string str2)
{
  vector<int> prev(m + 1, 0), curr(m + 1, 0);
  // base case
  for (int j = 0; j <= m; j++)
    prev[j] = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (str1[i - 1] == str2[j - 1])
      {
        curr[j] = 1 + prev[j - 1];
      }
      else
      {
        curr[j] = max(prev[j], curr[j - 1]);
      }
    }
    prev = curr;
  }
  return prev[m];
}

// so minimum operations required=(n-length)+(m-length)=(n+m-2*length)
int minimumOperations(string word1, string word2)
{
  int n = word1.size();
  int m = word2.size();
  int length = longestCommonSubsequence(n, m, word1, word2);
  int deletionsInWord1 = n - length;
  int deletionsInword2 = m - length;

  return (deletionsInWord1 + deletionsInword2);
}

int main()
{
  string word1, word2;
  cin >> word1 >> word2;
  cout << minimumOperations(word1, word2);
  return 0;
}
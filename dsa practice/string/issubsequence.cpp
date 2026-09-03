// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

// A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

// Example 1:

// Input: s = "abc", t = "ahbgdc"
// Output: true
// Example 2:

// Input: s = "axc", t = "ahbgdc"
// Output: false

// Constraints:

// 0 <= s.length <= 100
// 0 <= t.length <= 104
// s and t consist only of lowercase English letters

#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string t)
{
  int n = s.size();
  int m = t.size();
  int i = 0, j = 0;
  while (i < n && j < m)
  {
    if (s[i] == t[j])
    {
      i++;
      j++;
    }
    else if (s[i] != t[j])
      j++;
  }
  if (i == n)
    return true;
  return false;
}

int main()
{
  string s, t;
  cin >> s >> t;
  cout << isSubsequence(s, t) << endl;
  return 0;
}
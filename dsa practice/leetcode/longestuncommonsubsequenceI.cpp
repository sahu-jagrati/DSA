// Given two strings a and b, return the length of the longest uncommon subsequence between a and b. If no such uncommon subsequence exists, return -1.

// An uncommon subsequence between two strings is a string that is a subsequence of exactly one of them.

// Example 1:

// Input: a = "aba", b = "cdc"
// Output: 3
// Explanation: One longest uncommon subsequence is "aba" because "aba" is a subsequence of "aba" but not "cdc".
// Note that "cdc" is also a longest uncommon subsequence.
// Example 2:

// Input: a = "aaa", b = "bbb"
// Output: 3
// Explanation: The longest uncommon subsequences are "aaa" and "bbb".
// Example 3:

// Input: a = "aaa", b = "aaa"
// Output: -1
// Explanation: Every subsequence of string a is also a subsequence of string b. Similarly, every subsequence of string b is also a subsequence of string a. So the answer would be -1.

// Constraints:

// 1 <= a.length, b.length <= 100

#include <bits/stdc++.h>
using namespace std;

// if both string are same i.e if s1==s2 then there is no uncommon subsequence, all subsequence of string a is also a sunsequence of string b

// so if s1!=s2 then the longest uncommon subsequence it max size string itself means s1.size>s2.size then s1 is longest uncommon subsequence or vice-versa

// A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters

// we want longest uncommon instead of longest common so if s1!=s2 then max size string is longest uncommon subsequence

int findLUSLength(string s1, string s2)
{
  int n = s1.size();
  int m = s2.size();
  if (s1 == s2)
    return -1;
  return max(n, m);
}

int main()
{
  string s1, s2;
  cin >> s1 >> s2;

  cout << findLUSLength(s1, s2) << endl;
  return 0;
}
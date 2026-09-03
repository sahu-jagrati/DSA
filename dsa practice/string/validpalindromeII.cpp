// Given a string s, return true if the s can be palindrome after deleting at most one character from it.

// Example 1:
// Input: s = "aba"
// Output: true

// Example 2:
// Input: s = "abca"
// Output: true
// Explanation: You could delete the character 'c'.

// Example 3:
// Input: s = "abc"
// Output: false

// Constraints:

// 1 <= s.length <= 105
// s consists of lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

// When mismatch happens:

// either Try skipping left character
// OR skip right character
// Check if the remaining substring is palindrome

// only one deletion allowed, so we return immediately
bool isPalindrome(string &s, int l, int r)
{
  while (l <= r)
  {
    if (s[l] != s[r])
      return false;
    l++;
    r--;
  }
  return true;
}

// t.c-O(n)
// s.c-O(1)
bool validPalindrome(string s)
{
  int n = s.size();
  int l = 0, r = n - 1;
  while (l <= r)
  {
    if (s[l] == s[r])
    {
      l++;
      r--;
    }
    else
    {
      return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
    }
  }
  return true;
}

int main()
{
  string s;
  cin >> s;

  cout << validPalindrome(s) << endl;
  return 0;
}
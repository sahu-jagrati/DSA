// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

// Example 1:

// Input: s = "egg", t = "add"

// Output: true

// Explanation:

// The strings s and t can be made identical by:

// Mapping 'e' to 'a'.
// Mapping 'g' to 'd'.
// Example 2:

// Input: s = "f11", t = "b23"

// Output: false

// Explanation:

// The strings s and t can not be made identical as '1' needs to be mapped to both '2' and '3'.

// Example 3:

// Input: s = "paper", t = "title"

// Output: true

// Constraints:

// 1 <= s.length <= 5 * 10^4
// t.length == s.length
// s and t consist of any valid ascii character.

#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{
  int n = s.size();
  int m = t.size();
  if (n != m)
    return false;
  map<char, char> mpp;
  vector<int> ascii(256, 0);
  int i = 0, j = 0;
  while (i < n && j < m)
  {
    if (mpp.find(s[i]) != mpp.end())
    {
      if (mpp[s[i]] != t[j])
        return false;
    }
    else
    {
      if (ascii[t[j]] == 0)
      {
        mpp[s[i]] = t[j];
        ascii[t[j]] = 1;
      }
      else if (ascii[t[j]] != 0)
      {
        return false;
      }
    }
    i++;
    j++;
  }
  return true;
}

int main()
{
  string s, t;
  cin >> s >> t;

  bool answer = isIsomorphic(s, t);
  cout << answer << endl;
  return 0;
}
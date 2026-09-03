// A string is good if there are no repeated characters.

// Given a string s​​​​​, return the number of good substrings of length three in s​​​​​​.

// Note that if there are multiple occurrences of the same substring, every occurrence should be counted.

// A substring is a contiguous sequence of characters in a string.

// Example 1:

// Input: s = "xyzzaz"
// Output: 1
// Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz".
// The only good substring of length 3 is "xyz".
// Example 2:

// Input: s = "aababcabc"
// Output: 4
// Explanation: There are 7 substrings of size 3: "aab", "aba", "bab", "abc", "bca", "cab", and "abc".
// The good substrings are "abc", "bca", "cab", and "abc".

// Constraints:

// 1 <= s.length <= 100
// s​​​​​​ consists of lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

// brute force - generate all substrings and check
int countGoodSubstrings(string s)
{
  int n = s.size();
  int cnt = 0;
  // we go upto n-3 because we want good substring of length 3 so if we go for i=n-2 then there is only 2 char left so not length=3
  for (int i = 0; i <= n - 3; i++)
  {
    // set for checking char is already in substring or not
    set<char> st;
    bool flag = 1;
    for (int j = i; j < i + 3; j++)
    {
      if (st.count(s[j]))
      {
        flag = 0;
        break;
      }
      st.insert(s[j]); // when not in set
    }
    if (flag == 1)
      cnt++;
  }
  return cnt;
}

int main()
{
  string s;
  cin >> s;
  cout << countgoodSubstring(s);
  return 0;
}
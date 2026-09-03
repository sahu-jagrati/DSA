// Given a string s, return true if s is a good string, or false otherwise.

// A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).

// Example 1:

// Input: s = "abacbc"
// Output: true
// Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.
// Example 2:

// Input: s = "aaabb"
// Output: false
// Explanation: The characters that appear in s are 'a' and 'b'.
// 'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.

// Constraints:

// 1 <= s.length <= 1000
// s consists of lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

bool areOccurrencesEqual(string s)
{
  int n = s.size();
  int cnt[26] = {0};
  for (auto ch : s)
  {
    cnt[ch - 'a']++;
  }
  for (int i = 0; i < n - 1; i++)
  {
    if (cnt[s[i] - 'a'] != cnt[s[i + 1] - 'a'])
      return false;
  }
  return true;
}

int main()
{
  string s;
  cin >> s;
  cout << areOccurrencesEqual(s) << endl;
  return 0;
}
// Given an array of strings patterns and a string word, return the number of strings in patterns that exist as a substring in word.

// A substring is a contiguous sequence of characters within a string.

// Example 1:

// Input: patterns = ["a","abc","bc","d"], word = "abc"
// Output: 3
// Explanation:
// - "a" appears as a substring in "abc".
// - "abc" appears as a substring in "abc".
// - "bc" appears as a substring in "abc".
// - "d" does not appear as a substring in "abc".
// 3 of the strings in patterns appear as a substring in word.
// Example 2:

// Input: patterns = ["a","b","c"], word = "aaaaabbbbb"
// Output: 2
// Explanation:
// - "a" appears as a substring in "aaaaabbbbb".
// - "b" appears as a substring in "aaaaabbbbb".
// - "c" does not appear as a substring in "aaaaabbbbb".
// 2 of the strings in patterns appear as a substring in word.
// Example 3:

// Input: patterns = ["a","a","a"], word = "ab"
// Output: 3
// Explanation: Each of the patterns appears as a substring in word "ab".

// Constraints:

// 1 <= patterns.length <= 100
// 1 <= patterns[i].length <= 100
// 1 <= word.length <= 100
// patterns[i] and word consist of lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

// .find() is builtin functoion that is used to search for a substring or character inside a string.

// 🔹 Syntax
// size_t pos = s.find(value);
// value → character or substring to search
// Returns:
// ✅ index of first occurrence
// ❌ string::npos if not found

// .find() return index not boolean value
int numOfStrings(vector<string> &patterns, string word)
{
  int cnt = 0;
  for (int i = 0; i < patterns.size(); i++)
  {
    if (word.find(patterns[i]) != string::npos)
      cnt += 1;
  }
  return cnt;
}
int main()
{
  string word;
  cin >> word;
  int n;
  cin >> n;
  vector<string> patterns(n);
  for (int i = 0; i < n; i++)
    cin >> patterns[i];
  cout << numOfStrings(patterns, word);
  return 0;
}
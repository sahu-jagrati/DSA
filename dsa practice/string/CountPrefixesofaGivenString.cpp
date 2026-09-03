// You are given a string array words and a string s, where words[i] and s comprise only of lowercase English letters.

// Return the number of strings in words that are a prefix of s.

// A prefix of a string is a substring that occurs at the beginning of the string. A substring is a contiguous sequence of characters within a string.

// Example 1:

// Input: words = ["a","b","c","ab","bc","abc"], s = "abc"
// Output: 3
// Explanation:
// The strings in words which are a prefix of s = "abc" are:
// "a", "ab", and "abc".
// Thus the number of strings in words which are a prefix of s is 3.
// Example 2:

// Input: words = ["a","a"], s = "aa"
// Output: 2
// Explanation:
// Both of the strings are a prefix of s.
// Note that the same string can occur multiple times in words, and it should be counted each time.

// Constraints:

// 1 <= words.length <= 1000
// 1 <= words[i].length, s.length <= 10
// words[i] and s consist of lowercase English letters only.

#include <bits/stdc++.h>
using namespace std;

// in this we have to match that the whole string of words array should be equal to the prefix of s string
// we have to take prefix of s and match that how many string are equal to the prefix of s

int countPrefixes(vector<string> &words, string s)
{
  int n = words.size();
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    string str = words[i];
    bool flag = 1;
    for (int j = 0; j < str.size(); j++)
    {
      // we have to match whole string to the prefix of s string
      if (str[j] != s[j])
      {
        flag = 0;
        break;
      }
    }
    if (flag == 1)
      cnt += 1;
  }
  return cnt;
}
int main()
{
  int n;
  cin >> n;
  vector<string> words(n);
  for (int i = 0; i < n; i++)
  {
    cin >> words[i];
  }
  string s;
  cin >> s;
  cout << countPrefixes(words, s) << endl;
  return 0;
}
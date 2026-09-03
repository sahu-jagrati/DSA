// Given a string s and an array of strings words, determine whether s is a prefix string of words.

// A string s is a prefix string of words if s can be made by concatenating the first k strings in words for some positive k no larger than words.length.

// Return true if s is a prefix string of words, or false otherwise.

// Example 1:

// Input: s = "iloveleetcode", words = ["i","love","leetcode","apples"]
// Output: true
// Explanation:
// s can be made by concatenating "i", "love", and "leetcode" together.
// Example 2:

// Input: s = "iloveleetcode", words = ["apples","i","love","leetcode"]
// Output: false
// Explanation:
// It is impossible to make s using a prefix of arr.

// Constraints:

// 1 <= words.length <= 100
// 1 <= words[i].length <= 20
// 1 <= s.length <= 1000
// words[i] and s consist of only lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

// k is not larger than words length but we don't have to check about k because k maximum can be words.size() so wecheck upto there and in mid we get return
// because we done generally concatenate the string of words and check each time it is equal to s if equal return true or not equal traverse whole array and in last return false
//
bool isPrefixString(string s, vector<string> &words)
{
  string temp = "";
  for (int i = 0; i < words.size(); i++)
  {
    temp += words[i];
    if (temp == s)
      return true;
  }
  return false;
}
int main()
{
  string s;
  cin >> s;
  int n;
  cin >> n;
  vector<string> words(n);
  for (int i = 0; i < n; i++)
    cin >> words[i];
  cout << isPrefixString(s, words);
  return 0;
}
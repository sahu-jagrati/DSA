// We define the usage of capitals in a word to be right when one of the following cases holds:

// All letters in this word are capitals, like "USA".
// All letters in this word are not capitals, like "leetcode".
// Only the first letter in this word is capital, like "Google".
// Given a string word, return true if the usage of capitals in it is right.

// Example 1:

// Input: word = "USA"
// Output: true
// Example 2:

// Input: word = "FlaG"
// Output: false

// Constraints:

// 1 <= word.length <= 100
// word consists of lowercase and uppercase English letters.

#include <bits/stdc++.h>
using namespace std;

bool allCapital(string word)
{
  int n = word.size();
  for (int i = 0; i < n; i++)
  {
    char ch = word[i];
    if (ch >= 'a' && ch <= 'z')
      return false;
  }
  return true;
}
bool allNotCapital(string word)
{
  int n = word.size();
  for (int i = 0; i < n; i++)
  {
    char ch = word[i];
    if (ch >= 'A' && ch <= 'Z')
      return false;
  }
  return true;
}
bool firstCapital(string word)
{
  int n = word.size();
  if (word[0] >= 'a' && word[0] <= 'z')
    return false;
  for (int i = 1; i < n; i++)
  {
    char ch = word[i];
    if (ch >= 'A' && ch <= 'Z')
      return false;
  }
  return true;
}

bool detectCapitalUse(string word)
{
  return allCapital(word) || allNotCapital(word) || firstCapital(word);
}

int main()
{
  string word;
  cin >> word;
  cout << detectCapitalUse(word);
  return 0;
}
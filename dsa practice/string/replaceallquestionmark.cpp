// Given a string s containing only lowercase English letters and the '?' character, convert all the '?' characters into lowercase letters such that the final string does not contain any consecutive repeating characters. You cannot modify the non '?' characters.

// It is guaranteed that there are no consecutive repeating characters in the given string except for '?'.

// Return the final string after all the conversions (possibly zero) have been made. If there is more than one solution, return any of them. It can be shown that an answer is always possible with the given constraints.

// Example 1:

// Input: s = "?zs"
// Output: "azs"
// Explanation: There are 25 solutions for this problem. From "azs" to "yzs", all are valid. Only "z" is an invalid modification as the string will consist of consecutive repeating characters in "zzs".
// Example 2:

// Input: s = "ubv?w"
// Output: "ubvaw"
// Explanation: There are 24 solutions for this problem. Only "v" and "w" are invalid modifications as the strings will consist of consecutive repeating characters in "ubvvw" and "ubvww".

// Constraints:

// 1 <= s.length <= 100
// s consist of lowercase English letters and '?'

#include <bits/stdc++.h>
using namespace std;

// generate random character
// Generate a random character.

// Check if it is one of the excluded characters.

// If yes → generate again.
// How it works
// 'a' + rand()%26 → generates a to z
// do-while repeats until the character is not 'a' or 'b'
char randomChar(char ch1, char ch2)
{
  char c;
  do
  {
    c = 'a' + rand() % 26;
  } while (c == ch1 || c == ch2);
  return c;
}

// this is my thinking-
// t.c-O(n)
// s.c-O(1)
string modifyString(string s)
{
  int n = s.size();

  for (int i = 0; i < n; i++)
  {
    if (s[i] == '?')
    {
      if (i == 0)
      {
        s[i] = randomChar('#', s[i + 1]); // avoid next char
      }
      else if (i == n - 1)
      {
        s[i] = randomChar(s[i - 1], '#'); // avoid previous char
      }
      else
      {
        s[i] = randomChar(s[i - 1], s[i + 1]); // avoid both previous and next char
      }
    }
  }
  return s;
}

// without randomness
// better solution-
// t.c-O(n)
// s.c-O(1)
string ModifyString(string s)
{
  int n = s.size();

  // O(n)
  for (int i = 0; i < n; i++)
  {
    if (s[i] == '?')
    {
      // O(26)
      for (char c = 'a'; c <= 'z'; c++)
      {
        if ((i == 0 || s[i - 1] != c) && (i == n - 1 || s[i + 1] != c))
        {
          s[i] = c;
          break;
        }
      }
    }
  }
  return s;
}

// optimal solution-
// Replace ? with the first character from 'a', 'b', 'c' that is not equal to its neighbors.

// Since there are 26 letters, checking only 3 letters is enough.

// Why only 'a' to 'c'?

// At most two neighbors exist, so among 3 letters at least one will always be valid

// t.c-O(n)
// sc.-O(1)
string modifystring(string s)
{
  int n = s.size();
  // O(n)
  for (int i = 0; i < n; i++)
  {
    if (s[i] == '?')
    {
      // O(3) in worst case
      for (char c = 'a'; c <= 'c'; c++)
      {
        if ((i == 0 || s[i - 1] != c) && (i == n - 1 || s[i + 1] != c))
        {
          s[i] = c;
          break;
        }
      }
    }
  }
  return s;
}

int main()
{
  string s;
  cin >> s;
  cout << modifyString(s) << endl;
  cout << modifystring(s) << endl;
  cout << ModifyString(s) << endl;
  return 0;
}
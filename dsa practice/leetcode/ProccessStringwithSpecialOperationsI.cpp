// You are given a string s consisting of lowercase English letters and the special characters: *, #, and %.

// Build a new string result by processing s according to the following rules from left to right:

// If the letter is a lowercase English letter append it to result.
// A '*' removes the last character from result, if it exists.
// A '#' duplicates the current result and appends it to itself.
// A '%' reverses the current result.
// Return the final string result after processing all characters in s.

// Example 1:

// Input: s = "a#b%*"

// Output: "ba"

// Explanation:

// i	s[i]	Operation	Current result
// 0	'a'	Append 'a'	"a"
// 1	'#'	Duplicate result	"aa"
// 2	'b'	Append 'b'	"aab"
// 3	'%'	Reverse result	"baa"
// 4	'*'	Remove the last character	"ba"
// Thus, the final result is "ba".

// Example 2:

// Input: s = "z*#"

// Output: ""

// Explanation:

// i	s[i]	Operation	Current result
// 0	'z'	Append 'z'	"z"
// 1	'*'	Remove the last character	""
// 2	'#'	Duplicate the string	""
// Thus, the final result is "".

// Constraints:

// 1 <= s.length <= 20
// s consists of only lowercase English letters and special characters *, #, and %.

#include <bits/stdc++.h>
using namespace std;

// we solve this problem as the question mention
// t.c-O(n)
// s.c-O(1) because result string is required as mentioned in question
string processStr(string s)
{
  int n = s.size();
  string result = "";
  for (int i = 0; i < n; i++)
  {
    // A '*' removes the last character from result, if it exists.
    if (s[i] == '*')
    {
      // for removeing last char first we check result is not empty
      if (!result.empty())
      {
        result.pop_back();
      }
    }
    // A '#' duplicates the current result and appends it to itself. Means add the current result to itself
    else if (s[i] == '#')
    {
      result += result;
    }
    // A '%' reverses the current result.
    else if (s[i] == '%')
    {
      reverse(result.begin(), result.end());
    }
    // If the letter is a lowercase English letter append it to result.
    else
    {
      result += s[i];
    }
  }
  return result;
}
// Constraints:

// 1 <= s.length <= 20
// s consists of only lowercase English letters and special characters *, #, and %.
int main()
{
  string s;
  cin >> s;
  cout << processStr(s);
  return 0;
}
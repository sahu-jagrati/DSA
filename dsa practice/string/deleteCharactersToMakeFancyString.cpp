// A fancy string is a string where no three consecutive characters are equal.

// Given a string s, delete the minimum possible number of characters from s to make it fancy.

// Return the final string after the deletion. It can be shown that the answer will always be unique.

// Example 1:

// Input: s = "leeetcode"
// Output: "leetcode"
// Explanation:
// Remove an 'e' from the first group of 'e's to create "leetcode".
// No three consecutive characters are equal, so return "leetcode".
// Example 2:

// Input: s = "aaabaaaa"
// Output: "aabaa"
// Explanation:
// Remove an 'a' from the first group of 'a's to create "aabaaaa".
// Remove two 'a's from the second group of 'a's to create "aabaa".
// No three consecutive characters are equal, so return "aabaa".
// Example 3:

// Input: s = "aab"
// Output: "aab"
// Explanation: No three consecutive characters are equal, so return "aab".

// Constraints:

// 1 <= s.length <= 10^5
// s consists only of lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

// but this throw an error of- out of range
// string makeFancyString(string s)
// {
//   int n = s.size();
//   // If we're looping forward and erase a character:
//   // Problem: after erase, next character shifts into index i, but loop does i++, so you skip a character
//   for (int i = 1; i < n - 1; i++)
//   {
//     if (s[i] == s[i - 1] && s[i] == s[i + 1])
//     {
//       s.erase(i, 1);
//       // move back to recheck shifted character
//       i--;
//       // After erase, new character comes at index i
//       // i-- ensures we don’t skip it
//     }
//   }
//   return s;
// }

// When we do:

// s.erase(i, 1);
// Character at index i is removed
// All elements after i shift one step left
// String size decreases by 1

// better we traverse from back
// no need for i-- trick
string makeFancyString(string s)
{
  int n = s.size();
  for (int i = n - 2; i >= 1; i--)
  {
    if (s[i] == s[i - 1] && s[i] == s[i + 1])
      s.erase(i, 1);
  }
  return s;
}
int main()
{
  string s;
  cin >> s;
  cout << makeFancyString(s);
  return 0;
}
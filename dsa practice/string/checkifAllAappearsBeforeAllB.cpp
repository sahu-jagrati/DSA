// Given a string s consisting of only the characters 'a' and 'b', return true if every 'a' appears before every 'b' in the string. Otherwise, return false.

// Example 1:

// Input: s = "aaabbb"
// Output: true
// Explanation:
// The 'a's are at indices 0, 1, and 2, while the 'b's are at indices 3, 4, and 5.
// Hence, every 'a' appears before every 'b' and we return true.
// Example 2:

// Input: s = "abab"
// Output: false
// Explanation:
// There is an 'a' at index 2 and a 'b' at index 1.
// Hence, not every 'a' appears before every 'b' and we return false.
// Example 3:

// Input: s = "bbb"
// Output: true
// Explanation:
// There are no 'a's, hence, every 'a' appears before every 'b' and we return true.

// Constraints:

// 1 <= s.length <= 100
// s[i] is either 'a' or 'b'.

// Hint 1
// You can check the opposite: check if there is a ‘b’ before an ‘a’. Then, negate and return that answer.
// Hint 2
// s should not have any occurrences of “ba” as a substring.

// i solve this problem using hint 2

#include <bits/stdc++.h>
using namespace std;

bool checkString(string s)
{
  if (s.find("ba") != string::npos)
    return false;
  return true;
}

// hint 1solu-
bool check(string s)
{
  for (int i = 1; i < s.size(); i++)
  {
    if (s[i - 1] == 'b' && s[i] == 'a')
      return false;
  }
  return true;
}
int main()
{
  string s;
  cin >> s;
  cout << checkString(s) << endl;
  cout << check(s);
  return 0;
}
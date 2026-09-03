// Given a string of English letters s, return the greatest English letter which occurs as both a lowercase and uppercase letter in s. The returned letter should be in uppercase. If no such letter exists, return an empty string.

// An English letter b is greater than another letter a if b appears after a in the English alphabet.

// Example 1:

// Input: s = "lEeTcOdE"
// Output: "E"
// Explanation:
// The letter 'E' is the only letter to appear in both lower and upper case.
// Example 2:

// Input: s = "arRAzFif"
// Output: "R"
// Explanation:
// The letter 'R' is the greatest letter to appear in both lower and upper case.
// Note that 'A' and 'F' also appear in both lower and upper case, but 'R' is greater than 'F' or 'A'.
// Example 3:

// Input: s = "AbCdEfGhIjK"
// Output: ""
// Explanation:
// There is no letter that appears in both lower and upper case.

// Constraints:

// 1 <= s.length <= 1000
// s consists of lowercase and uppercase English letters.

#include <bits/stdc++.h>
using namespace std;

string greatestLetter(string s)
{
  int n = s.size();
  vector<int> lowerCase(26, 0);
  vector<int> upperCase(26, 0);
  for (int i = 0; i < n; i++)
  {
    char ch = s[i];
    if (ch >= 'a' && ch <= 'z')
      lowerCase[ch - 'a'] += 1;
    else
      upperCase[ch - 'A'] += 1;
  }
  string answer = "";
  int max = 0; // use to get greater letter
  for (int i = 0; i < n; i++)
  {
    char ch = s[i];
    if (ch >= 'a' && ch <= 'z')
    {
      char upper = toupper(ch);
      if (upperCase[upper - 'A'] >= 1 && max <= (upper - 'A'))
      {
        max = upper - 'A';
        answer = upper;
      }
    }
    else
    {
      char lower = tolower(ch);
      if (lowerCase[lower - 'a'] >= 1 && max <= (ch - 'A'))
      {
        max = ch - 'A';
        answer = ch;
      }
    }
  }
  return answer;
}

int main()
{
  string s;
  cin >> s;

  string answer = greatestLetter(s);

  cout << answer << endl;
  return 0;
}
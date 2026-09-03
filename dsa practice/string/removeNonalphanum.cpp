// s=He@llo Wo!rld#123
// return s after removing all non-alphnumeric characters. Alphanumeric characters include letters and numbers.

// 1 <= s.length <= 2 * 10^5
// s consists only of printable ASCII characters.
#include <bits/stdc++.h>
using namespace std;

// s is a sentence
string removeNotAlphNum(string s)
{
  for (int i = 0; i < s.size();)
  {
    if (!isalnum(s[i]))
    {
      // s.erase(s[i]); // erase does not take character, it takes an index or an iterator
      s.erase(i, 1); // erase 1 character at index i
    }
    else
    {
      i++; // move forward only if not erased
    }
  }
  return s;
}

string removeNonAlpha(string phrase)
{
  string result;
  for (char ch : phrase)
  {
    if (isalnum(ch))
      result += ch;
  }
  return result;
}
int main()
{
  string phrase;
  getline(cin, phrase);
  // string answer = removeNotAlphNum(phrase);
  string answer = removeNonAlpha(phrase);
  cout << answer << endl;
  return 0;
}
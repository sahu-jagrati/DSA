// Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.

// Example 1:
// Input: s = "Hello"
// Output: "hello"

// Example 2:
// Input: s = "here"
// Output: "here"

// Example 3:
// Input: s = "LOVELY"
// Output: "lovely"

// Constraints:

// 1 <= s.length <= 100
// s consists of printable ASCII characters.

#include <bits/stdc++.h>
using namespace std;

// t.c-O(n)
// s.c-O(n) for result string
string toLowerCase(string s)
{
  int n = s.size();
  string result; // if we don't initialize it with size then it repeating string resizing every time when we add ch in it so we optimize it in next code

  for (int i = 0; i < n; i++)
  {
    char ch = s[i];
    if (ch >= 'A' && ch <= 'Z')
    {
      ch = ch + 32;
      result += ch;
    }
    else
    {
      result += ch;
    }
  }
  return result;
}

// we slightly optimize our version by initialize result with same size of s so
// No repeated string resizing
// More efficient
// Same logic, cleaner implementation

string tolowercase(string s)
{
  int n = s.size();
  string result = s; // initialize with same size
  for (int i = 0; i < n; i++)
  {
    if (result[i] >= 'A' && result[i] <= 'Z')
      result[i] = result[i] + 32;
  }
  return result;
}

// if in interview say change in s no extra string return then
string toLowercase(string s)
{
  for (char &ch : s)
  {
    if (ch >= 'A' && ch <= 'Z')
      ch = ch + 32;
  }
  return s;
}

// using STL
string tolowerCase(string s)
{
  // transform(s.begin(), s.end(), s.begin(), ::tolower);
  transform(s.begin(), s.end(), s.begin(),
            [](unsigned char c)
            { return tolower(c); });
  return s;
}
int main()
{
  string s;
  cin >> s;

  // string answer = toLowerCase(s);
  // string answer = tolowerCase(s);
  // string answer = tolowercase(s);
  string answer = toLowercase(s);
  cout << answer << endl;

  return 0;
}
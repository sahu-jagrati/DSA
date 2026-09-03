// Substring
// A substring is a contiguous non-empty sequence of characters within a string

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// generate all possible substring
// time complexity -
// outer loop runs n times
// inner loop in worst case runs n-i times
// inside inner loop-s1.find() itself takes O(s1.size()) time which is in worst case=O(n)
// total time complexity-O(n^3)

// space complexity-O(n) in worst case if in s there are all unique charater
int longestSubstringWithoutRepeatingCharacters(string &s)
{
  int n = s.size();
  int length = 0;

  for (int i = 0; i < n; i++)
  {
    string s1;
    for (int j = i; j < n; j++)
    {
      if (s1.find(s[j]) != string::npos)
      {        // string::npos is a special constant in C++ that represents “not found” when you use string search functions like .find()
        break; // repeating character found
      }
      s1.push_back(s[j]);
      length = max(length, (int)s1.size());
    }
  }
  return length;
}

// optimal - sliding window
// time complexity-O(n)
// space complexity-O(1)(constant for ascii characters)
int longestSubstring(string &s)
{
  vector<int> lastIndex(256, -1); // 256 are ascii characters // store last index of each char
  int maxLen = 0, start = 0;
  int n = s.size();
  for (int i = 0; i < n; i++)
  {
    if (lastIndex[s[i]] >= start)
      start = lastIndex[s[i]] + 1; // move start to avoid duplicate
    lastIndex[s[i]] = i;
    maxLen = max(maxLen, i - start + 1);
  }
  return maxLen;
}
int main()
{
  int n; // string length
  cin >> n;
  string s;
  s.resize(n); // string now has length n, filled with '\0' (null chars), but the characters are null('\0')
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
  }
  cout << s << endl;
  // int result = longestSubstringWithoutRepeatingCharacters(s);
  int result = longestSubstring(s);
  cout << result << endl;
  return 0;
}
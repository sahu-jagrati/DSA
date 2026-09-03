// Given a binary string s ​​​​​without leading zeros, return true​​​ if s contains at most one contiguous segment of ones. Otherwise, return false.

// Example 1:

// Input: s = "1001"
// Output: false
// Explanation: The ones do not form a contiguous segment.
// Example 2:

// Input: s = "110"
// Output: true

// Constraints:

// 1 <= s.length <= 100
// s[i]​​​​ is either '0' or '1'.
// s[0] is '1'.

#include <bits/stdc++.h>
using namespace std;

// done by me fully
bool checkOnesSegment(string s)
{
  int n = s.size();
  int r = 0;
  while (r < n)
  {
    if (s[r] == '0')
    {
      for (int i = r; i < n; i++)
      {
        if (s[i] == '1')
          return false;
      }
    }
    r++;
  }
  return true;
}

int main()
{
  string s;
  cin >> s; // enter binary string

  cout << checkOnesSegment(s) << endl;
  return 0;
}
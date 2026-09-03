// Given a binary string s, return true if the longest contiguous segment of 1's is strictly longer than the longest contiguous segment of 0's in s, or return false otherwise.

// For example, in s = "110100010" the longest continuous segment of 1s has length 2, and the longest continuous segment of 0s has length 3.
// Note that if there are no 0's, then the longest continuous segment of 0's is considered to have a length 0. The same applies if there is no 1's.

// Example 1:

// Input: s = "1101"
// Output: true
// Explanation:
// The longest contiguous segment of 1s has length 2: "1101"
// The longest contiguous segment of 0s has length 1: "1101"
// The segment of 1s is longer, so return true.
// Example 2:

// Input: s = "111000"
// Output: false
// Explanation:
// The longest contiguous segment of 1s has length 3: "111000"
// The longest contiguous segment of 0s has length 3: "111000"
// The segment of 1s is not longer, so return false.
// Example 3:

// Input: s = "110100010"
// Output: false
// Explanation:
// The longest contiguous segment of 1s has length 2: "110100010"
// The longest contiguous segment of 0s has length 3: "110100010"
// The segment of 1s is not longer, so return false.

// Constraints:

// 1 <= s.length <= 100
// s[i] is either '0' or '1'.

#include <bits/stdc++.h>
using namespace std;

int contiguousSegment(string s, char ch)
{
  int n = s.size();
  int l = 0, r = 0;
  int maxLen = 0;
  while (r < n)
  {
    if (s[r] != ch)
    {
      l = r + 1;
    }
    else
    {
      maxLen = max(maxLen, r - l + 1);
    }
    r++;
  }
  return maxLen;
}

// done by me fully
bool checkZeroOnes(string s)
{
  int cnt0 = contiguousSegment(s, '0');
  int cnt1 = contiguousSegment(s, '1');
  if (cnt1 > cnt0)
    return true;
  return false;
}

int main()
{
  string s;
  cin >> s; // enter binary string

  cout << checkZeroOnes(s) << endl;
  return 0;
}
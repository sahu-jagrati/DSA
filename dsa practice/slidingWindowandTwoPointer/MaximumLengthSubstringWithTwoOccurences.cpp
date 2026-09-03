// Given a string s, return the maximum length of a substring such that it contains at most two occurrences of each character.

// Example 1:

// Input: s = "bcbbbcba"

// Output: 4

// Explanation:

// The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".
// Example 2:

// Input: s = "aaaa"

// Output: 2

// Explanation:

// The following substring has a length of 2 and contains at most two occurrences of each character: "aaaa".

// Constraints:

// 2 <= s.length <= 100
// s consists only of lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

// here we use sliding window for getting substring and for occurences we use unordered map because in average it take O(1)

// t.c-O(n)(for outer while loop because we travel each char at once in a string)+O(n)(for inner while loop because throughout the whole process I removed n char not each time) so total t.c=O(2n), not O(n^2)
// s.c-O(n)(in worst case for mpp)
int maximumLengthSubstring(string s)
{
  int n = s.size();
  int l = 0, r = 0;
  int maxLength = 0;
  unordered_map<char, int> mpp;
  while (r < n)
  {
    // first we push the char in mpp with increase the frequency
    mpp[s[r]]++;
    // now we check that if mpp[s[r]]>2 then we decrease it frequency until it is is <=2 because we want substring that have atmost two occurences of each char so we move l i.e shrink the substring
    while (mpp[s[r]] > 2)
    {
      mpp[s[l]]--;
      l++;
    }
    // for maxlength
    // when we have each char frequency atmost 2
    if (mpp[s[r]] <= 2)
      maxLength = max(maxLength, r - l + 1);
    // expand the substring
    r++;
  }
  return maxLength;
}

int main()
{
  string s;
  cin >> s;
  cout << maximumLengthSubstring(s);
  return 0;
}
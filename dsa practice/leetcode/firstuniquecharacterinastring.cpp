// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

// Example 1:
// Input: s = "leetcode"
// Output: 0
// Explanation:

// The character 'l' at index 0 is the first character that does not occur at any other index.

// Example 2:
// Input: s = "loveleetcode"
// Output: 2

// Example 3:
// Input: s = "aabb"
// Output: -1

// Constraints:

// 1 <= s.length <= 10^5
// s consists of only lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

// t.c-O(2*n) in worst case when in second for loop we don't get first non-repeating char so we have to travel whole string so
// s.c-O(26) for char array

// i write this code by my own
int firstUniqChar(string s)
{
  int n = s.size();
  vector<int> charArray(26, 0);
  for (int i = 0; i < n; i++)
  {
    charArray[s[i] - 'a']++;
  }
  for (int i = 0; i < n; i++)
  {
    if (charArray[s[i] - 'a'] == 1)
      return i;
  }
  return -1;
}

int main()
{
  string s;
  cin >> s;
  int answer = firstUniqChar(s);
  cout << answer << endl;
  return 0;
}
// You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.

// The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.

// Return the minimum number of operations needed to make s alternating.

// Example 1:

// Input: s = "0100"
// Output: 1
// Explanation: If you change the last character to '1', s will be "0101", which is alternating.
// Example 2:

// Input: s = "10"
// Output: 0
// Explanation: s is already alternating.
// Example 3:

// Input: s = "1111"
// Output: 2
// Explanation: You need two operations to reach "0101" or "1010".

// Constraints:

// 1 <= s.length <= 104
// s[i] is either '0' or '1'.

#include <bits/stdc++.h>
using namespace std;

// solution is - there is only two possibility that string can be of
// 01010101... or
// 10101010...
// we make both possibility of string and count number of operations to make both
// and answer is min of both

// t.c-O(n)
// s.c-O(1)
int minOperations(string s)
{
  int n = s.size();
  int cnt1 = 0, cnt2 = 0; // count number of operations to make alternate binary string
  for (int i = 0; i < n; i++)
  {
    // for pattern- 010101...
    if (s[i] != (i % 2 == 0 ? '0' : '1'))
      cnt1++;
    // for pattern- 101010...
    if (s[i] != (i % 2 == 0 ? '1' : '0'))
      cnt2++;
  }
  return min(cnt1, cnt2);
}

int main()
{
  string s; // enter binary string
  cin >> s;
  cout << "Min operations to make alternate binary string: " << minOperations(s) << endl;
  return 0;
}
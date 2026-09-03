// given a string we have to find longest substring length that have no repeating charater
// substring-consecutive portion of a string
// can be single caharacter also or can be entire string also or can be a consecutive portion of a string
// string can contain any character from 256

#include <bits/stdc++.h>
using namespace std;

// naive solution- generate all substring and check there is not repeating character
// we use hashmap array for not repeating of 256 size for all caharcter

// t.c-O(N*N)=O(N^2) where N is size of string
// s.c-O(256) for hasharray of every character

int longest(string &s)
{
  int n = s.size();
  int maxlen = 0;
  for (int i = 0; i < n; i++)
  {
    // for each substring we redefine hasharray so
    vector<int> hasharray(256, 0); // 0 denote not visit
    for (int j = i; j < n; j++)
    {
      if (hasharray[s[j]] == 1)
        break; // means already in substring so break and here s[j] automatically convert in integer to their ascii value

      // else when hasharray[s[j]]==0
      int len = j - i + 1;
      maxlen = max(maxlen, len);
      hasharray[s[j]] = 1; // mark when visit
    }
  }
  return maxlen;
}

// optimize solution-
//  we want longest substring so we used two pointer/sliding window approach
//  we use hashmap to  store character with their updating index if they repeat
//  we can use hashmap but it take logarithmic time to insert and for finding so we used hasharray with initially -1 marking to all 256 char

// t.c-
//  only r is moving continously, l not contributing in while loop
//  so, t.c-O(n) where n is size of string hence we use hasharray so no logarithmic time include
// s.c-O(256) hasharray of every character
int longestSubstring(string &s)
{
  int n = s.size();
  // l → left pointer of the sliding window
  // r → right pointer of the sliding window
  // The window is s[l ... r]
  int l = 0, r = 0; // two pointers
  int maxlen = 0;
  // we use hasharray instead of hashmap to avoid logarithmic time of insertion and finding
  // Size 256 → covers all ASCII characters.
  //  hasharray[ch] stores the last index where character ch appeared.
  //  Initially -1 → character has not appeared yet
  //  Example:
  //  hasharray['a'] = 3  → 'a' last appeared at index 3
  //  hasharray['b'] = -1 → 'b' not seen yet
  vector<int> hasharray(256, -1); // we store index of the character in the hasharray

  while (r < n)
  {

    //  here s[r] automatically convert in integer to their ascii value
    // If not -1, it means s[r] already appeared before
    if (hasharray[s[r]] != -1)
    {
      // This checks whether the duplicate character lies inside the current window.
      // If it’s before l, it doesn’t affect the current substring
      if (hasharray[s[r]] >= l)
      {
        // Move l just after the previous occurrence of s[r].
        // This removes the duplicate and keeps the substring unique
        // Example:
        //  s = "abcabcbb"
        //             r
        //  window = "abc"
        //  duplicate 'a' found at index 0
        //  l moves from 0 → 1
        l = hasharray[s[r]] + 1;
      }
    }
    // Length of current substring without repetition
    int len = r - l + 1;
    maxlen = max(maxlen, len);
    // Store the current index of character s[r]
    hasharray[s[r]] = r;
    // Expand the window
    r = r + 1;
  }
  return maxlen;
}
int main()
{
  string s;
  cout << "Enter the string: ";
  cin >> s;
  // int result = longest(s);
  int result = longestSubstring(s);
  cout << "Longest Substring without repeating character: " << result << endl;
  return 0;
}

// Example -by optimize solution
// Input:
// s = "abcabcbb"

// r	char	l	window	maxlen
// 0	a	0	a	1
// 1	b	0	ab	2
// 2	c	0	abc	3
// 3	a	1	bca	3
// 4	b	2	cab	3
// 5	c	3	abc	3

// Output: 3
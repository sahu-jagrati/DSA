// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.

// Constraints:

// m == s.length
// n == t.length
// 1 <= m, n <= 10^5

// s and t consist of uppercase and lowercase English letters

//  we want minimum window substring of s that have all character of t including duplicates, also if in minimum window of s we have extra character that it is fine

// example- s=ddaaabbcca, t=abc
// minimum window is bca having all occurences of all char of t
// aabbc also has all occurence of t but we want minimum so bca is answer

// if t=abbc
// then bca is not answer because it does not have b twice, in that case minimum window is abbc

// example- s=adobecodebanc, t=abc
// then minimum window is banc here n is extra but it's okay because after that we have no minimum window

#include <bits/stdc++.h>
using namespace std;

// naive solution- generate all substring of s
// we can also use map but it take logarithmic time so
// in this we use hasharray which initially store frequency of all char of t which is positive
// when we traverse string s and the char is not having positive frequency means it is not in so we insert it with starting frequency -1 and we reduce frequency each time when wee traverse s because we want duplicate of t also in minimum substring so

string minimumWindow(string s, string t)
{
  int n = s.size();
  int m = t.size();
  int minlen = INT_MAX;
  int sIndex = -1; // starting index to get substring in last

  for (int i = 0; i < n; i++)
  {
    // we declare hasharray, we can also use map but it take logarithmic time so
    vector<int> hasharray(256, 0); // initially all have 0  frequency, we store<char,freq>

    int cnt = 0;
    // initially put all char of t in hasharray
    for (int j = 0; j < m; j++)
    {
      hasharray[t[j]]++; // t[j] automatically convert to integer
    }
    for (int j = i; j < n; j++)
    {
      if (hasharray[s[j]] > 0) // +ve means already in hasharray  means it is in string t, so cnt++ so we take it and reduce it frequency now
        cnt = cnt + 1;
      hasharray[s[j]]--;
      // when cnt = tsize means substring has all char of t now
      if (cnt == m)
      {
        if ((j - i + 1) < minlen)
        {
          minlen = j - i + 1;
          sIndex = i;
          break;
        }
      }
    }
  }
  return sIndex == -1 ? "" : s.substr(sIndex, minlen);
}

// optimal solution- we want substring and minimum so we use two pointers/sliding window
// we can also use map but it take logarithmic time so
// in this we use hasharray which initially store frequency of all char of t which is positive
// when we traverse string s and the char is not having positive frequency means it is not in so we insert it with starting frequency -1 and we reduce frequency each time when we traverse s because we want duplicate of t also in minimum substring so
// we reduce frequency every time when we expand the window and we increase the frequency when we shrink the window because when we shrink we remove that char from the substring so we have that char in mpp return back so we increase frequency

// t.c-O(n(outer while looop)+n(inner while loop))+O(m)(for for loop =O(n+m) where n is size of string s and m is size of string t
// s.c-O(256) for hasharray

string minimumWindowSubstring(string s, string t)
{
  int n = s.size();
  int m = t.size();
  int l = 0, r = 0, cnt = 0, sIndex = -1; // sIndex is starting index
  int minlen = INT_MAX;
  vector<int> hasharray(256, 0); // store <char,freq>

  // initially put all char of t in hasharray
  // run m times
  for (int i = 0; i < m; i++)
  {
    hasharray[t[i]]++;
  }

  // run n times
  while (r < n)
  {
    // first we check if hasharray[s[r]]>0 means it is already in hasharray means it is in string t also so cnt++
    if (hasharray[s[r]] > 0)
      cnt++;
    // decrease frequency when we expand the window which means we cnt that char because we want duplicates char also in minimum window substring if string t has duplicates
    hasharray[s[r]]--;

    // this while loop not run n length every time, in worst case it is run n length at a single time throughout the whole journey
    // when cnt = tsize means substring has all char of t now and we want minimum substring so we do shrinking now
    while (cnt == m)
    {
      if ((r - l + 1) < minlen)
      {
        minlen = r - l + 1;
        sIndex = l;
      }
      hasharray[s[l]]++; // increase frequency when we shrink the window which means return back the char
      if (hasharray[s[l]] > 0)
        cnt = cnt - 1; // meanse when +ve it means it is in string t so
      l++;
    }
    r++;
  }
  return sIndex == -1 ? "" : s.substr(sIndex, minlen);
}

int main()
{
  string s, t;
  cout << "ENter both the strings: ";
  cin >> s >> t;

  // string answer = minimumWindow(s, t);
  string answer = minimumWindowSubstring(s, t);
  cout << "Minimum window subtring: " << answer << endl;
  return 0;
}
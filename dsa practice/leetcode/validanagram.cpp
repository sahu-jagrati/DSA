// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true

// Example 2:
// Input: s = "rat", t = "car"
// Output: false

// Constraints:
// 1 <= s.length, t.length <= 5 * 10^4
// s and t consist of lowercase English letter

#include <bits/stdc++.h>
using namespace std;

// solution-1 my thinking somewhat
// t.c-O(nlogn)+O(mlogm) where n and m sre size of string s and t
// s.c-O(1)
bool isAnagram(string s, string t)
{
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  if (s == t)
    return true;
  return false;
}

bool isanagram(string s, string t)
{
  if (s.size() != t.size())
    return false;
  unordered_map<char, int> mpp_s; // store <char,frequency>
  unordered_map<char, int> mpp_t;

  for (char ch : s)
  {
    mpp_s[ch]++;
  }
  for (char ch : t)
  {
    mpp_t[ch]++;
  }
  for (auto it : mpp_s)
  {
    if (mpp_t[it.first] != it.second)
      return false;
  }
  return true;
}

// we can convert two map in map because if both strings have same elt with same frequency then we

// Time: O(n log n) - log n if we use ordered map
// time-O(n*1)-if use unordered map in average case or in worst case O(n*n)

// Space: O(1) (only 26 letters if lowercase)
bool anagram(string s, string t)
{
  if (s.size() != t.size())
    return false;
  unordered_map<char, int> mpp; // store<char,frequency>
  for (char ch : s)
    mpp[ch]++;
  for (char ch : t)
    mpp[ch]--;
  for (auto it : mpp)
  {
    if (it.second != 0) // means if equal to 0 means no. of ch push by s is same with t so it decrease all and become equal to 0 and if not equal to 0 means the char ch have different frequency in both string
      return false;
  }
  return true;
}

// t.c-O(n)
// s.c-O(26) constant
bool AnagramIs(string s, string t)
{
  if (s.size() != t.size())
    return false;

  vector<int> charArray(26, 0); // we have only lowercase letters
  for (char ch : s)
    charArray[ch - 'a']++;
  for (char ch : t)
    charArray[ch - 'a']--;
  for (int i = 0; i < 26; i++)
  {
    if (charArray[i] != 0)
      return false;
  }
  return true;
}
int main()
{
  string s, t;
  cin >> s >> t;
  // bool answer = isAnagram(s, t);
  // bool answer = isanagram(s, t);
  // bool answer = anagram(s, t);
  bool answer = AnagramIs(s, t);
  cout << answer << endl;
  return 0;
}

// for (int i = 0; i < mpp_s.size(); i++)
// ❌ map is not index-based like a vector
// mpp_s[i] does NOT mean the i-th element

// If you used ASCII (256 size), make sure you did this:
// freq[(unsigned char)c]

// Not just:
// freq[c]   // ❌ risky if char is signed
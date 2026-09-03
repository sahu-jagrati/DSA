// Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

// Each letter in magazine can only be used once in ransomNote.
 

// Example 1:

// Input: ransomNote = "a", magazine = "b"
// Output: false
// Example 2:

// Input: ransomNote = "aa", magazine = "ab"
// Output: false
// Example 3:

// Input: ransomNote = "aa", magazine = "aab"
// Output: true
 

// Constraints:

// 1 <= ransomNote.length, magazine.length <= 10^5
// ransomNote and magazine consist of lowercase English letters

#include <bits/stdc++.h>
using namespace std;

bool isRansomNote(string ransomNote, string magazine)
{
  int n = ransomNote.size();
  int m = magazine.size();

  vector<int> charArray(26, 0);
  for (int i = 0; i < n; i++)
  {
    char ch = ransomNote[i];
    charArray[ch - 'a']++;
  }
  for (int i = 0; i < m; i++)
  {
    char ch = magazine[i];
    if (charArray[ch - 'a'] != 0)
      charArray[ch - 'a']--;
  }
  for (int i = 0; i < n; i++)
  {
    char ch = ransomNote[i];
    if (charArray[ch - 'a'] != 0)
      return false;
  }
  return true;
}

int main()
{
  string ransomNote, magazine;
  cin >> ransomNote >> magazine;

  cout << isRansomNote(ransomNote, magazine) << endl;
  return 0;
}
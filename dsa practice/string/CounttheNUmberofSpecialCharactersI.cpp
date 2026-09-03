// You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.

// Return the number of special letters in word.

// Example 1:

// Input: word = "aaAbcBC"

// Output: 3

// Explanation:

// The special characters in word are 'a', 'b', and 'c'.

// Example 2:

// Input: word = "abc"

// Output: 0

// Explanation:

// No character in word appears in uppercase.

// Example 3:

// Input: word = "abBCab"

// Output: 1

// Explanation:

// The only special character in word is 'b'.

// Constraints:

// 1 <= word.length <= 50
// word consists of only lowercase and uppercase English letters.

#include <bits/stdc++.h>
using namespace std;

// t.c-O(n)+O(26)
// s.c-O(26)+O(26)=O(1)
int numberOfSpecialChars(string word)
{
  vector<int> lowerCase(26, 0);
  vector<int> upperCase(26, 0);
  for (int i = 0; i < word.size(); i++)
  {
    char ch = word[i];
    if (ch >= 'a' && ch <= 'z')
      lowerCase[ch - 'a'] = 1;
    else
      upperCase[ch - 'A'] = 1;
  }
  int ans = 0;
  for (int i = 0; i < 26; i++)
  {
    if (lowerCase[i] == 1 && upperCase[i] == 1)
      ans += 1;
  }
  return ans;
}
int main()
{
  string word;
  cin >> word;
  cout << numberOfSpecialChars(word);
  return 0;
}
// You are given a palindromic string s.

// Return the lexicographically smallest palindromic permutation of s.

// Example 1:

// Input: s = "z"

// Output: "z"

// Explanation:

// A string of only one character is already the lexicographically smallest palindrome.

// Example 2:

// Input: s = "babab"

// Output: "abbba"

// Explanation:

// Rearranging "babab" → "abbba" gives the smallest lexicographic palindrome.

// Example 3:

// Input: s = "daccad"

// Output: "acddca"

// Explanation:

// Rearranging "daccad" → "acddca" gives the smallest lexicographic palindrome.

// Constraints:

// 1 <= s.length <= 105
// s consists of lowercase English letters.
// s is guaranteed to be palindromic.

#include <bits/stdc++.h>
using namespace std;

// I solved this problem using Hint from discussion
// Hint 1
// Consider a palindrome as composed of two mirror-image halves.
// Hint 2
// Construct one half (using s), and then the other half is its reverse to obtain the lexicographically smallest permutation.

// Hint:

// Build frequency map sMap
// Sort entries alphabetically
// For each character — add floor(count/2) copies to res
// If count is odd — that character goes to middle
// Return res + middle + reverse(res)

// I use this hint to solve the problem but initially I get that I have to store frequency of character so that if there is odd frequency then the char goes to middle with one count because of palindrome

// t.c-O(n)(for freq array compute)+O(26)(for res and middle string compute)
// s.c-O(26)for freq array
string smallestPalindrome(string s)
{
  int n = s.size();
  // as there is only lowercase letters so I used array of size 26 so there is no need to sort it separately if we take map data structure then we need to sort entries alphabetically separately
  vector<int> freq(26, 0);
  for (int i = 0; i < n; i++)
  {
    char ch = s[i];
    freq[ch - 'a']++;
  }
  // two strings define i) res ii) middle and in last we add the reverse of res in end of ans string to get palindrome
  string res, middle; // in middle string I store those char with 1 count whose freq is odd so they appear 1 time in middle
  // as we use freq array so need of sorting it separately we check it manually
  for (int i = 0; i < 26; i++)
  {
    if (freq[i] != 0 && freq[i] % 2 == 0)
    {
      int half = freq[i] / 2;
      char ch = 'a' + i;
      res.append(half, ch); // append ch half times
    }
    else if (freq[i] != 0 && freq[i] % 2 != 0)
    {
      char ch = 'a' + i;
      // then 1 times char add in middle
      middle += ch;
      // decrease freq by 1
      freq[i] -= 1;
      // now freq is even
      int half = freq[i] / 2;
      res.append(half, ch);
    }
  }
  string ans; // ans=res+middle+reverse(res)  because we want palindromice string
  ans += res;
  ans += middle;
  reverse(res.begin(), res.end());
  ans += res;
  return ans;
}

int main()
{
  string s; // s is palindromic string
  cin >> s;
  cout << smallestPalindrome(s);
  return 0;
}
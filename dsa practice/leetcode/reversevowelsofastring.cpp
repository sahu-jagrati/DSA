// If you only want to store vowels, it depends on what you’re doing with them. Here are the clean, common options 👇

// ✅ Best & simplest: set

// If your goal is checking whether a character is a vowel:

// set<char> vowels = {'a','e','i','o','u',
//                     'A','E','I','O','U'};

// Usage:

// if (vowels.count(ch)) {
//     // ch is a vowel
// }

// ✔ Fast lookups
// ✔ No duplicates
// ✔ Very readable

// ⚡ Fastest for competitive coding: boolean array

// If you want maximum speed:

// bool isVowel[256] = {false};

// isVowel['a'] = isVowel['e'] = isVowel['i'] = isVowel['o'] = isVowel['u'] = true;
// isVowel['A'] = isVowel['E'] = isVowel['I'] = isVowel['O'] = isVowel['U'] = true;

// Usage:

// if (isVowel[ch]) {
//     // vowel
// }

// ⚡ O(1) lookup

// If you just want to store extracted vowels

// Use a vector or string:

// string vowelsOnly;

// if (isVowel[ch]) {
//     vowelsOnly.push_back(ch);
// }

// ❌ What NOT to use

// map<char,int> → overkill

// unordered_map → unnecessary for just 10 chars

// Given a string s, reverse only all the vowels in the string and return it.

// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

// Example 1:
// Input: s = "IceCreAm"
// Output: "AceCreIm"
// Explanation:
// The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

// Example 2:
// Input: s = "leetcode"
// Output: "leotcede"

// Constraints:

// 1 <= s.length <= 3 * 10^5
// s consist of printable ASCII characters.

#include <bits/stdc++.h>
using namespace std;

// we want to reverse only vowels of string so we use two pointer approach

// i write this code by own no help of anyone
string reverseVowels(string s)
{
  int n = s.size();
  int l = 0, r = n - 1;
  set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
  while (l < r)
  {
    // when both are vowels so,swap them and move both pointers l and r to next
    if (vowels.count(s[l]) && vowels.count(s[r]))
    {
      char temp = s[l];
      s[l] = s[r];
      s[r] = temp;
      l++;
      r--;
    }
    // if s[l] is not vowel but s[r] can be vowel so we move only l pointer
    else if (!vowels.count(s[l]))
      l++;
    // if s[r] is not vowel but s[l] can be vowel so we move only r pointer
    else if (!vowels.count(s[r]))
      r--;
    // when both s[l] and s[r] are not vowels so move both pointers
    else
    {
      l++;
      r--;
    }
  }
  return s;
}

int main()
{
  // for taking input string see question above
  string s;
  cin >> s;
  string answer = reverseVowels(s);
  cout << "After reversing vowels: " << answer << endl;
  return 0;
}
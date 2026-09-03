// Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

// You can use each character in text at most once. Return the maximum number of instances that can be formed.

// Example 1:

// Input: text = "nlaebolko"
// Output: 1
// Example 2:

// Input: text = "loonbalxballpoon"
// Output: 2
// Example 3:

// Input: text = "leetcode"
// Output: 0

// Constraints:

// 1 <= text.length <= 104
// text consists of lower case English letters only.

#include <bits/stdc++.h>
using namespace std;

// wrong
// int maxNumberOfBalloons(string text)
// {
//   int n = text.size();
//   unordered_map<char, int> mpp;
//   for (int i = 0; i < n; i++)
//   {
//     mpp[text[i]]++;
//   }
//   string word = "balloon";

//   int minimum = INT_MAX;
//   for (int i = 0; i < word.size(); i++)
//   {
//     if (!mpp.count(word[i]))
//       return 0;
//     if (word[i] == 'l' && mpp['l'] < 2)
//       return 0;
//     if (word[i] == 'o' && mpp['o'] < 2)
//       return 0;
//     minimum = min(minimum, mpp[word[i]]);
//   }

//   if (minimum == INT_MAX)
//     return 0;
//   return minimum;
// }
// Problem in your code

// Letters l and o appear twice in "balloon".

// But in your code you only check:

// if(word[i]=='l'&&mpp['l']<2)return 0;
// if(word[i]=='o'&&mpp['o']<2)return 0;

// However, when calculating the minimum, you still use:

// minimum=min(minimum,mpp[word[i]]);

// This does not divide the counts of l and o by 2, so the result becomes incorrect.

// Correct Logic

// For "balloon" we need:

// Letter	Needed
// b	1
// a	1
// l	2
// o	2
// n	1

// So the answer should be:

// min(
// count(b),
// count(a),
// count(l)/2,
// count(o)/2,
// count(n)
// )

// t.c-O(n*1) we use unordered map so at average it takes O(1)
// s.c-O(5) size of balloon
int maxNumberOfBalloons(string text)
{
  unordered_map<char, int> mpp;
  for (int i = 0; i < text.size(); i++)
  {
    mpp[text[i]]++;
  }
  return min({mpp['b'], mpp['a'], mpp['l'] / 2, mpp['o'] / 2, mpp['n']});
}
// Since the required characters are fixed, you don't even need a map. An array of size 26 is faster.

int maxnumberOfBalloons(string text)
{
  int cnt[26] = {0};
  for (auto ch : text)
  {
    cnt[ch - 'a']++;
  }
  return min({cnt['b' - 'a'], cnt['a' - 'a'], cnt['l' - 'a'] / 2, cnt['o' - 'a'] / 2, cnt['n' - 'a']});
}
// Why this is better

// Array instead of map → faster (O(1) access).

// Code is short and clean.

// Directly handles l and o by dividing by 2.

// Time Complexity

// O(n) (single traversal of string)

// Space Complexity

// O(1) (only 26 letters)

// Interview Tip 💡

// Whenever the question is about lowercase English letters, prefer:

// int freq[26]

// instead of

// unordered_map<char,int>

// because it is faster and simpler.
int main()
{
  string text;
  cin >> text;

  cout << maxNumberOfBalloons(text) << endl;
  cout << maxnumberOfBalloons(text) << endl;
  return 0;
}
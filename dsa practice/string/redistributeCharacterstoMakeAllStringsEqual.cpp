// You are given an array of strings words (0-indexed).

// In one operation, pick two distinct indices i and j, where words[i] is a non-empty string, and move any character from words[i] to any position in words[j].

// Return true if you can make every string in words equal using any number of operations, and false otherwise.

// Example 1:

// Input: words = ["abc","aabc","bc"]
// Output: true
// Explanation: Move the first 'a' in words[1] to the front of words[2],
// to make words[1] = "abc" and words[2] = "abc".
// All the strings are now equal to "abc", so return true.
// Example 2:

// Input: words = ["ab","a"]
// Output: false
// Explanation: It is impossible to make all the strings equal using the operation.

// Constraints:

// 1 <= words.length <= 100
// 1 <= words[i].length <= 100
// words[i] consists of lowercase English letters.

// Hint 1
// Characters are independent—only the frequency of characters matters.
// Hint 2
// It is possible to distribute characters if all characters can be divided equally among all strings.

// from the hint we conclude that we have to return in yes or not that we make or not , we don't have to return string
// so if we check that each char has freq as a factor of words array length then each char is equally divided to each string of words array

#include <bits/stdc++.h>
using namespace std;

bool makeEquals(vector<string> &words)
{
  int n = words.size();
  unordered_map<char, int> mpp;
  for (int i = 0; i < n; i++)
  {
    string str = words[i];
    for (int j = 0; j < str.size(); j++)
    {
      mpp[str[j]]++;
    }
  }
  for (auto it : mpp)
  {
    if (it.second % n != 0)
      return false; // means that character cannot be divided in each string of the words array
  }
  return true;
}
int main()
{
  int n;
  cin >> n;
  vector<string> words(n);
  for (int i = 0; i < n; i++)
    cin >> words[i];
  cout << makeEquals(words);
  return 0;
}
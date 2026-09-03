// You are given an array of strings words and a string chars.

// A string is good if it can be formed by characters from chars (each character can only be used once for each word in words).

// Return the sum of lengths of all good strings in words.

// Example 1:

// Input: words = ["cat","bt","hat","tree"], chars = "atach"
// Output: 6
// Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
// Example 2:

// Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
// Output: 10
// Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.

// Constraints:

// 1 <= words.length <= 1000
// 1 <= words[i].length, chars.length <= 100
// words[i] and chars consist of lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

int countCharacters(vector<string> &words, string chars)
{
  int n = words.size();
  unordered_map<char, int> mpp;
  for (int i = 0; i < chars.size(); i++)
  {
    mpp[chars[i]]++;
  }
  int len = 0;
  for (int i = 0; i < n; i++)
  {
    string str = words[i];
    unordered_map<char, int> temp = mpp; // we copy map because for each string we decrase the freq of each char also
    bool flag = 1;
    for (int j = 0; j < str.size(); j++)
    {
      if (!temp.count(str[j]))
      {
        flag = 0;
        break;
      }
      else
      {
        temp[str[j]]--;
        if (temp[str[j]] == 0)
          temp.erase(str[j]);
      }
    }
    if (flag == 1)
      len += (str.size());
  }
  return len;
}

// instead of map we use vector
int countChar(vector<string> &words, string chars)
{
  int n = words.size();
  vector<int> freq(26, 0);
  for (int i = 0; i < chars.size(); i++)
  {
    freq[chars[i] - 'a']++;
  }
  int len = 0;
  for (int i = 0; i < n; i++)
  {
    string str = words[i];
    vector<int> temp = freq;
    bool flag = 1;
    for (int j = 0; j < str.size(); j++)
    {
      if (temp[str[j] - 'a'] == 0)
      {
        flag = 0;
        break;
      }
      else
      {
        temp[str[j] - 'a']--;
      }
    }
    if (flag == 1)
      len += (str.size());
  }
  return len;
}
int main()
{
  int n;
  cin >> n;
  vector<string> words(n);
  for (int i = 0; i < n; i++)
  {
    cin >> words[i];
  }
  string chars;
  cin >> chars;
  // cout << countCharacters(words, chars);
  cout << countChar(words, chars);
  return 0;
}

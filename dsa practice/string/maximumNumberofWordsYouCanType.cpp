// There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.

// Given a string text of words separated by a single space (no leading or trailing spaces) and a string brokenLetters of all distinct letter keys that are broken, return the number of words in text you can fully type using this keyboard.

// Example 1:

// Input: text = "hello world", brokenLetters = "ad"
// Output: 1
// Explanation: We cannot type "world" because the 'd' key is broken.
// Example 2:

// Input: text = "leet code", brokenLetters = "lt"
// Output: 1
// Explanation: We cannot type "leet" because the 'l' and 't' keys are broken.
// Example 3:

// Input: text = "leet code", brokenLetters = "e"
// Output: 0
// Explanation: We cannot type either word because the 'e' key is broken.

// Constraints:

// 1 <= text.length <= 10^4
// 0 <= brokenLetters.length <= 26
// text consists of words separated by a single space without any leading or trailing spaces.
// Each word only consists of lowercase English letters.
// brokenLetters consists of distinct lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

int canBeTypedWords(string text, string brokenLetters)
{
  vector<int> freq(26, 0);
  for (int i = 0; i < brokenLetters.size(); i++)
    freq[brokenLetters[i] - 'a']++;
  int cnt = 0;
  stringstream ss(text);
  string word;
  while (ss >> word)
  {
    bool flag = 1;
    for (int j = 0; j < word.size(); j++)
    {
      if (freq[word[j] - 'a'] != 0)
      {
        flag = 0;
        break;
      }
    }

    if (flag == 1)
      cnt += 1;
  }
  return cnt;
}
int main()
{
  string text;
  getline(cin, text);
  string brokenLetters;
  cin >> brokenLetters;
  cout << canBeTypedWords(text, brokenLetters);

  return 0;
}
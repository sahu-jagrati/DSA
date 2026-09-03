// Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.

// Note that the strings are case-insensitive, both lowercased and uppercased of the same letter are treated as if they are at the same row.

// In the American keyboard:

// the first row consists of the characters "qwertyuiop",
// the second row consists of the characters "asdfghjkl", and
// the third row consists of the characters "zxcvbnm".

// Example 1:

// Input: words = ["Hello","Alaska","Dad","Peace"]

// Output: ["Alaska","Dad"]

// Explanation:

// Both "a" and "A" are in the 2nd row of the American keyboard due to case insensitivity.

// Example 2:

// Input: words = ["omk"]

// Output: []

// Example 3:

// Input: words = ["adsdf","sfd"]

// Output: ["adsdf","sfd"]

// Constraints:

// 1 <= words.length <= 20
// 1 <= words[i].length <= 100
// words[i] consists of English letters (both lowercase and uppercase).

#include <bits/stdc++.h>
using namespace std;

vector<string> findWords(vector<string> &words)
{
  int n = words.size();
  set<char> firstRow = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'};
  set<char> secondRow = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'};
  set<char> thirdRow = {'z', 'x', 'c', 'v', 'b', 'n', 'm', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'};
  vector<string> ans;
  for (int i = 0; i < n; i++)
  {
    string str = words[i];
    bool flag = 1;
    if (firstRow.count(str[0]))
    {
      for (int j = 1; j < str.size(); j++)
      {
        if (!firstRow.count(str[j]))
        {
          flag = 0;
          break;
        }
      }
    }
    else if (secondRow.count(str[0]))
    {
      for (int j = 1; j < str.size(); j++)
      {
        if (!secondRow.count(str[j]))
        {
          flag = 0;
          break;
        }
      }
    }
    else
    {
      for (int j = 1; j < str.size(); j++)
      {
        if (!thirdRow.count(str[j]))
        {
          flag = 0;
          break;
        }
      }
    }
    if (flag == 1)
      ans.push_back(str);
  }
  return ans;
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
  vector<string> ans = findWords(words);
  for (auto it : ans)
  {
    cout << it << " ";
  }
  return 0;
}
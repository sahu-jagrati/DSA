// You are given an array of strings words and a string pref.

// Return the number of strings in words that contain pref as a prefix.

// A prefix of a string s is any leading contiguous substring of s.

// Example 1:

// Input: words = ["pay","attention","practice","attend"], pref = "at"
// Output: 2
// Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".
// Example 2:

// Input: words = ["leetcode","win","loops","success"], pref = "code"
// Output: 0
// Explanation: There are no strings that contain "code" as a prefix.

// Constraints:

// 1 <= words.length <= 100
// 1 <= words[i].length, pref.length <= 100
// words[i] and pref consist of lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

// in this we have to check that string in words has prefix = pref
int prefixCount(vector<string> &words, string pref)
{
  int n = words.size();
  int m = pref.size();
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    string str = words[i];
    bool flag = 1;
    for (int j = 0; j < m; j++)
    {
      if (str[j] != pref[j])
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
  int n;
  cin >> n;
  vector<string> words(n);
  for (int i = 0; i < n; i++)
  {
    cin >> words[i];
  }
  string pref;
  cin >> pref;
  cout << prefixCount(words, pref) << endl;
  return 0;
}
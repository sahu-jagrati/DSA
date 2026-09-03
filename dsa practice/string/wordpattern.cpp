// Given a pattern and a string s, find if s follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:

// Each letter in pattern maps to exactly one unique word in s.
// Each unique word in s maps to exactly one letter in pattern.
// No two letters map to the same word, and no two words map to the same letter.

// Example 1:

// Input: pattern = "abba", s = "dog cat cat dog"

// Output: true

// Explanation:

// The bijection can be established as:

// 'a' maps to "dog".
// 'b' maps to "cat".
// Example 2:

// Input: pattern = "abba", s = "dog cat cat fish"

// Output: false

// Example 3:

// Input: pattern = "aaaa", s = "dog cat cat dog"

// Output: false

// Constraints:

// 1 <= pattern.length <= 300
// pattern contains only lower-case English letters.
// 1 <= s.length <= 3000
// s contains only lowercase English letters and spaces ' '.
// s does not contain any leading or trailing spaces.
// All the words in s are separated by a single space.

#include <bits/stdc++.h>
using namespace std;

//  i != n → pattern still left
// ss >> word → extra words left
//  Only valid if both exactly consumed
// if (i != n || ss >> word)
//   return false;
// but there is issue in this line:Why LeetCode can still fail here

// ss >> word modifies the stream

// Using extraction (>>) inside a condition is risky and not recommended in judges

// LeetCode expects a pure check, not another extraction attempt

// Even though this works logically, it can behave inconsistently across test cases. like pattern="aaa" and s="aa aa aa aa" it give true but answer is false so this is fails here

// correct issue
bool wordPattern(string pattern, string s)
{
  int n = pattern.size();
  int i = 0; // traverse pattern

  unordered_map<char, string> mpp;
  set<string> st;

  stringstream ss(s);
  string word;

  // read the sentence
  while (ss >> word)
  {
    if (i == n)
      return false; // means there is extra word in s but pattern is finish so return false
    char ch = pattern[i];
    if (mpp.find(ch) != mpp.end())
    {
      if (mpp[ch] != word)
        return false;
    }
    else
    {
      if (st.find(word) != st.end())
      {
        return false;
      }

      mpp[ch] = word;
      st.insert(word);
    }
    i++;
  }

  return i == n; // if pattern still left then it return false;
}

// minimze above code by small change
bool isWordPattern(string pattern, string s)
{
  unordered_map<char, string> mpp;
  unordered_map<string, char> rev; // use map in place of set

  stringstream ss(s);
  string word;

  int i = 0; // traverse pattern
  while (ss >> word)
  {
    if (i == pattern.size())
      return false; // means there is extra word in s

    char ch = pattern[i];
    if (mpp.count(ch) && mpp[ch] != word)
      return false; // count check exists or not
    if (rev.count(word) && rev[word] != ch)
      return false;
    mpp[ch] = word;
    rev[word] = ch;
    i++;
  }
  return i == pattern.size(); // if i!=n meanse there is extra char in pattern
}
int main()
{
  string pattern;
  cout << "Enter pattern:";
  cin >> pattern;

  cout << "Enter sentence: ";
  string sentence;
  cin.ignore(); // 🔥 clear newline
  getline(cin, sentence);

  // bool answer = wordPattern(pattern, sentence);
  bool answer = isWordPattern(pattern, sentence);
  cout << answer << endl;
  return 0;
}
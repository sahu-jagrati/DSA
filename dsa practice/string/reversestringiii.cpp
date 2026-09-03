// Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

// Example 1:

// Input: s = "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"
// Example 2:

// Input: s = "Mr Ding"
// Output: "rM gniD"

// Constraints:

// 1 <= s.length <= 5 * 104
// s contains printable ASCII characters.
// s does not contain any leading or trailing spaces.
// There is at least one word in s.
// All the words in s are separated by a single space.

#include <bits/stdc++.h>
using namespace std;

string reverseString(string word)
{
  int l = 0, r = word.size() - 1;
  while (l < r)
  {
    swap(word[l], word[r]); // we can also use temp for swap
    l++;
    r--;
  }
  return word;
}

string reverseWords(string s)
{
  stringstream ss(s);
  string word;
  string sentence = "";
  while (ss >> word)
  {
    if (!sentence.empty()) // only add space if not first word
      sentence += " ";
    // sentence += reverseString(word);
    reverse(word.begin(), word.end());
    sentence += word;
  }
  return sentence;
}

int main()
{
  string s;
  getline(cin, s);
  cout << reverseWords(s);
  return 0;
}